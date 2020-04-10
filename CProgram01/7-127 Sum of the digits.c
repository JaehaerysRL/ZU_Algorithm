// 7-127 Sum of the digits (6分)
//Given a none-negative number, print out the sum of its digits.

//Input Format:
//A none-negative integer number.

//Output Format:
//The sum of its all digits.

//Sample Input:
//123

//Sample Output:
//6

#include <stdio.h>
int main() {
	int n, s = 0, temp;
	scanf("%d", &n);
	do
	{
		temp = n % 10;
		s += temp;
		n /= 10;
	} while (n != 0);
	printf("%d", s);
}