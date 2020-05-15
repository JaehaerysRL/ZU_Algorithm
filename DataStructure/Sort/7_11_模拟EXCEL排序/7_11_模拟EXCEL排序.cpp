// 7_11_模拟EXCEL排序.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

typedef struct _stu* stu;
struct _stu
{
	char id[7];
	char name[9];
	int grade;
};

bool cmpId(struct _stu a, struct _stu b) {
	return strcmp(a.id, b.id) < 0;
}
bool cmpName(struct _stu a, struct _stu b) {
	if (strcmp(a.name, b.name) == 0)
		return strcmp(a.id, b.id) < 0;
	else
		return strcmp(a.name, b.name) < 0;
}
bool cmpGrade(struct _stu a, struct _stu b) {
	if (a.grade == b.grade)
		return strcmp(a.id, b.id) < 0;
	else
		return a.grade < b.grade;
}

int main()
{
	int N, C;
	cin >> N >> C;
	stu s = (stu)malloc(sizeof(struct _stu) * N);
	for (int i = 0; i < N; i++)
		cin >> s[i].id >> s[i].name >> s[i].grade;
	switch (C)
	{
	case 1:
		sort(s, s + N, cmpId); break;
	case 2:
		sort(s, s + N, cmpName); break;
	case 3:
		sort(s, s + N, cmpGrade); break;
	}
	for (int i = 0; i < N; i++)
		cout << s[i].id << " " << s[i].name << " " << s[i].grade << endl;
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
