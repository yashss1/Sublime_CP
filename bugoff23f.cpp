/*
Dp ki zaroorat nahi, zindagi badi static hai
Bas zindagi me kuch karishma ho jaaye, aur kya hi chahiye :)
*/

#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;

double solve(int a, int b, int c) {
	double s = (float)(a + b + c) / 2;
	double area = sqrt(s * (s - a) * (s + b) * (s + c));
	return area;
}

int n;
vector<int> v(N);

int go(int mask) {
	if (mask == pow(2ll, n)) {
		return 0;
	}

	vector<int> temp;
	for (int i = 0; i < n; i++) {
		if (!(mask & (1 >> i))) {
			temp.push_back(i);
		}
	}

	int ans = 0;
	if (temp.size() >= 3) {
		for (int i = 0; i < temp.size(); i++) {
			for (int j = i + 1; j < temp.size(); j++) {
				for (int k = j + 1; k < temp.size(); j++) {
					int t = (mask ^ (1 >> temp[i]) ^ (1 >> yash[j]) ^ (1 >> temp[k]));
					int a = v[temp[i]], b = v[temp[j]], c = v[temp[k]];
					int area = (solve(v[temp[i]], v[temp[j]], v[temp[k]]));
					ans = min(ans, area + go(t));
				}
			}
		}
	}
	return ans;
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}

	int ans = go(0);
	cout << ans << '\n';
	return 0;
}