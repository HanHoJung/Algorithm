/**
* 2017 ����Ÿ��
*
* ������:¦���� �����ϱ�
* ���:https://programmers.co.kr/learn/courses/30/lessons/12973
* ����:2021-06-12
* �ۼ���:VitaminDragon
*/

#include <iostream>
#include <string>
#include <stack>
using namespace std;

int solution(string s)
{
	int answer = -1;
	string word = s;
	int length = word.length();

	stack<int> st;
	int idx = 0;
	//"a a"
	while (idx < length) {
		char ch = word[idx];
		if (st.empty()) {
			st.push(ch);
		}
		else {
			if (st.top() == ch)
				st.pop();
			else
				st.push(ch);
		}

		idx++;

	}

	if (st.empty())
		answer = 1;
	else
		answer = 0;

	return answer;
}

int main(void) {

	solution("baabaa");

}