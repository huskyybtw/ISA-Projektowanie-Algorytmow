#ifndef ISA_PROJEKTOWANIE_ALGORYTMOW_MOVIELOADER_H
#define ISA_PROJEKTOWANIE_ALGORYTMOW_MOVIELOADER_H
#include <string>
#include <vector>

struct Movie{
    int num;
    std::string title;
    double score;
};

class MovieLoader {
private:
    std::vector<Movie> vec;
    std::vector<Movie*> arrays; // VECTOR HOLDING DYNAMICLY ALOCATED ARRAYS FROM GET METHODS
public:
    MovieLoader(std::string path);
    ~MovieLoader();
    void printMovies();
    Movie* getData();
    Movie* getData(int size);
    int getSize();
};


#endif //ISA_PROJEKTOWANIE_ALGORYTMOW_MOVIELOADER_H
