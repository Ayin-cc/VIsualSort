#include "sortAlogorithm.h"

void paint(cv::Mat canvas, std::vector<int> arr, int s1, int t1, int t2) {
    canvas.setTo(cv::Scalar(0, 0, 0));

    cv::Scalar color;
    for (int i = 0; i < arr.size(); i++) {
        if (i == t1 || i == t2) {
            color = cv::Scalar(0, 256, 0);
        }
        else if (i == s1) {
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

// 1、选择排序
void selectionSort(std::vector<int>& arr, cv::Mat canvas) {
    int n = arr.size();
    for (int i = 0; i < n; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            paint(canvas, arr, minIndex, j);
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

// 2、插入排序
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

// 3、冒泡排序
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


// 4、希尔排序
void shellSort(std::vector<int>& arr, cv::Mat canvas) {
    int n = arr.size();
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; ++i) {
            for (int j = i; j >= gap; j -= gap) {
                paint(canvas, arr, -1, j);
                if (arr[j - gap] > arr[j]) {
                    cv::waitKey(100);
                    std::swap(arr[j], arr[j - gap]);
                    paint(canvas, arr, -1, j - gap);
                }       
                else {
                    break;
                }
            }
        }
    }
}

// 5、归并排序
void merge(std::vector<int>& arr, int left, int mid, int right, cv::Mat canvas) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // 保存子数组
    std::vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }

    // 合并两个子数组
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            paint(canvas, arr, -1, k);
            arr[k] = L[i];
            i++;
        }
        else {
            paint(canvas, arr, -1, k);
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        paint(canvas, arr, -1, k);
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        paint(canvas, arr, -1, k);
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(std::vector<int>& arr, int left, int right, cv::Mat canvas) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid, canvas);
        mergeSort(arr, mid + 1, right, canvas);
        merge(arr, left, mid, right, canvas);
    }
}

// 6、快速排序
int partition(std::vector<int>& arr, int l, int r, cv::Mat canvas) {
    // pivot 基准元素
    int pivot = arr[r];
    int i = l - 1;

    for (int j = l; j < r; j++) {
        paint(canvas, arr, r, i, j);
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    paint(canvas, arr, -1, i + 1, r);
    std::swap(arr[i + 1], arr[r]);
    return i + 1;
}

void quickSort(std::vector<int>& arr, int l, int r, cv::Mat canvas) {
    if (l < r) {
        int pi = partition(arr, l, r, canvas);
        quickSort(arr, l, pi - 1, canvas);
        quickSort(arr, pi + 1, r, canvas);
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
    case 5:
        mergeSort(arr, 0, arr.size() - 1, canvas);
        break;
    case 6:
        quickSort(arr, 0, arr.size() - 1, canvas);
        break;
    default:
        break;
    }
    paint(canvas, arr);
    cv::waitKey();
}