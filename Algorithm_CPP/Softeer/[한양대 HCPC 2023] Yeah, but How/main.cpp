#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string S, result;
    cin >> S;
    for (int i = 0; i < S.size() - 1; i++) {
        result += S[i];
        if (S[i] == '(' && S[i + 1] == ')') {
            result += '1';
        }
        if (S[i] == ')' && S[i + 1] == '(') {
            result += '+';
        }
    }
    result += S[S.size() - 1];
    cout << result << endl;
    return 0;
}