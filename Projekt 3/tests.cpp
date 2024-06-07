#include "tests.h"
#include "GraphList.h"
#include "GraphMatrix.h"
#include <chrono>
#include <vector>

double test_Matrix(int* seeds,int seedsSize,int amount,int density,int times){
    double result = 0;
    for(int i=0 ; i < seedsSize ; i++) {
        GraphMatrix *G = new GraphMatrix(amount,density,seeds[i]);
        double avg = 0;
        for(int j=0 ; j<times ; j++) {

            auto start = std::chrono::high_resolution_clock::now();

            G->findShortestPath(0,amount-1);

            auto end = std::chrono::high_resolution_clock::now();

            std::chrono::duration<double> duration = end - start;
            avg += duration.count();
            //std::cout << "SEED :" << seeds[i] << " ELEM :" << amount << " TIME : " << duration.count() << std::endl;

        }
        avg = avg/times;
        result += avg;
        //std::cout << "Srednia" << " " << "SEED :" << seeds[i] << " ELEM :" << amount << " TIME : " << avg << std::endl;
        delete G;
    }
    return result / seedsSize;
}

double test_List(int* seeds,int seedsSize,int amount,int density,int times){
    double result = 0;
    for(int i=0 ; i < seedsSize ; i++) {
        GraphList *G = new GraphList(amount,density,seeds[i]);
        double avg = 0;
        for(int j=0 ; j<times ; j++) {

            auto start = std::chrono::high_resolution_clock::now();

            G->findShortestPath(0,amount-1);

            auto end = std::chrono::high_resolution_clock::now();

            std::chrono::duration<double> duration = end - start;
            avg += duration.count();
            //std::cout << "SEED :" << seeds[i] << " ELEM :" << amount << " TIME : " << duration.count() << std::endl;

        }
        avg = avg/times;
        result += avg;
        //std::cout << "Srednia" << " " << "SEED :" << seeds[i] << " ELEM :" << amount << " TIME : " << avg << std::endl;
        delete G;
    }
    return result / seedsSize;
}

