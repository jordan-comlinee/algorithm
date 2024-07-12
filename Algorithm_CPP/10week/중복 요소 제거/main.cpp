#include <bits/stdc++.h>
using namespace std;
map<int, int> mp;

// 1, 1, 2, 3, 3, 2 에서 1, 2, 3 만 오름차순으로 뽑아내는 방법
int main() {
	// map을 사용하는 방법 {1:1}, {2:1}, {3:1}...할당하는 방법
	vector <int> v{1, 1, 2, 2, 3, 3};
	// for(int i=0; i < v.size(); i++) 와 같음
	for (int i : v) {
		if (mp[i])
			continue;
		else
			mp[i] = 1;
	}
	vector<int> ret;
	for (auto it : mp)
	{
		// ret에 it의 key를 넣어주는 것임!
		ret.push_back(it.first);
	}
	for (int i : ret) cout << i << '\n';

	//unique() 함수를 사용하는 방법. 범위 안의 있는 요소 중 앞에서부터 서로 비교해가며 중복되는 요소를 제거하고
	//나머지 요소들은 삭제하지 않고 그대로 두는 함수. O(n)





}