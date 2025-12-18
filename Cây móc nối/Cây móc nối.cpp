#include <iostream>

using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class Caymocnoi {
private:
    Node* root;

public:
    Caymocnoi() {
        root = nullptr;
    }
   
    Node* Nutgoc(int val) {
        root = new Node(val);
        return root;
    }

    Node* Themtrai(Node* parent, int val) {
        if (parent == nullptr) return nullptr;
        parent->left = new Node(val);
        return parent->left;
    }

    Node* Themphai(Node* parent, int val) {
        if (parent == nullptr) return nullptr;
        parent->right = new Node(val);
        return parent->right;
    }

    
    void Duyettruoc(Node* node) {
        if (node == nullptr) return;
        cout << node->data << " ";
        Duyettruoc(node->left);
        Duyettruoc(node->right);
    }

    void Duyetgiua(Node* node) {
        if (node == nullptr) return;
        Duyetgiua(node->left);
        cout << node->data << " ";
        Duyetgiua(node->right);
    }

    void Duyetsau(Node* node) {
        if (node == nullptr) return;
        Duyetsau(node->left);
        Duyetsau(node->right);
        cout << node->data << " ";
    }

    Node* Laygoc() { return root; }
};

int main() {
    Caymocnoi Tree;

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

    Node* n10 = Tree.Nutgoc(10);

    Node* n1 = Tree.Themtrai(n10, 1);
    Node* n7 = Tree.Themphai(n10, 7);

    Node* n3 = Tree.Themtrai(n1, 3);
    Node* n5 = Tree.Themphai(n1, 5);

    Node* n12 = Tree.Themtrai(n7, 12);
    Node* n101 = Tree.Themphai(n7, 101);

    Node* n14 = Tree.Themtrai(n12, 14);
    Node* n13 = Tree.Themphai(n12, 13);

    Node* n31 = Tree.Themphai(n101, 31);

    Node* n15 = Tree.Themtrai(n14, 15);

    Node* n9 = Tree.Themtrai(n13, 9);
    Node* n1_child = Tree.Themphai(n13, 1);

    cout << "Duyet truoc  : "; Tree.Duyettruoc(Tree.Laygoc()); cout << endl;
    cout << "Duyet giua   : "; Tree.Duyetgiua(Tree.Laygoc());  cout << endl;
    cout << "Duyet sau    : "; Tree.Duyetsau(Tree.Laygoc()); cout << endl;

    return 0;
}