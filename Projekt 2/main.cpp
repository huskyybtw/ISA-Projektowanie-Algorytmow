#include <string>
#include "MovieLoader.h"
#include "tests.h"

int sizes[4] = {10000,100000,250000,500000};
int main(){
    std::string path = "../movies.csv";
    MovieLoader* fileLoader = new MovieLoader(path);

    for(int i=0; i < 3; i++){
      test(i,fileLoader->getData(sizes[0]),sizes[0],1);
      test(i,fileLoader->getData(sizes[1]),sizes[1],1);
      test(i,fileLoader->getData(sizes[2]),sizes[2],1);
      test(i,fileLoader->getData(sizes[3]),sizes[3],1);
      test(i,fileLoader->getData(),fileLoader->getSize(),1);
    }
    delete fileLoader;
}