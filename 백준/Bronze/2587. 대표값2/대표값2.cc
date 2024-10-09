#include <bits/stdc++.h>

#define SIZE 5

using namespace std;

int arr[SIZE];
int sum;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);

    int n = SIZE;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];

        sum += arr[i];
    }

    sort(arr, arr + n);

    int mid = (n % 2 == 0) ? (arr[n / 2] + arr[n / 2 - 1]) / 2 : arr[n / 2];

    cout << sum / n << ' ' << mid << '\n';
}