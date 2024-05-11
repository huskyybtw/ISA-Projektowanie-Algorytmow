
#include <string>
#include <vector>
#include "Heap.h"
#include "Utilities.h"

// plik .exe nie w folderze razem z plikami
std::string basePath = "..\\data";

int main() {
    int amount;
    std::cout << "Ile liczb chcesz przetestowac" << std::endl;
    std::cin >> amount;


    generateFile(amount,basePath);
    basePath = basePath + std::to_string(amount);
    fileTest(basePath);
    std::cout << "Dziala? : " << checkEqual(basePath,basePath+ "_output") << std::endl;
    return 0;
}
