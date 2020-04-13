// 6-26 D字符串的连接函数 (5分)
//D字符串是动态分配内存的字符串，它也采用char数组来保存字符串中的字符，但是这个数组是在堆中动态分配得到的。
//本题要求编写D字符串的连接函数。
//dstr_add在s的后面加上一个字符c，返回新的字符串。 dstr_concat在this后面加上字符串that，返回新的字符串。 这两个函数的第一个参数都必须是D字符串，不能是静态数组。

//输入样例：
//123A

//输出样例：
//6-hello!
//10-hello!123A

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//	这两个函数由系统提供
char *dstr_readword();
char *dstr_create(const char *s);

char *dstr_add(char *s, char c);
char *dstr_concat(char *this, const char *that);

int main()
{
	char *s = dstr_create("hello");
	s = dstr_add(s, '!');
	printf("%lu-%s\n", strlen(s), s);
	char *t = dstr_readword();
	s = dstr_concat(s, t);
	free(t);
	printf("%lu-%s\n", strlen(s), s);
	free(s);
}

/* 请在这里填写答案 */
char* dstr_add(char* s, char c) {
	int size = strlen(s);
	s = (char*)realloc(s, (size+1) * sizeof(char));
	s[size] = c;
	s[size + 1] = '\0';
	return s;
}

char* dstr_concat(char *this,const char *that) {
	int s1 = strlen(this), s2 = strlen(that);
	int size = s1 + s2;
	this = (char*)realloc(this, (size + 1) * sizeof(char));
	for (int i = 0; i < s2; i++)
	{
		this[s1 + i] = that[i];
	}
	this[size] = '\0';
	return this;
}