#include <iostream>
using namespace std;
void BuildHeap(int* A, int n, int i) {
	int e = A[i];
	int j = 2 * i + 1;
	while (j < n) {
		int k = j + 1;
		if (k < n && A[j] < A[k])
			j = k;
		if (A[j] < e) break;
		A[i] = A[j]; i = j; j = 2 * i + 1;
	}
	A[i] = e;
}
void HeapSort(int* A, int n) {
	for (int i = n / 2 - 1; i > 0; i--)
		BuildHeap(A, n, i);
	while (n > 1) {
		BuildHeap(A, n, 0);
		swap(A[0], A[n - 1]);
		n = n - 1;
	}

}
int main() {
	int A[] = { 33, 44, 11, 66, 55, 22 };
	int n = sizeof(A) / sizeof(A[0]);
	HeapSort(A, n);
	for (int i = 0; i < n; i++) {
		cout << A[i] << '\t';
	}
	return 0;


}


