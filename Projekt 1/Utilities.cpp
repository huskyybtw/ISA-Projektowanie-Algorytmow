#include <fstream>
#include <vector>
#include <ctime>
#include <optional>
#include <chrono>
#include "Utilities.h"
#include "Heap.h"

void generateFile(int amount,std::string& basePath) {
    std::ofstream file(basePath + std::to_string(amount));
    if (file.is_open()) {
        for (int i = 0; i < amount; ++i) {
            file << i + 1 << "\n";
        }
        file.close();
        std::cout << "File " << basePath << "data" << amount << " generated.\n";
    } else {
        std::cerr << "Failed to open file.\n";
    }
}

bool checkEqual (const std::string& file1, const std::string& file2) {
    std::ifstream f1(file1, std::ios::binary);
    std::ifstream f2(file2, std::ios::binary);

    if (!f1.is_open() || !f2.is_open()) {
        std::cerr << "Failed to open files.\n";
        return false;
    }

    return std::equal(std::istreambuf_iterator<char>(f1.rdbuf()),
                      std::istreambuf_iterator<char>(),
                      std::istreambuf_iterator<char>(f2.rdbuf()));
}

template<class T>
void shuffleArray(T array[], int size) {
    size--;
    std::srand(std::time(nullptr));
    for (int i = 0; i < size; i++) {
        int j = std::rand() % (size+1);
        if(i != j){
            std::swap(array[i], array[j]);
        }
    }
}


void fileTest(std::string path){
    std::ifstream file(path);
    if (!file.is_open()) {
        std::cerr << "Failed to open the file.\n";
        return;
    }
    auto start_Wysylania = std::chrono::high_resolution_clock::now();
    // WYSYLANIE WIADOMOSCI
    int linecount = 0;
    std::string line;
    while(std::getline(file,line)){
        linecount++;
    }

    Heap<int>* queue = new Heap<int>(linecount);
    Node<int>* array = new Node<int>[linecount];
    linecount = 0;

    file.clear();
    file.seekg(0, std::ios::beg);

    while(std::getline(file,line)) {
        array[linecount].elem = std::stoi(line);
        array[linecount].priority = linecount;
        linecount++;
    }
    file.close();
    auto end_Wysylania = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration_Wysylania = end_Wysylania - start_Wysylania;
    std::cout << "Wysylanie trwalo: " << duration_Wysylania.count() << " s" << std::endl;

    // MIESZANIE KOLEJNOSCI W KTOREJ JEST UPORZADKOWANA WIADOMOSC
    shuffleArray(array,linecount);

    auto start_Wpisywania = std::chrono::high_resolution_clock::now();
    for (int i=0 ; i<linecount; i++){
        queue->insert(array[i].priority,array[i].elem);
    }
    auto end_Wpisywania = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration_Wpisywania = end_Wpisywania  - start_Wpisywania ;
    std::cout << "Dodawanie do kopca trwalo: " << duration_Wpisywania.count() << " s" << std::endl;

    auto start_Wyciagania = std::chrono::high_resolution_clock::now();
    // WYCIAGANIE DANYCH Z KOPCA PO PIORYTETACH
    std::vector<int> vec;
    while( queue->getSize() >= 0 ){
        vec.push_back(queue->pop());
    }
    auto end_Wyciagania = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration_Wyciagania = end_Wyciagania - start_Wyciagania;
    std::cout << "Usuwanie z kopca trwalo: " << duration_Wyciagania.count() << " s" << std::endl;

    // ZAPIS ODCZYTANEJ WIADOMOSCI
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
    delete []array;
}
