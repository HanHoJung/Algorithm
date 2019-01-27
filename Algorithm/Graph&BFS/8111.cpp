#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(void) {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		vector<int> dist(n, -1);
		vector<int> how(n, -1);//어떻게 만들어 졌는지
		vector<int> from(n, -1);//어떤것을 통해서 만들어졌는지
		queue<int> q;
		dist[1 % n] = 0;
		how[1 % n] = 1;
		q.push(1 % n);//n이 1일 수도 있는 예외 때문에 1%n

		while (!q.empty()) {

			int current = q.front();
			q.pop();

			for (int i = 0; i <= 1; i++) {

				int next = (current * 10 + i) % n;

				if (dist[next] == -1) {
					dist[next] = dist[current] + 1;
					from[next] = current;
					how[next] = i;
					q.push(next);

				}
			}
		}
		int index = 0;
		
		vector<int> result;

		while (from[index] != -1) {
			
			result.push_back(how[index]);
			index = from[index];
				
		}
		result.push_back(how[index]);

		for (int i = 0; i < result.size() / 2; i++) {
			int temp = result[i];
			result[i] = result[result.size() - 1 - i];
			result[result.size() - 1 - i] = temp;
		}

		for (int i = 0; i < result.size(); i++) {
			cout << result[i];
		}
		cout << "\n";

		
		


	
		

	}


}