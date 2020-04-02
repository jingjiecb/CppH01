#include<iostream>
#include<math.h>
using namespace std;

int main() {
	int isPrime(int);
	char c;
	int begin, end;
	cin >> c >> begin >> end >> c;
	int res = 0;
	for (int i = begin; i <= end; i++) {
		if (isPrime(i))
		{
			res+=i;
		}
	}
	cout << res << endl;
}

int isPrime(int a) {
	if (a == 1) return 0;
	int s = int(sqrt(a));
	for (int i = 2; i <= s; i++)
	{
		if (a%i == 0) {
			return 0;
		}
	}
	return 1;
}