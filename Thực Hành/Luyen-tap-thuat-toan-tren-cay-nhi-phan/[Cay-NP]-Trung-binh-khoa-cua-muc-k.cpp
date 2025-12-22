#include <iostream>
#include <vector>
#include <iomanip>

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

double AverageByLevel(TREE, int);

int main() {
    vector<int> nlr, lnr;
    int n, key, m, lvl;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> key;
        nlr.push_back(key);
    }

    for (int i = 0; i < n; i++) {
        cin >> key;
        lnr.push_back(key);
    }

    TREE r = CreateTree(nlr, lnr, 0, nlr.size()-1, 0, lnr.size()-1);

    cin >> m;

    cout << setprecision(2) << fixed;

    for (int i = 0; i < m; i++) {
        cin >> lvl;
        cout << AverageByLevel(r, lvl) << endl;
    }

    return 0;
}

void Bfs(TREE root, int level, vector<vector<int>>& values) {
    if (!root) {
        return;
    }
    if (values.size() <= level) {
        values.push_back({});
    }
    values[level].push_back(root->key);
    Bfs(root->left, level + 1, values);
    Bfs(root->right, level + 1, values);
} 

double AverageByLevel(TREE root, int level) {
    if (!root) {
        return 0;
    }
    vector<vector<int>> values;
    Bfs(root, 0, values);
    if (values.size() <= level) {
        return 0;
    }
    int Sum = 0;
    for (int i = 0; i < values[level].size(); i++) {
        Sum += values[level][i];
    }
    return Sum / (values[level].size() * 1.0);
}