// 7_24_PAT排名汇总.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <cstring>
#include <algorithm>
#define MAXT 30000
using namespace std;

struct student {
	char num[20];
	int grade;
	int kaoDianNum;
	int kaoDianPaiMing;
	int AllPaiming;
}s[MAXT];
int compare(student a, student b) {  //排序 
	if (a.grade == b.grade) {
		return strcmp(a.num, b.num) < 0;
	}
	return a.grade > b.grade;
}
int main() {
	int N, K, num = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &K);
		for (int j = num; j < num + K; j++) {
			scanf("%s %d", &s[j].num, &s[j].grade);
			s[j].kaoDianNum = i + 1;
		}
		sort(s + num, s + num + K, compare);
		int paiming = 1;
		s[num].kaoDianPaiMing = paiming;
		for (int l = num + 1; l < num + K; l++) {
			paiming++;
			if (s[l].grade == s[l - 1].grade) s[l].kaoDianPaiMing = s[l - 1].kaoDianPaiMing;
			else s[l].kaoDianPaiMing = paiming;
		}
		num += K;
	}
	sort(s, s + num, compare);
	int paiming = 1;
	s[0].AllPaiming = paiming;
	for (int l = 1; l < num; l++) {
		paiming++;
		if (s[l].grade == s[l - 1].grade) s[l].AllPaiming = s[l - 1].AllPaiming;
		else s[l].AllPaiming = paiming;
	}
	printf("%d\n", num);
	for (int i = 0; i < num; i++) {
		printf("%s %d %d %d\n", s[i].num, s[i].AllPaiming, s[i].kaoDianNum, s[i].kaoDianPaiMing);
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
