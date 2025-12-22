#include <iostream>

using namespace std;

struct Node {
    int Data;
    Node* Next;
};

Node* CreateNode(int x) {
    Node* p = new Node();
    p->Data = x;
    p->Next = NULL;
    return p;
}

struct List {
    Node* Head = NULL;
    Node* Tail = NULL;
};

void AddTail(List& l, int x) {
    Node* p = CreateNode(x);
    if (!l.Head) {
        l.Head = p;
        l.Tail = p;
    } else {
        l.Tail->Next = p;
    }
    l.Tail = p;
}

int GetData(List l, int k) {
    Node* p = l.Head;
    while (k--) {
        p = p->Next;
    }
    return p->Data;
}

int main() {
    int n; cin >> n;
    List l;
    while (n--) {
        int x; cin >> x;
        AddTail(l, x);
    }
    int sum = 0; cin >> n;
    while (n--) {
        int k; cin >> k;
        sum += GetData(l, k);
    }
    cout << sum;
}
