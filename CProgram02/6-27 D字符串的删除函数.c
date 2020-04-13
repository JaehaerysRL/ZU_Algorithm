// 6-27 D字符串的删除函数 (5分)
//D字符串是动态分配内存的字符串，它也采用char数组来保存字符串中的字符，但是这个数组是在堆中动态分配得到的。
//本题要求编写D字符串的字符删除函数。
//dstr_remove删除s在index位置上的字符，返回新的字符串。index从0开始。

//输入样例：
//123A

//输出样例：
//6-hello!
//5-ello!
//8-ello123A

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//	这4个函数由系统提供
char *dstr_readword();
char *dstr_create(const char *s);
char *dstr_add(char *s, char c);
char *dstr_concat(char *this, const char *that);

char *dstr_remove(char *s, int index);

int main()
{
	char *s = dstr_create("hello");
	s = dstr_add(s, '!');
	printf("%lu-%s\n", strlen(s), s);
	s = dstr_remove(s,0);
	printf("%lu-%s\n", strlen(s), s);
	char *t = dstr_readword();
	s = dstr_remove(dstr_concat(s, t), strlen("hello")-1);
	free(t);
	printf("%lu-%s\n", strlen(s), s);
	free(s);
}

/* 请在这里填写答案 */
char* dstr_remove(char* s, int index) {
	int size = strlen(s);
	for (int i = index; i < size-1; i++)
	{
		s[i] = s[i + 1];
	}
    s[size-1]=0;
	return s;
}