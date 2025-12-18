#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Caytuantu {
private:
    int* tree;      
    int capacity;    
    int count;       

public:
    Caytuantu(int size) {
        capacity = size;
        tree = new int[capacity];
        count = 0;
        for (int i = 0; i < capacity; i++) {
            tree[i] = -1;
        }
    }
    bool isEmpty() {
        return (tree[0] == -1);
    }
    void Nutgoc(int val) {
        tree[0] = val;
        count++;
    }

    void Themtrai(int parentIdx, int val) {
        int leftIdx = (2 * parentIdx) + 1;
        if (parentIdx < 0 || tree[parentIdx] == -1) {
            cout << "Loi: Nut cha khong ton tai!" << endl;
        }
        else if (leftIdx >= capacity) {
            cout << "Loi: Vuot qua kich thuoc mang!" << endl;
        }
        else {
            tree[leftIdx] = val;
            count++;
        }
    }

    void Themphai(int parentIdx, int val) {
        int rightIdx = (2 * parentIdx) + 2;
        if (parentIdx < 0 || tree[parentIdx] == -1) {
            cout << "Loi: Nut cha khong ton tai!" << endl;
        }
        else if (rightIdx >= capacity) {
            cout << "Loi: Vuot qua kich thuoc mang!" << endl;
        }
        else {
            tree[rightIdx] = val;
            count++;
        }
    }
    void Duyettruoc(int idx = 0) {
        if (idx < capacity && tree[idx] != -1) {
            cout << tree[idx] << " ";     
            Duyettruoc(2 * idx + 1);       
            Duyettruoc(2 * idx + 2);        
        }
    }

   
    void Duyetgiua(int idx = 0) {
        if (idx < capacity && tree[idx] != -1) {
            Duyetgiua(2 * idx + 1);        
            cout << tree[idx] << " ";   
            Duyetgiua(2 * idx + 2);         
        }
    }
    void Duyetsau(int idx = 0) {
        if (idx < capacity && tree[idx] != -1) {
            Duyetsau(2 * idx + 1);       
            Duyetsau(2 * idx + 2);        
            cout << tree[idx] << " ";    
        }
    }
};

int main() {
  
    Caytuantu Tree(30);

    // Xây dựng cây: 
    //                                 10
    //                               /   \
    //                              /     \
    //                             /       \
    //                            1         7
    //                           / \      /  \
    //                          3   5    12   101
    //                                  /  \    \
    //                                 14   13   31
    //                                /    / \
    //                               15   9   1 
    Tree.Nutgoc(10);

    Tree.Themtrai(0, 1);    
    Tree.Themphai(0, 7); 

    Tree.Themtrai(1, 3);
    Tree.Themphai(1, 5);

    Tree.Themtrai(2, 12);
    Tree.Themphai(2, 101);

    Tree.Themtrai(5, 14);
    Tree.Themphai(5, 13);

    Tree.Themphai(6, 31);

    Tree.Themtrai(11, 15);

    Tree.Themtrai(12, 9);
    Tree.Themphai(12, 1);

    cout << "Duyet truoc  : "; Tree.Duyettruoc(); cout << endl;
    cout << "Duyet giua   : "; Tree.Duyetgiua(); cout << endl;
    cout << "Duyet sau    : "; Tree.Duyetsau(); cout << endl;

    return 0;
}

