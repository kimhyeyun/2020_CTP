#include<iostream>
#include<stdio.h>
using namespace std;

int main() {
	int h, m, s, h1, m1, s1, ans;
	scanf_s("%2d:%2d:%2d\n%2d:%2d:%2d", &h, &m, &s, &h1, &m1, &s1);

	int sum = h * 3600 + m * 60 + s;
	int sum1 = h1 * 3600 + m1 * 60 + s1;

	if (sum > sum1)
		ans = 86400 - sum + sum1;
	else if (sum == sum1)
		ans = 86400;
	else
		ans = sum1 - sum;

	printf("%02d:%02d:%02d", ans / 3600, ans % 3600 / 60, ans % 60);

}