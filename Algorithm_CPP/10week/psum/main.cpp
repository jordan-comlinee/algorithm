#include <bits/stdc++.h>
using namespace std;


int a[100004], psum[10004];

int main() {
	for (int i = 1; i <= 4; i++) {
		cin >> a[i];
		psum[i] = psum[i - 1] + a[i];
	}
}