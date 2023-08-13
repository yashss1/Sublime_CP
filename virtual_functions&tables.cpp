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


class Employee {
public:
	Employee() {
		cout << "Employee constructor\n";
	}
	virtual void RaiseSalary() {
		cout << "Employee Salary Raised\n";
	}
};

class Engineer: public Employee {
public:
	Engineer() {
		cout << "Engineer constructor\n";
	}

	void RaiseSalary() override {
		cout << "Engineer Salary Raised\n";
	}
};

void yash()
{
	Employee* emp = new Employee();
	emp->RaiseSalary();
	cout << '\n';

	Employee* eng = new Engineer();
	eng->RaiseSalary();
	cout << '\n';

	Engineer* eng2 = new Engineer();
	eng2->RaiseSalary();
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