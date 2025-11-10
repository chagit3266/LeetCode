class Solution {
public:
    void dfs(const string& u,
             map<string,
                 priority_queue<string, vector<string>, greater<string>>>& adj,
             vector<string>& path) {
        auto& dests = adj[u];

        while (!dests.empty()) {
            string next = dests.top();
            dests.pop();
            dfs(next, adj, path);
        }

        path.push_back(u);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        map<string, priority_queue<string, vector<string>, greater<string>>>
            adj;

        for (auto& ticket : tickets) {
            string from = ticket[0];
            string to = ticket[1];
            adj[from].push(to);
        }

        vector<string> path;
        dfs("JFK", adj, path);
        reverse(path.begin(), path.end());
        return path;
    }
};