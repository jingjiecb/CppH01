#include<iostream>
using namespace std;

int main() {
	int isRun(int);

	int oyear[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int ryear[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };

	int y, m, d;
	char c;
	cin >> y >> c >> m >> c >> d;

	if (m > 12 || m <= 0) {
		cout << -1 << endl;
		return 0;
	}
	int res = 0;
	if (isRun(y))
	{
		for (int i = 0; i < m - 1; i++) {
			res += ryear[i];
		}
		if (d <= ryear[m - 1] && d>0) {
			res += d;
		}
		else
		{
			res = -1;
		}
	}
	else
	{
		for (int i = 0; i < m - 1; i++) {
			res += oyear[i];
		}
		if (d <= oyear[m - 1] && d>0) {
			res += d;
		}
		else
		{
			res = -1;
		}
	}

	cout << res << endl;
}

int isRun(int year) {
	if (year%100==0)
	{
		if (year % 400 == 0) {
			return 1;
		}
		return 0;
	}
	if (year%4==0)
	{
		return 1;
	}
	return 0;
}