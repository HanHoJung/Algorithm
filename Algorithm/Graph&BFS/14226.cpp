#include <iostream>
#include <queue>
using namespace std;

bool check[1001][1001];
int dist[1001][1001];
int main(void) {
	int s;
	cin >> s;

	queue<pair<int, int>> q;
	q.push(make_pair(1, 0));
	check[1][0] = true;


	while (!q.empty()) {

		int view = q.front().first;
		int clip = q.front().second;
		q.pop();

		if (view == s) {
			cout << dist[view][clip];
			break;
		}


		//1. ȭ�鿡 �ִ� �̸�Ƽ�� ��� ���� =>  Ŭ�����忡 ����
		int new_view = view;
		int new_clip = view;

		if (new_clip <= 1000) {

			if (check[new_view][new_clip] == false) {
				check[new_view][new_clip] = true;
				dist[new_view][new_clip] = dist[view][clip] + 1;
				q.push(make_pair(new_view, new_clip));
			}
		}
		//2. Ŭ���� �ִ� ��� �̸�Ƽ���� = > ȭ�鿡 �ٿ��ֱ�
		new_view = view + clip;
		new_clip = clip;
		if (new_view <= 1000) {
			if (check[new_view][new_clip] == false) {
				check[new_view][new_clip] = true;
				dist[new_view][new_clip] = dist[view][clip] + 1;
				q.push(make_pair(new_view, new_clip));
			}

		}
		//3. ȭ�鿡 �ִ� �̸�Ƽ�� �ϳ� ����
		new_view = view - 1;
		new_clip = clip;

		if (new_view >= 0) {
			if (check[new_view][new_clip] == false) {
				check[new_view][new_clip] = true;
				dist[new_view][new_clip] = dist[view][clip] + 1;
				q.push(make_pair(new_view, new_clip));
			}
		}

	}


}