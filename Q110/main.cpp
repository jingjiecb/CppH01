#include<iostream>
using namespace std;

int main() {
	void intliSort(int* nums, int n);

	int n;
	cin >> n;
	int ps[26] = {0};
	int res[26] = {0};
	char c;
	for (int i = 0; i < n+1; i++)
	{
		c = getchar();
		while (c != '\n') {
			if (c >= 0x41 && c <= 0x5A) c += 0x20;
			if (c >= 0x61 && c <= 0x7A) {
				ps[c - 0x61]++;
			}
			c = getchar();
		}
	}

	int counter = 0;
	for (int i = 0; i < 26; i++)
	{
		if (ps[i] != 0) {
			res[counter] = ps[i];
			counter++;
		}
	}

	if (counter == 0) {
		cout << "[]" << endl;
		return 0;
	}

	intliSort(res, counter);
	cout << '[';
	for (int i = 0; i < counter-1; i++)
	{
		cout << res[i] << ',';
	}
	cout << res[counter - 1] << ']' << endl;
}

void intliSort(int* nums,int n) {
	for (int i = n - 1; i > 0; i--) {
		for (int j = 0; j < i; j++)
		{
			if (nums[j] > nums[j + 1])
			{
				int tmp = nums[j];
				nums[j] = nums[j + 1];
				nums[j + 1] = tmp;
			}
		}
	}
}