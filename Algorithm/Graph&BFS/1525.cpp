#define MAX 3
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;


int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int main(void) {
	int sum = 0;
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			int input;
			scanf("%d", &input);
			if (input == 0)
				input = 9;

			sum = sum * 10 + input;

		}
	}

	map<int, int> d;//°¡ÁßÄ¡
	queue<int> q;
	q.push(sum);
	d[sum] = 0;

	
	while (!q.empty()) {

		int node = q.front();
		q.pop();

		string s_node = to_string(node);
		int i_node = stoi(s_node);
		int index = s_node.find('9');
		int x = index / MAX;
		int y = index % MAX;

		for (int i = 0; i < 4; i++) {

			int new_x = x + dx[i];
			int new_y = y + dy[i];

			if (new_x < 0 || new_x >= MAX || new_y < 0 || new_y >= MAX)
				continue;

			string next = s_node;
			swap(next[x*MAX + y], next[new_x*MAX + new_y]);

			int new_i_node = stoi(next);
			if (d.count(new_i_node) == 0){
				q.push(new_i_node);
				d[new_i_node] = d[i_node] + 1;
			}
			
		}

	}
	if (d.count(123456789) == 0) {
		cout << -1 << '\n';
	}
	else {
		cout << d[123456789] << '\n';
	}

}