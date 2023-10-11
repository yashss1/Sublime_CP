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

void yash()
{
	string s;
	cin >> s;
	int pos;
	cin >> pos;

	int n = s.size();

	vector<int> temp;
	int prev = 0;
	for (int i = n; i >= 1; i--) {
		temp.push_back(i + prev);
		prev = temp[temp.size() - 1];
	}
	// pVec(temp);

	// for (int i = 1; i < n; i++) {
	// 	if (s[i - 1] > s[i]) {
	// 		dips++;
	// 	}
	// }

	int atOperation = 0;
	for (int i = 0; i < temp.size(); i++) {
		if (temp[i] >= pos) {
			atOperation = i;
			break;
		}
	}

	// cout << atOperation << '\n';

	if (atOperation == 0) {
		cout << s[pos - 1];
		return;
	}

	stack<char> st;
	// st.push(s[0]);

	int idx2 = 0;

	int dips = s.size();

	int i = 0;
	for (; i < n;) {

		while (!st.empty() && st.top() > s[i]) {
			if (dips >= pos) {
				break;
			}
			st.pop();
			// if (dips == atOperation) {
			// 	idx2 = i;
			// 	break;
			// }
			pos -= dips;
			dips--;
		}
		if (dips >= pos) {
			break;
		}
		st.push(s[i]);
		i++;
		idx2++;
	}

	// cout << remm << '\n';

	while (!st.empty() && dips < pos) {
		pos -= dips;
		dips--;
		st.pop();
	}
	while (idx2 < n) {
		st.push(s[idx2]);
		idx2++;
	}

	string tempS = "";
	while (!st.empty()) {
		tempS.push_back(st.top());
		st.pop();
	}
	reverse(all(tempS));
	for (int i = idx2 + 1; i < n; i++) {
		tempS.push_back(s[i]);
	}

	// cout << tempS << '\n';

	int idxWant = (pos);
	// cout << idxWant << "\n";
	cout << tempS[idxWant - 1];
}

signed main()
{
	init_code();
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	test
	yash();
	return 0;
}