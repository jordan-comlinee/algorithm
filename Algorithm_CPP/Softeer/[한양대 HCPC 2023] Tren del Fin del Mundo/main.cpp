#include<iostream>
using namespace std;


int N;
int x, y;
pair<int, int> result{ 1001, 1001 };
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        if (result.second > y) {
            result.first = x;
            result.second = y;
        }
    }
    cout << result.first << " " << result.second << endl;
    return 0;
}