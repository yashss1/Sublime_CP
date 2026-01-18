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

	// n is always odd

	int n;
	cin >> n;


	// remember stars always start from 1 and goes to n, and with each row we have 2 stars extra
	// means there always will be odd number of stars in each row
	for (int i = 1; i <= n; i += 2) {
		// find how many spaces u want
		// for n you need 0 spaces
		// for n - 2 (that is row before it) you need 1 space
		// for n - 4 (more previous row) you need 2 spaces

		int spaces = (n - i) / 2;

		// print spaces
		for (int j = 0; j < spaces; j++) {
			cout << " ";
		}

		// print i stars
		for (int j = 0; j < i; j++) {
			cout << "*";
		}
		cout << "\n";
	}

	// now decrease value of stars by 2 for each row
	for (int i = n - 2; i >= 1; i -= 2) {
		// find how many spaces u want
		// for n you need 0 spaces
		// for n - 2 (that is row before it) you need 1 space
		// for n - 4 (more previous row) you need 2 spaces

		int spaces = (n - i) / 2;

		// print spaces
		for (int j = 0; j < spaces; j++) {
			cout << " ";
		}

		// print i stars
		for (int j = 0; j < i; j++) {
			cout << "*";
		}
		cout << "\n";
	}

	cout << "___________________\n";

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

/*


 *
***
 *


  *
 ***
*****
 ***
  *


*/