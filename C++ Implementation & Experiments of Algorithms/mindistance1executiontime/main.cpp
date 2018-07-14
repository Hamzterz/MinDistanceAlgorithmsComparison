#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <ctime>
#include <ratio>
#include <chrono>
#include <cstdlib>
#include <iomanip>

using namespace std;
using namespace std::chrono;

int MinDistance(int Array[], int n){
    int dmin = std::numeric_limits<int>::max();
    for(int i = 0; i < n; i++){
        for(int j = 0; j< n; j++){
            if(i != j && abs(Array[i]-Array[j]) < dmin){
                dmin = abs(Array[i]-Array[j]);
            }
        }
    }
    return dmin;
}

int numArraysToTest = 100;
int numOfSamples = 100.0f;

int main(){
    ofstream outFile("NumberOfArrays.txt", ios::out);
    int Sizes[100];
    for(int i = 0; i<numArraysToTest; i++){
        Sizes[i] = (i+10)*numArraysToTest;
    }
    int ArraySize = (sizeof(Sizes))/(sizeof(Sizes[0]));

    for(int k=0; k<ArraySize; k++){
        int totalTimeforSamples = 0;
        for(int j=0; j<numOfSamples; j++){
        int* Array = new int[Sizes[k]];
        for (int i = 0; i < Sizes[k]; i++){
            Array[i] = rand() % (Sizes[k] * 10);
        }
        for (int i = 0; i < Sizes[k]; i++){
            Array[i] = rand() % (Sizes[k] * 10);
        }
        high_resolution_clock::time_point t1 = high_resolution_clock::now();
        MinDistance(Array, Sizes[k]);
        high_resolution_clock::time_point t2 = high_resolution_clock::now();
        duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
        totalTimeforSamples += time_span.count()*1000;
        }
        cout << "Average time for an array of length " << (k+1)*numArraysToTest << " was "
        << setprecision(5) << totalTimeforSamples/numOfSamples << " ms." << endl;
        outFile << fixed << setprecision(5) << totalTimeforSamples/numOfSamples << "\n";
        }
    return 0;
}

