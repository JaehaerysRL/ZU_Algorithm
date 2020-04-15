// 7-81 Least Prefix (10分)
//Given a non-empty array of N integers A, please find the smallest integer P such that all the numbers in A are in the subarray A[0..P].

//Input Format:
//A positive number N, followed by a list of N non-negative integers less than 1000000. N is no larger than 1000000.

//Output Format:
//The smallest integer P.

//Sample Input:
//5
//2 2 1 0 1
 
//Sample Output:
//3

#include <stdio.h>

int main()
{
	int n, t, m = 0;
	scanf("%d", &n);
	int num[1000000] = {0};
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &t);
		if (num[t] == 0) {
			if (i > m) m = i;
			num[t] = 1;
		}
	}
	printf("%d", m);
}
