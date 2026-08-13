
- 用户名：lan_sora
- 日期：2026-08-11


## 代码

```cPP

/*
思路可能在注释里吧....可能
写到这里，我已经在猝死边缘了
这坨代码很显然有优化空间，
但是
写到这里，我已经在猝死边缘了
*/


#include <iostream>
#include <vector>
using namespace std;
int main()
{
int Num,flag;//FLAG是YESorNO标志位
cin>>Num;
    for (int i=0;i<Num;i++)//测试次数
    {
        int sum,temp,min=1000000000,max=-1;
        cin>>sum;
        vector<int>arr(sum+3,0);
        for(int i=1;i<sum+1;i++){
                            cin>>arr[i];
                        }
        if (sum%2!=0){//奇数直接不要了
            flag=0;
        }
        else{//偶数的来
                
            //我去，我快睡着了，管不了CPP还是C了我踏马写写写
                for(int i=1;i<sum+2;i++){
                    temp=arr[i];
                    if (i<sum+1){//这是我认为整个代码最变态的地方，为了防止这个连续++两次的函数把数组搞越界，
                        i++;     //我直接把数组设置大了不少，之后用一个IF避免读到过大的0们，真可谓屎之上品。
                        if (temp<min ) min=temp;//记录奇数项最小值
                        if (arr[i]>max ) max=arr[i];//记录偶数项最大值
                        if (temp > arr[i] && temp-arr[i]>1){//如果奇数项比偶数项大，并且相减值大于1 （这里好像多余了。。。。）
                        }//我马上就猝死了，我不改了
                    }
                        else {//不满足FLAG标0
                            flag=0;
                            break;//跑路了兄弟
                        }
                }
            if (min-max>1)flag=1;//这个函数里面奇数位的最小值和偶数位的最大值都找的到K，说明过了，OK
            else{
                flag=0;//不过
            }
        }

    
    if (flag==1){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }}
    return 0;
}
```

