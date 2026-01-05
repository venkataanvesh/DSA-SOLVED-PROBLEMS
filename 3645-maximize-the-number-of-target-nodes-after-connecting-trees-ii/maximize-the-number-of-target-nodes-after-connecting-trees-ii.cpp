class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        auto findEvenNodes = [](vector<vector<int>>& edges, int n) -> vector<bool> {
            vector<vector<int>> graph(n);
            vector<bool> evens(n, false);
            queue<pair<int, bool>> q;
            vector<bool> visited(n, false);

            for (auto& edge : edges) {
                graph[edge[0]].push_back(edge[1]);
                graph[edge[1]].push_back(edge[0]);}

            q.push({0, true}); 
            visited[0] = true;

            while (!q.empty()) {
                auto [node, isEven] = q.front();
                q.pop();
                evens[node] = isEven;

                for (int neighbor : graph[node]) {
                    if (!visited[neighbor]) {
                        visited[neighbor] = true;
                        q.push({neighbor, !isEven});}
                }
            }

            return evens;};

        int n1 = edges1.size() + 1, n2 = edges2.size() + 1;
        vector<bool> evens1 = findEvenNodes(edges1, n1);
        vector<bool> evens2 = findEvenNodes(edges2, n2);

        int sm1 = count(evens1.begin(), evens1.end(), true);
        int sm2 = count(evens2.begin(), evens2.end(), true);
        int mx = max(sm2, n2 - sm2);

        vector<int> result(n1);
        for (int i = 0; i < n1; ++i) {
            result[i] = mx + (evens1[i] ? sm1 : (n1 - sm1));}

        return result;}
};