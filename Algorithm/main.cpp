#pragma once
#include "sortAlogorithm.h"

int main() {
  std::vector<int> arr = {
        87, 12, 65, 44, 96, 78, 32, 50, 9, 73,
        22, 68, 35, 91, 59, 5, 80, 17, 41, 93,
        72, 26, 63, 38, 89, 11, 75, 29, 57, 83,
        21, 94, 69, 46, 2, 64, 31, 67, 48, 14,
        88, 23, 81, 36, 77, 53, 19, 99, 66, 43
    };

    std::cout << "ѡ��ʹ���㷨: \n\t" 
        << "1��ѡ������\n\t" 
        << "2����������\n\t" 
        << "3��ð������\n\t" 
        << "4��ϣ������" 
        << std::endl;
    int opt;
    std::cin >> opt;
    selectAlgorithm(opt, arr);

    return 0;
}
