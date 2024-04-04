#include "Heap.h"

template<typename T>
Heap<T>::Heap(int array_size){
    array = new Node<T>[array_size];
    Size = array_size;
}

template<typename T>
Heap<T>::~Heap(){
    delete[] array;
}

