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

void Sort(List& l) {
    for (Node* p = l.Head; p->Next != NULL; p = p->Next) {
        for (Node* q = p->Next; q != NULL; q = q->Next) {
            if (p->Data < q->Data) {
                swap(p->Data, q->Data);
            }
        }
    }
}

int main() {
    int n; cin >> n;
    if (n == 0) {
        cout << 0;
        return 0;
    }
    List l; int size = n;
    while (n--) {
        int x; cin >> x;
        AddTail(l, x);
    }
    Sort(l);
    int sum = 0;
    int k = 0;
    while (k < size) {
        sum += GetData(l, k);
        k += 2;
    }
    cout << sum;
}
