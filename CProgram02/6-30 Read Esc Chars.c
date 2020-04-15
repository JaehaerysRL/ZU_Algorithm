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
int read_esc_char(char* line, int len)
{
    scanf("%s", line);
    int p = 0, q = 0;
    while (line[p] && p < len)
    {
        if (line[p] == '\\')
        {
            switch (line[p + 1])
            {
            case 'n':line[q++] = '\n';p += 2;break;
            case 'r':line[q++] = '\r';p += 2;break;
            case 't':line[q++] = '\t';p += 2;break;
            case 'b':line[q++] = '\b';p += 2;break;
            default:
            {
                if (p > len - 3) goto END;
                char tmp= (line[p + 1] - '0') * 16 + line[p + 2] - '0';
                if (tmp == 0)goto END;
                line[q++] = tmp;
                p += 3;
                break;
            }
            }
        }
        else
        {
            line[q++] = line[p++];
        }
    }
END:
    if (q >= len) q = len - 1;
    line[q] = '\0';
    return q;
}