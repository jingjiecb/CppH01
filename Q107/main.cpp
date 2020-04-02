#include<iostream>
#include<string>
using namespace std;

int main() {
	char c;
	string src = "";
	while ((c=getchar())!='\n')
	{
		if (c == '-') continue;
		if (c >= 0x61 && c <= 0x7A) c -= 0x20;
		src += c;
	}
	int k;
	cin >> k;

	int length = src.size();
	for (int i = length-k; i>0; i-=k)
	{
		src.insert(i, "-");
	}
	cout << src;
}