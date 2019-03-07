#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <string>
using namespace std;
int main(void) {

	int t = 0;
	vector<string> arr(3,"");
	vector<string> output(3, "");
	while (t < 3) {
		int input;
		cin >> input;
		if(input!=0)
			cin >> arr[t];

		t++;
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < arr[i].size(); j++) {
			if (arr[i][j] == 'A')
				output[0] += 'A';

			if (arr[i][j] == 'B')
				output[1] += 'B';

			if (arr[i][j] == 'C')
				output[2] += 'C';
		}
	}

	queue<vector<string>> q;
	map<vector<string>, int> dist;
	q.push(arr);
	dist[arr] = 0;

	while (!q.empty()) {
		auto str = q.front();
		q.pop();
		
		
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {

				if (i == j)
					continue;
				if (str[i].size() == 0)
					continue;
				
				
				vector<string> narr(str);
				narr[j]+= str[i][str[i].size() - 1];
				narr[i].pop_back();

				if (dist.count(narr) == 0) {
					dist[narr] = dist[str] + 1;
					q.push(narr);
				}
			}
		}
	}

	cout << dist[output] << "\n";

}