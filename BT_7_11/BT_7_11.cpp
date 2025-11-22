

#include <iostream>
using namespace std;

//int Indexof(int* a, int n, int x) {
//    for (int i = 0; i < n; i++) {
//        if (a[i]==x) return i;
//    }
//    return -1;
//}
//int lastIndexof(int* a, int n, int x) {
//    for (int i = n-1; i >= 0; i--) {
//        if (a[i]==x) return i;
//    }
//    return -1;
//}
//int count(int* a, int n, int x) {
//    int d = 0;
//    for (int i = 0; i < n; i++) {
//        if (a[i]==x) d++;
//    }
//    return d;
//}




//int search(int* a, int n, int x) {             Tìm kiếm
//    int first = 0, last = n - 1;
//    while (first <= last) {
//        int m = (first + last) / 2;
//        int c = a[m] - x;
//        if (c == 0) return m;
//        if (c < 0)
//            first = m + 1;
//        else
//            last = m - 1;
//    }
//    return -1;
//
//}





//template <class T>         Ngăn xếp 
//class stack {
//    T* data;
//    int capacity;
//    int top;
//public:
//    stack(int size =100)
//        : capacity(size), top(-1), data(new T[size]) {}
//    ~ stack() { delete[]data; }
//public:
//    void push(const T & value) { data[++top] = value; }
//    T pop() { return data[top--]; }
//    T peek() const { return data[top]; }
//    bool isEmpty() const { return top < 0; }
//    bool isFull() const { return count()==capacity; }
//    int count() const { return top + 1; }
//
//};

//template <class T>              Hàng đợi 
//class queue {
//    T* data;
//    int capacity;
//    int front, rear;
//public:
//    queue(int size = 100)
//        : capacity(size), front (0), rear(0), data(new T[size]) {}
//    ~queue() { delete[]data; }
//public:
//    void enqueue(const T& value) {
//        data[rear] = value;
//        ++rear;
//        if (rear == capacity) rear = 0;
//    }
//    T dequeue() {
//        int f = front;
//        if (++front == capacity) front = 0;
//        return data[f];
//    }
//};





int main()
{
    /*int a[10] = { 0,11,22,33,44,55,66,77,88,99 };
    int pos = search(a, 10, 66);
    if (pos != -1)
        cout << "Tim thay tai vi tri: " << pos << endl;
    else
        cout << "Khong tim thay!" << endl;*/
    
    
    /*int x = 25;
    stack <int> s(sizeof(int));
    cout << x << "(10)=";
    do {
        s.push(x % 2);
        x /= 2;
    } while (x);
    while (!s.isEmpty())
        cout << s.pop();
    cout << "(2)\n";*/
    
}
    


