#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	int input;

	while (true) {
		vector<int> list;
		while (true) {
			cin >> input;
			if (input == -1 ||input==0)
				break;
			list.push_back(input);
		}

		if (input == -1)
			break;

		
		int n = list.size();
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			int mine = list[i];
			for (int j = 0; j < n; j++) {
				if (i == j)
					continue;

				if (mine * 2 == list[j]) {
					cnt++;
					break;
				}
			}	
		}
		cout << cnt << "\n";
	}
}