#include <iostream>

using namespace std;

struct Hocsinh{
    string Hodem, Ten;
    bool Gioitinh;
    int Ngay, Thang, Nam;
    double Toan, Van, Ly, Hoa, Anh, Sinh;
};

void InputElement(Hocsinh &x) {
    getline(cin>>ws, x.Hodem);
    getline(cin>>ws, x.Ten);
    cin >> x.Gioitinh;
    cin >> x.Ngay >> x.Thang >> x.Nam;
    cin >> x.Toan >> x.Van >> x.Ly >> x.Hoa >> x.Anh >> x.Sinh;
}

void OutputElement(Hocsinh hs) {
    cout << hs.Hodem
            << ' ' << hs.Ten
            << '\t' << hs.Gioitinh
            << '\t' << hs.Ngay
            << '/' << hs.Thang
            << '/' << hs.Nam
            << '\t' << hs.Toan
            << '\t' << hs.Van
            << '\t' << hs.Ly
            << '\t' << hs.Hoa
            << '\t' << hs.Anh
            << '\t' << hs.Sinh << endl;;
}

struct Node {
    Hocsinh data;
    Node * next;
};

struct List {
    Node * head, * tail;
};

Node * CreateNode(Hocsinh x) {
    Node * p = new Node;
    if (p == NULL) exit(1);
    p->data = x;
    p->next = NULL;
    return p;
}

void CreateList(List &l) {
    l.head = l.tail = NULL;
}

void AddHead(List &l, Hocsinh x) {
    Node * p = CreateNode(x);
    if (l.head == NULL)
        l.tail = p;
    else
        p->next = l.head;
    l.head = p;
}

void AddTail(List &l, Hocsinh x) {
    Node * p = CreateNode(x);
    if (l.head == NULL)
        l.head = p;
    else
        l.tail->next = p;
    l.tail = p;
}

Node * RemoveHead(List &l) {
    if (l.head == NULL)
        return NULL;
    Node *p = l.head;
    l.head = p->next;
    p->next = NULL;
    return p;
}

void PrintList(List l) {
    Node * p = l.head;
    while (p != NULL) {
        OutputElement(p->data);
        p = p->next;
    }
}

void Sort(List &);

int main()
{
    List l;
    int n;
    Hocsinh hs;

    CreateList(l);
    cin >> n;
    for (int i = 0; i < n; i++) {
        InputElement(hs);
        AddTail(l, hs);
    }

    Sort(l);
    PrintList(l);
    return 0;
}

int Compare(Hocsinh Hs1, Hocsinh Hs2) {
    if (Hs1.Ten == Hs2.Ten) {
        if (Hs1.Hodem == Hs2.Hodem) {
            if (Hs1.Nam == Hs2.Nam) {
                if (Hs1.Thang == Hs2.Thang) {
                    if (Hs1.Ngay == Hs2.Ngay) {
                        return 0;
                    } else if (Hs1.Ngay > Hs2.Ngay) {
                        return -1;
                    } else {
                        return 1;
                    }
                } else if (Hs1.Thang > Hs2.Thang) {
                    return -1;
                } else {
                    return 1;
                }
            } else if (Hs1.Nam > Hs2.Nam) {
                return -1;
            } else {
                return 1;
            }
        } else if (Hs1.Hodem < Hs2.Hodem) {
            return -1;
        } else {
            return 1;
        }
    } else if (Hs1.Ten < Hs2.Ten) {
        return -1;
    } else {
        return 1;
    }
}

void Concat(List& l, List& front, List& back) {
    if (l.head == NULL || l.head->next == NULL) {
        front.head = l.head;
        back.head = NULL;
        return;
    }
    Node* slow = l.head;
    Node* fast = l.head->next;
    while (fast != NULL) {
        fast = fast->next;
        if (fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    front.head = l.head;
    front.tail = slow;

    back.head = slow->next;
    back.tail = l.tail;

    slow->next = nullptr;
}

List Merge(List& a, List& b) {
    List result;
    Node dummy;  
    Node* tail = &dummy;
    dummy.next = nullptr;
    Node* pa = a.head;
    Node* pb = b.head;
    while (pa && pb) {
        if (Compare(pa->data, pb->data) == -1 || Compare(pa->data, pb->data) == 0) {
            tail->next = pa;
            pa = pa->next;
        } else {
            tail->next = pb;
            pb = pb->next;
        }
        tail = tail->next;
    }
    tail->next = (pa ? pa : pb);
    result.head = dummy.next;
    Node* t = result.head;
    if (t == nullptr)
        result.tail = nullptr;
    else {
        while (t->next != nullptr) t = t->next;
        result.tail = t;
    }
    return result;
}

void Sort(List& l) {
    if (l.head == nullptr || l.head->next == nullptr)
        return;
    List front, back;
    Concat(l, front, back);
    Sort(front);
    Sort(back);
    l = Merge(front, back);
}