// 7-66 时间换算 (15分)
//本题要求编写程序，以hh:mm:ss的格式输出某给定时间再过n秒后的时间值（超过23:59:59就从0点开始计时）。

//输入格式：
//输入在第一行中以hh:mm:ss的格式给出起始时间，第二行给出整秒数n（<60）。

//输出格式：
//输出在一行中给出hh:mm:ss格式的结果时间。

//输入样例：
//11:59:40
//30
 
//输出样例：
//12:00:10

#include <stdio.h>
int main() {
	int h, m, s, n, isUp = 0;
	scanf("%d:%d:%d", &h, &m, &s);
	scanf("%d", &n);
	if (s + n < 60) s += n;
	else {
		isUp = 1;
		s = s + n - 60;
	}
	if(isUp == 1) {
		if (m + 1 < 60) {
			m++;
			isUp = 0;
		}
		else {
			isUp = 1;
			m = m - 59;
		}
	}
	if (isUp == 1) {
		if (h + 1 < 24) h++;
		else h -= 23;
	}
	printf("%02d:%02d:%02d", h, m, s);
}