# B-N-001 题解：删除 `niu` 和 `mo`

## 思路

每次可以删除连续子串 `niu` 或 `mo`，删除后左右两边会拼接在一起。因此，拼接后可能会形成新的 `niu` 或 `mo`，还需要继续删除。

可以使用栈模拟这个过程：

1. 从左到右遍历字符串。
2. 将当前字符压入栈中。
3. 每次压入后，检查栈顶：
   - 如果栈顶三个字符是 `niu`，删除这三个字符。
   - 如果栈顶两个字符是 `mo`，删除这两个字符。
4. 删除后继续检查，因为新的栈顶可能又组成了可删除的字符串。
5. 最终栈为空，说明原字符串可以被全部删除，输出 `Yes`；否则输出 `No`。

## 正确性说明

每次删除的 `niu` 或 `mo` 都是当前字符串中的连续子串，符合题意。

删除后，原来分开的左右部分会相连。栈中的字符始终表示当前还没有被删除的字符串；如果拼接后形成新的 `niu` 或 `mo`，它一定出现在栈顶附近，因此继续检查栈顶即可。

当遍历结束时，栈为空，表示所有字符均已被合法删除，答案为 `Yes`。如果栈不为空，说明仍有无法删除的字符，答案为 `No`。

## 复杂度分析

每个字符最多入栈一次、出栈一次。

- 时间复杂度：`O(n)`
- 空间复杂度：`O(n)`

## C++ 代码

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string s;
    cin >> n >> s;

    string st;

    for (char ch : s) {
        st.push_back(ch);

        while (true) {
            int len = st.size();

            if (len >= 3 &&
                st[len - 3] == 'n' &&
                st[len - 2] == 'i' &&
                st[len - 1] == 'u') {
                st.erase(st.end() - 3, st.end());
            } else if (len >= 2 &&
                       st[len - 2] == 'm' &&
                       st[len - 1] == 'o') {
                st.erase(st.end() - 2, st.end());
            } else {
                break;
            }
        }
    }

    cout << (st.empty() ? "Yes" : "No") << '\n';

    return 0;
}
```