#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    map<string, int> yearning_point;
    for (int i = 0; i < name.size(); i++) {
        yearning_point[name[i]] = yearning[i];
    }
    for (int i = 0; i < photo.size(); i++) {
        int score = 0;
        for (int j = 0; j < photo[i].size(); j++) {
            score += yearning_point[photo[i][j]];
        }
        answer.push_back(score);
    }
    return answer;
}