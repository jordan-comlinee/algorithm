#include <string>
#include <cmath>
#include <vector>

using namespace std;

int solution(int n, int t) {
    int answer = n * ((int)pow((float)2, (float)t));
    return answer;
}