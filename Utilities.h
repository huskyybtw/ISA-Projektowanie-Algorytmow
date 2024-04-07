#ifndef ISA_PROJEKTOWANIE_ALGORYTMOW_UTILITIES_H
#define ISA_PROJEKTOWANIE_ALGORYTMOW_UTILITIES_H
#include <iostream>

template <class T>
void shuffleArray(T array[], int size);
void fileTest(std::string path);

void generateFile(int amount,std::string& basePath);
bool checkEqual(const std::string& file1, const std::string& file2);


#endif //ISA_PROJEKTOWANIE_ALGORYTMOW_UTILITIES_H
