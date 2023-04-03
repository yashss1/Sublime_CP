#include <bits/stdc++.h>

using namespace std;
#define test int T;cin >> T;while (T--)
#define int long long

void init_code() {
  #ifndef ONLINE_JUDGE
  freopen("inputf.txt", "r", stdin);
  freopen("outputf.txt", "w", stdout);
  #endif // ONLINE_JUDGE
}

// string game_winner(int n, int player, long long a, long long b, unordered_map<pair<int, int>, string>& memo) {
//     if (n <= 0) {
//         return (player == 1) ? "Sarthak" : "Pratham";
//     }
//     if (memo[{n, player}]) {
//         return memo[make_pair(n, player)];
//     }
//     if (player == 1) {
//         if (n % a == 0) {
//             string result = game_winner(n - a, 2, a, b, memo);
//             memo[make_pair(n, player)] = (result == "Pratham") ? "Pratham" : "Sarthak";
//             return memo[make_pair(n, player)];
//         } else {
//             memo[make_pair(n, player)] = "Sarthak";
//             return "Sarthak";
//         }
//     } else {
//         if (n % b == 0) {
//             string result = game_winner(n - b, 1, a, b, memo);
//             memo[make_pair(n, player)] = (result == "Pratham") ? "Pratham" : "Sarthak";
//             return memo[make_pair(n, player)];
//         } else {
//             memo[make_pair(n, player)] = "Pratham";
//             return "Pratham";
//         }
//     }
// }

void solve() {
  long long n, a, b;
  cin >> n >> a >> b;
  long long g = __gcd(a, b);
  // if (n % g != 0) {
  //   cout << "0\n";
  //   return;
  // }

  //   long long m = n / g;
  //   if (m % 2 == 0) {
  //     cout << "2\n";
  //     return;
  //   }
  //   cout << "1\n";
  b = min(a, b);
    // k mod a < b
    // k >= a
    if (n < a)
    {
      cout << "0\n";
      return;
    }
    cout << b * (n / a - 1) + min(n % a + 1, b) << '\n';
}

signed main() {
  init_code();
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  test
  solve();
  return 0;
}