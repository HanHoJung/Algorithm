#include <iostream>
#include <string>
using namespace std;
int n;
int a[101];

int possible(int i, string str) {
	int cnt = 0;
	if (i + str.size() > n)
		return 0;

	int basic = a[i] - (str[0] - '0');//기본 높이

	for (int j = 0; j < str.length(); j++) {

		int height = a[i + j] - (str[j] - '0');
		if (basic != height)
			return 0;

	}

	return 1;

}

int main(void) {
	int order;
	int ans = 0;
	cin >> n;
	cin >> order;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}


	for (int i = 0; i < n; i++) {

		switch (order)
		{
		case 1:
			ans += possible(i, "0") + possible(i, "0000");
			break;

		case 2:
			ans += possible(i, "00");
			break;

		case 3:
			ans += possible(i, "001") + possible(i, "10");
			break;

		case 4:
			ans += possible(i, "100") + possible(i, "01");
			break;

		case 5:
			ans += possible(i, "000") + possible(i, "101") + possible(i, "10") + possible(i, "01");
			break;

		case 6:
			ans += possible(i, "000") + possible(i, "00") + possible(i, "011") + possible(i, "20");
			break;

		case 7:
			ans += possible(i, "000") + possible(i, "02") + possible(i, "110") + possible(i, "00");
			break;


		}

	}
	cout << ans << "\n";

}

