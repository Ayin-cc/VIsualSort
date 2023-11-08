#include <vector>
#include <opencv2/opencv.hpp>

void paint(cv::Mat canvas, std::vector<int> arr, int s = -1, int t1 = -1, int t2 = -1);
void selectAlgorithm(int opt, std::vector<int> arr);