// 6-21 P字符串的输入输出 (5分)
//P字符串是另一种字符串实现形式。它也采用char数组来保存字符串中的字符，但是最后一个字符后面没有结尾的'\0'。它使用另一个int类型的变量来表示字符串中的字符的个数。
//本题要求编写P字符串的输入输出函数，能从标准输入读入一个以空格结尾的单词，填入一个P字符串，能将一个P字符串输出到标准输出。
//pstr_scan要从标准输入读入一个字符串，读到空格类字符为止。空格类字符包括空格、Tab和回车换行。str是要填的P字符串数组，size是这个数组的大小。函数返回读到的字符串的长度。
//pstr_print要将一个字符串输出到标准输出。str是要输出的字符串，length是字符串的长度（字符串中的字符个数）。

//输入样例：
//i18 -299

//输出样例：
//i18

#include <stdio.h>

const int SIZE = 80;

int pstr_scan(char* str, int size);
void pstr_print(const char* str, int length);

int main()
{
	char line[SIZE];

	int length = pstr_scan(line, SIZE);
	pstr_print(line, length);
	
  return 0;
}

/* 请在这里填写答案 */
int pstr_scan(char* str, int size) {
	int length = 0;
	for (int i = 0; i < size; i++)
	{
		scanf("%c",&str[i]);
		if (str[i] != '\n' && str[i] != '\r' && str[i] != '\t' && str[i] != ' ') length++;
		else break;
	}
	return length;
}

void pstr_print(const char* str, int length) {
	for (int i = 0; i < length; i++)
	{
		printf("%c", str[i]);
	}
}