#include <bits/stdc++.h>
using namespace std;

int N, M, u, v, result = 0;
string S, c;
vector<vector<pair<string, int>>> tree;

void input_data() {
	cin >> N >> M;
	cin >> S;
	tree.resize(N + 1);
	for (int i = 0; i < N-1; ++i) {
		cin >> u >> v >> c;
		tree[u].push_back({ c, v });
		tree[v].push_back({ c, u });
	}
}

int getLCS(string N, string M) {
	int nLen = N.length();
	int mLen = M.length();
	vector<vector<int>> NM(nLen+1, vector<int>(mLen+1, 0));
	for (int i = 1; i <= nLen; ++i) {
		for (int j = 1; j <= mLen; ++j) {
			if (N[i - 1] == M[j - 1]) {
				NM[i][j] = NM[i - 1][j - 1] + 1;
			}
			else {
				NM[i][j] = max(NM[i - 1][j], NM[i][j - 1]);
			}
		}
	}
	//cout << NM[nLen][mLen] << endl;
	return NM[nLen][mLen];
}
void solution() { 
	queue<pair<string, int>> q;
	vector<bool>visited(N + 1, false);
	visited[1] = true;
	q.push({ "", 1 });
	while (!q.empty()) {
		string alphabet = q.front().first;
		int node = q.front().second;
		q.pop();
		visited[node] = true;
		if (tree[node].size() == 1 && alphabet.length() > result) {
			//cout << alphabet << endl;
			result = max(getLCS(alphabet, S), result);
			if (result == M) return;
		}
		for (int i = 0; i < tree[node].size(); ++i) {
			if (visited[tree[node][i].second] == false) {
				q.push({ alphabet + tree[node][i].first, tree[node][i].second });
			}
		}
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	input_data();
	solution();
	cout << result << endl;
	return 0;
}