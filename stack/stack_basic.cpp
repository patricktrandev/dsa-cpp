#include <iostream>

using namespace std;

template<class T>
class Stack {
private:
    T* S;
    int top, len, size;

public:
    Stack(int sz = 10);
    ~Stack(){}; // Destructor
    void push(T val);
    bool pop(T& val);
    bool find(int pos, T& val);
    int search(T val);
    int length();
    bool isEmpty();
    bool isFull();
    void display();
};

// Constructor
template<class T>
Stack<T>::Stack(int sz) {
    size = (sz > 0) ? sz : 10;
    S = new T[size];
    top = -1;
    len = 0;
}

// Destructor
template<class T>
Stack<T>::Stack() {
    // todo
}


template<class T>
bool Stack<T>::isEmpty() {
    return top == -1;
}


template<class T>
bool Stack<T>::isFull() {
    return top == size - 1;
}


template<class T>
int Stack<T>::length() {
    return len;
}

template<class T>
void Stack<T>::push(T val) {
    if (isFull()) {
        return;
    }
    S[++top] = val;
    len++;
}


template<class T>
bool Stack<T>::pop(T& val) {
    if (isEmpty()) {
        return false;
    }
    val = S[top--];
    len--;
    return true;
}

template<class T>
bool Stack<T>::find(int pos, T& val) {
    if (pos < 0 || pos > top) {
        return false; 
    }
    val = S[pos];
    return true;
}


template<class T>
int Stack<T>::search(T val) {
    for (int i = top; i >= 0; i--) {
        if (S[i] == val) {
            return i;
        }
    }
    return -1;
}


template<class T>
void Stack<T>::display() {
    if (isEmpty()) {
        cout << "Empty Stack" << endl;
        return;
    }
    cout << "Stack (Top -> Bottom): ";
    for (int i = top; i >= 0; i--) {
        cout << S[i] << " ";
    }
    cout << endl;
}

int main() {
    Stack<int> s(5);

    // Dynamic push
    s.push(10);
    s.push(20);
    s.push(30);

    s.display(); // Top -> Bottom: 30 20 10
    cout << "Length of Stack: " << s.length() << endl;

    int poppedVal;
    if (s.pop(poppedVal)) {
        cout << "pop value= " << poppedVal << endl;
    }

    s.display();

    // Search
    int pos = s.search(10);
    if (pos != -1) {
        cout << "index= " << pos << endl;
    }

    // Find
    int valAtPos;
    if (s.find(0, valAtPos)) {
        cout << "index= " << valAtPos << endl;
    }

    return 0;
}