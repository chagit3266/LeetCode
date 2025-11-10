#include <iostream>
#include <vector>
using namespace std;

class UnionFind {
private:
    vector<int> parent, rank;

public:
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]); // Path Compression
        return parent[x];
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY) return;

        // Union by rank
        if (rank[rootX] < rank[rootY])
            parent[rootX] = rootY;
        else if (rank[rootX] > rank[rootY])
            parent[rootY] = rootX;
        else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }

    bool connected(int x, int y) {
        return find(x) == find(y);
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        UnionFind unionF(isConnected.size());
        int num = isConnected.size();
        for(int i=0; i< isConnected.size(); i++){
            for(int j = 0; j<isConnected[0].size(); j++){
                if(isConnected[i][j]){
                   if(!unionF.connected(i,j)){
                       unionF.unite(i,j);
                       num--;
                   }
                }
            }
        }
        return num;
    }
};

