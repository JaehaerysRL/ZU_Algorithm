// 6-30 Read Esc Chars (30分)
//Esc characters are represented as \x in C string, such as \n and \t.
//Function read_esc_chars() reads a line that may contains esc character representations from the standard input and parses all those esc character representations into esc characters.
//For example, a string:
//This is \t a test. 
//will be converted as:
//This is    a test. 
//There is a tab between is and a.
//Your function should be able to recognize esc characters below:
//\n
//\r
//\t
//\b
//And all other characters below 0x20 will be presented as:
//\hh 
//where hh is the hexadecimal of the value, all letters in capital. For a value below 0x10, a leading 0 is needed to keep two positions.
//And as a C string, 0x00 will not be part of the string but the terminator.

//函数接口定义：
//int read_esc_char(char *line, int len);

//line is the place that can hold the string read from user's input.
//len is the size of line.
//The function reads a whole line from the standard input and returns number of characters in the converted string. If the inputed line is longer than the place, only the characters that can be safely placed in the place can be read in.

//输入样例：
//hello\tworld

//输出样例：
//11
//hello   world

#include <stdio.h>

int read_esc_char(char *line, int len);

static const LINE_LEN = 80;

int main()
{
	  char line[LINE_LEN];
    printf("%d\n", read_esc_char(line, LINE_LEN));
    printf("%s\n", line);
}

/* 请在这里填写答案 */
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
		return '0';
	}
}

int read_esc_char(char* line, int len) {
	int j = 0, count = 0;
	char tmp;
	for (int i = 0; i < len; i++)
	{
		if (j >= len - 1) {
            line[j++] = '\0';
			break;
        }
		tmp = getchar();
		if (tmp == 0) {
            line[j++] = '\0';
			break;
		}
		else if (tmp <= 32) {
			int a = tmp / 16;
			int b = tmp - a * 16;
            if (j >= len - 3) {
                line[j++] = '\0';
			    break;
            }
			line[j++] = '\\';
			line[j++] = hex(a);
			line[j++] = hex(b);
            count++;
		}
		else {
			line[j++] = tmp;
            count++;
		}
	}
	return count;
}