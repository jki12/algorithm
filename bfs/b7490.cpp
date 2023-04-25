#include <bits/stdc++.h>

using namespace std;

const int len = 10;

int t, n;

int arr[] = { 2, 3, 4, 5, 6, 7, 8, 9 };
int op[len];

int get_length(int n)
{
	int length = 0;

	while (n != 0) {
		n /= 10;

		length++;
	}

	return length;
}

int _stoi(string s, int index)
{
	stack<int> st;

	int n = 0;

	while (index < s.length() && '0' <= s[index] && s[index] <= '9') {
		st.push(s[index++]);
	}

	int digit = 1;
	while (!st.empty()) {
		int cur = st.top() - '0'; st.pop();

		n += (cur * digit);
		digit *= 10;
	}

	return n;
}

void dfs(const int k)
{
	if (k == n - 1) {

		string s = "1"; // 1은 +, -, ' ' 영향 안받음, arr 배열도 2부터 시작 / 연산자와 index도 같게 할 수 있음..
		for (int i = 0; i < n - 1; ++i) {
			if (op[i] != 0) s += (op[i] == 1 ? '+' : '-');
			s += (arr[i] + '0');
		}

		int res = stoi(s);
		for (int i = get_length(res); i < s.length(); ++i) {
			if (s[i] == '+' || s[i] == '-') {
				int x = _stoi(s, i + 1);

				res += (s[i] == '+' ? x : -x);
				i += get_length(x);
			}
		}

		if (res == 0) {
			bool temp = false;

			for (int i = 0; i < s.length(); ++i) {
				if (temp && ('0' <= s[i] && s[i] <= '9')) {
					cout << ' '; temp = !temp;
				}

				cout << s[i];
				temp = !temp;
			}

			cout << '\n';
		}

		return;
	}

	for (int i = 0; i < 3; ++i) { // ascii order, space, +, -
		op[k] = i;

		dfs(k + 1);
	}
}

int main(void)
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> t;

	while (t--) {
		cin >> n;

		dfs(0);
		cout << '\n';
	}

	return 0;
}