#include <bits/stdc++.h>

bool isSafe(int node, int v, int color, vector<int> &colorOfNode, vector<vector<int>> &mat) {
    for (int i = 0; i < v; i++) {
        if (mat[node][i] == 1) {
            if (colorOfNode[i] == color) {
                return false;
            }
        }
    }

    colorOfNode[node] = color;
    return true;
}

bool solve(int node, int v, int m, vector<int> &colorOfNode, vector<vector<int>> &mat) {
    if (node == v) {
        return true;
    }
    for (int i = 1; i <= m; i++) {
        if (isSafe(node, v, i, colorOfNode, mat)) {
            if (solve(node + 1, v, m, colorOfNode, mat)) {
                return true;
            }
            colorOfNode[node] = 0;
        }
    }

    return false;
}

string graphColoring(vector<vector<int>> &mat, int m) {
    int v = mat.size();
    vector<int> colorOfNode(v, 0);

    if (solve(0, v, m, colorOfNode, mat)) {
        return "YES";
    }
    return "NO";
}