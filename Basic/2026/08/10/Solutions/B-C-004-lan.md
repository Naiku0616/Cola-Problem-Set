
- 用户名：lan_sora
- 日期：2026-08-13
- 题目：打boss伤害


## 代码

```cpp
/*
思路：
我再不睡觉就猝死了晚点写
*/
#include <iostream>
#include <vector>
using namespace std;
int main(){
int Num;
cin >> Num ;
    while (Num--){
        int card_num,f_dmg=0,lost_dmg=0,total_dmg=0;
        cin >> card_num;
        vector<int> card(card_num);
        vector<int> dmg(1001,0);
        for (int i=0;i<card_num; i++)
        {   
            cin>>card[i];
            total_dmg+=card[i];
            dmg[card[i]]++;//伤害最大为1000，伤害为数组dmg的索引，如果卡牌有对应伤害则++；
        }
        for(int i=0;i<1001;i++){
            if (dmg[i]>dmg[f_dmg]){
                f_dmg=i;
            }
        }
        int others=card_num-dmg[f_dmg];
        if (dmg[f_dmg]>=others+2){
            lost_dmg=(dmg[f_dmg]-(others+2))*f_dmg;
        }
        cout<<total_dmg-lost_dmg<<endl;
    }


return 0;
}

```

