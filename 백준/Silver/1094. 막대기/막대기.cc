#include <iostream>

using namespace std;

int n;

int recur(int r, int k) {
    if (r == k) return 1;

    if (r < k) return recur(r, k / 2);
    else return recur(r - k, k) + 1; // 막대기 2개로 나누었을때 하나는 사용하고 남은 하나는 다시 재활용
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;

    cout << recur(n, 64) << '\n';
}
