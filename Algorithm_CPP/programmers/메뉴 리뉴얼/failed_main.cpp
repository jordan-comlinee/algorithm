#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <set>

using namespace std;

void sortOrders(vector<string>& orders) {
    for (auto& order : orders) {
        sort(order.begin(), order.end());
    }
}

string get_intersection(string first, string second) {
    vector<char> result;
    string resultStr;
    set_intersection(first.begin(), first.end(), second.begin(), second.end(), back_inserter(result));
    for (auto res : result) {
        resultStr.push_back(res);
    }
    return resultStr;
}

vector<string> getBestCourse(int size, set<string> courses, vector<string> orders) {
    vector<string> result;
    int maxNum = 0;
    for (auto course : courses) {
        int num = 0;
        for (auto order : orders) {
            if (get_intersection(course, order).size() == size) num++;
        }
        maxNum = max(maxNum, num);
    }
    for (auto course : courses) {
        int num = 0;
        for (auto order : orders) {
            if (get_intersection(course, order).size() == size) {
                num++;
            }
        }
        if (num == maxNum && num > 0) { // num이 0보다 커야 유효한 결과로 간주
            result.push_back(course);
        }
    }
    //cout << maxNum << endl;
    return result;
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    set<int> count;
    //set<string> intersected;
    unordered_map<int, set<string>> courses;
    sortOrders(orders);

    for (auto c : course) {
        count.insert(c);
    }

    for (int i = 0; i < orders.size() - 1; ++i) {
        string ans;
        for (int j = i + 1; j < orders.size(); ++j) {
            ans = get_intersection(orders[i], orders[j]);
            //cout << ans << endl;
            if (count.find(ans.size()) != count.end()) {
                //intersected.insert(ans);
                courses[ans.size()].insert(ans);
            }
        }
    }

    for (auto courseNum : course) {
        vector<string> courseResult;
        //cout << "courseNum "<<courseNum << endl;
        courseResult = getBestCourse(courseNum, courses[courseNum], orders);
        answer.insert(answer.end(), courseResult.begin(), courseResult.end());
    }

    sort(answer.begin(), answer.end());
    return answer;
}