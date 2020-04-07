// 7-39 龟兔赛跑 (20分)
//乌龟与兔子进行赛跑，跑场是一个矩型跑道，跑道边可以随地进行休息。乌龟每分钟可以前进3米，兔子每分钟前进9米；兔子嫌乌龟跑得慢，觉得肯定能跑赢乌龟，于是，每跑10分钟回头看一下乌龟，若发现自己超过乌龟，就在路边休息，每次休息30分钟，否则继续跑10分钟；而乌龟非常努力，一直跑，不休息。假定乌龟与兔子在同一起点同一时刻开始起跑，请问T分钟后乌龟和兔子谁跑得快？

//输入格式：
//输入在一行中给出比赛时间T（分钟）。

//输出格式：
//在一行中输出比赛的结果：乌龟赢输出@_@，兔子赢输出^_^，平局则输出-_-；后跟1空格，再输出胜利者跑完的距离。

//输入样例：
//242

//输出样例：
//@_@ 726

#include <stdio.h>

int main(){
    int st = 0, sr = 0, vt = 3, vr = 9, T, restTime = 0, runTime = 0;
    scanf("%d", &T);
    int isWait = 0;
    for (int i = 0; i < T; i++)
    {
        st += vt;
        if (isWait != 1) {
            sr += vr;
            runTime++;
        }
        else restTime++;
        if (runTime == 10) {
            if (sr > st) {
                isWait = 1;
                restTime = 0;
            }
            runTime = 0;
        }
        if (restTime == 30) {
            isWait = 0;
            runTime = 0;
            restTime = 0;
        }
    }
    if (st < sr) printf("^_^ %d",sr);
    else if (st > sr) printf("@_@ %d",st);
    else  printf("-_- %d",sr);
}
