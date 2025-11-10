class Solution {
public:
    const long long MOD = 1e9 + 7;
    void dijkstra(int n, vector<vector<pair<int, int>>>& adj,
                  vector<int>& countRow) {
        const long long INF = 1e15;
        vector<long long> dist(n, INF);
        // vector<int> count(n, 0);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                       greater<>>
            queue;
        queue.push({0, 0});
        dist[0] = 0;
        countRow[0] = 1;
        while (!queue.empty()) {
            auto [d, u] = queue.top();
            queue.pop();
            if (d > dist[u])
                continue;
            for (auto [v, w] : adj[u]) {
                long long newDist = d + w;
                if (newDist < dist[v]) {
                    dist[v] = newDist;
                    countRow[v] = countRow[u];
                    queue.push({newDist, v});
                } else if (newDist == dist[v]) {
                    countRow[v] = (countRow[v] + countRow[u]) % MOD;
                }
            }
        }
    }
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& r : roads) {
            adj[r[0]].push_back({r[1], r[2]});
            adj[r[1]].push_back({r[0], r[2]});
        }

        vector<int> res(n, 0); // num rows
        dijkstra(n, adj, res);
        return res[n - 1];
    }
};