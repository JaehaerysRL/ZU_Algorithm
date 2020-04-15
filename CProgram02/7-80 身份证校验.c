// 7-80 身份证校验 (100分)
//一个合法的身份证号码由17位地区、日期编号和顺序编号加1位校验码M组成。校验码M的计算规则如下：
//首先对前17位数字加权求和，权重分配为：{7，9，10，5，8，4，2，1，6，3，7，9，10，5，8，4，2}；然后将计算的和对11取模得到值Z；最后按照以下关系从Z值计算出校验码M的值：
//Z：0 1 2 3 4 5 6 7 8 9 10
//M：1 0 X 9 8 7 6 5 4 3 2 
//现在输入一个身份证号码，请你验证校验码的有效性。注意这里只检验校验码，不检查地区、生日等的正确性。

//输入格式:
//输入一个18位的身份证号码。

//输出格式:
//如果有效，输出YES，否则输出NO。注意输出为全部大写字母。

//输入样例:
//320124198808240056
 
//输出样例:
//YES

#include <stdio.h>
#include <string.h>

char zTom(int z) {
	switch (z)
	{
	case 0:return '1';
	case 1:return '0';
	case 3:return '9';
	case 4:return '8';
	case 5:return '7';
	case 6:return '6';
	case 7:return '5';
	case 8:return '4';
	case 9:return '3';
	case 10:return '2';
	default:
		return 'X';
		break;
	}
}

int main()
{
	int sig = 1;
	int num[20];
	char input[20];
	gets(input);
	for (int j = 0; j < 18; j++)
	{
		if ((input[j] < 48 || input[j] > 57) && j != 17) {
			sig = 0;
		}
	}
	char m, tm;
	m = input[17];
	int z;
	if (sig == 1) {
		for (int j = 0; j < 17; j++) {
			num[j] = (int)(input[j] - 48);
		}
		z = num[0] * 7 + num[1] * 9 + num[2] * 10 + num[3] * 5 + num[4] * 8 + num[5] * 4 + num[6] * 2 + num[7] * 1 + num[8] * 6 + num[9] * 3 + num[10] * 7 + num[11] * 9 + num[12] * 10 + num[13] * 5 + num[14] * 8 + num[15] * 4 + num[16] * 2;
		z %= 11;
		tm = zTom(z);
		if (tm != m) {
			sig = 0;
		}
	}
	if (sig == 0) printf("NO");
	else printf("YES");
}