#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
struct TNode {
    int key;
    TNode *left, *right;
};

typedef TNode * TREE;

void CreateTree(TREE &t) {
    t = NULL;
}

TNode * CreateTNode(int x) {
    TNode * p = new TNode;
    if (p == NULL) return NULL;
    p->left = p->right = NULL;
    p->key = x;
    return p;
}

void InsertNode(TREE &t, int x) {
    TNode *p = CreateTNode(x);

    if (t == NULL) {
        t = p;
        return;
    }
    TREE q = t;
    while (q != NULL) {
        if (x == q->key) return;
        if (x > q->key) {
            if (q->right == NULL) {
                q->right = p;
                return;
            }
            q = q->right;
        }
        else {
            if (q->left == NULL) {
                q->left = p;
                return;
            }
            q = q->left;
        }
    }
}

void LoadTree(TREE &t) {
    int n, k;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> k;
        InsertNode(t, k);
    }
}

void MaxFindingCost(TREE);

int main()
{
    vector<int> keys;
    TREE t;
    CreateTree(t);
    LoadTree(t);
    MaxFindingCost(t);
    return 0;
}

void BFS(TREE Root, int Height, vector<vector<int>>& Width) {
    if (!Root) {
        return;
    }
    if (Width.size() <= Height) {
        Width.push_back({});
    }
    Width[Height].push_back(Root->key);
    BFS(Root->left, Height + 1, Width);
    BFS(Root->right, Height + 1, Width);
}

void MaxFindingCost(TREE Root) {
    vector<vector<int>> Values;
    BFS(Root, 0, Values);
    for (int i = 0; i < Values[Values.size() - 1].size(); i++) {
        cout << Values[Values.size() - 1][i] << " ";
    }
}