#if 0
#include <bits/stdc++.h>
using namespace std;

const int MAX = 21;
int n, m, K, c; // ������ ũ��, �ڸ� ���� �Ⱓ, Ȯ�� ����, ������ �ܿ� ��
int board[MAX][MAX];	// ���� ����
int killBoard[MAX][MAX];// �������� �ִ� ��ġ
int result;		// �ڸ��� ������ �׷� ��
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int cx[2] = { 1, -1 };
int cy[2] = { 1, -1 };
typedef struct _tree {
	int val;
	int first;
	int second;
}Tree;

bool isInRange(int x, int y);
void inputData();
void printData();
void growReproduce();
int getAvailableKill(int x, int y);
void kill();

int main() {
	inputData();
	for (int i = 0; i < m; ++i) {
		growReproduce();
		kill();
        printData();
        cout << endl;
	}
	cout << result << endl;
}

void inputData() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m >> K >> c;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> board[i][j];
		}
	}
}

bool isInRange(int x, int y) {
	return (0 <= x && x < n && 0 <= y && y < n && board[x][y] != -1);
}

void printData() {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
}
// ������ �װ��� ĭ�� �� ��ŭ ������ �����Ѵ�. ������ ��� �������� ���ÿ� �Ͼ��.
// ������ �־��� �������� ������ 4���� ĭ �� ��, �ٸ� ����, ������ ��� ���� ĭ�� �����Ѵ�.
// �� ĭ�� ���� �׷� ������ �� ������ ������ ĭ�� ������ŭ �������� �׷� ����ŭ ������ �ȴ�.
// ������ ������ ��� �������� ���ÿ� �Ͼ��.
void growReproduce() {
	queue<Tree> q;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			// ĭ�� ������ �ִ��� Ȯ���Ѵ�.
			if (board[i][j] > 0) {
				int growth = 0, noneBlock = 0;
				vector<pair<int, int>> none;
				// �װ� ĭ�� ������ �ִ� �� Ȯ���Ѵ�.
				for (int k = 0; k < 4; ++k) {
					if (isInRange(i + dx[k], j + dy[k])) {
						if (board[i + dx[k]][j + dy[k]] > 0) growth++;
						else if (board[i + dx[k]][j + dy[k]] == 0 && killBoard[i+dx[k]][j+dy[k]] == 0) {
							noneBlock++;
							none.push_back({ i + dx[k], j + dy[k] });
						}
					}
				}
				board[i][j] += growth;
				// �� ĭ�� ���� �׷� ������ �� ������ ������ ĭ�� ������ŭ �������� �׷� ����ŭ ������ �ȴ�.
				if (noneBlock > 0) {
					int reproduceVal = board[i][j] / noneBlock;
					// ������ �Ǵ� �κ��� ť�� �����Ѵ�.
					for (auto n : none) {
						q.push({ reproduceVal, n.first, n.second });
					}
				}

			}
		}
	}
	// �Ѳ����� ������ �����Ѵ�.
	while (!q.empty()) {
		Tree newTree = q.front();
		q.pop();
		if (killBoard[newTree.first][newTree.second] == 0) {
			board[newTree.first][newTree.second] += newTree.val;
		}
	}
}

int getAvailableKill(int x, int y) {
	int killedTree = board[x][y];
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 2; ++j) {
			int k = 1;
			for (int k = 1; k <= K; ++k) {
				int nx = x + cx[i] * k;
				int ny = y + cy[j] * k;

				if (!isInRange(nx, ny)) break;
				if (board[nx][ny] == -1) break;
				killedTree += board[nx][ny];
				if (board[nx][ny] == 0) break;
			}
		}
	}
	return killedTree;
}

// �� ĭ ��, �������� �ѷ��� �� ������ ���� ���� �۸�Ǵ� ĭ�� �������� �Ѹ���.
// ������ ���� ĭ�� �������� �Ѹ��� �ڸ�Ǵ� ������ ���� ���� ���·� ������.
// �������� �ѷ��� ĭ���� c�� ��ŭ �������� �����ִ�.
// �������� �ѷ��� �ִ� ���� �ٽ� �Ѹ���, c�� ���� �������� ���´�.
void kill() {
	// �������� �Ѹ� ��ġ�� �����Ѵ�.
	Tree killSpot = { 0, 0, 0 };
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			// �������� ���ŵȴ�.
			killBoard[i][j] = killBoard[i][j] > 0 ? killBoard[i][j] - 1 : 0;
			int availableKill = 0;
			if (board[i][j] > 0) {
				availableKill = getAvailableKill(i, j);
				if (killSpot.val < availableKill) {
					killSpot.val = availableKill;
					killSpot.first = i; killSpot.second = j;
				}
			}
		}
	}
	// �������� �Ѹ� ��, X�ڷ� c ��ŭ�� �������� ���´�.
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 2; ++j) {
			int k = 1;
			for (int k = 1; k <= K; ++k) {
				int nx = killSpot.first + cx[i] * k;
				int ny = killSpot.second + cy[j] * k;

				if (!isInRange(nx, ny)) break;
				if (board[nx][ny] == -1) break;
				killBoard[nx][ny] = c;
				if (board[nx][ny] == 0) break;
				board[nx][ny] = 0;
				
			}
		}
	}
	board[killSpot.first][killSpot.second] = 0;
	killBoard[killSpot.first][killSpot.second] = c;
	result += killSpot.val;
}

#endif

#if 1
#include <iostream>  
#include <vector>

using namespace std;

// ���� ũ�� // �ڸ� ���� ��� //  ������Ȯ�� ���� // �����ִ� ���
int n, m, k, c;

vector<vector<int>> timeout(vector<vector<int>> v) {
    // �� �� ������ c ���� 
    // 1�� ���� ��� ���� ���� �ϱ� ���� 0 ���� ���� 
    // �̿��� ��� +1

    vector<vector<int>> temp = v;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (temp[i][j] == -2) {
                temp[i][j] = 0;
            }
            else if (temp[i][j] < -1) {
                temp[i][j]++;
            }
        }
    }

    return temp;
}

pair<vector<vector<int>>, int> drugproc(vector<vector<int>> v, int c, int k) {

    // �� ĭ �� ������ �ѷ��� �� ������ ���� ���� �ڸ� �Ǵ� ĭ�� ������
    // 4���� �밢�� �������� kĭ ��ŭ ����
    // c�� ���� ������ ����

    vector<vector<int>> temp = v;
    int del_num = 0;
    int max_del = 0, max_x = 0, max_y = 0;

    // �밢������ ������ -c    

    //���� ���� ���� ����
    int dx[4] = { -1, 1, -1, 1 };
    int dy[4] = { -1, -1, 1, 1 };

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (v[i][j] <= 0) continue;

            int cur_del = v[i][j];

            for (int dir = 0; dir < 4; dir++) {
                for (int step = 1; step <= k; step++) {
                    int nx = i + dx[dir] * step;
                    int ny = j + dy[dir] * step;
                    if (nx < 0 || ny < 0 || nx >= n || ny >= n) break;
                    if (v[nx][ny] == -1) break;

                    cur_del += v[nx][ny];

                    if (v[nx][ny] == 0) {
                        break;
                    }
                }
            }

            if (cur_del > max_del) {
                max_del = cur_del;
                max_x = i;
                max_y = j;
            }
        }
    }

    // ������ �Ѹ���
    if (v[max_x][max_y] > 0) {
        del_num += v[max_x][max_y];
        temp[max_x][max_y] = -c - 2;
    }

    for (int dir = 0; dir < 4; dir++) {
        for (int step = 1; step <= k; step++) {
            int nx = max_x + dx[dir] * step;
            int ny = max_y + dy[dir] * step;

            if (nx < 0 || ny < 0 || nx >= n || ny >= n) break;

            if (v[nx][ny] == 0) {
                temp[nx][ny] = -c-2;
                break;
            }

            if (v[nx][ny] == -1) break;

            del_num += v[nx][ny];
            temp[nx][ny] = -c-2;
        }
    }

    return { temp, del_num };
}


vector<vector<int>> addproc(vector<vector<int>> v) {
    // cout << "addproc!!" << '\n';
    // ���� ��ĭ �� ������ �ִ� ĭ ����ŭ 
    // �� ���� ������ �� ���� ��� ĭ�� ���� �� 
    // ���� ������ ĭ�� ������ŭ �������� �׷� �� ��ŭ ����
    // �������� ���� 
    vector<vector<int>> temp = v;

    // �� �� �� ��
    int dx[4] = { -1, 1, 0, 0 };
    int dy[4] = { 0, 0, -1, 1 };
    int num = 0;
    int treenum = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            num = 0;
            treenum = 0;
            if (v[i][j] > 0) {
                for (int dir = 0; dir < 4; dir++) {
                    int nx = i + dx[dir];
                    int ny = j + dy[dir];

                    if (nx >= 0 && ny >= 0 && nx < n && ny < n && v[nx][ny] == 0) {
                        num++;
                    }
                    if (nx >= 0 && ny >= 0 && nx < n && ny < n && v[nx][ny] > 0) {
                        treenum++;
                    }
                }

                temp[i][j] += treenum;
                if (num == 0) {
                    continue;
                }
                else {
                    int spread = temp[i][j] / num;


                    for (int dir = 0; dir < 4; dir++) {
                        int nx = i + dx[dir];
                        int ny = j + dy[dir];

                        if (nx >= 0 && ny >= 0 && nx < n && ny < n && v[nx][ny] == 0) {
                            temp[nx][ny] += spread;
                        }
                    }
                }

            }
        }
    }

    return temp;
}

// ��ĭ 0 // �� -1 // ������  1 �̻� 100 ����
int main(void) {

    int result = 0;
    cin >> n >> m >> k >> c;

    // vector <vector <int>> v;
    vector<vector<int>> v(n, vector<int>(n)); // ���� ũ�� �����ؼ� �ʱ�ȭ

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> v[i][j];
        }
    }

    while (m--) {
        // cout << "while!!" << '\n';
        v = addproc(v);

         cout << m << '\n';
         for(int i=0; i<n; i++){
             for(int j=0; j<n; j++){
                 cout << v[i][j] << ' ';
             }
             cout << '\n';
         }

        auto res = drugproc(v, c, k);
        v = res.first;



        // cout << m << '\n';
        // for(int i=0; i<n; i++){
        //     for(int j=0; j<n; j++){
        //         cout << v[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }
        // ������ c ����
        // -1 ���� ������ +1.. ��� ���� 
        v = timeout(v);

        // cout << m << '\n';
        // for(int i=0; i<n; i++){
        //     for(int j=0; j<n; j++){
        //         cout << v[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }
        result += res.second;
    }



    cout << result << '\n';

    return 0;
}


#endif