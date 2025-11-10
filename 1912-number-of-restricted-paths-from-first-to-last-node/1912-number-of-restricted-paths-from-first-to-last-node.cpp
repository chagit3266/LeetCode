class Solution {
public:

    // Dijkstra
    vector<long long> distanceToLastNode(int n, vector<vector<pair<int, int>>> &adj) {
        vector<long long> distance(n, 1e18);
        distance[n - 1] = 0;

        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> pq;

        pq.push({0, n - 1});
        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            if (d > distance[u])
                continue;

            for (auto [v, w] : adj[u]) {
                if (distance[v] > d + w) {
                    distance[v] = d + w;
                    pq.push({distance[v], v});
                }
            }
        }
        return distance;
    }
    const int MOD = 1e9 + 7;
    // dfs
    int dfs(int u, vector<vector<pair<int, int>>>& adj, vector<long long>& distance,
            vector<int>& memo) {

        if (u == distance.size() - 1)
            return 1;

        if (memo[u] != -1)
            return memo[u];
        long long count = 0;
        for (auto [v, w] : adj[u]) {
            if (distance[u] > distance[v]) {
                count = (count + dfs(v, adj, distance, memo)) % MOD;
            }
        }

        memo[u] = (int)count;
        return memo[u];
    }
    int countRestrictedPaths(int n,vector<vector<int>>& edges) {
        // Function body
        vector<int> path(n, 0);

        // adjacency list
        vector<vector<pair<int, int>>> adj(n); // adj[u] = {(v, weight)}
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0] - 1;
            int v = edges[i][1] - 1;
            int w = edges[i][2];

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        vector<long long> distance = distanceToLastNode(n, adj);

        vector<int> memo(n, -1);
        return dfs(0, adj, distance, memo);
    }
};