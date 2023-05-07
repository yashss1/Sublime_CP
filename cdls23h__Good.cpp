//YashS
#include <bits/stdc++.h>
using namespace std;
#define test              int T;cin>>T;while(T--)
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

#define int int64_t
#define sz(x) (int)(x.size())
#define ALL(x) (x).begin(), (x).end()
#define F0R(i, R) for (int i = (0); i < (R); ++i)
#define FOR(i, L, R) for (int i = (L); i <= (R); ++i)

#include <complex>
const double PI = acos(-1);

namespace fft {
typedef complex<double> base;
void fft(vector<base>& v, bool inv) {
	vector<base> w(v.size());
	for (int i = 2; i <= sz(v); i <<= 1) {
		int bsz = v.size() / i;
		base ang(cos(2 * PI / i), sin(2 * PI / i));
		if (inv)
			ang = base(1, 0) / ang;
		for (int j = 0; j < bsz; j++) {
			for (int k = 0; k < i; k++) {
				w[k] = v[bsz * k + j];
			}
			base pw(1, 0);
			for (int k = 0; k < i / 2; k++) {
				base a = w[2 * k], b = w[2 * k + 1] * pw;
				v[bsz * k + j] = a + b;
				v[bsz * k + j + v.size() / 2] = a - b;
				pw *= ang;
			}
		}
	}
	if (inv) {
		for (int i = 0; i < sz(v); i++) {
			v[i] /= v.size();
		}
	}
}
vector<int> multiply(vector<int>& v, vector<int>& w) {
	vector<base> fv(v.begin(), v.end()), fw(w.begin(), w.end());
	int n = 1;
	while (n < max(sz(v), sz(w)))
		n <<= 1;
	n <<= 1;
	fv.resize(n);
	fw.resize(n);
	fft(fv, 0);
	fft(fw, 0);
	for (int i = 0; i < n; i++)
		fv[i] *= fw[i];
	fft(fv, 1);
	vector<int> ret(n);
	for (int i = 0; i < n; i++)
		ret[i] = round(fv[i].real());
	return ret;
}
} // namespace fft


int32_t main() {
	init_code();

	// for (int i = 18; i <= 19; i++) {
	// 	string infile = to_string(i) + ".in";
	// 	string outfile = to_string(i) + ".out";
	// 	freopen(infile.c_str(), "r", stdin);
	// 	freopen(outfile.c_str(), "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	if (n <= 0 || n > 100000) {
		assert(false);
	}
	vector<int> pos(2 * n + 1, 0), neg(2 * n + 1, 0);
	F0R(i, n) {
		int val;
		cin >> val;
		if (val > 0) {
			pos[i] = 1;
		} else if (val < 0) {
			neg[-i + n] = 1;
		}
		if (val == 0) {
			assert(false);
		}
	}
	vector<int> product = fft::multiply(pos, neg);
	const int MX = sz(product);
	vector<int> distance_counter(MX + 1, 0);
	F0R(dist, MX) {
		if (product[dist] > 0) {
			int d = abs(dist - n);
			distance_counter[d] += product[dist];
		}
	}
	vector<int> answer_counter(MX + 1, 0);

	FOR(k, 1, MX) {
		for (int multiple = k; multiple <= MX; multiple += k) {
			answer_counter[k] += distance_counter[multiple];
		}
	}

	int Q;
	cin >> Q;
	while (Q--) {
		int K;
		cin >> K;
		if (K == 0 || K >= n) {
			assert(false);
		}
		int answer = K <= MX ? answer_counter[K] : 0;
		cout << answer << "\n";
	}
	// }

	return 0;
}
