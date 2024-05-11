#include <iostream>
#include "Heap.h"

template class Heap<int>;
template class Heap<char>;

template<typename T>
Heap<T>::Heap(int array_size){
    array = new Node<T>[array_size];
    size = -1;
}

template<typename T>
Heap<T>::~Heap(){
    delete[] array;
}

template<typename T>
const T Heap<T>::getMin() {
    if(size >= 0){
        return array[0].elem;
    }
}

template<typename T>
int Heap<T>::getSize() {
    return size;
}

template<typename T>
void Heap<T>::insert(const int prio,const T& t) {

    size++;
    Node<T>* temp = new Node<T>;
    temp->priority = prio;
    temp->elem = t;
    array[size] = *temp;
    siftUp(size);
}

template<typename T>
T Heap<T>::pop() {
    if (size < 0) {
        throw std::out_of_range("Heap is empty");
    }

    Node<T> temp = array[0];
    array[0] = array[size];
    array[size] = temp;
    size--;

    siftDown(0);
    return temp.elem;
}
template<typename T>
void Heap<T>::printHeap() {
    for(int i=0 ; i<=size ; i++){
        std::cout << array[i].elem << std::endl;
    }
}
template<typename T>
void Heap<T>::siftUp(int i) {
    int parentIndex = (i-1)/2 ;

    // DOPÓKI MAMY ELEMENTY W TABLICY
    // ORAZ PIORYTET DZIECKA JEST MNIEJSZY NIZ RODZICA
    // PODMIENIAMY MIEJSCAMI WĘZLY
    while (i != 0 && array[i].priority < array[parentIndex].priority){
        std::swap(array[i],array[parentIndex]);

        i = parentIndex;
        parentIndex = (i-1) / 2;
    }
}

template<typename T>
void Heap<T>::siftDown(int i) {
    int leftChild = 2 * i + 1;
    int rightChild = 2 * i + 2;

    while ((leftChild <= size && array[i].priority > array[leftChild].priority) ||
           (rightChild <= size && array[i].priority > array[rightChild].priority)) {

        int smallest = leftChild;
        if (rightChild <= size && array[rightChild].priority < array[leftChild].priority) {
            smallest = rightChild;
        }
        std::swap(array[i],array[smallest]);

        i = smallest;
        leftChild = 2 * i + 1;
        rightChild = 2 * i + 2;
    }
}





