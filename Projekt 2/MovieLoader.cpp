#include <fstream>
#include <iostream>
#include "MovieLoader.h"

MovieLoader::MovieLoader(std::string path) {
    std::ifstream file(path);

    if (file.is_open()) {
        std::string line;
        std::string skip;
        std::getline(file, skip);
        while (std::getline(file, line)) {
            size_t pos1 = line.find(',');
            if (pos1 == std::string::npos) continue;
            size_t pos2 = line.find(',', pos1 + 1);
            if (pos2 == std::string::npos) continue;
            size_t pos3 = line.find(',');
            if (pos3 == std::string::npos) continue;
            size_t pos4 = line.find(',',pos2 +1);
            if (pos4 != std::string::npos) continue;

            std::string idStr = line.substr(0, pos1);
            std::string title = line.substr(pos1 + 1, pos2 - pos1 - 1);
            std::string scoreStr = line.substr(pos2 + 1, pos3 - pos2 - 1);

            if (!isdigit(scoreStr[0])) continue;
            int id = std::stoi(idStr);
            double score = std::stod(scoreStr);

            vec.push_back({id, title, score});
        }
    }
    file.close();
}

MovieLoader::~MovieLoader(){
    for(Movie* temp : arrays){
        delete[] temp;
    }
}

void MovieLoader::printMovies() {
    for (Movie movie : vec){
            std::cout << "Number: " << movie.num <<
                        "Title: " << movie.title <<
                        "Score: " << movie.score << std::endl;
    }
}

int MovieLoader::getSize() {
    return vec.size();
}

Movie* MovieLoader::getData(){
    Movie *arr = new Movie[vec.size()];
    arrays.push_back(arr);
    for (int i=0 ; i<vec.size() ; i++){
        arr[i] = vec[i];
    }
    return arr;
}

Movie* MovieLoader::getData(int size){
    if (size <= 0 || size > vec.size())  {
        return this->getData();
    }
    Movie *arr = new Movie[size];
    arrays.push_back(arr);
    for (int i=0 ; i<size ; i++){
        arr[i] = vec[i];
    }
    return arr;
}
