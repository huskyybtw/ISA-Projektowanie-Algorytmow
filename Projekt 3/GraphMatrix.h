#ifndef PROJEKT3_GRAPHMATRIX_H
#define PROJEKT3_GRAPHMATRIX_H
#include <vector>
#include <list>

struct VertexMartix{
    int elem;
    int id;
};

struct Edge{
    int weight;
    bool isPresent = false;
};

class GraphMatrix {
private:
    std::vector<VertexMartix*> Vertexes;
    std::vector<std::vector<Edge>> Matrix;
    std::vector<int> Generator(int seed,int size);
    std::vector<int> DensityGenerator(int seed,int size, int max);
public:
    GraphMatrix (int size,double density,int seed);
    ~GraphMatrix ();
    int findShortestPath(int e1,int e2);
    void printMatrix();
};


#endif //PROJEKT3_GRAPHMATRIX_H
