#include "Node.h"

template<typename T>
Node<T>::Node(int i,T e){
    index = i;
    elem = e;
}

template<typename T>
Node<T>::~Node() = default;
