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
const int N = 5e5 + 7;

void init_code() {
#ifndef ONLINE_JUDGE
	freopen("inputf.txt", "r", stdin);
	freopen("outputf.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

/*
Given a sequence A, write a program to find the largest sum among the decreasing subsequences of that sequence.

For example, if the sequence A = {1, 100, 2, 50, 60, 8, 7, 3, 6, 5}, the decreasing subsequence with the largest sum is A = {1, 100, 2, 50 , 60 , 8 , 7 , 3, 6 , 5 }, and the sum is 186.

A = {100, 60, 8, 7, 6, 5};
*/

// go(idx + 1, idx);
// go(idx + 1, prev);

// v[idx] < v[prev] -> dp[idx][prev] = v[idx] + go(idx + 1, idx);
// always -> dp[idx][prev] = go(idx + 1, prev);
// dp[idx][prev] = max({v[idx] + go(idx + 1, idx), go(idx + 1, prev)});


// int n;
// vector<int> v;
// int go(int idx) {
//     if (idx == n) {
//         return 0;
//     }

//     // idx th -> idx + 1 = n

//     int ans = 0;
//     for (int i = idx + 1; i < n; i++) {
//         if (v[idx] > v[i]) {
//             ans = max(ans, v[i] + go(i));
//         }
//     }
//     return ans;
// }
// cin >> n;
// v.assign(n, 0);
// for (int i = 0; i < n; i++) {
//     cin >> v[i];
// }

// int ans = 0;
// for (int i = 0; i < n; i++) {
//     ans = max(ans, v[i] + go(i));
// }
// cout << ans << '\n';


/*
https://www.acmicpc.net/problem/7117
The task is to write a program that outputs the smallest possible number s for an input natural number n. The number s must have the following properties:

s ≥ n;
the value of s written in decimal form contains only digits 7, 2 and 0 and it does not start with 0;
the decimal form of s contains at most 18 digits;
the remainder of s divided by n equals 0.

n = 3 -> s = 27
n = 61 ->  s = 70272
1 <= N <= 1e5
*/

// 0 -> 7, 2
// 1 - 20 = (0, 2, 7)
// (x) -> (702 % 61 != 0)

// 123 4 -> (123 * 10 + 4);

// 70272



/*
Explain dp[i][j], what it denotes
Say whenever u write a sentence
take input first
write hints from interviewer
Time complexity lihaychi
Memory complexity
Use i, j variable name
*/



int n;
string l, r;
int arr[] = {0, 2, 7};
int dp[2][2][2][21][N];

int go(int idx, int upper, int lower, int modN, int nonZeroTaken) {
	if (idx == r.size()) {
		return modN == 0 && nonZeroTaken == 1;
	}

	int &ans = dp[nonZeroTaken][lower][upper][idx][modN];
	if (ans != -1) {
		return ans;
	}

	ans = 0;
	for (int i = 0; i < 3; i++) {
		if (upper && (arr[i] > (r[idx] - '0'))) continue;
		if (lower && (arr[i] < (l[idx] - '0'))) continue;

		int modNew = (modN * 10) + (arr[i]);
		modNew %= n;

		ans += go(idx + 1, upper && (arr[i] == (r[idx] - '0')), lower && (arr[i] == (l[idx] - '0')), modNew, nonZeroTaken || (arr[i] != 0));
	}

	return ans;
}

int solve(int L, int R) {
	memset(dp, -1, sizeof(dp));
	l = to_string(L);
	r = to_string(R);
	string temp((r.size() - l.size()), '0');
	temp += l;
	l = temp;

	// This gives total numbers from l to r which satisfies this condition
	int ans = 0;
	for (int i = 0; i < 3; i++) {
		if (arr[i] > (r[0] - '0')) continue;
		if (arr[i] < (l[0] - '0')) continue;
		int modNew = arr[i];
		modNew %= n;
		ans += go(1, arr[i] == (r[0] - '0'), arr[i] == (l[0] - '0'), modNew, arr[i] != 0);
	}

	return ans;
}

void yash()
{
	cin >> n;

	int i = n, j = 1e18;
	int res = -1;
	while (i <= j) {
		int mid = (i + j) / 2;
		if (solve(n, mid) > 0) {
			res = mid;
			j = mid - 1;
		}
		else {
			i = mid + 1;
		}
	}


	cout << res << '\n';
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