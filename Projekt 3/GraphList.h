#ifndef PROJEKT3_GRAPHLIST_H
#define PROJEKT3_GRAPHLIST_H
#include <vector>
#include <list>
#include <unordered_map>

struct VertexList;

struct EdgeList{
    int weight;
    VertexList* vertex;
};

struct VertexList{
    int elem;
    int id;
    std::list<EdgeList> listOfEdges;
};


class GraphList {
private:
    std::vector<VertexList*> Vertexes;
    std::vector<int> Generator(int seed,int size);

    std::unordered_multimap<int, int> DensityGenerator(int seed,int size, int max);
public:
    GraphList (int size,double density,int seed);
    ~GraphList ();
    int findShortestPath(int e1,int e2);
    void printMatrix();
};

#endif //PROJEKT3_GRAPHLIST_H
