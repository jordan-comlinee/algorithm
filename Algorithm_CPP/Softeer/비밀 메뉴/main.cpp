#include <stdio.h>
#include <vector>
#include <cmath>
using namespace std;
int M, N, K;
int pwd = 0;
int main(void) {
	scanf_s("%d %d %d", &M, &N, &K);
	vector<int> m(M);
	vector<int> n(N);
	for (int i = 0; i < M; i++)	{
		scanf_s("%d", &m[i]);
		pwd += m[i]*pow(10, M-i-1);
	}
	for (int i = 0; i < N; i++)	{
		scanf_s("%d", &n[i]);
	}
	for (int i = 0; i < N-K+1; i++) {
		int check = 0;
		for (int j = 0; j < M; j++) {
			check += n[i+j]*pow(10, M-j-1);
		}
		if (pwd == check) {
			printf("secret");
			return 0;
		}
	}
	printf("normal");
	return 0;
}