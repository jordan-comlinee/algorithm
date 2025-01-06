#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#if 0
bool isRightAngle(int a, int b, int c) {
	if (c*c == a*a+b*b){
		return true;
	}
	return false;
	
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	while (true) {
		int a[3];
		cin >> a[0] >> a[1] >> a[2];
		if (a[0] + a[1] + a[2] == 0) {
			return 0;
		}
		sort(a, a+3);
		if (isRightAngle(a[0], a[1], a[2]))
		{
			cout << "right" << endl;
		}
		else
		{
			cout << "wrong" << endl;
		}
	}
}
#endif