//
// Created by Administrator on 29.03.2024.
//

#ifndef ISA_PROJEKTOWANIE_ALGORYTMOW_HEAP_H
#define ISA_PROJEKTOWANIE_ALGORYTMOW_HEAP_H

#include "Node.h"
// KOPIEC ZAKLADAJACY STALA LICZBE ELEMENTOW NIE WIEKSZA OD SIZE
template<typename T>
class Heap {

public:
    Heap(int array_size);
    ~Heap();

    void insert();
    T getMin();
    T pop();

private:
    Node<T>* array;
    int Size;;

    // UTILITIES

    void siftUp();
    void siftDown();
};


#endif //ISA_PROJEKTOWANIE_ALGORYTMOW_HEAP_H

