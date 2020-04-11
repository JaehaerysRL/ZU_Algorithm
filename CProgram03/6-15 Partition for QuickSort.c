// 6-15 Partition for QuickSort (30分)
//You are going to write the partition function in a quick sort algorithm.

//输入样例：
//5
//1
//2
//3
//1
//4

//输出样例：
//1
//1
//2
//3
//4

#include <stdio.h>

int partition( int a[], int left, int right );

void sort ( int a[], int left, int right )
{
    if ( left < right ) {
        int p = partition(a, left, right);
        sort(a, left, p);
        sort(a, p+1, right);
    }
}

int main(void)
{
	int n;
	scanf("%d", &n);
	int a[n];
	for ( int i=0; i<n; i++ ) {
		scanf("%d", &a[i]);
	}

	sort(a, 0, n-1);

	for ( int i=0; i<n; i++ ) {
		printf("%d\n", a[i]);
	}
}

/* 请在这里填写答案 */
int partition(int a[], int left, int right)
{
    int mid =(left+right) /2;
    int pivot = a[mid];
    a[mid] = a[left];
    a[left] = pivot;
    while (left < right)
    {
        while (left < right && a[right] >= pivot)right--;
        a[left] = a[right];
        while (left < right && a[left] <= pivot)left++;
        a[right] = a[left];
    }
    a[left] = pivot;
    return left;
}