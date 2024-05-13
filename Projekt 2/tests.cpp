//
// Created by marek on 29.04.2024.
//
#include "MovieLoader.h"
#include <iostream>
#include "chrono"
#include "algorythms.h"

bool sortedCorrectly(Movie* arr,int size){
    for (int i=0 ; i< size-1 ; i++){
        if(arr[i].score > arr[i+1].score){
            std::cout << "SORTED INCORRECTLY :" << arr[i].num << ": "
            << arr[i].score << std::endl;
            return false;
        }
    }
    return true;
}

Movie* test(int sort, Movie* arr, int sizeOfArray) {
    std::chrono::duration<double> duration;
    double avg = 0.0;

    Movie *arrPtr = arr;
        auto start = std::chrono::high_resolution_clock::now();
        switch (sort) {
            case 0 :
                mergeSort(arrPtr, sizeOfArray);
                break;
            case 1 :
                bucketSort(arrPtr, sizeOfArray);
                break;
            case 2 :
                quickSort(arrPtr, 0, sizeOfArray - 1);
                break;
    }
    auto end = std::chrono::high_resolution_clock::now();
    duration = end - start;
    if(sortedCorrectly(arrPtr,sizeOfArray)) {
        avg += duration.count();
    }

    //std::cout << "SORT: " << sort <<"SIZE: "<< sizeOfArray << " TOOK ALL: " << avg << " seconds" << std::endl;
    return arrPtr;
}

double testMultiple(int sort, Movie* arr, int sizeOfArray, int times) {
    std::chrono::duration<double> duration;
    int divide = times;
    double avg = 0.0;

    for (int i = 0; i < times; i++) {
        auto start = std::chrono::high_resolution_clock::now();

        Movie *arrPtr = arr;
        switch (sort) {
            case 0 :
                mergeSort(arrPtr, sizeOfArray);
                break;
            case 1 :
                bucketSort(arrPtr, sizeOfArray);
                break;
            case 2 :
                quickSort(arrPtr, 0, sizeOfArray - 1);
                break;
        }

        auto end = std::chrono::high_resolution_clock::now();
        duration = end - start;
        if(sortedCorrectly(arrPtr,sizeOfArray)) {
            avg += duration.count();
            divide--;
        }
    }

    avg /= divide;
    std::cout << "SORT: " << sort <<"SIZE: "<< sizeOfArray << " TOOK ALL: " << avg << " seconds" << std::endl;
    return avg;
}

double Avg(Movie* arr,int size){
    double result = 0.0;
    for(int i=0 ; i<size ; i++){
        result += arr[i].score;
    }
    return result/size;
}


double Median(Movie* arr,int size){
    if(size/2 % 2 == 0){
        return arr[size/2].score;
    }
    else{
        return (arr[size/2].score + arr[size/2 + 1].score)/2;
    }
}