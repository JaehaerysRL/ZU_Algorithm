// 6-24 D字符串的输入 (5分)
//D字符串是动态分配内存的字符串，它也采用char数组来保存字符串中的字符，但是这个数组是在堆中动态分配得到的。
//本题要求编写D字符串的读入一个单词的函数。
//dstr_readword从标准输入读入一个字符串，到回车换行、空格或Tab字符、或遇到输入结束为止。返回读入的字符串。
//注意这里可能读到的字符串长度没有限制。

//输入样例：
//123A

//输出样例：
//4-123A

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *dstr_readword();

int main()
{
	char *s = dstr_readword();
	printf("%lu-%s\n", strlen(s), s);
}

/* 请在这里填写答案 */
char* dstr_readword() {
	int judge = 1;
	char* s, * p;
	int size = 100000, i = 0;
	s = (char*)malloc(size * sizeof(char));
	p = s;
	while (judge == 1)
	{
		if (i >= size) {
			size += 100;
			s = (char*)realloc(s, size * sizeof(char));
		}
		scanf("%c", &s[i]);
		if (s[i] == '\n' || s[i] == '\r' || s[i] == '\t' || s[i] == ' ' || s[i] == '\0') {
			s[i] = '\0';
			judge = 0;
			break;
		}
		else i++;
	}
	return p;
}
