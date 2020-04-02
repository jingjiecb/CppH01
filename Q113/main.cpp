#include<iostream>
using namespace std;

int main() {
	int num;
	cin >> num;
	int res = 0;
	switch (num)
	{
	case(1):res++; cout << res << endl; return 0;
	case(2):res += 2; cout << res << endl; return 0;
	case(3):res += 6; cout << res << endl; return 0;
	default:
		break;
	}

	res = int(num*(num - 1) / (num - 2)) + num - 3;
	num -= 4;
	while (num>=4)
	{
		res -= (int(num*(num - 1) / (num - 2)) - num + 3);
		num -= 4;
	}

	switch (num)
	{
	case(1):res--; break;
	case(2):res -= 2; break;
	case(3):res -= 6; break;
	default:
		break;
	}

	cout << res << endl;
}