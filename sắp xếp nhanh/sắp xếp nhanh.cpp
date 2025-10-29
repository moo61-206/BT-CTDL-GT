

#include <iostream>
using namespace std;


void quickSort(int A[], int l, int r, int n) {
    int p = A[l]; 
    int i = l + 1;
    int j = r;

    while (i <= j) {
        while (i <= r && A[i] < p) i++;
        while (j >= l && A[j] > p) j--;

        if (i <= j) {
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
            for (int k = 0; k < n; k++) cout << A[k] << " ";
            cout << endl;

            i++;
            j--;
        }
    }
    int temp = A[l];
    A[l] = A[j];
    A[j] = temp;
    for (int k = 0; k < n; k++) cout << A[k] << " ";   
    cout <<  endl;

    if (l < j - 1) quickSort(A, l, j - 1, n);
    if (j + 1 < r) quickSort(A, j + 1, r, n);
}

int main() {
    int A[] = { 3,10,1,23,103,34,17,53,64,71 };
    int n = sizeof(A) / sizeof(A[0]);
    quickSort(A, 0, n-1, n);

    return 0;
}



