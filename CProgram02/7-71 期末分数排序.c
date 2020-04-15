// 7-71 期末分数排序 (10分)
//考试结束了，全班同学的分数都出来了。老师需要对分数做一次排序，看看从高到低，分数的排列是怎样的。

//输入格式:
//第一行是一个n，表示班级同学的人数，1<=n<=500000。 第二行开始有n个分数，0<=分数<=100，分数都是整数，没有零点五分。

//输出格式:
//输出排序后的分数，按照从大到小排列，相同的分数排在一起，每两个分数之间间隔一个空格。

//输入样例:
//10
//0 60 73 60 82 90 100 18 55 84 

//输出样例:
//100 90 84 82 73 60 60 55 18 0

#include <stdio.h>

void sort ( int a[], int len );

int main(void)
{
	int n;
	scanf("%d", &n);
	int a[n];
	for ( int i=0; i<n; i++ ) {
		scanf("%d", &a[i]);
	}
	
	sort(a, n);
    printf("%d", a[n-1]);
	for ( int i=n-2; i>=0; i-- ) {
		printf(" %d", a[i]);
	}
}

void Merge(int a[], int tmpA[], int L, int R, int RightEnd) {
	int LeftEnd, tmp, numE, i;
	LeftEnd = R - 1;
	tmp = L;
	numE = RightEnd - L + 1;
	while (L<=LeftEnd && R<=RightEnd)
	{
		if (a[L] <= a[R]) tmpA[tmp++] = a[L++];
		else tmpA[tmp++] = a[R++];
	}
	while (L <= LeftEnd) tmpA[tmp++] = a[L++];
	while (R <= RightEnd) tmpA[tmp++] = a[R++];
	for (i = 0; i < numE; i++,RightEnd--)
	{
		a[RightEnd] = tmpA[RightEnd];
	}
}


void Msort(int a[], int tmpA[], int L,int RightEnd) {
	int center;
	if (L < RightEnd) {
		center = (L + RightEnd) / 2;
		Msort(a, tmpA, L, center);
		Msort(a, tmpA, center + 1, RightEnd);
		Merge(a, tmpA, L, center + 1, RightEnd);
	}
}

void sort(int a[], int len) {
	int* tmpA;
	tmpA = (int*)malloc(len * sizeof(int));
	if (tmpA != NULL) {
		Msort(a, tmpA, 0, len - 1);
		free(tmpA);
	}
}