//这个文件里可以用到的有用函数：判断两个int相乘是否溢出的方法。

#include<iostream>
using namespace std;

int main() {
	int isOverflow(int, int);
	char c;
	int x, y;
	cin >> c >> c >> x >> c >> c >> c >> y;
	if (y == 0) {
		cout << 1 << endl;
		return 0;
	}
	if (x == -1) {
		int res = y % 2 == 0 ? 1 : -1;
		cout << res << endl;
		return 0;
	}
	if (x == 1 || x==0 ||y==1) {
		cout << x << endl;
		return 0;
	}
	if (y > 31) {
		cout << -1 << endl;
		return 0;
	}

	int last = 1;
	int res = x;
	for (int i = y; i > 1; i--) {
		last = res;
		if (isOverflow(res, x)) {
			cout << -1 << endl;
		}
		res = res * x;
	}
	cout << res << endl;
	return 0;
}

int isOverflow(int a, int b) {// 判断相乘是否溢出的方法
	if (a == 0 || b == 0) {
		return 0;
	}
	if (a >= 0 && b >= 0) {
		return INT_MAX / a < b;
	}
	else if (a < 0 && b < 0) {
		return INT_MAX / a > b;
	}
	else if (a*b == INT_MIN) {
		return 0;
	}
	else {
		return a < 0 ? isOverflow(-a, b) : isOverflow(a, -b);
	}
}