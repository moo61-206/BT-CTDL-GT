
#include <iostream>
using namespace std;

int main()
{
    int A[10] = { 3,10,1,23,103,34,17,53,64,71 };

    for (int i = 0; i < 9; i++) {
        cout << "Lan lap " << i + 1 << ": ";
        bool swap = false;
        for (int j = 0; j < 10-i-1; j++) {  
            if (A[j] > A[j + 1]) {  
                int temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;  
                swap = true;
            }
        }       
        for (int k = 0; k < 10; k++) {
            cout << A[k] << " ";
        }
        cout << endl;    
        if (!swap) break;
    }
    return 0;
   
}
