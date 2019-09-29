#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(int start, vector <int> graph[], bool chec[]);

int main() {

	int n, m, start;
	cin >> n >> m >> start;

	vector<int> graph[999];
	bool check[999];
	fill(check, check + 999, false);

	
	for (int i = 0; i<m; i++) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	for (int i = 1; i <= n; i++) {
		sort(graph[i].begin(), graph[i].end());
	}

	dfs(start, graph, check);

	return 0;
}

void dfs(int start, vector <int> graph[], bool check[]) {
	check[start] = true;
	printf("%d ", start);

	for (int i = 0; i<graph[start].size(); i++) {
		int next = graph[start][i];
		if (check[next] == false) {
			dfs(next, graph, check);
		}
	}
}