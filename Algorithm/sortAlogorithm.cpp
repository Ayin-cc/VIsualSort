#include "sortAlogorithm.h"

void paint(cv::Mat canvas, std::vector<int> arr, int s, int t1, int t2) {
    canvas.setTo(cv::Scalar(0, 0, 0));

    cv::Scalar color;
    for (int i = 0; i < arr.size(); i++) {
        if (i == t1 || i == t2) {
            color = cv::Scalar(0, 256, 0);
        }
        else if (i == s) {
            color = cv::Scalar(0, 0, 256);
        }
        else {
            color = cv::Scalar(256, 256, 256);
        }
        cv::rectangle(canvas, cv::Point(i * 15 + 20, 450 - arr[i] * 4), cv::Point(i * 15 + 30, 450), color, -1);
    }
    cv::imshow("view", canvas);
    cv::waitKey(200);
}

// 1°¢—°‘Ò≈≈–Ú
void selectionSort(std::vector<int>& arr, cv::Mat canvas) {
    int n = arr.size();
    for (int i = 0; i < n; ++i) {
        int minIndex = i;
        paint(canvas, arr, minIndex);
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
                paint(canvas, arr, minIndex);
            }
        }       
        paint(canvas, arr, -1, i, minIndex);        
        cv::waitKey(100);
        std::swap(arr[i], arr[minIndex]);
        paint(canvas, arr, -1, i, minIndex);
    }
}

// 2°¢≤Â»Î≈≈–Ú
void insertionSort(std::vector<int>& arr, cv::Mat canvas) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        cv::waitKey(100);
        paint(canvas, arr, i);
        while (j >= 0 && arr[j] > key) {
            std::swap(arr[j], arr[j + 1]);
            paint(canvas, arr, -1, j);
            j--;
        }
        arr[j + 1] = key;
    }
}

// 3°¢√∞≈›≈≈–Ú
void bubbleSort(std::vector<int>& arr, cv::Mat canvas) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                paint(canvas, arr, -1, j, j + 1);
                cv::waitKey(100);
                std::swap(arr[j], arr[j + 1]);
                paint(canvas, arr, -1, j, j + 1);
            }
        }
    }
}


// 4°¢œ£∂˚≈≈–Ú
void shellSort(std::vector<int>& arr, cv::Mat canvas) {
    int n = arr.size();
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; ++i) {
            paint(canvas, arr, i);
            for (int j = i; j >= gap && arr[j - gap] > arr[j]; j -= gap) {
                paint(canvas, arr, -1, j, j - gap);
                cv::waitKey(100);
                std::swap(arr[j], arr[j - gap]);
                paint(canvas, arr, -1, j, j - gap);
            }
        }
    }
}

void selectAlgorithm(int opt, std::vector<int> arr) {
    cv::Mat canvas(500, 800, CV_8UC3, cv::Scalar(0, 0, 0));
    cv::namedWindow("view", cv::WINDOW_NORMAL);
    cv::resizeWindow("view", 800, 500);
    switch (opt) {
    case 1:
        selectionSort(arr, canvas);
        break;
    case 2:
        insertionSort(arr, canvas);
        break;
    case 3:
        bubbleSort(arr, canvas);
        break;
    case 4:
        shellSort(arr, canvas);
        break;
    default:
        break;
    }
    paint(canvas, arr);
    cv::waitKey();
}