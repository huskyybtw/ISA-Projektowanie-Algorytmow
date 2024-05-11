#ifndef ISA_PROJEKTOWANIE_ALGORYTMOW_ALGORYTHMS_H
#define ISA_PROJEKTOWANIE_ALGORYTMOW_ALGORYTHMS_H
#include "MovieLoader.h"

Movie* mergeSort(Movie* arr,int size);
void merge(Movie* leftArray,Movie* arr,Movie* rightArray,int sizeLeft,int sizeRight);

Movie* bucketSort(Movie* arr, int size);
void insertSort(std::vector<Movie>& bucket);

void quickSort(Movie* arr, int low, int high);
int partition(Movie* arr, int low, int high);

void quickSort(int* arr, int low, int high);
int partition(int* arr, int low, int high);

#endif //PROJEKT2_ALGORYTHMS_H
