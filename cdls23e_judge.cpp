#include "spoj_interactive.h"
#include <bits/stdc++.h>
#define MAX 500005
long long int a[MAX], n, cnt[MAX];
using namespace std;
void verdict_wrong(int i)
{
	fprintf(spoj_for_tested, "%d\n", i);
	spoj_assert(false);
}
void finalizeIT(int score)
{
	fprintf(spoj_score, "%d", score);
}
int main()
{
	spoj_init();
	// int t;
	// fscanf(spoj_p_in, "%d", &t);
	// fprintf(spoj_for_tested, "%d\n", t);
	int t = 1;
	while (t--)
	{
		fscanf(spoj_p_in, "%lld", &n);
		fprintf(spoj_for_tested, "%lld\n", n);
		long long int querylimit = n;
		long long int i, j;
		memset(a, 0, sizeof(a));
		memset(cnt, 0, sizeof(cnt));
		for (i = 1; i <= n; i++)
		{
			fscanf(spoj_p_in, "%lld", &a[i]);
		}
		j = 0;
		bool ac = false;
		int ch;
		while (true)
		{
			j++;
			fscanf(spoj_t_out, "%d", &ch);
			if (ch != 1)
			{
				break;
			}
			if (j <= querylimit)
			{
				long long int x, y, z;
				fscanf(spoj_t_out, "%lld", &x);
				fscanf(spoj_t_out, "%lld", &y);
				if (x <= n && y <= n && x >= 1 && y >= 1)
				{
					if (a[x] > a[y]) {
						fprintf(spoj_for_tested, "%s\n", "First");
					}
					else {
						fprintf(spoj_for_tested, "%s\n", "Second");
					}
					swap(a[x], a[y]);
				}
				else
				{
					verdict_wrong(-1);
				}
			}
			else
			{
				verdict_wrong(-1);
			}
		}
		if (ch == 2)
		{
			long long int x, y, fl = 0;
			fscanf(spoj_p_out, "%lld\n", &x);
			fscanf(spoj_t_out, "%lld\n", &y);
			// cout << x << ' ' << y << endl;
			if (x == y) fl = 1;
			if (fl)
			{
				fprintf(spoj_for_tested, "%d\n", 1);
				ac = true;
			}
		}
		if (!ac)
		{
			verdict_wrong(-1);
		}
	}
	finalizeIT(1);
	return 0;
}
