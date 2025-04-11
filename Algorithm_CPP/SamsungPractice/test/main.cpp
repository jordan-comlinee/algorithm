#include <algorithm>
#include <iostream>
#include <utility>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

// ��� ����
const int INF = 1e9 + 10;    // ���Ѵ븦 ��Ÿ���� ���
const int MAX_N = 60;         // �ִ� �׸��� ũ�� (50 + 10)
const int MAX_M = 310;        // �ִ� ���� �� (300 + 10)

// ���� ���� ����
int obstacleGrid[MAX_N][MAX_N];    // ��ֹ� �׸��� (1: ��ֹ�, 0: �����ο� ����)
int distanceGrid[MAX_N][MAX_N];    // �� ������ ���� ���������� �Ÿ�
pii warriorPositions[MAX_M];        // ������� ���� ��ġ
int sightMap[MAX_N][MAX_N];        // ���� �þ� ���� (1: �þ� ��, 0: �þ� ��)
int warriorCountGrid[MAX_N][MAX_N]; // �� ���� �ִ� ������ ��

// ���� �迭: ��, �Ʒ�, ����, ������
const int DX[4] = { -1, 1, 0, 0 };
const int DY[4] = { 0, 0, -1, 1 };

/**
 * @brief �� �� ������ ����ư �Ÿ��� ����ϴ� �Լ�
 *
 * @param a ù ��° ���� ��ǥ (x, y)
 * @param b �� ��° ���� ��ǥ (x, y)
 * @return int ����ư �Ÿ�
 */
inline int calculateManhattanDistance(const pii& a, const pii& b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

/**
 * @brief BFS�� �̿��Ͽ� ���� ����(startX, startY)���� ��� ���� ������ �������� �ִ� �Ÿ��� ����ϴ� �Լ�
 *
 * @param startX ���� ������ x ��ǥ (���� ����)
 * @param startY ���� ������ y ��ǥ (���� ����)
 * @param N �׸����� ũ�� (N x N)
 */
void computeDistances(int startX, int startY, int N) {
    // �Ÿ� �׸��带 �ʱ�ȭ: ��ֹ��� �ִ� ���� INF, �׷��� ������ -1�� ����
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            distanceGrid[i][j] = obstacleGrid[i][j] ? INF : -1;
        }
    }

    queue<pii> q;               // BFS�� ���� ť
    q.push({ startX, startY });   // ���� ������ ť�� �߰�
    distanceGrid[startX][startY] = 0;  // ���� ������ �Ÿ��� 0

    // BFS �˰��� ����
    while (!q.empty()) {
        int currentX = q.front().first;
        int currentY = q.front().second;
        q.pop();

        // �� �������� �̵�
        for (int dir = 0; dir < 4; dir++) {
            int nextX = currentX + DX[dir];
            int nextY = currentY + DY[dir];

            // �׸��� ��踦 ������� Ȯ��
            if (nextX < 0 || nextY < 0 || nextX >= N || nextY >= N)
                continue;
            // �̹� �湮�߰ų� ��ֹ��� �ִ��� Ȯ��
            if (distanceGrid[nextX][nextY] != -1)
                continue;

            // ���� ���� �Ÿ� ������Ʈ �� ť�� �߰�
            distanceGrid[nextX][nextY] = distanceGrid[currentX][currentY] + 1;
            q.push({ nextX, nextY });
        }
    }
}

// �þ� ���⿡ ���� �Լ� ���� (��, �Ʒ�, ����, ������)
int sightUp(int x, int y, int N, bool isTest);
int sightDown(int x, int y, int N, bool isTest);
int sightLeft(int x, int y, int N, bool isTest);
int sightRight(int x, int y, int N, bool isTest);

/**
 * @brief ������ �þ� ������ �����Ͽ� �þ߸� �����ϴ� �Լ�
 *
 * @param x ���� �÷��̾��� x ��ǥ
 * @param y ���� �÷��̾��� y ��ǥ
 * @param N �׸����� ũ��
 * @return int �ִ� Ŀ������ (�þ߷� Ŀ���� ������ ��)
 */
int chooseBestSight(int x, int y, int N) {
    // �þ� ���� �ʱ�ȭ (��� ���� �þ� �ܷ� ����)
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            sightMap[i][j] = 0;

    int maxCoverage = -1;    // �ִ� Ŀ�������� ������ ����
    int bestDirection = -1;   // ������ �þ� ���� (0: ��, 1: �Ʒ�, 2: ����, 3: ������)

    // �þ� ���⺰ �Լ� ������ �迭
    typedef int (*SightFunc)(int, int, int, bool);
    SightFunc sightFunctions[4] = { sightUp, sightDown, sightLeft, sightRight };

    // ��� �þ� ������ �׽�Ʈ�Ͽ� �ִ� Ŀ�������� ã��
    for (int dir = 0; dir < 4; dir++) {
        // �׽�Ʈ�� ���� �þ� ���� �ʱ�ȭ
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                sightMap[i][j] = 0;

        // ���� �������� �þ� �����ϰ� Ŀ������ ���
        int coverage = sightFunctions[dir](x, y, N, true);
        if (maxCoverage < coverage) {
            maxCoverage = coverage;
            bestDirection = dir;
        }
    }

    // ������ �������� ���� �þ� ����
    sightFunctions[bestDirection](x, y, N, false);

    return maxCoverage;
}

/**
 * @brief ���� �������� �þ߸� �����ϴ� �Լ�
 *
 * @param x ���� �÷��̾��� x ��ǥ
 * @param y ���� �÷��̾��� y ��ǥ
 * @param N �׸����� ũ��
 * @param isTest �׽�Ʈ ��� ���� (true: �׽�Ʈ, false: ���� ����)
 * @return int �þ߷� Ŀ���� ������ ��
 */
int sightUp(int x, int y, int N, bool isTest) {
    // ���̾Ƹ�� ���·� ���� ���� �þ߿� ���Խ�Ŵ
    for (int i = x - 1; i >= 0; i--) {
        int left = max(0, y - (x - i));           // ���� ��� ���
        int right = min(N - 1, y + (x - i));      // ������ ��� ���
        for (int j = left; j <= right; j++) {
            sightMap[i][j] = 1;                   // �þ� ����
        }
    }

    // ��ֹ� ó��: �þ� ���� ���� Ȯ��
    bool obstructionFound = false;
    for (int i = x - 1; i >= 0; i--) {
        if (obstructionFound) {
            sightMap[i][y] = 0;                   // ��ֹ��� �߰ߵ� �Ŀ��� �þ� ����
        }
        else {
            sightMap[i][y] = 1;                   // ��ֹ��� �߰ߵ��� ������ �þ� ����
        }

        if (warriorCountGrid[i][y]) {             // ���簡 �ִ� ��� ��ֹ��� ����
            obstructionFound = true;
        }
    }

    // ��ֹ��� ���� �þ� ����
    for (int i = x - 1; i >= 1; i--) {
        int left = max(0, y - (x - i));           // ���� ��� ���
        int right = min(N - 1, y + (x - i));      // ������ ��� ���

        // ���� ���� ����
        for (int j = left; j < y; j++) {
            if ((!sightMap[i][j]) || warriorCountGrid[i][j]) {
                if (j > 0) sightMap[i - 1][j - 1] = 0; // ���� �� ���� �þ� ����
                sightMap[i - 1][j] = 0;            // �ٷ� �� ���� �þ� ����
            }
        }

        // ������ ���� ����
        for (int j = y + 1; j <= right; j++) {
            if ((!sightMap[i][j]) || warriorCountGrid[i][j]) {
                if (j + 1 < N) sightMap[i - 1][j + 1] = 0; // ������ �� ���� �þ� ����
                sightMap[i - 1][j] = 0;                // �ٷ� �� ���� �þ� ����
            }
        }
    }

    // �þ߷� Ŀ���� ���� �� ���
    int coverage = 0;
    for (int i = x - 1; i >= 0; i--) {
        int left = max(0, y - (x - i));           // ���� ��� ���
        int right = min(N - 1, y + (x - i));      // ������ ��� ���
        for (int j = left; j <= right; j++) {
            if (sightMap[i][j]) {
                coverage += warriorCountGrid[i][j]; // �þ� ���� �ִ� ������ ���� ����
            }
        }
    }

    // �׽�Ʈ ����� ��� �þ� ���� ������� �ǵ���
    if (isTest) {
        for (int i = x - 1; i >= 0; i--) {
            int left = max(0, y - (x - i));
            int right = min(N - 1, y + (x - i));
            for (int j = left; j <= right; j++) {
                sightMap[i][j] = 0;                   // �þ� ����
            }
        }
    }

    return coverage;    // Ŀ������ ��ȯ
}

/**
 * @brief �Ʒ��� �������� �þ߸� �����ϴ� �Լ� (sightUp�� ����)
 *
 * @param x ���� �÷��̾��� x ��ǥ
 * @param y ���� �÷��̾��� y ��ǥ
 * @param N �׸����� ũ��
 * @param isTest �׽�Ʈ ��� ���� (true: �׽�Ʈ, false: ���� ����)
 * @return int �þ߷� Ŀ���� ������ ��
 */
int sightDown(int x, int y, int N, bool isTest) {
    // ���̾Ƹ�� ���·� �Ʒ��� ���� �þ߿� ���Խ�Ŵ
    for (int i = x + 1; i < N; i++) {
        int left = max(0, y - (i - x));           // ���� ��� ���
        int right = min(N - 1, y + (i - x));      // ������ ��� ���
        for (int j = left; j <= right; j++) {
            sightMap[i][j] = 1;                   // �þ� ����
        }
    }

    // ��ֹ� ó��: �þ� ���� ���� Ȯ��
    bool obstructionFound = false;
    for (int i = x + 1; i < N; i++) {
        if (obstructionFound) {
            sightMap[i][y] = 0;                   // ��ֹ��� �߰ߵ� �Ŀ��� �þ� ����
        }
        else {
            sightMap[i][y] = 1;                   // ��ֹ��� �߰ߵ��� ������ �þ� ����
        }

        if (warriorCountGrid[i][y]) {             // ���簡 �ִ� ��� ��ֹ��� ����
            obstructionFound = true;
        }
    }

    // ��ֹ��� ���� �þ� ����
    for (int i = x + 1; i < N - 1; i++) {
        int left = max(0, y - (i - x));           // ���� ��� ���
        int right = min(N - 1, y + (i - x));      // ������ ��� ���

        // ���� ���� ����
        for (int j = left; j < y; j++) {
            if ((!sightMap[i][j]) || warriorCountGrid[i][j]) {
                if (j > 0) sightMap[i + 1][j - 1] = 0; // ���� �Ʒ� ���� �þ� ����
                sightMap[i + 1][j] = 0;            // �ٷ� �Ʒ� ���� �þ� ����
            }
        }

        // ������ ���� ����
        for (int j = y + 1; j <= right; j++) {
            if ((!sightMap[i][j]) || warriorCountGrid[i][j]) {
                if (j + 1 < N) sightMap[i + 1][j + 1] = 0; // ������ �Ʒ� ���� �þ� ����
                sightMap[i + 1][j] = 0;                // �ٷ� �Ʒ� ���� �þ� ����
            }
        }
    }

    // �þ߷� Ŀ���� ���� �� ���
    int coverage = 0;
    for (int i = x + 1; i < N; i++) {
        int left = max(0, y - (i - x));           // ���� ��� ���
        int right = min(N - 1, y + (i - x));      // ������ ��� ���
        for (int j = left; j <= right; j++) {
            if (sightMap[i][j]) {
                coverage += warriorCountGrid[i][j]; // �þ� ���� �ִ� ������ ���� ����
            }
        }
    }

    // �׽�Ʈ ����� ��� �þ� ���� ������� �ǵ���
    if (isTest) {
        for (int i = x + 1; i < N; i++) {
            int left = max(0, y - (i - x));
            int right = min(N - 1, y + (i - x));
            for (int j = left; j <= right; j++) {
                sightMap[i][j] = 0;                   // �þ� ����
            }
        }
    }

    return coverage;    // Ŀ������ ��ȯ
}

/**
 * @brief ���� �������� �þ߸� �����ϴ� �Լ� (sightUp�� ����)
 *
 * @param x ���� �÷��̾��� x ��ǥ
 * @param y ���� �÷��̾��� y ��ǥ
 * @param N �׸����� ũ��
 * @param isTest �׽�Ʈ ��� ���� (true: �׽�Ʈ, false: ���� ����)
 * @return int �þ߷� Ŀ���� ������ ��
 */
int sightLeft(int x, int y, int N, bool isTest) {
    // ���̾Ƹ�� ���·� ���� ���� �þ߿� ���Խ�Ŵ
    for (int i = y - 1; i >= 0; i--) {
        int top = max(0, x - (y - i));            // ��� ��� ���
        int bottom = min(N - 1, x + (y - i));     // �ϴ� ��� ���
        for (int j = top; j <= bottom; j++) {
            sightMap[j][i] = 1;                    // �þ� ����
        }
    }

    // ��ֹ� ó��: �þ� ���� ���� Ȯ��
    bool obstructionFound = false;
    for (int i = y - 1; i >= 0; i--) {
        if (obstructionFound) {
            sightMap[x][i] = 0;                    // ��ֹ��� �߰ߵ� �Ŀ��� �þ� ����
        }
        else {
            sightMap[x][i] = 1;                    // ��ֹ��� �߰ߵ��� ������ �þ� ����
        }

        if (warriorCountGrid[x][i]) {               // ���簡 �ִ� ��� ��ֹ��� ����
            obstructionFound = true;
        }
    }

    // ��ֹ��� ���� �þ� ����
    for (int i = y - 1; i > 0; i--) {
        int top = max(0, x - (y - i));             // ��� ��� ���
        int bottom = min(N - 1, x + (y - i));      // �ϴ� ��� ���

        // ��� ���� ����
        for (int j = top; j < x; j++) {
            if ((!sightMap[j][i]) || warriorCountGrid[j][i]) {
                if (j > 0) sightMap[j - 1][i - 1] = 0; // ���� �� ���� �þ� ����
                sightMap[j][i - 1] = 0;            // �ٷ� ���� ���� �þ� ����
            }
        }

        // �ϴ� ���� ����
        for (int j = x + 1; j <= bottom; j++) {
            if ((!sightMap[j][i]) || warriorCountGrid[j][i]) {
                if (j + 1 < N) sightMap[j + 1][i - 1] = 0; // ���� �Ʒ� ���� �þ� ����
                sightMap[j][i - 1] = 0;                // �ٷ� ���� ���� �þ� ����
            }
        }
    }

    // �þ߷� Ŀ���� ���� �� ���
    int coverage = 0;
    for (int i = y - 1; i >= 0; i--) {
        int top = max(0, x - (y - i));             // ��� ��� ���
        int bottom = min(N - 1, x + (y - i));      // �ϴ� ��� ���
        for (int j = top; j <= bottom; j++) {
            if (sightMap[j][i]) {
                coverage += warriorCountGrid[j][i]; // �þ� ���� �ִ� ������ ���� ����
            }
        }
    }

    // �׽�Ʈ ����� ��� �þ� ���� ������� �ǵ���
    if (isTest) {
        for (int i = y - 1; i >= 0; i--) {
            int top = max(0, x - (y - i));
            int bottom = min(N - 1, x + (y - i));
            for (int j = top; j <= bottom; j++) {
                sightMap[j][i] = 0;                   // �þ� ����
            }
        }
    }

    return coverage;    // Ŀ������ ��ȯ
}

/**
 * @brief ������ �������� �þ߸� �����ϴ� �Լ� (sightUp�� ����)
 *
 * @param x ���� �÷��̾��� x ��ǥ
 * @param y ���� �÷��̾��� y ��ǥ
 * @param N �׸����� ũ��
 * @param isTest �׽�Ʈ ��� ���� (true: �׽�Ʈ, false: ���� ����)
 * @return int �þ߷� Ŀ���� ������ ��
 */
int sightRight(int x, int y, int N, bool isTest) {
    // ���̾Ƹ�� ���·� ������ ���� �þ߿� ���Խ�Ŵ
    for (int i = y + 1; i < N; i++) {
        int top = max(0, x - (i - y));            // ��� ��� ���
        int bottom = min(N - 1, x + (i - y));     // �ϴ� ��� ���
        for (int j = top; j <= bottom; j++) {
            sightMap[j][i] = 1;                    // �þ� ����
        }
    }

    // ��ֹ� ó��: �þ� ���� ���� Ȯ��
    bool obstructionFound = false;
    for (int i = y + 1; i < N; i++) {
        if (obstructionFound) {
            sightMap[x][i] = 0;                    // ��ֹ��� �߰ߵ� �Ŀ��� �þ� ����
        }
        else {
            sightMap[x][i] = 1;                    // ��ֹ��� �߰ߵ��� ������ �þ� ����
        }

        if (warriorCountGrid[x][i]) {               // ���簡 �ִ� ��� ��ֹ��� ����
            obstructionFound = true;
        }
    }

    // ��ֹ��� ���� �þ� ����
    for (int i = y + 1; i < N - 1; i++) {
        int top = max(0, x - (i - y));             // ��� ��� ���
        int bottom = min(N - 1, x + (i - y));      // �ϴ� ��� ���

        // ��� ���� ����
        for (int j = top; j < x; j++) {
            if ((!sightMap[j][i]) || warriorCountGrid[j][i]) {
                if (j > 0) sightMap[j - 1][i + 1] = 0; // ������ �� ���� �þ� ����
                sightMap[j][i + 1] = 0;            // �ٷ� ������ ���� �þ� ����
            }
        }

        // �ϴ� ���� ����
        for (int j = x + 1; j <= bottom; j++) {
            if ((!sightMap[j][i]) || warriorCountGrid[j][i]) {
                if (j + 1 < N) sightMap[j + 1][i + 1] = 0; // ������ �Ʒ� ���� �þ� ����
                sightMap[j][i + 1] = 0;                // �ٷ� ������ ���� �þ� ����
            }
        }
    }

    // �þ߷� Ŀ���� ���� �� ���
    int coverage = 0;
    for (int i = y + 1; i < N; i++) {
        int top = max(0, x - (i - y));             // ��� ��� ���
        int bottom = min(N - 1, x + (i - y));      // �ϴ� ��� ���
        for (int j = top; j <= bottom; j++) {
            if (sightMap[j][i]) {
                coverage += warriorCountGrid[j][i]; // �þ� ���� �ִ� ������ ���� ����
            }
        }
    }

    // �׽�Ʈ ����� ��� �þ� ���� ������� �ǵ���
    if (isTest) {
        for (int i = y + 1; i < N; i++) {
            int top = max(0, x - (i - y));
            int bottom = min(N - 1, x + (i - y));
            for (int j = top; j <= bottom; j++) {
                sightMap[j][i] = 0;                   // �þ� ����
            }
        }
    }

    return coverage;    // Ŀ������ ��ȯ
}

/**
 * @brief �÷��̾ ���� ������� �̵���Ű�� �Լ�
 *
 * @param playerX �÷��̾��� ���� x ��ǥ
 * @param playerY �÷��̾��� ���� y ��ǥ
 * @param N �׸����� ũ��
 * @param M ������ ��
 * @return pii (�� �̵��� ���� ��, �÷��̾�� ������ ���� ��)
 */
pii moveWarriors(int playerX, int playerY, int N, int M) {
    int totalMoved = 0;   // �� �̵��� ���� ��
    int totalHits = 0;    // �÷��̾�� ������ ���� ��

    // ������ �̵� ����: ��, �Ʒ�, ����, ������
    const int moveDX[4] = { -1, 1, 0, 0 };
    const int moveDY[4] = { 0, 0, -1, 1 };

    // ��� ���翡 ���� �̵� ó��
    for (int i = 0; i < M; i++) {
        if (warriorPositions[i].first == -1)
            continue; // �̹� ���� ����� �ǳʶ�

        int warriorX = warriorPositions[i].first;
        int warriorY = warriorPositions[i].second;

        // �þ� ���� �ִ� ����� �̵����� ����
        if (sightMap[warriorX][warriorY])
            continue;

        // ���� �÷��̾���� �Ÿ� ���
        int currentDistance = calculateManhattanDistance({ playerX, playerY }, { warriorX, warriorY });
        bool hasMoved = false;   // �̵� ���� �÷���

        // ù ��° �̵�: �Ÿ��� ���̱� ���� �̵�
        for (int dir = 0; dir < 4; dir++) {
            int nextX = warriorX + moveDX[dir];
            int nextY = warriorY + moveDY[dir];

            // �̵��� ��ġ�� �׸��� ���� �ְ� �þ� ���� ���� ������ Ȯ��
            if (nextX < 0 || nextY < 0 || nextX >= N || nextY >= N)
                continue;
            if (sightMap[nextX][nextY])
                continue;

            // ���ο� ��ġ������ �Ÿ� ���
            int newDistance = calculateManhattanDistance({ playerX, playerY }, { nextX, nextY });
            if (newDistance < currentDistance) {
                warriorX = nextX;
                warriorY = nextY;
                hasMoved = true;
                totalMoved++;
                break; // ù ��° �̵� �� ���� Ż��
            }
        }

        // �� ��° �̵�: �߰��� �Ÿ��� ���� �� �ִ��� Ȯ��
        if (hasMoved) {
            int newDistance = calculateManhattanDistance({ playerX, playerY }, { warriorX, warriorY });
            for (int dir = 0; dir < 4; dir++) {
                // �ݴ� �������� �̵� �õ�
                int nextX = warriorX + moveDX[(dir + 2) % 4];
                int nextY = warriorY + moveDY[(dir + 2) % 4];

                // �̵��� ��ġ�� �׸��� ���� �ְ� �þ� ���� ���� ������ Ȯ��
                if (nextX < 0 || nextY < 0 || nextX >= N || nextY >= N)
                    continue;
                if (sightMap[nextX][nextY])
                    continue;

                // ���ο� ��ġ������ �Ÿ� ���
                int furtherDistance = calculateManhattanDistance({ playerX, playerY }, { nextX, nextY });
                if (furtherDistance < newDistance) {
                    warriorX = nextX;
                    warriorY = nextY;
                    totalMoved++;
                    break; // �� ��° �̵� �� ���� Ż��
                }
            }
        }
        cout << totalMoved << endl;
        // ������ ��ġ ������Ʈ
        warriorPositions[i] = { warriorX, warriorY };
    }

    // �÷��̾�� ������ ���� �� ���
    for (int i = 0; i < M; i++) {
        if (warriorPositions[i].first == -1)
            continue; // �̹� ���� ����� �ǳʶ�

        if (warriorPositions[i].first == playerX && warriorPositions[i].second == playerY) {
            totalHits++;
            warriorPositions[i] = { -1, -1 }; // ���縦 ���� ���·� ǥ��
        }
    }

    return { totalMoved, totalHits }; // ��� ��ȯ
}

/**
 * @brief ���� ������� ��ġ�� ������� �� ���� �ִ� ������ ���� ������Ʈ�ϴ� �Լ�
 *
 * @param N �׸����� ũ��
 * @param M ������ ��
 */
void updateWarriorCountGrid(int N, int M) {
    // ���� �� �׸��带 �ʱ�ȭ
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            warriorCountGrid[i][j] = 0;

    // �� ������ ��ġ�� Ȯ���Ͽ� ���� �� �׸��忡 �ݿ�
    for (int i = 0; i < M; i++) {
        if (warriorPositions[i].first == -1)
            continue; // �̹� ���� ����� �ǳʶ�
        int x = warriorPositions[i].first;
        int y = warriorPositions[i].second;
        warriorCountGrid[x][y]++;
    }
}

int main()
{
    ios::sync_with_stdio(false); // ����� �ӵ� ����� ���� ����
    cin.tie(NULL);                // ����� ���� ����

    int N, M;                     // �׸��� ũ�� N, ���� �� M
    cin >> N >> M;

    int startX, startY, endX, endY;   // ���� ������ ���� ������ ��ǥ
    cin >> startX >> startY >> endX >> endY;

    // �ʱ� ���� ��ġ �Է�
    for (int i = 0; i < M; i++) {
        cin >> warriorPositions[i].first >> warriorPositions[i].second;
    }

    // ��ֹ� �׸��� �Է�
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> obstacleGrid[i][j];
        }
    }

    // ���� �������κ��� ��� �������� �Ÿ��� ���
    computeDistances(endX, endY, N);

    // ���� ������ ���� ������ ������ �� ���� ��� ����
    if (distanceGrid[startX][startY] == -1) {
        cout << "-1\n";
        return 0;
    }

    int currentX = startX; // ���� �÷��̾��� x ��ǥ
    int currentY = startY; // ���� �÷��̾��� y ��ǥ

    // ���� ����: �÷��̾ ���� ������ ������ ������ �ݺ�
    while (true) {
        bool moved = false; // �÷��̾ �̵��ߴ��� ����

        // ���� ��ġ���� ���� �������� ���ϴ� �������� �� ĭ �̵�
        for (int dir = 0; dir < 4; dir++) {
            int nextX = currentX + DX[dir];
            int nextY = currentY + DY[dir];
            if (nextX < 0 || nextY < 0 || nextX >= N || nextY >= N)
                continue; // �׸��� ��踦 ����� ����
            if (distanceGrid[nextX][nextY] < distanceGrid[currentX][currentY]) {
                currentX = nextX;
                currentY = nextY;
                moved = true;
                break; // �̵� �� ���� Ż��
            }
        }

        // ���� ������ ������ ��� ����
        if (currentX == endX && currentY == endY) {
            cout << "0\n"; // ���� �� ���
            break;
        }

        // ���� ��ġ�� �ִ� ������� ���� (�þ߷� ����)
        for (int i = 0; i < M; i++) {
            if (warriorPositions[i].first == currentX && warriorPositions[i].second == currentY) {
                warriorPositions[i] = { -1, -1 }; // ���縦 ���� ���·� ǥ��
            }
        }

        // ���� ������� ��ġ�� ������� ���� �� �׸��带 ������Ʈ
        updateWarriorCountGrid(N, M);

        // ������ �þ� ������ �����ϰ� �þ߷� Ŀ���� ������ ���� ���
        int sightCoverage = chooseBestSight(currentX, currentY, N);

        // ������� �̵���Ű�� �̵��� ���� ���� �÷��̾�� ������ ���� ���� ����
        pii warriorResult = moveWarriors(currentX, currentY, N, M);
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                cout << warriorCountGrid[i][j] << " ";
            }
            cout << endl;
        }
        // ��� ���: �̵��� ���� ��, �þ� Ŀ������, �÷��̾�� ������ ���� ��
        cout << warriorResult.first << " " << sightCoverage << " " << warriorResult.second << "\n";
    }

    return 0;
}
