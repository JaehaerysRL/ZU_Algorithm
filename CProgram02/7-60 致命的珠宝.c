// 7-60 致命的珠宝 (10分)
//Mini使用神风无影来到了大魔王所居住的洞穴，门口却有着险恶的机关。门上有着N个宝珠，每个宝珠都有一个数字。传说，只要宝珠里的两颗珠撞在一起后就会发出奇异的光彩，但发出的光彩有可能是致命的，也有可能是打开前进之路的钥匙。Mini询问老者后，得知要想打开这扇门，就得找出两颗珠宝，使这两颗珠宝撞在一起后产生的能量值最接近16。
//两颗珠宝撞在一起以后产生的能量值的计算方法是：将两个珠宝所代表的数字转换为7进制的数后，一一对照这两个七进制数的每一位，若相同，则结果为0否则为1。
//如：两颗珠子所代表的数为18和370，将这两个数转化为7进制后是24和1036，对于高位不足的数，采取高位添‘0’的方法，即两个数为0024，1036。最后得到的能量值C为1011，再将C当作二进制数转换为十进制数。那么转换后的C就为这两个珠撞在一起以后所产生的能量值。

//输入格式:
//第一行一个数N，表示宝珠的数量（2<=N<=1200）。 第二行N个数，每个数用空格隔开，每个数表示第I个宝珠所代表的数字(0<=每个数<=11111)。

//输出格式:
//一个数，代表你所找到的最接近16的能量值。

//输入样例:
//5
//18 370 45 36 78

//输出样例:
//15

#include <stdio.h>
#include <math.h>

struct jew
{
	int num;
	char seven[5];
};


int ene(char a[], char b[]) {
	int sum = 0;
	for (int i = 0; i < 5; i++)
	{
		if (a[i] != b[i])sum += pow(2, i);
	}
	return sum;
}

int abs(int a){
    if(a<0)a=-a;
    return a;
}

int main()
{
	int N;
	scanf("%d", &N);
    struct jew jews[N];
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &jews[i].num);
		int tmp = jews[i].num;
		for (int j = 0; j < 5; j++)
		{
			jews[i].seven[j] = tmp % 7 + 48;
			tmp /= 7;
		}
	}
	int energy = ene(jews[0].seven, jews[1].seven);
	int min = abs(16 - energy);
	int tmpm, tmpe;
	for (int i = 0; i < N-1; i++)
	{
		for (int j = 1; j < N; j++)
		{
			tmpe = ene(jews[i].seven, jews[j].seven);
			tmpm = abs(16 - tmpe);
			if (tmpm < min) {
				min = tmpm;
				energy = tmpe;
			}
		}
    }
    printf("%d", energy);
}