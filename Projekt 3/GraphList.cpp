//
// Created by marek on 18.05.2024.
//

#include "GraphList.h"
#include <random>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <queue>

GraphList::GraphList(int size, double density, int seed) {
    int MaxEdges = (size * (size - 1)) / 2;
    int numEdges = static_cast<int>(MaxEdges * density);

    std::vector<int>EdgeValues = Generator(seed,MaxEdges);
    std::unordered_multimap<int,int> Edges = DensityGenerator(seed + 101, size, numEdges);


    for(int i=0 ; i<size ; i++){
        Vertexes.push_back(new VertexList({i,i}));
    }
    int edgeIndex = 0;
    for (auto& i : Edges) {
        int fromVertexIndex = i.first;
        int toVertexIndex = i.second;
        VertexList* fromVertex = Vertexes[fromVertexIndex];
        VertexList* toVertex = Vertexes[toVertexIndex];
        if(fromVertex != toVertex) {
            fromVertex->listOfEdges.push_front({EdgeValues[edgeIndex], toVertex});
            toVertex->listOfEdges.push_front({EdgeValues[edgeIndex], fromVertex});
            edgeIndex++;
        }
    }
}

GraphList::~GraphList(){
    for(int i =0 ; i < Vertexes.size() ; i++){
        delete Vertexes[i];
    }
}

std::unordered_multimap<int, int> GraphList::DensityGenerator(int seed, int size, int numEdges) {
    std::vector<std::pair<int, int>> allPairs;
    for (int i = 0; i < size; ++i) {
        for (int j = i + 1; j < size; ++j) {
            allPairs.push_back({i, j});
        }
    }

    std::mt19937 rng(seed);
    std::shuffle(allPairs.begin(), allPairs.end(), rng);

    std::unordered_multimap<int, int> map;
    for (int i = 0; i < numEdges; ++i) {
        map.insert(allPairs[i]);
    }

    return map;
}

std::vector<int> GraphList::Generator(int seed, int size) {
    std::vector<int> numbers;
    std::mt19937 rng(seed);
    std::uniform_int_distribution<int> dist(0, 1000);

    for (int i = 0; i < size; ++i) {
        int rand = dist(rng);
        numbers.push_back(rand);
    }

    return numbers;
}

int GraphList::findShortestPath(int start, int end) {
    std::vector<int> distances(Vertexes.size(), INT_MAX);
    std::vector<bool> visited(Vertexes.size(), false);
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> pq;

    distances[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int currentDistance = pq.top().first;
        int currentVertex = pq.top().second;
        pq.pop();

        if (visited[currentVertex]){
            continue;
        }

        visited[currentVertex] = true;

        for (auto& edge : Vertexes[currentVertex]->listOfEdges) {
            int neighbor = edge.vertex->id;
            int weight = edge.weight;

            if (distances[currentVertex] + weight < distances[neighbor]) {
                distances[neighbor] = distances[currentVertex] + weight;
                pq.push({distances[neighbor], neighbor});
            }
        }
    }

    return distances[end];
}

void GraphList::printMatrix() {
    for(VertexList* v : Vertexes){
        std::cout << v->id << " :";
        for(EdgeList e : v->listOfEdges){
            std::cout << e.vertex->id << "(" << e.weight << ")" << " -> ";
        }
        std::cout << std::endl;
    }
}