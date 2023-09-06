//YashS
#include <bits/stdc++.h>
using namespace std;
#define test              int T;cin>>T;while(T--)
// #define int               long long
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

// void yash()
// {
//   // int n;
//   // printf("%d\n", 6);
//   // scanf("%d\n", &n);
//   // cout << n << '\n';

//   /*
//   int *ptr;
//   int num = 10;
//   ptr = (int *)num;
//   ptr++;
//   num = (int)ptr;
//   printf("%d\n", num);
//   */


// }

// signed main()
// {
//   init_code();
//   ios_base::sync_with_stdio(false);
//   cin.tie(0);
//   cout.tie(0);
//   // test
//   yash();
//   return 0;
// }



int main() {
	int *a = foo();
	printf("%d", *a);
}

int *foo() {
	int a = 5;
	return &a;
}
