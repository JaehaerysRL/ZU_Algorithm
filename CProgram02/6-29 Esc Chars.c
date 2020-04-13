// 6-29 Esc Chars (20分)
//Esc characters are represented as \x in C string, such as \n and \t.
//Function prt_esc_chars() gets a string which may contains esc characters, and prints the string into the standard ouput with all esc characters been replaced by a \x format combination.
//输入样例：
//hello    world
//There is a tab between hello and world.
//输出样例：
//hello\tworld\n14

#include <stdio.h>

int prt_esc_char(const char *s);

int main()
{
	char *line = NULL;
	size_t linecap = 0;
	getline(&line, &linecap, stdin);
	int len = prt_esc_char(line);
	printf("%d\n", len);
}

char hex(int i) {
	switch (i)
	{
	case 0:return '0';
	case 1:return '1';
	case 2:return '2';
	case 3:return '3';
	case 4:return '4';
	case 5:return '5';
	case 6:return '6';
	case 7:return '7';
	case 8:return '8';
	case 9:return '9';
	case 10:return 'A';
	case 11:return 'B';
	case 12:return 'C';
	case 13:return 'D';
	case 14:return 'E';
	case 15:return 'F';
	default:
		return 0;
	}
}

int prt_esc_char(const char* s) {
	int i = 0, count = 0;
	while (s[i])
	{
		if (s[i] == '\n') {
			putchar('\\');
			putchar('n');
			count = count + 2;
		}
		else if (s[i] == '\r') {
			putchar('\\');
			putchar('r');
			count = count + 2;
		}
		else if (s[i] == '\t') {
			putchar('\\');
			putchar('t');
			count = count + 2;
		}
		else if (s[i] == '\b') {
			putchar('\\');
			putchar('b');
			count = count + 2;
		}
		else if (s[i] == ' ') {
			putchar('\\');
			putchar('0');
			count = count + 2;
		}
		else if (s[i] == 0) {
			break;
		}
		else if (s[i] <= 32) {
			int a = s[i] / 16;
			int b = s[i] - a * 16;
			putchar('\\');
			putchar(hex(a));
			putchar(hex(b));
			count = count + 3;
		}
		else {
			putchar(s[i]);
			count++;
		}
		i++;
	}
	return count;
}