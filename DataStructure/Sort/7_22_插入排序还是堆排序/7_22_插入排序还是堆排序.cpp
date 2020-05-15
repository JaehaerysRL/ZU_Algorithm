// 7_22_插入排序还是堆排序.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <algorithm>
#define maxn 111
using namespace std;

int origin[maxn], tempOri[maxn], changed[maxn];
int n;
bool flag;

bool isSame(int a[], int b[]) {
	for (int i = 1; i <= n; i++) {
		if (a[i] != b[i])
			return false;
	}
	return true;
}

void showArray(int a[]) {
	for (int i = 1; i <= n; i++) {
		printf("%d", a[i]);
		if (i < n)
			printf(" ");
	}
}

bool insertSort() {
	flag = false;
	for (int i = 2; i <= n; i++) {
		if (i != 2 && isSame(tempOri, changed)) {
			flag = true;
		}
		sort(tempOri + 1, tempOri + i + 1);
		if (flag == true) {
			return true;
		}
	}
	return false;
}

void downAdjust(int low, int high) {
	int i = low, j = low * 2;   //调整节点，左孩子
	while (j <= high) {           //如果存在左孩子
		if (j + 1 <= high && tempOri[j + 1] > tempOri[j]) {  //如果存在右孩子，且值大于左孩子
			j = j + 1;
		}
		if (tempOri[j] > tempOri[i]) {      //如果孩子节点最大值大于要调整的节点
			swap(tempOri[i], tempOri[j]);
			i = j;
			j = j * 2;
		}
		else
			break;
	}
}

void createHeap() {
	for (int i = n / 2; i >= 1; i--) {
		downAdjust(i, n);
	}
}

void heapSort() {
	createHeap();
	bool flag = false;
	for (int i = n; i > 1; i--) {
		if (i != n && isSame(tempOri, changed)) {
			flag = true;
		}
		swap(tempOri[i], tempOri[1]);
		downAdjust(1, i - 1);
		if (flag == true) {
			showArray(tempOri);
			return;
		}
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &origin[i]);
		tempOri[i] = origin[i];
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &changed[i]);
	}
	if (insertSort()) {
		printf("Insertion Sort\n");
		showArray(tempOri);
	}
	else {
		printf("Heap Sort\n");
		for (int i = 1; i <= n; i++) {
			tempOri[i] = origin[i];
		}
		heapSort();
	}
	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
