// 3_04_一元多项式的乘法与加法运算.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//设计函数分别求两个一元多项式的乘积与和。

//输入格式:
//输入分2行，每行分别先给出多项式非零项的个数，再以指数递降方式输入一个多项式非零项系数和指数（绝对值均为不超过1000的整数）。数字间以空格分隔。
//输出格式 :
//输出分2行，分别以指数递降方式输出乘积多项式以及和多项式非零项的系数和指数。数字间以空格分隔，但结尾不能有多余空格。零多项式应输出0 0。

//输入样例 :
//4 3 4 - 5 2  6 1 - 2 0
//3 5 20 - 7 4  3 1
//输出样例 :
//15 24 - 25 22 30 21 - 10 20 - 21 8 35 6 - 33 5 14 4 - 15 3 18 2 - 6 1
//5 20 - 4 4 - 5 2 9 1 - 2 0

#include <iostream>

using namespace std;

typedef struct PolyNode* Poly;
struct PolyNode {
	int coef;
	int expon;
	Poly next;
};

Poly ReadPoly() {
	int n;
	Poly L, p, t;
	cin >> n;
	L = (Poly)malloc(sizeof(struct PolyNode));
	p = L;
	for (int i = 0; i < n; i++)
	{
		t = (Poly)malloc(sizeof(struct PolyNode));
		cin >> t->coef >> t->expon;
		p->next = t;
		p = p->next;
	}
	p->next = NULL;
	return L;
}

void PrintPoly(Poly L) {
	Poly p = L->next;
	cout << p->coef << " " << p->expon;
	p = p->next;
	while (p)
	{
		cout << " " << p->coef << " " << p->expon;
		p = p->next;
	}
	cout << "\n";
}

Poly AddPoly(Poly L1, Poly L2) {
	Poly L, p, q1, q2, t;
	int tmp;
	L = (Poly)malloc(sizeof(struct PolyNode));
	p = L;
	q1 = L1->next;
	q2 = L2->next;
	if (!q1 && !q2) {
		t = (Poly)malloc(sizeof(struct PolyNode));
		t->coef = 0;
		t->expon = 0;
		p->next = t;
		p = p->next;
	}
	int sig = 0;
	while (q1 && q2)
	{
		if (q1->expon == q2->expon) {
			tmp = q1->coef + q2->coef;
			if (tmp != 0) {
				t = (Poly)malloc(sizeof(struct PolyNode));
				t->coef = tmp;
				t->expon = q1->expon;
				p->next = t;
				p = p->next;
				sig = 1;
			}
			q1 = q1->next;
			q2 = q2->next;
		}
		else if (q1->expon > q2->expon) {
			t = (Poly)malloc(sizeof(struct PolyNode));
			t->coef = q1->coef;
			t->expon = q1->expon;
			p->next = t;
			p = p->next;
			q1 = q1->next;
			sig = 1;
		}
		else {
			t = (Poly)malloc(sizeof(struct PolyNode));
			t->coef = q2->coef;
			t->expon = q2->expon;
			p->next = t;
			p = p->next;
			q2 = q2->next;
			sig = 1;
		}
	}
	if (q1) p->next = q1;
	else if (q2) p->next = q2;
	else {
		if (sig == 0){
			t = (Poly)malloc(sizeof(struct PolyNode));
			t->coef = 0;
			t->expon = 0;
			p->next = t;
			p = p->next;
		}
		p->next = NULL;
	}
	return L;
}

Poly MultPoly(Poly L1, Poly L2) {
	Poly L, p, q1, q2, t, r;
	int tmp;
	L = (Poly)malloc(sizeof(struct PolyNode));
	L->next = NULL;
	q1 = L1->next;
	q2 = L2->next;
	p = L;
	if (!q1 || !q2) {
		t = (Poly)malloc(sizeof(struct PolyNode));
		t->coef = 0;
		t->expon = 0;
		p->next = t;
		t->next = NULL;
	}
	else {
		while (q1)
		{
			while (q2)
			{
				t = (Poly)malloc(sizeof(struct PolyNode));
				t->coef = q1->coef * q2->coef;
				t->expon = q1->expon + q2->expon;
				p = L;
				int sig = 0;
				r = p->next;
				while (r)
				{
					if (t->expon > r->expon) {
						t->next = r;
						p->next = t;
						sig = 1;
						break;
					}
					else if (t->expon == r->expon) {
						r->coef += t->coef;
						if (r->coef == 0) {
							free(t);
							p->next = r->next;
							free(r);
						}
						else free(t);
						sig = 1;
						break;
					}
					else {
						p = p->next;
						r = r->next;
					}
				}
				if (sig == 0) {
					p->next = t;
					t->next = NULL;
				}
				q2 = q2->next;
			}
			q1 = q1->next;
			q2 = L2->next;
		}
	}
	return L;
}

int main()
{
	Poly L1, L2, LA, LM;
	L1 = ReadPoly();
	L2 = ReadPoly();
	LM = MultPoly(L1, L2);
	PrintPoly(LM);
	LA = AddPoly(L1, L2);
	PrintPoly(LA);
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
