#include <fstream>
#include <vector>
#include <ctime>
#include <optional>
#include "Utilities.h"
#include "Heap.h"

template<class T>
void shuffleArray(T array[], int size) {
    size--;
    std::srand(std::time(nullptr)); // Seed the random number generator
    for (int i = 0; i < size; i++) {
        int j = std::rand() % (size+1); // Generate a random index between 0 and i (inclusive)
        if(i != j){
            std::swap(array[i], array[j]); // Swap elements at indices i and j
        }
    }
}
void fileTest(std::string path){
    std::ifstream file(path);
    if (!file.is_open()) {
        std::cerr << "Failed to open the file.\n";
        return;
    }

    int linecount = 0;
    std::string line;
    while(std::getline(file,line)){
        linecount++;
    }

    Heap<int>* queue = new Heap<int>(linecount);
    Node<int> array[linecount];
    linecount = 0;
    file.clear();
    file.seekg(0, std::ios::beg);

    while(std::getline(file,line)) {
        array[linecount].elem = std::stoi(line);
        array[linecount].priority = linecount;
        linecount++;
    }
    file.close();
    shuffleArray(array,linecount);

    for (int i=0 ; i<linecount; i++){
        queue->insert(array[i].priority,array[i].elem);
    }

    std::vector<int> vec;
    while( queue->getSize() >= 0 ){
        vec.push_back(queue->pop());
    }

    std::ofstream outputFile(path + "_output");
    if (outputFile.is_open()) {
        for (int element : vec) {
            outputFile << element << std::endl;
        }
        outputFile.close();
    } else {
        std::cerr << "Failed to open output file.\n";
    }

    delete queue;
}
