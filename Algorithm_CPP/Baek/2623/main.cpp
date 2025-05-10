#include<bits/stdc++.h>
using namespace std;

// 가수의 수 N, 보조 PD의 수 M
int N, M, S;
vector<vector<int>> singers;


void inputData();
bool checkCombi(vector<int> singerList);
void solution();


int main()
{
	inputData();
	solution();
	return 0;
}

void inputData()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	singers.resize(M);
	for (int m = 0; m < M; ++m)
	{
		cin >> S;
		singers[m].resize(S);
		for (int s = 0; s < S; ++s)
		{
			cin >> singers[m][s];
		}
	}
}

bool checkCombi(vector<int> singerList)
{
	vector<int> position(N + 1);
	for (int i = 0; i < N; ++i)
	{
		position[singerList[i]] = i;
	}

	for (const auto& seq : singers)
	{
		for (int i = 0; i < seq.size() - 1; ++i)
		{
			int before = seq[i];
			int after = seq[i + 1];
			if (position[before] >= position[after])
			{
				return false;
			}
		}
	}

	return true;
}

void solution()
{
	vector<int> singerList;
	for (int i = 1; i <= N; ++i)
	{
		singerList.push_back(i);
	}
	do
	{
		if (checkCombi(singerList))
		{
			for (auto s : singerList)
			{
				cout << s << "\n";
			}
			return;
		}
	} while (next_permutation(singerList.begin(), singerList.end()));
}