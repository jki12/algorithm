#include <bits/stdc++.h>

using namespace std;

#define SIZE 200001

stack<int> s;
int n, ans;

int arr[SIZE];

int main(void) {
    scanf("%d ", &n); // 개행문자 무시하기 위한 공백.

    char c;
    for (int i = 0; i < n; ++i) {
        scanf("%c", &c);

        if (c == '(') s.push(i);
        else {
            if (!s.empty()) {
                arr[s.top()] = 1; s.pop();
                arr[i] = 1;
            }
        }
    }

    int temp = 0;
    for (int i = 0; i < n; ++i) {
        if (arr[i]) temp++;
        else {
            ans = max(ans, temp);
            temp = 0;
        }
    }

    printf("%d", max(ans, temp));
}
