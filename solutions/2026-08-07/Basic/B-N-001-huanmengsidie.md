#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);        //显著提高 cin 和 cout 的效率
    cin.tie(nullptr);           //解除cin与cout的绑定，进一步提高效率

    int n;
    string s;
    cin >> n >> s;

    string st;          //用 string 模拟栈
    for(char c : s){        //遍历输入字符串 s 中的每一个字符 c 
        st.push_back(c); //将字符压入栈中
        while(true){            //进入无限循环，直到无法再删除字符串为止
            int m =(int)st.size();          //获取当前栈的大小（字符串长度），记录为 m 
            bool done = false;           //定义一个标志位 done 初始值为false 用以记录本次循环是否成功执行删除操作
                //优先看能否删除“mo”
            if (m >= 2 && st[m-2] == 'm' && st[m-1] == 'o') {       //判断栈中最后两个字符是否为 "mo"，且长度是否大于等于2
                // m-1 表示栈顶的索引，m-2 表示栈顶下一个元素的索引
                st.pop_back();
                st.pop_back();          //连续调用 pop_back() 方法删除栈顶的两个字符
                done = true;            //标记已执行删除
            }
            //在看能否删除“niu”
            else if (m>=3 && st[m-3] == 'n' && st[m-2] == 'i' && st[m-1] == 'u') {          //判断栈中最后三个字符是否为 "niu"，且长度是否大于等于3
                st.pop_back();
                st.pop_back();
                st.pop_back();          //连续调用 pop_back() 方法删除栈顶的三个字符
                done = true;            //标记已执行删除
            }
            if(!done) break;            //如果本次循环没有执行删除操作，则跳出循环
        }
    }
    cout << (st.empty()? "YES" :"NO") << '\n';          
    // 检查栈（st）是否为空（ st.empty()），如果为空则输出 "YES"，否则输出 "NO"
    return 0;
}
