#include<iostream>
#include<string>
using namespace std;

int main() {
	int strComp(string, string);
	string strSort(string);
	string outPut(string);
	int findL(string, char);
	void append(string*, string);
	void printLi(string*);
	int getLength(string*);
	void getAll(string src, int start, int length, string* res, string path);
	void allSort(string* res, int length);

	//输入字符集和查找的字符。
	string src = "";
	char c;
	cin >> c;
	while ((c = getchar()) != '}') {
		if (c == ',') continue;
		src += c;
	}
	char des;
	cin >> des >> des;
	int index = findL(src, des);
	src.erase(index, 1);

	string res[1000];
	string path = "";
	path += des;
	getAll(src, 0, src.size(), res, path);
	int length = getLength(res);
	allSort(res, length);
	for (int i = 0; i < length; i++) {
		res[i] = outPut(res[i]);
	}
	printLi(res);
}

int strComp(string a, string b) {
	if (a.size() != b.size()) {
		return a.size() > b.size() ? 1 : -1;
	}
	else{
		return a.compare(b);
	}
}

string strSort(string src) {
	int n = src.size();
	for (int i = n-1; i >0; i--) {
		for (int j = 0; j < i; j++)
		{
			if (src.at(j)>src.at(j+1))
			{
				char tmp = src.at(j);
				src.at(j) = src.at(j + 1);
				src.at(j + 1) = tmp;
			}
		}
	}
	return src;
}

string outPut(string src) {
	int len = src.size();
	for (int i = 1; i < src.size(); i++)
	{
		src.insert(i, ",");
		i++;
	}
	src = "{" + src + "}";
	return src;
}

int findL(string src, char des) {
	for (int i = 0; i < src.size(); i++)
	{
		if (src.at(i) == des) {
			return i;
		}
	}
	return 0;
}

void append(string* strli, string str) {
	int i;
	for (i = 0; i < 1000; i++) {
		string cur = *(strli+i);
		if (cur.empty()) {
			break;
		}
	}
	*(strli+i) = str;
}

void printLi(string* strli) {
	for (int i = 0; i < 1000; i++) {
		string cur = *(strli+i);
		if (cur.empty()) {
			break;
		}
		cout << cur;
		if (!((*(strli + i + 1)).empty())) {
			cout<< ",";
		}
	}
}

int getLength(string* strli) {
	int res = 0;
	for (res = 0; res < 1000; res++) {
		if ((*(strli + res)).empty()) {
			break;
		}
	}
	return res;
}

void getAll(string src, int start, int length, string* res, string path) {
	string strSort(string src);
	void append(string*, string);
	if (start == length) {
		append(res, strSort(path));
		return;
	}

	string path1 = path + src.at(start);
	getAll(src, start + 1, length, res, path);
	getAll(src, start + 1, length, res, path1);
}

void allSort(string* res, int length) {
	int strComp(string a, string b);
	for (int i = length - 1; i > 0; i--) {
		for (int j = 0; j < i; j++)
		{
			if (strComp(res[j],res[j+1])==1)
			{
				string tmp = res[j];
				res[j] = res[j + 1];
				res[j + 1] = tmp;
			}
		}
	}
}