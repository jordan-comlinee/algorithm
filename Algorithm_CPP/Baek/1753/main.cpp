#include<bits/stdc++.h>
using namespace std;
#define MAX 20001
#define INF INT_MAX

int V, E, K, u, v, w;
int Dist[MAX];
vector<pair<int, int>> Vertex[MAX];

void solution() {
	// PQ는 왜 만드는거지?
	priority_queue<pair<int, int>> PQ;
	PQ.push(make_pair(0, K));
	// 자기 자신의 거리는 0으로 설정
	Dist[K] = 0;
	while (!PQ.empty())	{
		// 가는 데 드는 비용 - 첫번째
		int Cost = -PQ.top().first;
		int Cur = PQ.top().second;
		PQ.pop();

		for (int i = 0; i < Vertex[Cur].size(); i++) {
			int Next = Vertex[Cur][i].first;
			int nCost = Vertex[Cur][i].second;

			if (Dist[Next] > Cost + nCost) {
				Dist[Next] = Cost + nCost;
				PQ.push(make_pair(-Dist[Next], Next));
			}
		}
	}
	for (int i = 1; i <= V; i++) {
		if (Dist[i] == INF) cout << "INF" << endl;
		else cout << Dist[i] << endl;
	}
	

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> V >> E;
	cin >> K;
	for (int i = 0; i < E; i++) {
		cin >> u >> v >> w;
		Vertex[u].push_back(make_pair(v, w));
	}
	for (int i = 1; i <= V; i++) {
		Dist[i] = INF;
	}
	solution();
}