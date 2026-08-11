# 小红

- 用户名：lan_sora
- 日期：2026-08-07
- 题目：小红的陡峭值


## 代码

```c
/*
思路：
从他给出的数据中进行判断，如果可以全选0就全选0，不然就尽全力选1使MID尽可能大。最后进行判断
*/
#include <stdio.h>
int main ()
{
    int time,n,k,n1,MAX,MID;//运行次数，数据总量，选择数量，1的数量，最大值，中位数的位置
    scanf("%d",&time);
    while (time)
    {
        time--;
        scanf("%d",&n);
        scanf("%d",&k);
        int s[n];
        n1=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&s[i]);
            if (s[i]==1) n1++;//记录输入了几个1
        }
        if (k<=n-n1)printf("0\n");//k小于0的数量，可以选择全0（此处没有=也能AC..?)
        else 
        {
            MAX=1;//最大值为1
            MID=(k+1)/2;//中位数的位置
            if ((k-n1)>=MID)//排序后0为中位数
            {
                printf ("1\n");
            }
            else printf ("0\n");//排序后1为中位数
        }
    }
     return 0;
}

```

