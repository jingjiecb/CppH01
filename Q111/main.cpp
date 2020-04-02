#include<iostream>
#include<math.h>
using namespace std;

int main() {
	char c;
	int x1, y1, x2, y2, x3, y3;
	cin >> c >> x1 >> c >> y1 >> c >> x2 >> c >> y2 >> c >> x3 >> c >> y3 >> c;
	double s1, s2, s3;
	s1 = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
	s2 = sqrt(pow((x3 - x2), 2) + pow((y3 - y2), 2));
	s3 = sqrt(pow((x1 - x3), 2) + pow((y1 - y3), 2));
	int isORT = 0, isOIT = 0;
	if ((s1 + s2 <= s3) || (s2 + s3 <= s1) || (s1 + s3 <= s2)) {
		cout << "NT" << endl;
		return 0;
	}
	if (fabs(pow(s1,2)+pow(s2,2)-pow(s3,2))<0.000001 || fabs(pow(s3, 2) + pow(s2, 2) - pow(s1, 2))<0.000001 || fabs(pow(s1, 2) + pow(s3, 2) - pow(s2, 2))<0.000001)
	{
		isORT = 1;
	}
	if (fabs(s1-s2)<0.000001 || fabs(s3 - s2) < 0.000001 || fabs(s1 - s3) < 0.000001) {
		isOIT = 2;
	}

	int res = isOIT + isORT;
	switch (res)
	{
	case(1):cout << "ORT" << endl; break;
	case(2):cout << "OIT" << endl; break;
	case(3):cout << "LRT" << endl; break;
	default:cout << "OT" << endl; break;
	}
	return 0;
}