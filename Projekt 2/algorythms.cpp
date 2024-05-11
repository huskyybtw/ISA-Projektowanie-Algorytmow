#include "algorythms.h"
#include <vector>

void merge(Movie* leftArray,Movie* rightArray,Movie* arr,int sizeLeft,int sizeRight){
    int leftIterator = 0;
    int rightIterator = 0;
    int resultIterator = 0;

    // Merge the temporary arrays back into arr[]
    while (leftIterator < sizeLeft && rightIterator < sizeRight) {
        if (leftArray[leftIterator].score <= rightArray[rightIterator].score) {
            arr[resultIterator] = leftArray[leftIterator];
            leftIterator++;
        } else {
            arr[resultIterator] = rightArray[rightIterator];
            rightIterator++;
        }
        resultIterator++;
    }

    // Copy the remaining elements of leftArray[], if any
    while (leftIterator < sizeLeft) {
        arr[resultIterator] = leftArray[leftIterator];
        leftIterator++;
        resultIterator++;
    }

    // Copy the remaining elements of rightArray[], if any
    while (rightIterator < sizeRight) {
        arr[resultIterator] = rightArray[rightIterator];
        rightIterator++;
        resultIterator++;
    }
}
Movie* mergeSort(Movie* arr,int size){
    if(size == 1){
        return arr;
    }

    int sizeLeft = size/2;
    int sizeRight = size - sizeLeft;
    Movie* arrLeft = new Movie[sizeLeft];
    Movie* arrRight = new Movie[sizeRight];

    for(int i = 0 ; i < sizeLeft ; i++){
        arrLeft[i] = arr[i];
    }
    for(int i = 0 ; i < sizeRight ; i++){
        arrRight[i] = arr[sizeLeft + i];
    }
    arrLeft = mergeSort(arrLeft,sizeLeft);
    arrRight = mergeSort(arrRight,sizeRight);

    merge(arrLeft,arrRight,arr,sizeLeft,sizeRight);
    delete[] arrLeft;
    delete[] arrRight;
    return arr;
}
void insertionSort(std::vector<Movie>& bucket) {
    for (int i = 1; i < bucket.size(); ++i) {
        Movie key = bucket[i];
        int j = i - 1;
        while (j >= 0 && bucket[j].score > key.score) {
            bucket[j + 1] = bucket[j];
            j--;
        }
        bucket[j + 1] = key;
    }
}
Movie* bucketSort(Movie* arr, int size) {
    std::vector<Movie> buckets[10];

    for (int i = 0; i < size; i++) {
        int index = arr[i].score - 1;
        buckets[index].push_back(arr[i]);
    }

    for (int i = 0; i < 10; i++) {
        insertionSort(buckets[i]);
    }

    int index = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < buckets[i].size(); j++) {
            arr[index] = buckets[i][j];
            index++;
        }
    }
    return arr;
}

int partition(Movie* arr, int low, int high) {
    int pivotIndex = low + (high - low) / 2; // Wybór środkowego elementu jako pivot
    Movie pivot = arr[pivotIndex];

    int i = low;
    int j = high;

    while (i <= j) {
        while (arr[i].score < pivot.score) {
            i++;
        }
        while (arr[j].score > pivot.score) {
            j--;
        }
        if (i <= j) {
            std::swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    return i;
}

void quickSort(Movie* arr, int low, int high) {
    if (low < high) {
        int partitionIndex = partition(arr, low, high);
        quickSort(arr, low, partitionIndex - 1);
        quickSort(arr, partitionIndex, high);
    }
}