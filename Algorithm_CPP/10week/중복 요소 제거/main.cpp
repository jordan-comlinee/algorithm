#include <bits/stdc++.h>
using namespace std;
map<int, int> mp;

// 1, 1, 2, 3, 3, 2 ���� 1, 2, 3 �� ������������ �̾Ƴ��� ���
int main() {
	// map�� ����ϴ� ��� {1:1}, {2:1}, {3:1}...�Ҵ��ϴ� ���
	vector <int> v{1, 1, 2, 2, 3, 3};
	// for(int i=0; i < v.size(); i++) �� ����
	for (int i : v) {
		if (mp[i])
			continue;
		else
			mp[i] = 1;
	}
	vector<int> ret;
	for (auto it : mp)
	{
		// ret�� it�� key�� �־��ִ� ����!
		ret.push_back(it.first);
	}
	for (int i : ret) cout << i << '\n';

	//unique() �Լ��� ����ϴ� ���. ���� ���� �ִ� ��� �� �տ������� ���� ���ذ��� �ߺ��Ǵ� ��Ҹ� �����ϰ�
	//������ ��ҵ��� �������� �ʰ� �״�� �δ� �Լ�. O(n)





}