#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct TNode {
    int key;
    TNode * left, * right;
};

typedef TNode * TREE;

TREE CreateTree(vector<int> pre, vector<int> in, int preB, int preE, int inB, int inE) {
	int i;
	TREE root;
	if (inE < inB) return NULL;
	root = new TNode;
	if (root != NULL) {
		root->key = pre[preB];
		for (i = inB; i <= inE; i++)
			if (in[i] == pre[preB]) break;
		root->left = CreateTree(pre, in, preB+1, preE, inB, i - 1);
		root->right = CreateTree(pre, in, preB+i-inB+1, preE, i+1,inE);
	} return root;
}

void Input(vector<int> &v)
{
	int tmp;
	cin >> tmp;
	while (tmp > 0) {
		v.push_back(tmp);
		cin >> tmp;
	}
}


int MaxLevel(TREE);

int main() {
    vector<int> nlr, lnr;
    int n, key, m, lvl;

    Input(nlr);
    Input(lnr);


    TREE r = CreateTree(nlr, lnr, 0, nlr.size()-1, 0, lnr.size()-1);

    cout << MaxLevel(r) << endl;

    return 0;
}

void Bfs(TREE root, int level, vector<vector<int>>& value) {
    if (!root) {
        return;
    }
    if (value.size() <= level) {
        value.push_back({});
    }
    value[level].push_back(root->key);
    Bfs(root->left, level + 1, value);
    Bfs(root->right, level + 1, value);
} 

int MaxLevel(TREE root) {
    vector<vector<int>> value;
    Bfs(root, 0, value);
    int Max = 0, Index = 0;
    for (int i = 0; i < value.size(); i++) {
        int Sum = 0;
        for (int j = 0; j < value[i].size(); j++) {
            Sum += value[i][j];   
        }
        if (Sum > Max) {
            Max = Sum;
            Index = i;
        }
    }
    return Index;
}