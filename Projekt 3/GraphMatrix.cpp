//
// Created by marek on 17.05.2024.
//
#include <random>
#include <iostream>
#include <algorithm>
#include "GraphMatrix.h"
#include <climits>
#include <unordered_map>
#include <queue>

GraphMatrix::GraphMatrix(int size, double density, int seed) {
    int MaxEdges = (size * (size - 1)) / 2;
    int numEdges = static_cast<int>(MaxEdges * density);

    std::vector<int> EdgeValues = Generator(seed, MaxEdges);
    std::vector<int> Edges = DensityGenerator(seed + 101, MaxEdges, numEdges);

    for(int i=0 ; i<size ; i++){
        Vertexes.push_back(new VertexMartix({i,i}));
    }

    Matrix.resize(size, std::vector<Edge>(size, {0, false}));

    int edgeIndex = 0;
    int iterator = 0;
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if(edgeIndex == Edges.size()){
                break;
            }
            if(iterator == Edges[edgeIndex]) {
                Matrix[i][j] = {EdgeValues[edgeIndex], true};
                Matrix[j][i] = {EdgeValues[edgeIndex], true};
                iterator++;
                edgeIndex++;
            }
            else{
                iterator++;
            }
        }
    }

    std::cout << edgeIndex << std::endl;
}

int GraphMatrix::findShortestPath(int start, int end) {
    std::vector<int> distance(Vertexes.size(), INT_MAX);
    std::vector<bool> visited(Vertexes.size(), false);
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> queue;

    distance[start] = 0;
    queue.push({0, start});

    while (!queue.empty()) {
        int u = queue.top().second;
        queue.pop();

        if (visited[u]) {
            continue;
        }

        visited[u] = true;

        for (int i = 0; i < Matrix.size(); i++) {
            if (Matrix[u][i].isPresent) {
                int v = i;
                int weight = Matrix[u][i].weight;

                if (distance[v] > distance[u] + weight) {
                    distance[v] = distance[u] + weight;
                    queue.push({distance[v], v});
                }
            }
        }
    }

    return distance[end];
}

GraphMatrix::~GraphMatrix(){
    for(int i =0 ; i < Vertexes.size() ; i++){
        delete Vertexes[i];
    }
}
std::vector<int> GraphMatrix::DensityGenerator(int seed, int maxEdges, int numEdges) {
    std::vector<int> numbers(maxEdges);
    std::iota(numbers.begin(), numbers.end(), 0);

    std::mt19937 rng(seed);
    std::shuffle(numbers.begin(), numbers.end(), rng);

    numbers.resize(numEdges);
    std::sort(numbers.begin(), numbers.end());

    return numbers;
}

std::vector<int> GraphMatrix::Generator(int seed, int size) {
    std::vector<int> numbers;
    std::mt19937 rng(seed);
    std::uniform_int_distribution<int> dist(0, 1000);

    for (int i = 0; i < size; ++i) {
        int rand = dist(rng);
        numbers.push_back(rand);
    }

    return numbers;
}

void GraphMatrix::printMatrix(){
    for(int i=0 ; i<Matrix.size() ; i++){
        std::cout << std::endl;
        for(int j=0 ; j<Matrix.size() ; j++){
            if(!Matrix[i][j].isPresent){
                std::cout << "-" << " ";
            }
            else{
            std::cout << Matrix[i][j].weight << " ";
            }
        }
    }
}