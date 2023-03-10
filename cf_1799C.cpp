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

void yash()
{
  string s;
  cin >> s;
  int n = s.size();
  map<char, int> mp;
  for(int i = 0; i < n; i++) {
  	mp[s[i]]++;
  }

  // TRY 4
  int i = 0, j = n - 1;
  string ans(n, '-');
  for(char c = 'a'; c <= 'z'; c++) {
    if(mp[c] == 0) continue;

    while(mp[c] >= 2) {
      mp[c] -= 2;
      ans[i] = c;
      ans[j] = c;
      i++, j--;
    }

    if(mp[c] == 1) {
      mp[c]--;
      if(i == j) {
        ans[i] = c;
      }
      else {
        for(char c1 = c + 1; c1 <= 'z'; c1++) {
          if(mp[c1] == 0) continue;
          if(mp[c1] == j - i) {
            while (mp[c1] >= 2) {
              mp[c1] -= 2;
              ans[i] = c1;
              ans[j] = c1;
              i++, j--;
            }
            
            if (mp[c1] == 1) {
                mp[c1] -= 1;
                ans[i] = c1;
                i++;
            }
            
            ans[j] = c; // center -> a.bbbbabbb.a
          }
          else {
            for(char c2 = c1; c2 <= 'z'; c2++) {
              while(mp[c2] >= 1) {
                mp[c2]--;
                ans[i] = c2;
                i++;
              }
            }
            ans[j] = c; // small at last
          }

          break;
        }
      }
      break;
    }
  }

  cout << ans << '\n';

  // TRY 3
  // string ans(n, '-');
  // int i = 0, j = n - 1;
  // for(char c = 'a'; c <= 'z'; c++) {
  //   if(mp[c] == 0) continue;

  //   int t = mp[c] / 2;
  //   while(i < j && t > 0) {
  //     ans[i] = c;
  //     ans[j] = c;
  //     i++, j--;
  //     t--;
  //   }

  //   if(mp[c] % 2 == 1) {
  //     ans[j] = c;

  //     for(char c1 = (char)(c + 1); c1 <= 'z'; c1++) {
  //       int t = mp[c1];
  //       while(t--) {
  //         ans[i] = c1;
  //         i++;
  //       }
  //     }
  //     break;
  //   }
  // }

  // // ULTA
  // i = 0, j = n - 1;
  // string ans1(n, '-');
  // for(char c = 'z'; c >= 'a'; c--) {
  //   if(mp[c] == 0) continue;

  //   int t = mp[c] / 2;
  //   while(i < j && t > 0) {
  //     ans1[i] = c;
  //     ans1[j] = c;
  //     i++, j--;
  //     t--;
  //   }

  //   if(mp[c] % 2 == 1) {
  //     ans1[i] = c;
  //     i++;

  //     for(char c1 = 'a'; c1 < c; c1++) {
  //       int t = mp[c1];
  //       while(t--) {
  //         ans1[i] = c1;
  //         i++;
  //       }
  //     }
  //     break;
  //   }
  // }  

  // // cout << ans << " " << ans1 << "\n";
  // cout << min(ans, ans1) << "\n";

  // TRY 2
  // if(n == 1) {
  // 	cout << s << "\n";
  // 	return;
  // }

  // int i = 0, j = n - 1;
  // string ans(n, '-');
  // vector<char> temp;

  // int flag = 1;
  // for(char c = 'a'; c <= 'z'; c++) {
  // 	if(mp[c] == 0) continue;

  //   if(temp.size() == 2) {
  //     ans[j] = temp[0];
  //     ans[i] = temp[1];
  //     j--, i++;
  //     temp.clear();
  //   }

  // 	int t = mp[c] / 2;
  //   int doo = 0;
  //   if(temp.size() == 1) {
  //     if(mp[c] == 1) {
  //       goto here;
  //     }
  //     for(char c1 = (char)(c + 1); c1 <= 'z'; c1++) {
  //       if(mp[c1] == 0) continue;
  //       if(mp[c1] / 2 > 0) {
  //         doo = 1;
  //       } 
  //     }

  //     if(doo == 0) goto here;

  //     if(flag == 1) {
  //       ans[j] = temp[0];
  //       j--;
  //     }
  //     else {
  //       ans[i] = temp[0];
  //       i++;
  //     }
  //     flag ^= 1;
  //     temp.clear();
  //   }

  //   here:

  //   if(doo == 1 && t == 1) {
  //     if(flag == 0) {
  //       ans[i] = c;
  //       ans[i + 1] = c;
  //       i += 2;
  //     }
  //     else {
  //       ans[j] = c;
  //       ans[j - 1] = c;
  //       j -= 2; 
  //     }
  //     flag ^= 1;
  //   }
  //   else {
  //     while(i < j && t > 0) {
  //       ans[i] = c;
  //       ans[j] = c;
  //       i++, j--;
  //       t--;
  //     }
  //   }

  // 	if(mp[c] % 2 == 1) {
  // 		temp.push_back(c);
  // 	}
  // }

  // // cout << ans << " -> ";
  // // pVec(temp);

  // flag = 1;
  // i = 0, j = n - 1;
  // for(int k = 0; k < temp.size(); k++) {
  //   if(flag == 1) {
  //     while(ans[j] != '-' && j >= 0) {
  //       j--;
  //     }
  //     if(j == -1) {
  //       break;
  //     }
  //     ans[j] = temp[k];
  //   }
  //   else {
  //     while(ans[i] != '-' && i < n) {
  //       i++;
  //     }
  //     if(i == n) {
  //       break;
  //     }
  //     ans[i] = temp[k];
  //   }
  //   flag ^= 1;
  // }


  // TRY 1
  // while(i < j) {
  // 	if(ans[i - 1] == ans[j + 1]) {
  // 		ans[j] = s[k];
  // 		s[k] = '-';
  // 		ans[i] = s[k + 1];
  // 		s[k + 1] = '-';
  // 		k += 2;
  // 	}
  // 	else {
  // 		if(ans[i - 1] > ans[j + 1]) {
  // 			ans[i] = s[k];
  // 			s[k] = '-';
  // 			ans[j] = s[k + 1];
  // 			s[k + 1] = '-';
  // 			k += 2;
  // 		}
  // 		else {
  // 			ans[j] = s[k];
  // 			s[k] = '-';
  // 			ans[i] = s[k + 1];
  // 			s[k + 1] = '-';
  // 			k += 2;	
  // 		}
  // 	}
  // 	i++, j--;
  // }
  // if(k <= n -1) {
  // 	ans[i] = s[k];
  // 	s[k] = '-';
  // }

  // cout << s << "||\n";
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