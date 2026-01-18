#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define N1 1000
#define K 10
#define T 1
#define X 100000000

void init_code() {
#ifndef ONLINE_JUDGE
	// freopen("in6.in", "r", stdin);
	freopen("inputf.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

#define ll long long int

// nCr using inverse factorial

const ll mod = 1e9 + 7;

ll power(ll a, ll b, ll m = mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % m; a = (a * a) % m; b = b >> 1;} return res;}

ll invmod(ll a, ll m = mod) {return power(a, m - 2, m);} //For prime mod

ll mAdd(ll a, ll b, ll m = mod) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mSub(ll a, ll b, ll m = mod) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mMul(ll a, ll b, ll m = mod) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mDiv(ll a, ll b, ll m = mod) {a = a % m; b = b % m; return mMul(a, invmod(b, m), m);}

ll N = 1e6 + 1;

vector<ll> factorial (N, 1);
vector<ll> invFactorial (N, 1);

//Call this in main function
void prenCr() {
	for (ll i = 2; i < N; i++)
	{
		factorial[i] = mMul(i, factorial[i - 1]);
		invFactorial[i] = mDiv(1, factorial[i]);
	}
}

ll nCr(ll n, ll r) {
	if (r > n || r < 0) {
		return 0;
	}
	return mMul(factorial[n], mMul(invFactorial[r], invFactorial[n - r]));
}

void yash ()
{
	// init_code();
	srand(time(0));                   //IMPPPP....
	long long int t = rand() % T + 1; //Generate a random number between 1 and T.
	t = 1000;
	cout << t << endl;
	for (int tc = 0; tc < t; tc++)
	{
		long long int n = (rand() % (N1)) + 1; // 1 to N
		cout << n << '\n';
		// long long int k = (rand() % (K)) + 1;
		// cout << k << "\n";

		vector<int> v(n);
		for (int i = 0; i < n; i++) {

			long long int x = (rand() % (X)) + 1;
			v[i] = x;
		}
		for (auto it : v) {
			cout << it << " ";
		} cout << '\n';
	}
	/*-----------------------------*/
	// int t;
	// cin >> t;
	// prenCr();

	// while (t--) {
	//     ll n, k;
	//     cin >> n >> k;

	//     vector<ll> a (n);

	//     for (ll i = 0; i < n; i++)
	//     {
	//         cin >> a[i];
	//     }

	//     if (k == 0) { //removing this should not pass. Try during testing
	//         cout << factorial[n] << "\n";
	//         continue;
	//     }

	//     vector<vector<ll>> dpMinPlates (n + 1, vector<ll> (k + 1, INT_MAX));
	//     vector<vector<ll>> dpWays (n + 1, vector<ll> (k + 1));

	//     ll ansMinPlates = INT_MAX;//If n instead of INT_MAX, then this will fail when sum a[i] == k.
	//     ll ansWays = 1;//important in case when all plates are going to break

	//     dpMinPlates[0][0] = 0;
	//     dpWays[0][0] = 1;

	//     //sort(a.begin(), a.end(), greater<ll>());

	//     for (ll i = 0; i < n; i++)
	//     {
	//         for (ll j = 0; j <= k; j++)
	//         {
	//             if (j + a[i] >= k) { //Only > should not pass. Try during testing
	//                 if (dpMinPlates[i][j] + 1 == ansMinPlates) {
	//                     ansWays += dpWays[i][j];
	//                     ansWays %= mod;
	//                 }
	//                 else if (dpMinPlates[i][j] + 1 < ansMinPlates) {
	//                     ansWays = dpWays[i][j];
	//                     ansMinPlates = dpMinPlates[i][j] + 1;
	//                 }
	//             }
	//             else if (dpMinPlates[i][j] + 1 == dpMinPlates[i + 1][j + a[i]]) {
	//                 dpWays[i + 1][j + a[i]] += dpWays[i][j];
	//                 dpWays[i + 1][j + a[i]] %= mod;
	//             }
	//             else if (dpMinPlates[i][j] + 1 < dpMinPlates[i + 1][j + a[i]]) {
	//                 dpWays[i + 1][j + a[i]] = dpWays[i][j];
	//                 dpMinPlates[i + 1][j + a[i]] = dpMinPlates[i][j] + 1;
	//             }

	//             if (dpMinPlates[i][j] == dpMinPlates[i + 1][j]) {
	//                 dpWays[i + 1][j] += dpWays[i][j];
	//                 dpWays[i + 1][j] %= mod;
	//             }
	//             else if (dpMinPlates[i][j] < dpMinPlates[i + 1][j]) {
	//                 dpWays[i + 1][j] = dpWays[i][j];
	//                 dpMinPlates[i + 1][j] = dpMinPlates[i][j];
	//             }
	//         }
	//     }

	//     if (ansMinPlates == INT_MAX) { //k > sum a[i] case
	//         ansMinPlates = n;
	//     }

	//     ansWays *= factorial[ansMinPlates];//ansMinPlates instead of ansMinPlates - 1 should not pass. Try during testing
	//     ansWays %= mod;

	//     ansWays *= factorial[n - ansMinPlates];
	//     ansWays %= mod;

	//     cout << ansWays << "\n";
	// }
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
