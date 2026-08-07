/*
思路一：
    1.用string模拟栈
    2.检测栈内是否有目标字符串，
        以mniuo为例
        m-n ：不满足
        m-n-i ：不满足
        m-n-i-u ：满足 -> 删除 -> m
        m-o ：满足 -> 删除 -> empty
    栈内一次只存在一个目标，因为发现目标后会立即删除
    此方法为线性操作，时间复杂度为On
*/

#include <bits/stdc++.h>
using namespace std;

int n;
string s;

int main(){

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        char c;
        cin >> c;
        s.push_back(c);
        //数据的输入
        
        if(s.size() >= 3 && s.substr(s.size()-3) == "niu") s.erase(s.size()-3, 3);
        /*                               ^
        size-3是因为符合条件的字符串的最后一个字符必然在栈顶，那么起始位置就一定是从后往前第三个，然后截取比较删除
        */                  
        else if(s.size() >= 2 && s.substr(s.size()-2) == "mo") s.erase(s.size()-2, 2);
    }
    
    cout << (s.empty() ? "Yes" : "No");
    //三元运算符，代替简单的输出 语法是 condition ? true : false

    return 0;
}


/*
思路二（超时）：
    1.使用find方法寻找目标字符串
    2.找到就删
    3.循环
*/



/*
#include <bits/stdc++.h>
using namespace std;

int n;
string s;

int main(){

    cin >> n >> s;

    while (s.find("niu") != string::npos || s.find("mo") != string::npos)
    {
        while (s.find("niu") != string::npos){
            s.erase(s.find("niu"),3);
        }
        while (s.find("mo") != string::npos){
            s.erase(s.find("mo"),2);
        }
    }
    

    
    if(s.empty()) cout << "Yes";
    else cout << "No";

    return 0;
}
*/