#include <bits/stdc++.h>
using namespace std;

int main() {
	int nanjangi[9];
	for (int i = 0; i < 9; i++) {
		cin >> nanjangi[i];
	}
	// �����ϴ� ��! . . . algorithm ���̺귯�� �����
	sort(nanjangi, nanjangi + 9);

	do{
		//for (int i : nanjangi) cout << i << " ";
		//cout << '\n';
		int sum = 0;
		for (int i = 0; i < 7; i++)
			sum += nanjangi[i];
		if (sum == 100) break;
	} while (next_permutation(nanjangi, nanjangi + 9));
	for (int i = 0; i < 7; i++)
		cout << nanjangi[i] << endl;
	return 0;
}