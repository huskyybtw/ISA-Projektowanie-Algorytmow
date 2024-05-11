#ifndef ISA_PROJEKTOWANIE_ALGORYTMOW_HEAP_H
#define ISA_PROJEKTOWANIE_ALGORYTMOW_HEAP_H


template<typename T>
struct Node {
    int priority;
    T elem;
};


// KOPIEC ZAKLADAJACY STALA LICZBE ELEMENTOW NIE WIEKSZA OD SIZE
template<typename T>
class Heap {

public:
    Heap(int array_size);
    ~Heap();

    const T getMin();
    void insert(const int prio,const T& t);
    T pop();

    int getSize();
    void printHeap();
private:
    Node<T>* array;
    int size;
    int maxSize;

    // UTILITIES
    void siftUp(int i);
    void siftDown(int i);
};


#endif //ISA_PROJEKTOWANIE_ALGORYTMOW_HEAP_H

