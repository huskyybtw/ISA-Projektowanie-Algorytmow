#include <iostream>
#include "GraphMatrix.h"
#include "GraphList.h"
int main(){
    GraphList* G = new GraphList(5,0.75,10);
    G->printMatrix();
    auto a = G->findShortestPath(0,2);
    std::cout << a << std::endl;
    delete G;


    GraphMatrix* Z = new GraphMatrix(5,0.75,10);
    Z->printMatrix();
    auto aa = Z->findShortestPath(0,2);
    std::cout<<std::endl;
    std::cout << aa << std::endl;
    delete Z;
    return 0;
}