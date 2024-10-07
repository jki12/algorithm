#include <bits/stdc++.h>

using namespace std;

#define SIZE 1000001

int n, cnt;
int arr[SIZE];
int cpy[SIZE];
set<int> s; // 오름차순으로 정리, find() 시간 복잡도 O(log n).

int find(int target) {
    int l = 0; int r = cnt - 1;
    int mid;

    while (l <= r) {
        mid = (l + r) / 2;
        if (cpy[mid] == target) return mid;

        if (cpy[mid] < target) l = mid + 1;
        else r = mid - 1;
    }

    return -1;
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];

        if (s.find(arr[i]) == s.end()) {
            s.insert(arr[i]);
            cpy[cnt++] = arr[i];
        }
    }

    sort(cpy, cpy + cnt);

    for (int i = 0; i < n; ++i) {
        cout << find(arr[i]) << ' ';
    }
}
