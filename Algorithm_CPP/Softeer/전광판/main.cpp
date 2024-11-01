#define _CRT_SECURE_NO_WARNINGS 
#include<bits/stdc++.h>
using namespace std;

string number[11] = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1110010", "1111111", "1111011", "0000000"};

vector<int> getNumArray(string a) {
	reverse(a.begin(), a.end());
	vector<int> result(5, 10);
	for (int i = 0; i < a.size(); i++) {
		result[i] = int(a[i])-48;
	}
	return result;
}

int countSwitch(int a, int b) {
	int cnt = 0;
	for (int i = 0; i < 7; i++) {
		if (number[a][i] ^ number[b][i]) cnt += 1;
	}
	return cnt;
}


int getAllcounts(int a, int b) {
	int result = 0;
	vector<int> fArray = getNumArray(to_string(a));
	vector<int> sArray = getNumArray(to_string(b));
	for (int i = 0; i < 5; i++) {
		result += countSwitch(fArray[i], sArray[i]);
	}
	return result;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T, A, B;
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> A >> B;
		cout << getAllcounts(A, B) << endl;
	}
}