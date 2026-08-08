```cpp
#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define all(a) a.begin(), a.end()
#define part(a,n) a.begin() + 1, a.begin() + 1 + n
#define endl '\n'
#define yes puts("yes")
#define no puts("no")
#define Yes puts("Yes")
#define No puts("No")
#define YES puts("YES")
#define NO puts("NO")
#define int long long
#define lb(v,x) (int)(lower_bound(all(v),x)-v.begin())
#define ub(v,x) (int)(upper_bound(all(v),x)-v.begin())
#define lowbit(x) (x & -x)
#define F(i, x, y) for (int i = (x); i <= (y); i++)
#define DF(i, x, y) for (int i = (x); i >= (y); i--)
#define debug(x) cout << #x << ": " << x << endl;
#define ihb(x) ((x) == 0 ? -1 : (31 - __builtin_clz((x)))) // 最高1位子,0开始
#define lhb(x) ((x) == 0 ? -1 : (63 - __builtin_clzll((x))))
#define ione __builtin_popcount // 1的个数
#define lone __builtin_popcountll 

template<class T1, class T2> bool cmin(T1 &x, const T2 &y) { if (y < x) { x = y; return 1; } return 0; }
template<class T1, class T2> bool cmax(T1 &x, const T2 &y) { if (x < y) { x = y; return 1; } return 0; }

using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using PII = pair<int, int>;
using PLL = pair<ll, ll>;
using vei = vector<int>;
using veb = vector<bool>;
using vep = vector<PII>;
using vevei = vector<vector<int>>;
using ai3 = array<int, 3>;


const double PI = acos(-1);

void init(){
    ;
}

const int MOD = 998244353;

// 0~25: 'A'~'Z'
// 26~51: 'a'~'z'
// 52~61: '0'~'9'
// 62: 仅用于初始状态的“没有上一位”哨兵
int id(char ch) {
    if ('A' <= ch && ch <= 'Z') return ch - 'A';
    if ('a' <= ch && ch <= 'z') return 26 + ch - 'a';
    return 52 + ch - '0';
}

// 返回该字符所属类别对应的 mask 位
int charType(int c) {
    if (c < 26) return 1;       // 大写
    if (c < 52) return 2;       // 小写
    return 4;                   // 数字
}

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;

    vevei dp(10, vei(70, 0));
    dp[0][62] = 1;

    for(auto it : s){
        vevei ndp(10, vei(70, 0));
        vei sum(10, 0);

        for(int mask = 0; mask < 8; mask ++) /* 000 ~ 111*/{
            for(int j = 0; j <= 62; j ++){
                sum[mask] += dp[mask][j];
                sum[mask] %= MOD;
            }
        } 

        vei ch;

        if(it == '?'){
            for(int i = 0; i < 62; i ++) ch.pb(i);
        }else if('a' <= it && it <= 'z'){
            ch.pb(id(it));
            ch.pb(id(it - 'a' + 'A'));
        }else{
            ch.pb(id(it));
        }

        for(auto c : ch){

            for(int mask = 0; mask < 8; mask ++){
                int type = charType(c);
                int ways = sum[mask] - dp[mask][c];
                ways = (ways + MOD) % MOD;
                int nmask = mask | type;
                ndp[nmask][c] += ways;
                ndp[nmask][c] %= MOD;
            }

        }
        dp = ndp;
    }
    
    int ans = 0;
    for(int i = 0; i < 62; i ++){
        ans = (ans + dp[7][i]) % MOD;
    }

    cout << ans << endl;

    return;
}

signed main(){
    ios::sync_with_stdio(false); 
    cin.tie(0);

    init();
    
    int _ = 1;
     //cin >> _;
    while (_--) solve();
    return 0;
}
```