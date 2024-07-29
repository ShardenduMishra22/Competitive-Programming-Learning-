#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void dfs(int vertex, int parent,vector<vector<int>>& g, vector<long>& subtree_sum) {
    subtree_sum[vertex] = 1; // Initialize with the node itself
    for (int child : g[vertex]) {
        if (child == parent) continue;
        dfs(child, vertex, g, subtree_sum);
        subtree_sum[vertex] += subtree_sum[child];
    }
}

int main() {
    vector<int> Nodes = {1, 2, 3, 4, 5}; // Example node values
    vector<vector<int>> Edges = {{1, 2}, {1, 3}, {2, 4}, {2, 5}}; // Example edges

    vector<vector<int>> g(Nodes.size() + 1);
    vector<long> subtree_sum(Nodes.size() + 1, 0);
    for (const auto& edge : Edges) {
        g[edge[0]].push_back(edge[1]);
        g[edge[1]].push_back(edge[0]);
    }

    dfs(1, 0, g, subtree_sum);
    long long ans = 0;
    for (int i = 2; i <= Nodes.size(); ++i) {
        long long part1 = subtree_sum[i];
        long long part2 = subtree_sum[1] - part1;
        ans = max(ans, part1 * part2);
    }

    cout << "Maximum product of sums after deleting an edge: " << ans << endl;

    return 0;
}
