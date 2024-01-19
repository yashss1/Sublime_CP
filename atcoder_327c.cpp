//YashS
#include <bits/stdc++.h>
using namespace std;
#define test              int T;cin>>T;while(T--)
#define int               long long
#define pb                push_back
#define all(x)            (x).begin(),(x).end()
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define pVec(v)           for(auto e:v)cout<<e<<" ";cout<<"\n"
int MOD = 1e9 + 7;
int N = 1e5 + 7;

void init_code() {
#ifndef ONLINE_JUDGE
	freopen("inputf.txt", "r", stdin);
	freopen("outputf.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

// https://www.geeksforgeeks.org/check-if-given-sudoku-solution-is-valid-or-not/
bool isValidSudoku(vector<vector<int>> &board) {
	unordered_set<int> rows[9], cols[9], subgrids[9];
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			int num = board[i][j];
			if (num == 0) continue; // Skip empty cells

			int subgrid_index = (i / 3) * 3 + j / 3; // Get sub-grid index

			if (rows[i].count(num) || cols[j].count(num) || subgrids[subgrid_index].count(num))
				return false;
			rows[i].insert(num);
			cols[j].insert(num);
			subgrids[subgrid_index].insert(num);
		}
	}
	return true;
}


void yash()
{
	vector<vector<int>> v(9, vector<int>(9));
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> v[i][j];
		}
	}

	vector<int> want = {1, 2, 3, 4, 5, 6, 7, 8 , 9};
	// for (int i = 0; i < 9; i++) {
	// 	vector<int>temp;
	// 	for (int j = 0; j < 9; j++) {
	// 		temp.push_back(v[i][j]);
	// 	}
	// 	sort(temp.begin(), temp.end());
	// 	if (temp != want) {
	// 		cout << "No\n";
	// 		return;
	// 	}
	// }
	// for (int i = 0; i < 9; i++) {
	// 	vector<int>temp;
	// 	for (int j = 0; j < 9; j++) {
	// 		temp.push_back(v[j][i]);
	// 	}
	// 	sort(temp.begin(), temp.end());
	// 	if (temp != want) {
	// 		cout << "No\n";
	// 		return;
	// 	}
	// }

	if (isValidSudoku(v)) {
		cout << "Yes\n";
		return;
	}
	cout << "No\n";
}

signed main()
{
	init_code();
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	// test
	yash();
	return 0;
}