#include <bits/stdc++.h>
#define MAX 1000000007
using namespace std;

long long K, P, N;

long long pow(long long n) {
    if (n == 1) return P;
    long long result = pow(n / 2);
    result = (result * result) % MAX;
    if (n % 2) result = (result * P) % MAX;
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> K >> P >> N;
    cout << (pow(N * 10) * K) % MAX << endl;
    return 0;
}
