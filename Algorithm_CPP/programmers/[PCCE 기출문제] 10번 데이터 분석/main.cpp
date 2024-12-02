#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int sort_idx = 0;
map<string, int> exts = { {"code", 0}, {"date", 1}, {"maximum", 2}, {"remain", 3} };

bool compare(const vector<int>& a, const vector<int>& b) {
    return a[sort_idx] < b[sort_idx];
}

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;
    for (int i = 0; i < data.size(); i++) {
        if (data[i][exts[ext]] < val_ext)
            answer.push_back(data[i]);
    }
    sort_idx = exts[sort_by];
    sort(answer.begin(), answer.end(), compare);
    return answer;
}