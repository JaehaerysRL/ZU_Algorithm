// 7-82 排序 (30分)
//本题不限定排序算法，所给的数据集有种情况：
//小规模（n<1000）无序数据；
//小规模（n<1000）递增数据；
//小规模（n<1000）递减数据；
//大规模（10000<n<1000000）无序数据；
//大规模（10000<n<1000000）递增数据；
//大规模（10000<n<1000000）递减数据。
//数据均为32位int的全部范围。

//输入
//你的程序首先会读到一个正整数n，1<=n<=1000000。然后是n个整数，每个数字一行。

//输出
//输出排序后的结果，每个数字一行。
//输入例子
//5
//1
//2
//3
//1
//4
//对应的输出
//1
//1
//2
//3
//4

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

void Qsort(int a[], int left, int right) {
    if (left >= right)/*如果左边索引大于或者等于右边的索引就代表已经整理完成一个组了*/
    {
        return;
    }
    int i = left;
    int j = right;
    int key = a[left];

    while (i < j)                               /*控制在当组内寻找一遍*/
    {
        while (i < j && key <= a[j])
            /*而寻找结束的条件就是，1，找到一个小于或者大于key的数（大于或小于取决于你想升
            序还是降序）2，没有符合条件1的，并且i与j的大小没有反转*/
        {
            j--;/*向前寻找*/
        }

        a[i] = a[j];
        /*找到一个这样的数后就把它赋给前面的被拿走的i的值（如果第一次循环且key是
        a[left]，那么就是给key）*/

        while (i < j && key >= a[i])
            /*这是i在当组内向前寻找，同上，不过注意与key的大小关系停止循环和上面相反，
            因为排序思想是把数往两边扔，所以左右两边的数大小与key的关系相反*/
        {
            i++;
        }

        a[j] = a[i];
    }

    a[i] = key;/*当在当组内找完一遍以后就把中间数key回归*/
    Qsort(a, left, i - 1);/*最后用同样的方式对分出来的左边的小组进行同上的做法*/
    Qsort(a, i + 1, right);/*用同样的方式对分出来的右边的小组进行同上的做法*/
}


void sort(int a[], int len) {
    int judge = 0;
    if (a[0] < a[1]) {
        judge = 1;
        for (int i = 1;i < 20;i++) {
            if (a[i] > a[i + 1]) {
                judge = 0;
                break;
            }
        }
    }
    else if (a[0] > a[1]) {
        judge = -1;
        for (int i = 1;i < 20;i++) {
            if (a[i] < a[i + 1]) {
                judge = 0;
                break;
            }
        }
    }
    if (judge == -1) {
        int b[len];
        for (int i = 0;i < len;i++) b[i] = a[i];
        for (int i = 0;i < len;i++) a[i] = b[len - i - 1];
    }
    else if (judge == 0)Qsort(a, 0, len - 1);
}