

#include <iostream>
using namespace std;
int main()
{
    int A[] = { 3,10,1,23,103,34,17,53,64,71 };
    int n = sizeof(A) / sizeof(A[0]);
    for (int i = 0; i < n-1; i++) {   
        int min = i;
        for (int j = i + 1; j < 10; j++) {  
            if (A[j] < A[min]) {
                min = j;
            }
        }
        if (min != i) {
            int temp = A[i];
            A[i] = A[min];
            A[min] = temp;
        }
        cout << "\n lap lan thu " << i + 1 << ": ";
        for (int k = 0; k < 10; k++) {          
            cout << A[k] << " ";
        }
        cout << endl; 
    }
    return 0;
}

