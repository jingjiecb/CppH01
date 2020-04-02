#include<iostream>
#include<string>

using namespace std;

int main() {
	int getValue(string);

	int res = 0;
	string cur="";
	char c;
	while (cin>>cur) {
		int now = getValue(cur);
		if (now > res) {
			res = now;
		}
		char ch = getchar();// cin�����հ��ַ�ֹͣ�����һ�ѿհ��ַ������������С���������ͨ��getchar�ķ���֪������Ľ�����
		if (ch == '\n') break;
	}
	cout << res << endl;
	return 0;
}

int getValue(string src) {
	int getNumV(char);
	int len = src.size();
	int res = 0;
	int cter = 0;
	int cur = 0, last = 0;
	for (cter = 0; cter < len; cter++) {
		last = cur;
		cur = getNumV(src.at(cter));
		res += cur;
		int sum = last + cur;
		if ((sum == 6 || sum == 11 || sum == 60 || sum == 110 || sum == 600 || sum == 1100) && last<cur) {
			res -= 2 * last;
		}
	}
	return res;
}

int getNumV(char c) {
	int res = 0;
	switch (c)
	{
	case('I'): res = 1; break;
	case('V'):res = 5; break;
	case('X'):res = 10; break;
	case('L'):res = 50; break;
	case('C'):res = 100; break;
	case('D'):res = 500; break;
	case('M'):res = 1000; break;
	default: res = 0;
		break;
	}
	return res;
}