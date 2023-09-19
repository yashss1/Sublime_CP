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




/*
Print the lexicographically smallest string, if the difference between occurences of each letter from a and b is <= 3,
else print -1;

INPUT:
7
abcdoom abaaamm

OUTPUT:
abaaamm

*/

void yash()
{
	int n;
	cin >> n;
	string a, b;
	cin >> a >> b;

	map<int, int> A, B;
	for (int i = 0; i < n; i++) {
		A[a[i] - 'a']++;
	}
	for (int i = 0; i < n; i++) {
		B[b[i] - 'a']++;
	}

	int flag = 0;
	for (int i = 0; i < 26; i++) {
		if (abs(A[i] - B[i]) > 3) {
			flag = 1;
			break;
		}
	}

	if (flag == 1) {
		cout << "-1\n";
	}
	else {
		cout << min(a, b) << '\n';
	}
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