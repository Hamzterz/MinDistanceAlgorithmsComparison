#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <limits>
#include <iostream>
#include <fstream>

using namespace std;

int MinDistance2Count(int Array[], int n){
    int dmin = std::numeric_limits<int>::max();
    int numBasic = 0;
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j< n; j++){
                int temp = abs(Array[i]-Array[j]);
                if(temp < dmin){
                    dmin = temp;
                }
                numBasic += 1;
        }
    }
    return numBasic;
}

int numArraysToTest = 100;

int main(){
    ofstream outFile("NumberOfArrays.txt", ios::out);

    int Sizes[100];
    for(int i = 0; i<numArraysToTest+10; i++){
        Sizes[i] = (i+1)*(numArraysToTest);
    }

    int ArraySize = (sizeof(Sizes))/(sizeof(Sizes[0]));

    for(int k=0; k<ArraySize; k++){
        int* Array = new int[Sizes[k]];
        for (int i = 0; i < Sizes[k]; i++){
            Array[i] = rand() % (Sizes[k] * 10);
        }
        for (int i = 0; i < Sizes[k]; i++){
            Array[i] = rand() % (Sizes[k] * 10);
        }
        cout << MinDistance2Count(Array, Sizes[k]) << endl;
        outFile << MinDistance2Count(Array, Sizes[k]) << "\n";
    }
    return 0;
}
