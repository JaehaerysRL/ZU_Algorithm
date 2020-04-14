// 7-42 圆形体体积计算器 (20分)
//本题要求实现一个常用圆形体体积的计算器。计算公式如下：
//1-Ball
//2-Cylinder
//3-Cone
//other-Exit
//Please enter your command:
//然后从标准输入读进一个整数指令。

//输出格式：
//如果读入的指令是1或2或3，则执行相应的体积计算；如果是其他整数，则程序结束运行。
//当输入为1时，在计算球体体积之前，打印Please enter the radius:，然后读入球体半径，完成计算；
//当输入为2时，在计算圆柱体体积之前，打印Please enter the radius and the height:，然后读入底圆半径和高，完成计算；
//当输入为3时，在计算圆锥体体积之前，打印Please enter the radius and the height:，然后读入底圆半径和高，完成计算。
//计算结果在一行内输出，保留小数点后两位。

#include<stdio.h>
#include<math.h>
int main()
{
	int n;
	double pi=3.1415926535,r,h;
	while(1)
	{
		printf("1-Ball\n2-Cylinder\n3-Cone\nother-Exit\nPlease enter your command:\n");
		scanf("%d",&n);
		switch(n)
		{
			case 1:{
				printf("Please enter the radius:\n");
				scanf("%lf",&r);
				printf("%.2lf\n",4.0*pi*pow(r,3)/3); 
				break;
			}
			case 2:{
				printf("Please enter the radius and the height:\n");
				scanf("%lf%lf",&r,&h);
				printf("%.2lf\n",pi*pow(r,2)*h); 
				break;
			}
			case 3:{
				printf("Please enter the radius and the height:\n");
				scanf("%lf%lf",&r,&h);
				printf("%.2lf\n",pi*pow(r,2)*h/3);
				break;
			}
			default:return 0;
		}
	}
}