// 실행 시간 : 0.01489s
#include <bits/stdc++.h>
using namespace std;
// T = testcase, N = size, M = time, K = Colonies
int T, N, M, K, result;

// 2. 각 세균 군집에 대한 자료형을 만든다.
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

// 4. 각 시간 별 군집 이동을 구현한다.
void move_colonies() {
	for (colony& c : colonies) {
		if (c.count > 0) {
			c.move();
		}
		// 경계에 닿은 경우 군집이 절반으로 줄어들고, 반대방향으로 바꾼다.
		if (c.isOutOfBoundary(N)) {
			c.count /= 2;
			if (c.count > 0) {
				c.reverse_direction();
			}
		}

	}
}
// 5. 군집이 마주쳤을 경우, 합치는 과정을 구현한다.
void mergeColonies() {
	map<pair<int, int>, vector<colony>> positionMap;
	
	for (colony& c : colonies) {
		if (c.count > 0) {
			positionMap[c.location].push_back(c);
		}
	}
	colonies.clear();
	// 위치가 겹치는 군집들을 검사한다. position은 pair<int, int>, vector<colony> 이다.
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
// 1. 각 세균 군집의 정보를 받는다. 
// 3. 시간 별로 세균 군집의 이동을 수행한다.(구현)
void solution() {
	for (int k = 0; k < K; k++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		colonies.push_back(colony(a, b, c, d));
	}
	for (int m = 0; m < M; m++) {
		move_colonies();
		// 옮긴 이후, 겹치는 세균 군집을 합친다.
		mergeColonies();
	}
}
// 4. 남은 세균의 수를 구한다.
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