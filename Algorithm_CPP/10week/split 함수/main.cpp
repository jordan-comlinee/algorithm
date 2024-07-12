#include <bits/stdc++.h>
using namespace std;

// delimeter는 구분자
vector <string> split(string input, string delimeter) {
	vector<string> ret;
	long long pos = 0;
	string token = "";
	// string::npos 는 단어 유무를 찾기 위함. 찾는 문자열이 없는 경우에는 string::npos 반환함
	while ((pos = input.find(delimeter)) != string::npos) {
		// abcd 에서 d를 찾고 싶다! 그래서 찾으면 d의 인덱스를 token에 저장한다.
		token = input.substr(0, pos);
		ret.push_back(token);
		// 만약에 찾게 된다면, 0부터 pos까지가 찢어야 할 부분
		// delimeter(구분자의 길이만큼 빼는 이유임) 이후로 또다시 찢어서 구분자를 찾는다!!
		input.erase(0, pos + delimeter.length());
	}
	ret.push_back(input);
	return ret;
}

int main() {
	string s = "안녕하세요 소영이는 킹갓제너럴 천재입니다 정말이에요!", d = " ";
	vector<string> a = split(s, d);
	for (string b : a) cout << b << "\n";
}