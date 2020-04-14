// 7-53 删除字符串中的子串 (20分)
//输入2个字符串S1和S2，要求删除字符串S1中出现的所有子串S2，即结果字符串中不能包含S2。

//输入格式：
//输入在2行中分别给出不超过80个字符长度的、以回车结束的2个非空字符串，对应S1和S2。

//输出格式：
//在一行中输出删除字符串S1中出现的所有子串S2后的结果字符串。

//输入样例：
//Tomcat is a male ccatat
//cat

//输出样例：
//Tom is a male 

#include<stdio.h>
#include<string.h>
 
int main(){
	char s[1000],t[1000];
	char x;
	
	gets(s);
	gets(t);
	int lens=strlen(s);
	int lent=strlen(t);
	char q[1000];
	char *p;
	while(p=strstr(s,t)){//找到s中第一次与t匹配的地址，若找不到返回NULL
		while(*(p+lent)!='\0'){//能找到
			*p=*(p+lent);//从开始找到的位置将去掉t的那部分复制过来
			p++;
		}	
		*p='\0';//s串打上结束标志
	}
	puts(s);
	return 0;
}