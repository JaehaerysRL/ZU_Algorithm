// 7-83 币值转换 (20分)
//输入一个整数（位数不超过9位）代表一个人民币值（单位为元），请转换成财务要求的大写中文格式。如23108元，转换后变成“贰万叁仟壹百零捌”元。为了简化输出，用小写英文字母a-j顺序代表大写数字0-9，用S、B、Q、W、Y分别代表拾、百、仟、万、亿。于是23108元应被转换输出为“cWdQbBai”元。

//输入格式：
//输入在一行中给出一个不超过9位的非负整数。

//输出格式：
//在一行中输出转换后的结果。注意“零”的用法必须符合中文习惯。

//输入样例1：
//813227345

//输出样例1：
//iYbQdBcScWhQdBeSf

#include <stdio.h>
void printNum(char num) {
    switch (num)
    {
    case '1':
        printf("b");
        break;
    case '2':
        printf("c");
        break;
    case '3':
        printf("d");
        break;
    case '4':
        printf("e");
        break;
    case '5':
        printf("f");
        break;
    case '6':
        printf("g");
        break;
    case '7':
        printf("h");
        break;
    case '8':
        printf("i");
        break;
    case '9':
        printf("j");
        break;
    case '0':
        printf("a");
        break;
    default:
        break;
    }
}
void change(int len,char in[]) {
    for (int i = 0; i < len-1; i++)
    {
        in[i] = in[i + 1];
    }
}
int main() {
	char in[10];
	gets(in);
	int len = strlen(in);
    int flag = 0;
	if (len >= 9) {
        printNum(in[0]);
        printf("Y");
        flag = 1;
        change(len, in);
	}
    if (len >= 8) {
        if (in[0] == '0') {
            if (flag == 2) {
                printNum(in[0]);
                flag = 0;
            }
            else if (flag == 1) flag = 2;
        }
        else {
            printNum(in[0]);
            printf("Q");
            flag = 1;
        }
        change(len, in);
    }
    if (len >= 7) {
        if (in[0] == '0') {
            if (flag == 2) {
                printNum(in[0]);
                flag = 0;
            }
            else if (flag == 1) flag = 2;
        }
        else {
            printNum(in[0]);
            printf("B");
            flag = 1;
        }
        change(len, in);
    }
    if (len >= 6) {
        if (in[0] == '0') {
            if (flag == 2) {
                printNum(in[0]);
                flag = 0;
            }
            else if (flag == 1) flag = 2;
        }
        else {
            printNum(in[0]);
            printf("S");
            flag = 1;
        }
        change(len, in);
    }
    if (len >= 5) {
        if (flag == 2) printNum('0');
        if (in[0] != '0') {
            printNum(in[0]);
            flag = 1;
        }
        printf("W");
        change(len, in);
    }
    if (len >= 4) {
        if (in[0] == '0') {
            if (flag == 2) {
                printNum(in[0]);
                flag = 0;
            }
            else if (flag == 1) flag = 2;
        }
        else {
            printNum(in[0]);
            printf("Q");
            flag = 1;
        }
        change(len, in);
    }
    if (len >= 3) {
        if (in[0] == '0') {
            if (flag == 2) {
                printNum(in[0]);
                flag = 0;
            }
            else if (flag == 1) flag = 2;
        }
        else {
            printNum(in[0]);
            printf("B");
            flag = 1;
        }
        change(len, in);
    }
    if (len >= 2) {
        if (in[0] == '0') {
            if (flag == 2) {
                printNum(in[0]);
                flag = 0;
            }
            else if (flag == 1) flag = 2;
        }
        else {
            printNum(in[0]);
            printf("S");
            flag = 1;
        }
        change(len, in);
    }
    if (len >= 1) {  
        if (in[0] != '0') {
            if (flag == 2) printNum('0');
            printNum(in[0]);
        }
    }
    if (len == 1 && in[0] == '0') printNum('0');
}