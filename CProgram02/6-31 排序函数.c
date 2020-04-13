// 6-31 排序函数 (30分)
//本题不限定排序算法，所给的数据集有种情况：

//小规模（n<1000）无序数据；
//小规模（n<1000）递增数据；
//小规模（n<1000）递减数据；
//大规模（10000<n<1000000）无序数据；
//大规模（10000<n<1000000）递增数据；
//大规模（10000<n<1000000）递减数据。
//结果按照从小到大排序。数据均为32位int的全部范围。

//本题禁止使用C标准库的heapsort、heapsort_b、mergesort、mergesort_b、qsort、qsort_b和qsort_r。

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

	for ( int i=0; i<n; i++ ) {
		printf("%d\n", a[i]);
	}
}

/* 请在这里填写答案 */
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