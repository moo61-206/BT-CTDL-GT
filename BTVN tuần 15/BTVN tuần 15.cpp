#include <iostream>
#include <cmath>


using namespace std;

//////////////////////////////// BÀI 1 /////////////////////////////////////// 

/*
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
*/
//////////////////////////////////////////// BÀI 2 ////////////////////////////////////////
/*
struct Node
{
    int value;
    Node* left;
    Node* right;

    Node(int v)
    {
        value = v;
        left = right = NULL;
    }
};

bool isSameTree(Node* t1, Node* t2)
{
    if (t1 == NULL && t2 == NULL)
        return true;
    if (t1 == NULL || t2 == NULL)
        return false;
    if (t1->value != t2->value)
        return false;
    return isSameTree(t1->left, t2->left) &&
        isSameTree(t1->right, t2->right);
}

int main()
{
    Node* t1 = new Node(1);
    t1->left = new Node(2);
    t1->right = new Node(3);

    Node* t2 = new Node(1);
    t2->left = new Node(2);
    t2->right = new Node(3);

    if (isSameTree(t1, t2))
        cout << "Hai cay nhi phan giong nhau" << endl;
    else
        cout << "Hai cay nhi phan khong giong nhau" << endl;

    return 0;
}
*/
//////////////////////////////////////////// BÀI 3 /////////////////////////////////////////

/*
struct Node
{
    int value;
    Node* left;
    Node* right;

    Node(int v, Node* l = NULL, Node* r = NULL)
    {
        value = v;
        left = l;
        right = r;
    }
};

void PREORDER_travl(Node* t);
void INORDER_travl(Node* t);
void POSTORDER_travl(Node* t);

class BSTree
{
private:
    Node* root;

    void insert(int val1, Node*& t)
    {
        if (t == NULL)
            t = new Node(val1);
        else if (val1 < t->value)
            insert(val1, t->left);
        else if (val1 > t->value)
            insert(val1, t->right);
    }

    Node* search(int val2, Node* t)
    {
        if (t == NULL) return NULL;
        if (val2 == t->value) return t;
        if (val2 < t->value)
            return search(val2, t->left);
        return search(val2, t->right);
    }

    void makeEmpty(Node*& t)
    {
        if (t == NULL) return;
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete t;
        t = NULL;
    }

public:
    BSTree()
    {
        root = NULL;
    }

    ~BSTree()
    {
        makeEmpty();
    }

    bool isEmpty()
    {
        return root == NULL;
    }

    void makeEmpty()
    {
        makeEmpty(root);
    }

    void insert(int val1)
    {
        insert(val1, root);
    }

    Node* search(int val2)
    {
        return search(val2, root);
    }

    Node* getRoot()
    {
        return root;
    }
};


void PREORDER_travl(Node* t)
{
    if (t == NULL) return;
    cout << t->value << " ";
    PREORDER_travl(t->left);
    PREORDER_travl(t->right);
}
void INORDER_travl(Node* t)
{
    if (t == NULL) return;
    INORDER_travl(t->left);
    cout << t->value << " ";
    INORDER_travl(t->right);
}
void POSTORDER_travl(Node* t)
{
    if (t == NULL) return;
    POSTORDER_travl(t->left);
    POSTORDER_travl(t->right);
    cout << t->value << " ";
}

int main()
{
    BSTree bst;

    bst.insert(5);
    bst.insert(6);
    bst.insert(3);
    bst.insert(8);
    bst.insert(7);
    bst.insert(4);
    bst.insert(2);

    Node* root = bst.getRoot();

    cout << "Duyet cay thu tu truoc: ";
    PREORDER_travl(root);
    cout << endl;

    cout << "Duyet cay thu tu giua: ";
    INORDER_travl(root);
    cout << endl;

    cout << "Duyet cay thu tu sau: ";
    POSTORDER_travl(root);
    cout << endl;

    Node* n1 = bst.search(4);
    Node* n2 = bst.search(9);

    if (n1 != NULL)
        cout << "Node co gia tri = 4 la " << n1->value << endl;

    if (n2 == NULL)
        cout << "Khong tim thay node co gia tri = 9" << endl;

    bst.makeEmpty();

    if (bst.isEmpty())
        cout << "Cay da bi xoa rong" << endl;

    return 0;
}

*/