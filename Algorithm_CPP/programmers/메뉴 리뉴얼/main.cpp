#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

void getCombination(string str, int cnt, string result, int start, vector<string>& localCombinations) {
    if (result.size() == cnt) {
        localCombinations.push_back(result);
        return;
    }
    for (int i = start; i < str.size(); ++i) {
        getCombination(str, cnt, result + str[i], i + 1, localCombinations);
    }
}

vector<string> findCommonCourse(vector<string> everyCourse) {
    vector<string> result;
    int maxFreq = 0;
    unordered_map<string, int> frequency;
    for (auto course : everyCourse) {
        frequency[course] += 1;
        maxFreq = max(maxFreq, frequency[course]);
    }
    if (maxFreq >= 2) {
        for (auto [name, freq] : frequency) {
            //cout << name << " : " << freq << endl;
            if (freq == maxFreq) {
                result.push_back(name);
            }
        }
    }
    //cout << maxFreq << endl;
    return result;
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    for (auto& order : orders) {
        sort(order.begin(), order.end());
    }
    // cnt���� ��Ҹ� ���� �� �ִ� ��� �ڽ� ���� ���ϱ�
    for (auto cnt : course) {
        vector<string> everyCourse;
        vector<string> commonCourse;
        // orders ������ ��� ã��
        for (auto order : orders) {
            vector<string> combinations;
            getCombination(order, cnt, "", 0, combinations);
            everyCourse.insert(everyCourse.end(), combinations.begin(), combinations.end());
        }
        // ���� �߿��� ���� ���� ���� �͵� ã�Ƽ� answer�� �ֱ�
        commonCourse = findCommonCourse(everyCourse);
        answer.insert(answer.end(), commonCourse.begin(), commonCourse.end());
    }
    sort(answer.begin(), answer.end());
    return answer;
}