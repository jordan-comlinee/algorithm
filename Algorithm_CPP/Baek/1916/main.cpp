#include <bits/stdc++.h>
using namespace std;
#define MAX 1001
#define INF INT_MAX

int N, M;
int start_point, end_point;
vector<pair<int, int>> maps[MAX];
int dist[MAX];
void input_data(void);
void djikstra();
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	fill(dist, dist + MAX, INF);
	input_data();
	djikstra();
	cout << dist[end_point] << endl;
}

void input_data(void) {
	cin >> N >> M;
	for (int i = 0; i < M; ++i) {
		int st, en, cost;
		cin >> st >> en >> cost;
		maps[st].push_back(make_pair(cost, en));
	}

	cin >> start_point >> end_point;
	/*for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			cout << maps[i][j] << " ";
		}
		cout << endl;
	}*/
}

void djikstra() {
	priority_queue<pair<int, int>> q;
	q.push(make_pair(0, start_point));
	dist[start_point] = 0;
	while (!q.empty()) {
		int cost = -q.top().first;
		int cur = q.top().second;
		q.pop();
		if (dist[cur] < cost) continue;
		for (int i = 0; i < maps[cur].size(); ++i) {
			int cur_cost = cost + maps[cur][i].first;
			if (cur_cost < dist[maps[cur][i].second]) {
				//cout << "현재 노드: " << cur << ", 비용: " << cur_cost << endl;
				dist[maps[cur][i].second] = cur_cost;
				q.push(make_pair(-cur_cost, maps[cur][i].second));
			}
		}

	}
}