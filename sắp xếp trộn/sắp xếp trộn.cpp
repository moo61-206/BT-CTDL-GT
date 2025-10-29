

#include <iostream>
using namespace std;
const int MAX = 100; 
int temp[MAX];
void mergeParts(int* A, int l, int mid, int r, int n) {
    int i = l, j = mid + 1, k = 0;
    while (i <= mid && j <= r) {
        int p;
        if (A[i] < A[j]) p = A[i++];
        else p = A[j++];
        temp[k++] = p;
    }
    while (i <= mid) temp[k++] = A[i++];
    while (j <= r) temp[k++] = A[j++];
    for (int i = 0; i < k; i++) {
        A[l + i] = temp[i];
    }
    for (int t = 0; t < n; t++) cout << A[t] << " ";
    cout << endl;
}
void mergeSort(int* arr, int l, int r, int n) {
    if (l >= r) return;
    int mid = (l + r) / 2;
    mergeSort(arr, l, mid, n);
    mergeSort(arr, mid + 1, r, n);
    mergeParts(arr, l, mid, r, n);
}
int main()
{
    int A[] = { 3,10,1,23,103,34,17,53,64,71 };
    int n = sizeof(A) / sizeof(A[0]);
    mergeSort(A, 0, n - 1, n );
    return 0;


}
