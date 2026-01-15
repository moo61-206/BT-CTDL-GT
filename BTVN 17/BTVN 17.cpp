#include <iostream>
#include <vector>
using namespace std;

/*
#define V 11
int A[V + 1][V + 1] = { 0 };

void Themcanh(int u, int t) {
    A[u][t] = 1;
    A[t][u] = 1;  
}

int main() {
    Themcanh(1, 2);
    Themcanh(2, 11);
    Themcanh(10, 11);
    Themcanh(1, 10);
    Themcanh(1, 9);
    Themcanh(1, 8);
    Themcanh(1, 7);
    Themcanh(1, 6);
    Themcanh(6, 5);
    Themcanh(5, 4);
    Themcanh(6, 4);
    Themcanh(4, 3);
    Themcanh(2, 3);

    cout << "Ma tran ke: \n";
    for (int i = 1; i <= V; i++) {
        for (int j = 1; j <= V; j++)
            cout << A[i][j] << " ";
        cout << endl;
    }
    return 0;
}
*/

/*
#define V 11
vector<int> adj[V + 1];

void Themcanh(int u, int t) {
    adj[u].push_back(t);
    adj[t].push_back(u);
}

int main() {
    Themcanh(1, 2);
    Themcanh(2, 11);
    Themcanh(10, 11);
    Themcanh(1, 10);
    Themcanh(1, 9);
    Themcanh(1, 8);
    Themcanh(1, 7);
    Themcanh(1, 6);
    Themcanh(6, 5);
    Themcanh(5, 4);
    Themcanh(6, 4);
    Themcanh(4, 3);
    Themcanh(2, 3);

    cout << "Danh sach ke: \n";
    for (int i = 1; i <= V; i++) {
        cout << "Dinh " << i << ": ";
        for (int t : adj[i])
            cout << t << " ";
        cout << endl;
    }
    return 0;
}
*/