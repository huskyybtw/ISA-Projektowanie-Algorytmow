#ifndef ISA_PROJEKTOWANIE_ALGORYTMOW_NODE_H
#define ISA_PROJEKTOWANIE_ALGORYTMOW_NODE_H

template<typename T>
class Node {
public:
    Node(int i,T e);
    ~Node();


private:
    int index;
    T elem;
};


#endif //ISA_PROJEKTOWANIE_ALGORYTMOW_NODE_H
