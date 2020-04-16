// 9-1 A+B的文本文件版 (10分)
//这是A+B的文本文件版本。你要写一个完整的程序，打开当前路径下一个名为in.txt的文本文件，从中读两个十进制整数，然后打开一个名为out.txt的文本文件，写入这两个整数的和。
//如果打不开文件，你的程序应该返回-1。
//例子数据文件in.txt：
//12 23
  
//对应的输出数据文件out.txt：
//35

#include <stdio.h>
#include <stdlib.h>

int main(){
	FILE *fp;

    fp = fopen("in.txt", "r");
    if ( !fp ) {
        exit(-1);
    }
    int a,b;
    fscanf(fp, "%d %d", &a, &b);
    fclose(fp);

    fp = fopen("out.txt", "w");
    if ( !fp ) {
        exit(-1);
    }
    int sum = a + b;
    fprintf(fp,"%d",sum);  	
}