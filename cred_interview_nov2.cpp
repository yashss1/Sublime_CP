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

vector<int> spiralQuestionAntiClockwise(vector<vector<int>> &matrix) {
	int m = matrix.size();
	int n = matrix[0].size();

	int top = 0, bottom = m - 1, left = 0, right = n - 1;

	int currX = 0, currY = 0;
	vector<int> ans;

	while (top <= bottom && left <= right) {

		// down
		for (currY = top; currY <= bottom; currY++) {
			// cout << currY << " " << currX << '\n';
			ans.push_back(matrix[currY][currX]);
		}
		currY--;

		// right
		for (currX = left + 1; currX <= right; currX++) {
			// cout << currY << " " << currX << '\n';
			ans.push_back(matrix[currY][currX]);
		}
		currX--;


		// up
		for (currY = bottom - 1; currY >= top; currY--) {
			// cout << currY << " " << currX << '\n';
			ans.push_back(matrix[currY][currX]);
		}
		currY++;


		//left
		for (currX = right - 1; currX >= left + 1; currX--) {
			// cout << currY << " " << currX << '\n';
			ans.push_back(matrix[currY][currX]);
		}
		currX++;



		top++;
		bottom--;
		right--;
		left++;
	}
	return ans;
}

string reverseTheString(string s) {
	int n = s.size();

	vector<string> words;
	string curr = "";
	for (int index = 0; index < n; index++) {
		if (s[index] == ' ') {
			if (curr.size() > 0) {
				words.push_back(curr);
			}
			curr = "";
		}
		else {
			curr.push_back(s[index]);
		}
	}
	if (curr.size() > 0) {
		words.push_back(curr);
	}



	reverse(words.begin(), words.end());

	string ansString;
	for (auto it : words) {
		ansString += it;
		ansString.push_back(' ');
	}
	ansString.pop_back();

	return ansString;
}


void yash()
{
	// int n, m;
	// cin >> n >> m;
	// vector<vector<int>> matrix(n, vector<int>(m));
	// for (int i = 0; i < n; i++) {
	//     for (int j = 0; j < m; j++) {
	//         cin >> matrix[i][j];
	//     }
	// }


	// vector<int> spiralOrder = spiralQuestion(matrix);

	// for (auto it : spiralOrder) {
	//     cout << it << " ";
	// }
	// cout << '\n';

	string s;
	getline(cin, s);
	string reversedString = reverseTheString(s);

	cout << reversedString << '\n';

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