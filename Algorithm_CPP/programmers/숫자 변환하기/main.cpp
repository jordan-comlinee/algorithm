#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(int x, int y, int n) {
    vector<int> visited(1000001, -1);
    queue<pair<int, int>> q;

    q.push({ x, 0 });
    visited[x] = 0;

    while (!q.empty()) {
        int current = q.front().first;
        int operations = q.front().second;
        q.pop();

        if (current == y) return operations;

        vector<int> next_values = { current + n, current * 2, current * 3 };
        for (int nxt : next_values) {
            if (nxt > y || visited[nxt] != -1) continue;
            visited[nxt] = operations + 1;
            q.push({ nxt, operations + 1 });
        }
    }

    return -1;
}

/*
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int x, int y, int n) {
    queue<pair<int, int>> q;
    q.push(make_pair(y, 0));

    while (!q.empty())
    {
        int val = q.front().first;
        int count = q.front().second;
        q.pop();

        if (val == x)
            return count;

        if (val % 2 == 0)
        {
            q.push(make_pair(val / 2, count + 1));
        }

        if (val % 3 == 0)
        {
            q.push(make_pair(val / 3, count + 1));
        }

        if (val - n > 0)
        {
            q.push(make_pair(val - n, count + 1));
        }
    }

    return -1;
}
*/