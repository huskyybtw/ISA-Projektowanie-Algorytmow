
#include <string>
#include <vector>
#include "Heap.h"
#include "Utilities.h"

// plik .exe nie w folderze razem z plikami
std::string basePath = "C:\\Users\\marek\\CLionProjects\\ISA-Projektowanie-Algorytmow\\data";


int main() {
    int amount = 250000;
    if(amount > 250000){
        throw (std::runtime_error("Max working value is 250_000"));
    }
    generateFile(amount,basePath);
    basePath = basePath + std::to_string(amount);
    fileTest(basePath);
    std::cout << "Dziala? : " << checkEqual(basePath,basePath+ "_output") << std::endl;
    return 0;
}
