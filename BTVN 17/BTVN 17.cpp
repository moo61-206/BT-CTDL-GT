


#include<stdio.h>
#include<stdlib.h>
using namespace std;


#define N 11 

/*
int Matrix[N + 1][N + 1];

void TaoMaTran() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; i++) {
            Matrix[i][j] = 0;
        }
    }
}
void Themcanh(int i, int j) {
    Matrix[i][j] = 1;
    Matrix[j][i] = 1;
}
void HienThi() {
    printf("Ma tran:\n");
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            printf("%d ", Matrix[i][j]);
        }
        printf("\n");
    }
}
int main() {
    TaoMaTran;
    Themcanh(1, 2);
    Themcanh(1, 6);
    Themcanh(1, 7);
    Themcanh(1, 8);
    Themcanh(1, 9);
    Themcanh(1, 10);
    Themcanh(2, 3);
    Themcanh(2, 11);
    Themcanh(3, 4);
    Themcanh(4, 5);
    Themcanh(4, 6);
    Themcanh(5, 6);
    Themcanh(10, 11);

    HienThi();
    return 0;
}
*/  



/*


typedef struct Node {
    int v;
    struct Node* next;
} Node;

Node* List[N + 1];


Node* TaoNode(int x) {
    Node* p = (Node*)malloc(sizeof(Node));
    p->v = x;
    p->next = NULL;
    return p;
}

void Taodsach() {
    for (int i = 1; i <= N; i++) {
        List[i] = NULL;
    }
}

void Themcanh(int i, int j) {
    Node* p = TaoNode(j);
    p->next = List[i];
    List[i] = p;

    p = TaoNode(i);
    p->next = List[j];
    List[j] = p;
}

void HienThi() {
    printf("Danh sach: \n");
    for (int i = 1; i <= N; i++) {
        printf("%d: ", i);
        Node* p = List[i];
        while (p != NULL) {
            printf("%d -> ", p->v);
            p = p->next;
        }
        printf("NULL\n");
    }
}

int main() {
    Taodsach;
    Themcanh(1, 2);
    Themcanh(1, 6);
    Themcanh(1, 7);
    Themcanh(1, 8);
    Themcanh(1, 9);
    Themcanh(1, 10);
    Themcanh(2, 3);
    Themcanh(2, 11);
    Themcanh(3, 4);
    Themcanh(4, 5);
    Themcanh(4, 6);
    Themcanh(5, 6);
    Themcanh(10, 11);

    HienThi();
    return 0;
}
*/