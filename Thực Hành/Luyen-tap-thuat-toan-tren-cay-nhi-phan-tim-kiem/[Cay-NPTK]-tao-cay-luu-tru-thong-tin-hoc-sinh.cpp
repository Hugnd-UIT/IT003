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
            << '\t' << hs.Sinh << endl;
}

struct TNode {
    Hocsinh data;
    TNode * left, * right;
};

typedef TNode * TREE;

void CreateTree(TREE &r) {
    r = NULL;
}

TNode * CreateTNode(Hocsinh x) {
    TNode * p = new TNode;
    if (p == NULL) exit(1);
    p->data = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}

int Compare(Hocsinh a, Hocsinh b) {
    if (a.Ten == b.Ten) {
        if (a.Hodem < b.Hodem) {
            return 0;
        } else if (a.Hodem == b.Hodem) {
            return 1;
        } else {
            return 2;
        }
    } else if (a.Ten < b.Ten) {
        return 0;
    } else {
        return 2;
    }
}

void InsertNode(TREE& Root, Hocsinh Value) {
    if (Root == NULL) {
        Root = CreateTNode(Value);
        return;
    }
    if (Compare(Value, Root->data) == 1)
        return;
    else if (Compare(Value, Root->data) == 0)
        InsertNode(Root->left, Value);
    else
        InsertNode(Root->right, Value);
}

void LNR(TREE Root) {
    if (Root) {
        LNR(Root->left);
        OutputElement(Root->data);
        LNR(Root->right);
    }
}

int main() {
    int n;
    cin >> n;
    TREE Root;
    CreateTree(Root);
    for (int i = 0; i < n; i++) {
        Hocsinh Temp;
        InputElement(Temp);
        InsertNode(Root, Temp);
    }
    LNR(Root);
}