// 7-13 删除重复字符 (20分)
//本题要求编写程序，将给定字符串去掉重复的字符后，按照字符ASCII码顺序从小到大排序后输出。
//输入格式：
//输入是一个以回车结束的非空字符串（少于80个字符）。

//输出格式：
//输出去重排序后的结果字符串。

//输入样例：
//ad2f3adjfeainzzzv

//输出样例：
//23adefijnvz。

#include <stdio.h>
#include <string.h>

int main()
{
	char s[81];
	gets(s);
	int n = strlen(s);
	//排序
	for (int i = 0; i < n-1; i++)
	{
		char min = s[i];
		char temp;
		int index = i;
		for (int j = i + 1; j < n; j++)
		{
			if (s[j] < min) {
			    min = s[j];
			    index = j;
			}
		}
		if(index!=i){
		    temp = s[i];
		    s[i] = s[index];
		    s[index] = temp;
		}
	}
	//输出
	int flag = 0;
	char tmp = s[0];
	printf("%c", s[0]);
	for (int i = 1; i < n; i++)
	{
		if (s[i] == tmp) flag = 1;
		else flag = 0;
		if (flag == 0) {
			tmp = s[i];
			printf("%c", s[i]);
		}
	}
}