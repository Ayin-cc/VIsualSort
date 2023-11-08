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

    std::cout << "Ñ¡ÔñÊ¹ÓÃËã·¨: \n\t" 
        << "1¡¢Ñ¡ÔñÅÅÐò\n\t" 
        << "2¡¢²åÈëÅÅÐò\n\t" 
        << "3¡¢Ã°ÅÝÅÅÐò\n\t" 
        << "4¡¢Ï£¶ûÅÅÐò" 
        << std::endl;
    int opt;
    std::cin >> opt;
    selectAlgorithm(opt, arr);

    return 0;
}
