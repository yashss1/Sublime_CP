//YashS
#include <bits/stdc++.h>
using namespace std;
#define test              int T;cin>>T;while(T--)
#define int               long long
#define pb                push_back
#define all(x)            (x).begin(),(x).end()
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define pVec(v)           for(auto e:v)cout<<e<<" ";cout<<"\n"
const int MOD = 1e9 + 7;
const int N = 1e5 + 7;

void init_code() {
#ifndef ONLINE_JUDGE
  freopen("inputf.txt", "r", stdin);
  freopen("outputf.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

int prime[5000] = {0};
void seive(int n)
{
    for (int i = 2; i <= n; i++)
    {
        if (prime[i] == 0)
        {
            for (int j = i * i; j <= n; j += i)
            {
                prime[j] = 1;
            }
        }
    }
}

void yash()
{
  int n;
  cin >> n; 

  int num;
  for(int i = n;;i++) {
  	if(prime[i] == 0) {
  		num = i;
  		break;
  	}
  }

  cout << num << '\n';
  for(int i = 0; i < n - 1; i++) {
  	cout << i + 1 << " " << i + 2 << '\n';
  }
  cout << "1 " << n << "\n";

  for(int i = 1; i <= num - n; i++) {
  	cout << i << " " << i + (n / 2) << '\n'; 
  }
}

signed main()
{
  init_code();
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  seive(4000);
  // test
  yash();
  return 0;
}