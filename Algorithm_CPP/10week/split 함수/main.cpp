#include <bits/stdc++.h>
using namespace std;

// delimeter�� ������
vector <string> split(string input, string delimeter) {
	vector<string> ret;
	long long pos = 0;
	string token = "";
	// string::npos �� �ܾ� ������ ã�� ����. ã�� ���ڿ��� ���� ��쿡�� string::npos ��ȯ��
	while ((pos = input.find(delimeter)) != string::npos) {
		// abcd ���� d�� ã�� �ʹ�! �׷��� ã���� d�� �ε����� token�� �����Ѵ�.
		token = input.substr(0, pos);
		ret.push_back(token);
		// ���࿡ ã�� �ȴٸ�, 0���� pos������ ����� �� �κ�
		// delimeter(�������� ���̸�ŭ ���� ������) ���ķ� �Ǵٽ� ��� �����ڸ� ã�´�!!
		input.erase(0, pos + delimeter.length());
	}
	ret.push_back(input);
	return ret;
}

int main() {
	string s = "�ȳ��ϼ��� �ҿ��̴� ŷ�����ʷ� õ���Դϴ� �����̿���!", d = " ";
	vector<string> a = split(s, d);
	for (string b : a) cout << b << "\n";
}