// #include <bits/stdc++.h>

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;

#define SIZE 16

struct node {
    int pop;

    vector<int> next_index;
};

int n, m, total;
int ans = INT32_MAX;

int mask;
node arr[SIZE];

int to_index(int bit) {
    int index = 0;

    while (bit != 0) {
        bit >>= 1;
        index++;
    }

    return index;
}

int bfs(int mask) { // 구역이 전부 연결 되어 있다면 인구를 반환 합니다, 아니면 -1을 반환.
    int flag = (-mask & mask); // 최하위 비트 찾기
    if (flag == 0) {
        return -1;
    }

    queue<node> q;
    int count = 0;

    q.push(arr[to_index(flag)]);
    int cpy = mask & ~flag; // q에 넣어준 비트 끄기.
    
    while (!q.empty()) {
        node node = q.front(); q.pop();
        count += node.pop;

        for (int i = 0; i < node.next_index.size(); ++i) {
            flag = 1 << (node.next_index[i] - 1);

            if (cpy & flag) {
                cpy &= ~flag;

                q.push(arr[to_index(flag)]);
            }
        }
    }

    return (cpy) ? -1 : count;
}

void recur(int cur) {
    if (cur == n + 1) {
        return;
    }

    int a = bfs(mask);
    int b = bfs(((1 << n) - 1) & ~mask);

    if (a != -1 && a + b == total) {
        ans = min(ans, abs(a - b));
    }

    for (int i = cur; i < n; ++i) {
        mask |= (1 << i);
        recur(i + 1);
        mask &= ~(1 << i);
    }
}

int main(void) {
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        cin >> arr[i].pop;

        total += arr[i].pop;
    }

    int temp;
    for (int i = 1; i <= n; ++i) {
        cin >> m;

        for (int j = 0; j < m; ++j) {
            cin >> temp;

            arr[i].next_index.push_back(temp);
        }
    }

    recur(0);
    cout << (ans == INT32_MAX ? -1 : ans) << '\n';
}
