#include<iostream>
using namespace std;

int main() {
	int num;
	cin >> num;
	int res = 0;
	while (num!=0)
	{
		if (num%2!=0)
		{
			res += 1;
		}
		num >>= 1;
	}
	cout << res;
}