//
// Created by marek on 29.04.2024.
//
#include "MovieLoader.h"
#include <iostream>
#include "chrono"
#include "algorythms.h"

void test(int sort, Movie* arr, int sizeOfArray, int times) {
    std::chrono::duration<double> duration;
    double avg = 0.0;

    for (int i = 0; i < times; i++) {
        auto start = std::chrono::high_resolution_clock::now();

        Movie *arrPtr = arr;
        switch (sort) {
            case 0 :
                mergeSort(arrPtr, sizeOfArray -1);
                break;
            case 1 :
                bucketSort(arrPtr, sizeOfArray -1);
                break;
            case 2 :
                quickSort(arrPtr, 0, sizeOfArray - 1);
                break;
        }

        auto end = std::chrono::high_resolution_clock::now();
        duration = end - start;
        avg += duration.count();
    }

    avg /= times;
    std::cout << "SORT: " << sort <<"SIZE: "<< sizeOfArray << " TOOK ALL: " << avg << " seconds" << std::endl;
}