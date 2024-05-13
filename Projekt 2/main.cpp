#include <string>
#include <iostream>
#include "MovieLoader.h"
#include "tests.h"

int sizes[4] = {10000,100000,250000,500000};
int main(){
    std::string path = "../movies.csv";
    MovieLoader* fileLoader = new MovieLoader(path);

    for(int i=0 ;i<3 ; i++) {
        for (int j = 0; j < 4; j++) {
            Movie *arr = test(i, fileLoader->getData(sizes[j]), sizes[j]);
            std::cout << "AVG : " << Avg(arr, sizes[j]) <<
                      ", MEDIAN : " << Median(arr, sizes[j]) << std::endl;
        }
        Movie *arr = test(i, fileLoader->getData(), fileLoader->getSize());
        std::cout << "AVG : " << Avg(arr, fileLoader->getSize()) <<
                  ", MEDIAN : " << Median(arr, fileLoader->getSize()) << std::endl;
    }


    delete fileLoader;
}