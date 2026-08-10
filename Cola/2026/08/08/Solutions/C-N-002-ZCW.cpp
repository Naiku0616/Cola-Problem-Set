/*这道题只需要知道勾股数万能构造法
对于奇数k： (k*k-1)/2 (k*k+1)/2
对于偶数k：（k/2）*(k/2)-1 （k/2）*(k/2)+1
*/
#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long
signed main(){
    int t;cin>>t;
    while(t--){
        int x;cin>>x;
        if(x%2){
            int y=x*x-1;
            y/=2;
            int z=x*x+1;
            z/=2;
            if(y&&z)cout<<"Yes\n"<<x<<' '<<y<<' '<<z<<'\n';
            else cout<<"No\n";
        }
        else{
            int y=x*x/4;
            y-=1;
            int z=x*x/4;
            z+=1;
            if(y&&z)cout<<"Yes\n"<<x<<' '<<y<<' '<<z<<'\n';
            else cout<<"No\n";
        }
    }
}
