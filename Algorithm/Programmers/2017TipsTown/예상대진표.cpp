/**
* 2017 팁스타운
*
* 문제명:예상대진표
* 경로:https://programmers.co.kr/learn/courses/30/lessons/12985
* 일자:2021-06-12
* 작성자:VitaminDragon
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int decison(int type) {

    return  type % 2 == 0 ? type / 2 : (type + 1) / 2;
}
int solution(int n, int a, int b)
{
    int answer = 0;

    while(a!=b){

        a = decison(a);
        b = decison(b);
        answer++;
        
    }

    return answer;
}

//int main(void) {
//    solution(8, 4, 7);
//}