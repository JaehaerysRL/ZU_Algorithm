// 7-2 Have Fun with Numbers (20分)
//Notice that the number 123456789 is a 9-digit number consisting exactly the numbers from 1 to 9, with no duplication. Double it we will obtain 246913578, which happens to be another 9-digit number consisting exactly the numbers from 1 to 9, only in a different permutation. Check to see the result if we double it again!

//Now you are suppose to check if there are more numbers with this property. That is, double a given number with k digits, you are to tell if the resulting number consists of only a permutation of the digits in the original number.

//Input Specification:
//Each input contains one test case. Each case contains one positive integer with no more than 20 digits.

//Output Specification:
//For each test case, first print in a line "Yes" if doubling the input number gives a number that consists of only a permutation of the digits in the original number, or "No" if not. Then in the next line, print the doubled number.

//Sample Input:
//1234567899

//Sample Output:
//Yes
//2469135798

#include <stdio.h>
#include <string.h>
int main() {
	char in[21];
	char out[21];
	gets(in);
	int judge = 1, temp, m = 0, fit = 1, leng;
	leng = strlen(in);
	if ((in[0]-'0')>=5)
	{
		out[0] = '1';
		judge = 0;
	}
	for (int i = leng-1; i >= 0; i--)
	{
		if ((in[i] - '0') >= 5) {
			temp = (in[i] - '0') * 2 % 10 + m;
			out[i + 1] = '0' + temp;
			m = 1;
		}
		else {
			temp = (in[i] - '0') * 2 + m;
			out[i + 1] = '0' + temp;
			m = 0;
		}
	}
	for (int i = 1; i <= leng; i++)
	{
		for (int j = 0; j < leng; j++)
		{
			if (out[i]==in[j]) {
				in[j] = 'a';
				break;
			}
		}
	}
	for (int i = 0; i < leng; i++)
	{
		if (in[i] != 'a') {
			fit = 0;
			break;
		}
	}
	if (fit == 0) printf("No\n");
	else printf("Yes\n");
	if (judge == 0) {
		for (int i = 0; i <= leng; i++) printf("%c", out[i]);
	}
	else {
		for (int i = 1; i <= leng; i++) printf("%c", out[i]);
	}
}