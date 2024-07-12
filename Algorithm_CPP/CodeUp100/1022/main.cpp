#include <bits/stdc++.h>

using namespace std;

int main() 
{
	char data[2001];
	// fgets는 공백문자가 포함되어있는 문장을 입력받아 저장할 수 있는 함수
	// stdin은 키보드로 입력받겠다는 뜻!
	fgets(data, 2000, stdin);
	printf("%s", data);
}