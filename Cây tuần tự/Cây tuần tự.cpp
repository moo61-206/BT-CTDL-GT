#include <iostream>
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
    void Heapify(int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < capacity && tree[left] != -1 && tree[left] > tree[largest])
            largest = left;

        if (right < capacity && tree[right] != -1 && tree[right] > tree[largest])
            largest = right;

        if (largest != i) {
            swap(tree[i], tree[largest]);
            Heapify(largest);
        }
    }
    void Vundong() {
        for (int i = count / 2 - 1; i >= 0; i--) {
            Heapify(i);
        }
    }
};



int main() {
  
    Caytuantu Tree(30);

    // Xây dựng cây: 
    //                                4
    //                              /   \
    //                             /     \
    //                            /       \
    //                           1         3
    //                          /  \      /  \
    //                         2    6    9    10
    //                        / \   /
    //                       14  8 7
    
    Tree.Nutgoc(4);

    Tree.Themtrai(0, 1);    
    Tree.Themphai(0, 3); 

    Tree.Themtrai(1, 2);
    Tree.Themphai(1, 6);

    Tree.Themtrai(2, 9);
    Tree.Themphai(2, 10);

    Tree.Themtrai(3, 14);
    Tree.Themphai(3, 8);

    Tree.Themtrai(4, 7);

  
    cout << "Duyet truoc  : "; Tree.Duyettruoc(); cout << endl;
    cout << "Duyet giua   : "; Tree.Duyetgiua(); cout << endl;
    cout << "Duyet sau    : "; Tree.Duyetsau(); cout << endl;
    cout << endl; 

    cout << "Cay truoc khi vun dong: ";
    Tree.Duyettruoc();
    cout << endl;

    Tree.Vundong();

    cout << "Cay sau khi vun dong: ";
    Tree.Duyettruoc();
    cout << endl;

    return 0;
}

