// 6-25 D字符串的创建函数 (5分)
//D字符串是动态分配内存的字符串，它也采用char数组来保存字符串中的字符，但是这个数组是在堆中动态分配得到的。
//本题要求编写D字符串的创建函数。

//输入样例：
//123A

//输出样例：
//5-hello
//4-123A

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//	该函数由系统提供
char *dstr_readword();

char *dstr_create(const char *s);

int main()
{
	char *s = dstr_create("hello");
	printf("%lu-%s\n", strlen(s), s);
	free(s);
	char *t = dstr_readword();
	s = dstr_create(t);
	free(t);
	printf("%lu-%s\n", strlen(s), s);
	free(s);
}

/* 请在这里填写答案 */
char* dstr_create(const char* s) {
	int size = strlen(s);
	char* p = (char*)malloc((size+1) * sizeof(char));
	for (int i = 0; i < size; i++)
	{
		p[i] = s[i];
	}
	p[size] = '\0';
	return p;
}