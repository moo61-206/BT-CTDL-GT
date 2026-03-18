#include <iostream>
#include <string>
#include <queue>
using namespace std;

struct Node {
    char ch;
    int freq;
    Node* left, * right;

    Node(char c, int f) {
        ch = c;
        freq = f;
        left = right = NULL;
    }
};

struct compare {
    bool operator()(Node* l, Node* r) {
        return l->freq > r->freq;
    }
};

void printCode(Node* root, string str, string huffmanCode[]) {
    if (!root) return;

    if (!root->left && !root->right) {
        huffmanCode[root->ch] = (str != "") ? str : "0";
    }

    printCode(root->left, str + "0", huffmanCode);
    printCode(root->right, str + "1", huffmanCode);
}

int main() {

    string text;
    getline(cin, text);

    int freq[256] = { 0 };

    for (char c : text) {
        if (c != ' ')
            freq[c]++;
    }

    priority_queue<Node*, vector<Node*>, compare> pq;

    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            pq.push(new Node((char)i, freq[i]));
        }
    }

    while (pq.size() != 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();

        Node* sum = new Node('\0', left->freq + right->freq);
        sum->left = left;
        sum->right = right;

        pq.push(sum);
    }

    Node* root = pq.top();

    string huffmanCode[256];

    printCode(root, "", huffmanCode);

    cout << "Ma Huffman:\n";
    for (int i = 0; i < 256; i++) {
        if (huffmanCode[i] != "") {
            cout << (char)i << " : " << huffmanCode[i] << endl;
        }      
    }

    cout << "\nChuoi sau khi ma hoa:";

    string str = "";
    for (char c : text) {
        if (c != ' ')
            str += huffmanCode[c];
    }

    cout << str << endl;
    cout << "So bit: " << str.length() << endl;
    return 0;
}