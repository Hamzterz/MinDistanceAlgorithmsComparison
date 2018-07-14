#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <limits>

using namespace std;

int MinDistance2(int Array[], int n){
    int dmin = std::numeric_limits<int>::max();
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j< n; j++){
                int temp = abs(Array[i]-Array[j]);
                if(temp < dmin){
                    dmin = temp;
                }
        }
    } return dmin;
}

int main(){
    int Array[] = {1, 3, 6, 10, 15};
    int n = (sizeof(Array))/(sizeof(Array[0]));
    cout << "This array is: {";
    for (int i=0; i<n; i++){
        cout << " "<< Array[i];
    }
    cout << " }\n Minimum Distance between values in this Array: " << MinDistance2(Array, n) << endl;
    return 0;
}
