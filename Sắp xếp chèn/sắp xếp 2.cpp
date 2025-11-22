

#include <iostream>
using namespace std;


int main()
{
	int a[10] = { 3,10,1,23,103,34,17,53,64,71 };
    int n = sizeof(a) / sizeof(a[0]);
    for (int i = 1; i < n; i++) {
        int key = a[i];     
        int j = i - 1;  
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }  
        a[j + 1] = key;
        cout << "Lan lap " << i << ": ";
        for (int k = 0; k < 10; k++) {
            cout << a[k] << " ";
        }
        cout << endl;
    }
    return 0;

}

