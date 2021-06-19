/**
* 2017 팁스타운
*
* 문제명:짝지어 제거하기
* 경로:https://programmers.co.kr/learn/courses/30/lessons/12973
* 일자:2021-06-12
* 작성자:VitaminDragon
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