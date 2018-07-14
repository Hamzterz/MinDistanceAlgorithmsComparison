#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <limits>

using namespace std;

int MinDistance(int Array[], int n){
    int dmin = std::numeric_limits<int>::max();
    for(int i = 0; i < n; i++){
        for(int j = 0; j< n; j++){
            if(i != j && abs(Array[i]-Array[j]) < dmin){
                dmin = abs(Array[i]-Array[j]);
            }
        }
    } return dmin;
}

int main(){
    int Array[] = {-1, 3, -6, 10, -15};
    int n = (sizeof(Array))/(sizeof(Array[0]));
    cout << "This array is: {";
    for (int i=0; i<n; i++){
        cout << " "<< Array[i];
    }
    cout << " }\n Minimum Distance between values in this Array: " << MinDistance(Array, n) << endl;
    return 0;
}

