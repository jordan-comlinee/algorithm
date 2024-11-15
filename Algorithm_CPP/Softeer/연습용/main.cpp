// ���� �ð� : 0.01489s
#include <bits/stdc++.h>
using namespace std;
// T = testcase, N = size, M = time, K = Colonies
int T, N, M, K, result;

// 2. �� ���� ������ ���� �ڷ����� �����.
struct colony {
	pair<int, int> location;
	int count;
	int dir;
	pair<int, int> direction;

	void move() {
		location.first += direction.first;
		location.second += direction.second;
	}

	bool isOutOfBoundary(int N) {
		return (location.first == N - 1 || location.first == 0 || location.second == N - 1 || location.second == 0);
	}

	pair<int, int> get_direction(int dir) {
		switch (dir) {
		case 1: return make_pair(-1, 0);
		case 2: return make_pair(1, 0);
		case 3: return make_pair(0, -1);
		case 4: return make_pair(0, 1);
		default: return make_pair(0, 0);
		}
	}

	void reverse_direction() {
		switch (dir) {
		case 1: dir = 2; break;
		case 2: dir = 1; break;
		case 3: dir = 4; break;
		case 4: dir = 3; break;
		default:break;
		}
		direction = get_direction(dir);
	}

	colony(int a, int b, int c, int d)
		: location(make_pair(a, b)), count(c), dir(d), direction(get_direction(d)) {}

};
vector<colony> colonies;

// 4. �� �ð� �� ���� �̵��� �����Ѵ�.
void move_colonies() {
	for (colony& c : colonies) {
		if (c.count > 0) {
			c.move();
		}
		// ��迡 ���� ��� ������ �������� �پ���, �ݴ�������� �ٲ۴�.
		if (c.isOutOfBoundary(N)) {
			c.count /= 2;
			if (c.count > 0) {
				c.reverse_direction();
			}
		}

	}
}
// 5. ������ �������� ���, ��ġ�� ������ �����Ѵ�.
void mergeColonies() {
	map<pair<int, int>, vector<colony>> positionMap;
	
	for (colony& c : colonies) {
		if (c.count > 0) {
			positionMap[c.location].push_back(c);
		}
	}
	colonies.clear();
	// ��ġ�� ��ġ�� �������� �˻��Ѵ�. position�� pair<int, int>, vector<colony> �̴�.
	for (auto& position : positionMap) {
		vector<colony>& group = position.second;
		if (group.size() == 1){
			colonies.push_back(group[0]);
		}
		else {
			int maxCount = 0;
			colony mergedColony = group[0];
			mergedColony.count = 0;
			for (colony& c : group ) {
				if (c.count > maxCount) {
					maxCount = c.count;
					mergedColony.dir = c.dir;
					mergedColony.direction = c.direction;
				}
				mergedColony.count += c.count;
			}
			colonies.push_back(mergedColony);
		}
	}

}
// 1. �� ���� ������ ������ �޴´�. 
// 3. �ð� ���� ���� ������ �̵��� �����Ѵ�.(����)
void solution() {
	for (int k = 0; k < K; k++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		colonies.push_back(colony(a, b, c, d));
	}
	for (int m = 0; m < M; m++) {
		move_colonies();
		// �ű� ����, ��ġ�� ���� ������ ��ģ��.
		mergeColonies();
	}
}
// 4. ���� ������ ���� ���Ѵ�.
int countColonies() {
	int cnt = 0;
	for (colony& c : colonies){
		cnt += c.count;
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N >> M >> K;
		colonies.clear();
		solution();
		result = countColonies();
		cout << "#"<< t << " " << result << endl;
	}

}