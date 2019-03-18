#include <iostream>
using namespace std;
long long cnt[10];

void calc(long long n, long long mul) {
	while (n > 0) {
		cnt[n % 10]+=mul;
		n /= 10;
	}

}

int main(void) {
	long long  start = 1;
	long long  end;
	long long  mul = 1;
	cin >> end;

	while (start <= end) {

		//start가 0이 되도록
		while (start <= end && start % 10 != 0) {
			calc(start, mul);
			start++;

		}
		

		//end가 9가 되도록
		while (start <= end && end % 10 != 9) {
			calc(end, mul);
			end--;
		}

		if (start > end)
			break;


		long long val = (long long)(end /10 - start / 10 + 1)*mul;

		for (int i = 0; i < 10; i++)
			cnt[i] += val;


		start /= 10;
		end /= 10;
		mul *= 10;
	}
	for (int i = 0; i < 10; i++)
		cout << cnt[i] << " ";

	cout << "\n";

}
