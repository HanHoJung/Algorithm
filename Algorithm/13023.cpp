#include <iostream>
#include <vector>
using namespace std;
int N;//사람의 수
int M;//친구 관계 수

vector<int> edge[2001];//연결 그래프
bool check[2001];//방문 check

bool solve(int cnt, int node) {
	bool result = false;
	if (cnt == 4)
		return true;
	

	if (cnt > 4)
		return false;



	for (int i = 0; i < edge[node].size(); i++) {
		int next = edge[node][i];
		if (check[next] == false) {
			check[next] = true;
			result = solve(cnt + 1, next);
			check[next] = false;

		}

		if (result == true)
			return result;
	
	}

	return result;
	
}


int main(void) {

	cin >> N >> M;
	while (M--) {
		int start;
		int end;
		cin >> start >> end;
		edge[start].push_back(end);
		edge[end].push_back(start);
	}


	bool result;
	for (int i = 0; i < N; i++) {
		check[i] = true;
		 result= solve(0, i);
		check[i] = false;

		if (result == true)
			break;
	}

	if (result == true)
		cout << '1';
	else
		cout << '0';


}