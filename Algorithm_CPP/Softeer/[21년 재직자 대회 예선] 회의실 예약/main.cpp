#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

string Room;
int N, M, startTime, endTime;
vector<string> Rooms(51);
map<string, set<int>> books;

void initBooks(string roomName) {
    books.insert({ roomName, set<int>{} });
    for (int i = 9; i < 18; i++) {
        books[roomName].insert(i);
    }
}

void confirmBook(string roomName, int startTime, int endTime) {
    for (int i = startTime; i < endTime; i++) {
        books[roomName].erase(i);
    }
}

void printBooks(string roomName) {
    cout << "Room " << roomName << ":" << endl;
    if (books[roomName].size() == 0) {
        cout << "Not available" << endl;
    }
    else {
        vector<string> intervals;
        auto it = books[roomName].begin();
        int start = *it, prev = *it;
        int cnt = 0;

        ++it;
        while (it != books[roomName].end()) {
            if (*it != prev + 1) {
                intervals.push_back((start < 10 ? "0" : "") + to_string(start) + "-" + (prev + 1 < 10 ? "0" : "") + to_string(prev + 1));
                start = *it;
                cnt++;
            }
            prev = *it;
            ++it;
        }
        intervals.push_back((start < 10 ? "0" : "") + to_string(start) + "-" + (prev + 1 < 10 ? "0" : "") + to_string(prev + 1));
        cnt++;

        cout << cnt << " available:" << endl;

        for (const auto& interval : intervals) {
            cout << interval << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> Rooms[i];
        initBooks(Rooms[i]);
    }
    for (int i = 0; i < M; i++) {
        cin >> Room >> startTime >> endTime;
        confirmBook(Room, startTime, endTime);
    }
    sort(Rooms.begin(), Rooms.begin() + N);
    for (int i = 0; i < N - 1; i++) {
        printBooks(Rooms[i]);
        cout << "-----" << endl;
    }
    printBooks(Rooms[N - 1]);
    return 0;
}