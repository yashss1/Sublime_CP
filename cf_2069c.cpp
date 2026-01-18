//YashS

// (WITHOUT DP BITCH - solving easy DP is not good for health)

#include <bits/stdc++.h>
using namespace std;
#define test              int T;cin>>T;while(T--)
#define int               long long
#define pb                push_back
#define all(x)            (x).begin(),(x).end()
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define pVec(v)           for(auto e:v)cout<<e<<" ";cout<<"\n"
int MOD = 998244353;
int N = 1e5 + 7;

void init_code() {
#ifndef ONLINE_JUDGE
	freopen("inputf.txt", "r", stdin);
	freopen("outputf.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

/*
1 2 3 2 1 3 2 2 3
1 2 3 4 5 6 7 8 9

- 1 - 1 - - 2 2 -


Compulsorily take that 2 on which you are right now:
so that you have atleast one 2

2: count(2)={1} {subtract one from last number as that is compulsory}

Therefore hash[] = {0}
suffSum[] = {0}

threeFront = 3
two back = 0
so totalPnc * threeFront = (2 ^ 0) * 3 = 3
1 2 3
1 2 6
1 2 9

4: count(2)={2} {subtract one from last number as that is compulsory}

Therefore hash[] = {1}
suffSum[] = {1}

threeFront = 2
two back = 1
so totalPnc * threeFront = (2 ^ 1) * 2 = 4
1 4 6
1 2 4 6
1 4 9
1 2 4 9


7: count(2)={2, 1} {subtract one from last number as that is compulsory}

Therefore hash[] = {2, 0}
suffSum[] = {2, 0}

threeFront = 1
two back = 2
so totalPnc * threeFront = (2^2 * 1) + (2^0 * 1) = 5
1 7 9
1 2 7 9
1 4 7 9
1 2 4 7 9
5 7 9


8: count(2)={2, 2} {subtract one from last number as that is compulsory}

Therefore hash[] = {2, 1}
suffSum[] = {3, 1}

threeFront = 1
two back = 3
so totalPnc * threeFront = (2^3 * 1) + (2^1 * 1) = 10
1 8 9
1 2 8 9
1 4 8 9
1 2 4 8 9
1 7 8 9
1 7 4 8 9
1 2 7 8 9
1 2 4 7 8 9
5 8 9
5 7 8 9



Example:
1 2 2 2 1 2 2 2 2 1 [2 2 2] 3
 = {3, 4, 1}
hash[] = {3, 4, 0}
suffSum[] = {7, 4, 0}
2^7 + 2^4 + 2^0 -> base
((2^3 + 1) * 2^4) + 1

 = {3, 4, 2}
hash[] = {3, 4, 1}
suffSum[] = {8, 5, 1}
2^8 + 2^5 + 2^1 = (2^1)*(2^7 + 2^4 + 2^0)

 = {3, 4, 3}
hash[] = {3, 4, 2}
suffSum[] = {9, 6, 2}
2^9 + 2^6 + 2^2 = (2^2)*(2^7 + 2^4 + 2^0)


1 2 2 2 1 2 2 2 2 1 2 2 2 3 [2 2] 3
= {3, 4, 3, 1}
hash[] = {3, 4, 3, 0}
suffSum[] = {10, 7, 3, 0}
2^10 + 2^7 + 2^3 + 2^0 -> base
((((2^3 + 1) * 2^4) + 1) * 2^3) + 1 = 2^10 + 2^7 + 2^3 + 1

*/

int fpow(int x, int y, int p = MOD) {
	x = x % p; int sum = 1; while (y) {
		if (y & 1)sum = sum * x; sum %= p; y = y >> 1; x = x * x; x %= p;
	} return sum;
}

void yash()
{
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	vector<int> threeFront(n + 1, 0);
	for (int i = n - 1; i >= 0; i--) {
		if (v[i] == 3) threeFront[i]++;
		threeFront[i] += threeFront[i + 1];
	}


	int ans = 0;
	int hash = 1, numberOfTwo = 0, oneGot = 0;
	for (int i = 0; i < n; i++) {
		if (v[i] == 1 && oneGot == 0) oneGot = 1;
		else if (v[i] == 1 && oneGot == 1) {
			hash *= fpow(2, (numberOfTwo), MOD); hash %= MOD;
			hash++; hash %= MOD;
			numberOfTwo = 0;
		} else if (v[i] == 2 && oneGot == 1) {
			int temp = (hash * fpow(2, numberOfTwo, MOD)); temp %= MOD;
			ans += (temp * threeFront[i]); ans %= MOD;
			numberOfTwo++;
		}
	}

	cout << ans << '\n';

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