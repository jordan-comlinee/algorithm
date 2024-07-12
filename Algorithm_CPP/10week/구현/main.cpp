#include<bits/stdc++.h>

using namespace std;

string dopa = "abcde";

//Q1. 앞에서부터 3개의 문자열을 출력하라.
//Q2. 해당 문자열을 거꾸로 해서 출력하라.
//Q3. 해당 문자열 끝에 "umzunsik"이란 문자열을 추가하라.
int main() {
	// 3개 출력
	cout << dopa.substr(0, 3) << "\n";
	// 거꾸로 출력
	reverse(dopa.begin(), dopa.end());
	// 엄준식 추가 출력
	cout << dopa + " umzunsik" << "\n";
	return 0;
}