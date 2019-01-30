# 알고리즘(기초)

[TOC]



## 수학

> ### 나머지 연산

컴퓨터의 수의 범위는 한정적이기 때문에 Big number를 표현할 수 없다. 때문에, 그 수가 큰 경우 나머지 연산을 통해 답을 출력하라는 문제가 등장한다.

ex)

정수 자료형(int=> 2<sup>31</sup> -1, long=> 2<sup>63</sup>-1≈10<sup>18</sup>)

- **(A + B)mod M = ((A mod M) + (B mod M)) mod M**

- **(A * B)mod M = ((A mod M) * (B mod M)) mod M**

- (A - B)mod M = ((A mod M) - (B mod M) + M) mod M

- 나누기의 경우에는 성립하지 않는다.(Modular Inverse 적용, 페르마의 소정리)

  ```
  (6/3) % 3 = 2 % 3 = 2
  (6%3 / 3%3)%3 = (0/0)%3
  성립하지 않음
  ```



> ### 최대 공약수(GCD)

두 정수 A,B가 존재할 때 A와 B의 공통된 약수 중 가장 큰 정수를 **최대 공약수**라고 정의한다.

- 최대 공약수가 1인 두 수를 서로소(Coprime)라 한다.

- 최대 공약수 문제는 기약분수 형태로 출력하라는 문제에서 쓰이는 경우가 많다.

- 예를 들어 18/24 라는 수가 존재할 때 두 수의 최대공약수 6으로 나누게 되면 3/4 기약분수 형태가 된다.

```
ex)

24의 약수:1, 2, 3, 4, 6, 8, 12, 24

18의 약수:1, 2, 3, 6, 9, 18

24와 18의 공약수:1, 2, 3,6

최대 공약수:6
```

최대 공약수 찾는 방법: 유클리스 호제법

A>B일때, A%B r이라고 정의하자

GCD(A,B)

GCD(B,r)

r이 0이면 B가 최대 공약수 이다.

시간복잡도:O(logn)



> ### 최소 공배수(LCM)

두 정수 A,B가 존재할 때 A, B의 공통된 배수 중에서 가장 작은 정수

LCM = A*B/GCD 를 통해 구할 수 있다.



> ### 소수 찾기

소수란, 약수가 **1**과 **자기 자신 밖에 없는 수** 를 의미한다.



**어떤 수 N 소수 판별** 시간복잡도 O(루트 N)

**1~N 사이의 수 소수 판별** 시간복잡도 O(루트 N루트N)



**소수 판별법**

- 첫 번째 방법

  2보다 크고 N-1보다 작거나 같은 자연수로 나누어 떨어지면 소수가 아니다.

  2보다 크고 N-1보다 작거나 같은 자연수로 나누어 떨어지지 않으면 소수이다.

  ```c++
  bool primeCheck(int n){
      if(n<2){
          return false;
      }
      
      for(int i=2; i<=n-1; i++){
          if(n%i==0)
              return false;
      }
      
      return true;
  }
  
  //시간 복잡도 O(N)
  ```

- 두 번째 방법

  2보다 크고 N/2보다 작거나 같은 수로 나누어 떨어지면 소수가 아니다.

  2보다 크고 N/2보다 작거나 같은 수로 나누어 떨어지지 않으면 소수 이다.

  **어떤 수 N이 소수가 아니라면**

  N= a * b(a>1,a와 b는 자연수, a가 작을 수록 b는 크다.)라고 가정하자

  **N=2일때**

  a가 가질 수 있는 최소값은 2 이다. 그 때, b가 가질 수 있는 값은 b/2 이다.



  **N=3일때**

  a가 3일때, 그 때 b가 가질 수 있는 값은 b/3 이다.

  a가 가장 작을때 b가 가장 큰 값이므로 b는 N/2를 넘지 않는다.

```C++
bool primeCheck(int n){
    if(n<2){
        return false;
    }
    
    for(int i=2; i<=n/2; i++){
        if(n%i==0)
            return false;
    }
    
    return true;
}

//시간 복잡도 O(N/2)
```



- 세 번째 방법

​       2보다 크고 루트 N보다 작거나 같은 수로 나누어 떨어지면 소수가 아니다.

​       2보다 크고 루트 N보다 작거나 같은 수로 나누어 떨어지지 않으면 소수 이다.

​      **어떤 수 N이 소수가 아니라면**

​       N= a * b(a>1,  a<=b,  a<=루트n, b>=루트n) 이라 가정하자

​       a * b <= 루트 n * 루트 n = n

​       ex)

​        24의 약수 1, 2, 3, 4, 6, 8, 12, 24

​         루트 24=>4.xxx

​         1,2,3,4 |  6, 8, 12, 24

​         4까지 검사하면 모든 조합이 완성됨으로 4까지만 검사하면 된다.

```c++
bool primeCheck(int n){
    if(n<2){
        return false;
    }
    
    for(int i=2; i*i<=n; i++){
        if(n%i==0)
            return false;
    }
    
    return true;
}

//시간 복잡도 O(루트n)
2<= i <= 루트 n
i^2 <= n

```



- 네번째 방법

  **에라토스테네스의 체**

​       1부터 N까지 범위 안에 들어있는 모든 소수를 찾는 방법 입니다.

​        시간복잡도 O(N*log<sup>logn</sup>)

                1. 2부터 N까지 모든 수를 써놓는다.
                2. 아직 지워지지 않은 수 중에서 가장 작은 수를 찾는다.
                3. 그 수는 소수이다.
                4. 이제 그 수의 배수를 모두 지운다.

(참고 예제)


​      https://ko.wikipedia.org/wiki/%EC%97%90%EB%9D%BC%ED%86%A0%EC%8A%A4%ED%85%8C%EB%84%A4%EC%8A%A4%EC%9D%98_%EC%B2%B4

1부터 100까지 수가 있을 때      

2, 3, 5, 7 소수에 대하여 1~4과정을 수행하면 11의 배수는 이미 지워져 있으므로 더 이상 수행할 필요가 없다.

```c++
#include <iostream>
using namespace std;
int primeNumber[100];
int cnt=0;
int n=100;
bool check[101];

for(int i=i; i<=n; i++){//루트 n까지(i<=루트n) 검사해도 되지만, 우리는 prime 수를
                        //primeNumber배열에 모두 저장하기 위해서
    if(check[i]==false){
        primeNumber[cnt++] = i;
        //이 부분이 loglogn 복잡도
        for(int j=i*i; j<=n; j=j+i){
            check[j]=true;
        }
        //
    }
}

for(int i=i; i<=n; i++){
    if(check[i]==false){
        primeNumber[cnt++] = i;
        for(int j=i*2; j<=n; j=j+i){  //i*i 할 경우 n이 100만 인 경우 int 범위 초과나기때문에
            check[j]=true;
        }
    }
}

```



## 브루트 포스

**브루트 포스**: 모든 경우의 수를 시도하는 알고리즘 이다.

=> 이 때, 모든 경우의 수를 다 해보는데 **문제의 시간 제한**을 넘지 않아야 한다.

> 1단계: 문제의 가능한 경우의 수를 계산하기
>
> ```
> 비밀번호 4자리, 0~9
> 10*10*10*10 =10000가지
> ```
>
> 2단계:가능한 모든 방법을 다 만들어 본다.
>
> ```
> 0000
> 0001
> ...
> 9999
> ```
>
> 3단계:각각의 방법(순열, 재귀함수,bfs,비트마스크, for 문 등)을 이용해 답을 구해본다.
>
> =>3단계에서 코딩을 하는 단계



- 브루트 포스에서 경우의 수가 너무 많아서 시간 제한을 넘을 경우에는 **건너 뛰며** 해보는 방법이 있다.

  정답이 안 될 요소를 배제하면서 경우의 수르 줄여 시간 제한안에 문제를 해결할 수 있다.

  **(카잉달력,  날짜계산)**

**순열**

- 1~N까지의 수가 있을 때, 크기는 항상 N이 되어야 하고, 겹치는 숫자가 존재하지 않음
- 총 경우의 수 N!
- C++의 next_permutation , prev_permutation 라이브러리를 사용해도 된다.
- 모든 순열을 만드는 복잡도 O(N*N!) //N은 다음 순열을 구하는 시간 복잡도이다.
- N<=10일 때, 1초 안에 문제를 풀 수 있다.



**재귀**

- 재귀함수는 설계가 중요하다.
- 코드를 작성하기 전
  - 재귀 함수의 호출이 불가능한 경우
  - 정답을 찾은 경우
  - 다음 경우 호출

```
cf)
만약 조건에 위배되었는데도 그냥 계속 경우를 구하고 종료조건에서 조건에 맞는지 검사하는 방법은
재귀를 이용한 브루트 포스 알고리즘 이라고 한다.
그러나 조건이 위배되었으면 탐색을 바로 종료하면 백트래킹이라 한다.
```





**비트마스크**

- 어떤 그룹을 나눌 때 들어간다 안들어간다 즉, 0과 1로 나눌 수 있을 때 사용한다.

- 비트(0,1 bit)연산을 사용해서  부분집합을 모두 표현하는것을 의미한다.

  - 비트마스크를 이용하면, <u>정수로 집합</u>을나타낼 수 있습니다.(해당 정수 하나가 부분집합 하나를 나타냄)

  ​       (집합안에는 같은 원소가 있을 수 없다.)

  - 즉, 비트마스크는 0부터 N-1 원소로 만들 수 있는 집합을 의미한다.

  - 비트 마스크로 집합을 나타낼 때, 예를 들어

    {1,3,4,5,9} // 570 = 2<sup>1</sup>+2<sup>3</sup>+2<sup>4</sup> +2<sup>5</sup>+2<sup>9</sup>=01000111010(2)

    배열로 이를 나타내면

    int c[11];

    c[0]=0 c[1]=1 ...c[10]=0

    공간적으로 많은 크기가 필요하지만, 비트 마스크를 사용하면 정수 하나로 부분집합을 모두 표현할 수 있다. 

  - 보통 0부터 N-1 까지 정수로 이루어진 집합을 나타낼 때 사용한다.

    그 이유는 1부터 N까지 정수로 이루어진 집합을 사용하면 0의 공간이 다 버려지기 때문입니다.

  - 비트마스크에서 어떤 수가 포함되어 있으면 1이 들어가 있고 포함되어 있지 않으면 0이 들어가 있다.

    ```
    비트 마스크를 S라고 하고, i를 찾고 싶은 원소라고 가정하자
    
    {1,3,4,5,9} = 570
    1000111010(2) = 570
    
    <포함 여부 검사>
    S & (1<<i) //결과가 0이면 없음
                       (1<<i)이면 있음
    3이 포함되어 있는지 검사                   
    1000111010(2)
    0000001000(2)
    ----------------
    0000001000(2) 
    
    <새로운 수 추가>
    S | (1<<i)
    2를 추가
    1000111010(2)
    0000000100(2)
    ----------------
    1000111110(2) 
    
    
    <제거 연산>
    S & ~(1<<i)
    1을 제거
    1000111010(2)
    1111111101(2)
    ----------------
    1000111000(2) 
    
    <토글 연산>//1을 0으로 0을 1로
    S ^ (1<<i)
    
    <전체 집합>
    (1<<N)-1 
    
    ex)
    n=3
     1000
    -0001
    -----------
      111=>{0,1,2}를 원소로 가짐 총 8가지 원소를 표현할 수 있다.
    
    <공집합>
    0
    ```

    ```
    0 ~2 =>{0,1,2}
    000(0)=>{공집합}
    001(1)=>{0}
    010(2)=>{1}
    011(3)=>{0,1}
    100(4)=>{2}
    101(5)=>{0,2}
    110(6)=>{1,2}
    111(7)=>{1,2,3}
    ```

    ```c++
    /*1182 부분집합의 합 문제*/
    #include <iostream>
    using namespace std;
    int arr[20];
    int main(void) {
    	
    	int n, s;//n(정수의 개수), s(찾을려는 수)
    	int cnt = 0;
    	cin >> n >> s;
    
    	for (int i = 0; i < n; i++) {
    		scanf("%d", &arr[i]);
    	}
    
    	//(1<<n) == 2^n 같다.
    	//부분집합의 개수 공식: 2^n
    	//공집합 제거한 부분집합 개수 공식: 2^n -1
    	//공집합은 제거하라고 하였으므로 1부터 시작한다.
    	for (int i = 1; i < (1 << n); i++) {
    		int sum = 0;
    		for (int k = 0; k < n; k++) {
    
    			if (i &(1 << k)) {
    				/*
    				i가 3일때
    				3이라는 수에 
    				0이 있는지
    				1이 있는지
    				...
    				n-1이 있는지 검사
    				*/
    				sum = sum + arr[k];
    			}
    
    		}
    		if (s == sum)
    			cnt++;
    	}
    
    	cout << cnt << "\n";
    }
    ```

- AND, OR , NOT, XOR, SHIFT

- 아래와 같은 수를 Bit 연산한다고 할 때, 2진수로 변환 후 가장 뒤의 자리 수 부터 비트연산을 진행한다.

- NOT 연산자의 경우 unsigned, signed에 따라서 보여지는 값은 다르다.

  A=83=1010011(2)

  ~A=10101100(2)

  unsigned 

  ~A = 2<sup>7</sup>+ 2<sup>5</sup>+2<sup>3</sup>+ 2<sup>2</sup> =172

  signed

  ~A = -84

|  A   |  B   |  ~A  | A&B  | A\|B | A^B  |
| :--: | :--: | :--: | :--: | :--: | :--: |
|  0   |  0   |  1   |  0   |  0   |  0   |
|  0   |  1   |  1   |  0   |  1   |  1   |
|  1   |  0   |  0   |  0   |  1   |  1   |
|  1   |  1   |  0   |  1   |  1   |  0   |

- shift연산은 shift left(<<), shift right(>>) 연산이 존재합니다.

- A<<B는 A * 2<sup>B</sup>와 같다.

- A>>B는 A /  2<sup>B</sup>와 같다.

  ```
  A<<B(A를 왼쪽으로 B 비트만큼 이동시킨다.)
  1 << 0  = 1
  1 << 1 = 2 (10(2))
  1 << 2 = 4 (100(2))
  1 << 3 = 8 (1000(2))
  
  A>>B(A를 오른쪽으로 B비트만큼 이동시킨다.)
  1 >> 0 = 1
  1 >> 1 = 0 (0(2))
  10 >> 1 = 5 (101(2))
  10 >> 2 = 10 (10(2))
  10 >> 3 = 1 (1(2))
  1024 >>10 = 1 (1(2))
  
  ```




## 브루트 포스 - N과 M

N과 M 문제는 재귀 함수를 연습해 볼 수 있는 좋은 문제입니다.

우선, 이 문제에서 풀이법은 두 가지로 나누어 볼 수 있습니다.

**첫째, 자리를 만들어 놓고 채우는 방법(O(N<sup>M</sup>)**

m개의 자리 수를 만들어 놓고 자리에 수를 채어 넣는 방법



**둘째, 1~N까지 수 중 M의 자리 까지 선택 할 건지 말 건지 결정하는 방법(O(2<sup>M</sup>)**

예를 들어, 1<=n<=3 , m이 2자리 수 라고 하였을 때

1(0,x) 2(0,x) 3(0,x) => 경우의 수는 2 * 2 * 2 = 8가지 경우수가 나오게 됩니다.



## 그래프와 BFS

**그래프**:정점과 관계를 저장한 자료구조

>  **경로**:정점에서 다른 정점으로 가는 방법
>
> > **단순 경로**: 같은 정점을 두 번이상 방문하지 않는 경로

> **사이클**:시작 정점과 도착 정점이 같은 경로를 사이클이라 한다.
>
> > **단순 사이클**: 같은 정점을 두번이상 방문하지 않는 사이클

> **방향 있는 그래프:** 간선에 방향이 있는 그래프

> **방향 없는 그래프(양방향 그래프)** : 간선에 방향이 없는 그래프

> **가중치:** 간선을 방문할 때의 비용(가중치가 없는 경우는 1이라고 생각하면 된다.)

> **차수:**정점에 연결되어있는 간선의 개수
>
> > In-degree: 방향있는 그래프에서 해당 정점 안으로 들어오는 간선을 의미한다.
> >
> > out-degree:방향있는 그래프에서 해당 정점 밖으로 나가는 간선을 의미한다.

> **그래프의 표현**
>
> >  **인접행렬**
> >
> >  간선의 연결을 2차원 배열 형태로 표현한 것
> >
> >  정점을 V라고 할 때, V * V 크기의 이차원 배열을 이용한다.
> >
> >  `Graph[i][j]` 
> >
> >  (i->j가 연결되어 있으면, 1) 그런데 만약 그래프의 가중치가 있을 경우 1 대신 가중치의 값이 저장 된다.
> >
> >  (i->j가 연결되어 있지 않으면, 0) 
> >
> >  **공간복잡도**
> >
> >  O(V<sup>2</sup>)
> >
> >  **장점**
> >
> >  배열로 구성되어 있기 때문에 해당 정점의 연결 여부를 확인하는데 시간 복잡도는 O(1) 걸린다.
> >
> >  **단점**
> >
> >  배열의 공간이 인접리스트 보다 많이 필요하다.
>
> 
>
> > **인접리스트**
> >
> > 연결 리스트를 이용하여 정점의 연결을 표현한 것(vector, ArrayList 라이브러리 이용)
> >
> > `vector<int> Graph[v]`
> >
> > Graph[1].pushback(3)//해당 정점을 연결한다.
> >
> > Graph[1].pushback(4)
> >
> > **공간복잡도**
> >
> > O(E) //E는 간선의 개수(차수)
> >
> > **장점**
> >
> > 인접 행렬보다 저장공간이 많이 필요하지 않다. 그 이유는 인접행렬은 연결 안된 여부까지 포함하기 때문이다.
> >
> > **단점**
> >
> > 완전 그래프:그래프의 모든 정점 사이에 간선이 존재 
> >
> > 이러한 경우는, 인접리스트가 비효율적이다. 그 이유는 인접행렬만큼의 크기의 공간이 필요하고
> >
> > 정점 1과 5의 연결 정보를 파악한다 할때, 인접행렬 보다 많은 탐색시간 O(E)의 시간이 소비되기 때문이다. 
> >
> > 완전 그래프 일때는 인접행렬 방법이 더 효율적이다.
> >
> > ```
> > 완전 그래프 간선의 개수
> > E = v(v-1)/2
> > v개 중 2개의 선을 고르는 경우의 수(조합)
> > ```
>
> 
>
> >**간선리스트**
> >
> >만약, 라이브러리를 사용하지 못하는 경우 간선리스트를 이용하여 인접리스트를 구현할 수 있다.
> >
> >1. 모든 간선을 순서대로 배열에 저장한다.(pair형태로, 시작정점과 도착 정점 저장)
> >2. 오름차순으로 정렬한다.(배열의 시작정점 기준으로 정렬한다.)
> >3. 각각의 시작정점의 개수를 cnt배열에 저장한다.
> >4. cnt배열의 누적합을 구한다.
> >5. cnt[i]~cnt[i+1] 값 사이의 범위는 정점 i+1에 연결된 간선을 의미한다.
>
> 
>
> > **그래프 탐색 방법**
> >
> > 목표:임의의 시작점 X에서 시작해서 모든 정점을 한 번씩 탐색하는 방법
> >
> > > DFS(깊이 우선 탐색)
> >
> > 한 정점에서, 방문할 수 있는 정점을 갈 수 있는 만큼 방문하고 방문할 수 없는 경우에는 이전 정점으로 돌아온다.(STACK으로 구현)
> >
> > ```C++
> > //인접행렬로 구현
> > void dfs(int node){
> > check[node]=true;
> > printf("%d ",node);
> > 
> > for(int i=1; i<=n; i++){
> > if(edge[node][i]==1 && check[i]==false){//이 부분을 기준으로
> > dfs(i);
> > }
> > }
> > }
> > 
> > dfs함수는 총 V(정점의 개수 만큼 호출된다.)=>총 V번 호출
> > dfs함수 한 번 수행시 시간복잡도 O(V)//인접행렬은 모든 정점이 연결되어 있는지 검사해야함으로
> > 시간복잡도 O(V^2)
> > 
> > //인접리스트로 구현
> > void dfs(int node){
> > check[node]=true;
> > printf("%d ",node);
> > 
> > for(int i=1; i<=edge[node].size(); i++){
> > if(check[i]==false){//이 부분을 기준으로
> > dfs(i);
> > }
> > }
> > }
> > dfs함수는 총 V(정점의 개수 만큼 호출된다.)=>총 V번 호출
> > dfs함수 한 번 수행시 시간복잡도 O(E)//간선의 개수 만큼만 방문
> > edge[node].size()는 전체 간선의 개수가 아니라 한 정점에 연결된 간선의 개수를 의미
> > 시간복잡도 O(V+E)
> > 
> > ```
> >
> > 
> >
> > > BFS(너비 우선 탐색)
> > >
> > > 한 정점에서 연결된 모든 정점을 큐에 넣고
> > >
> > > ```c++
> > > //인접행렬로 구현
> > > void bfs(int node) {
> > > 	queue<int> q;
> > > 	q.push(node);
> > > 	check[node] = true;
> > > 
> > > 	while (!q.empty()) {
> > > 		int node = q.front();
> > > 		printf("%d ", node);
> > > 		q.pop();
> > > 
> > > 		for (int i = 1; i <=n; i++) {
> > > 			if(edge[node][i]==1 && check[i]==false) {//이 부분을 기준으로
> > > 				check[i] = true;
> > > 				q.push(i);
> > > 			}
> > > 		}
> > > 
> > > 	}
> > > 
> > > }
> > > 
> > > bfs함수는 총 V(정점의 개수 만큼 호출된다.)=>총 V번 호출
> > > bfs함수 한 번 수행시 시간복잡도 O(V)//인접행렬은 모든 정점이 연결되어 있는지 검사해야함으로
> > > 시간복잡도 O(V^2)
> > > 
> > > //인접리스트로 구현
> > > void bfs(int node) {
> > > 	queue<int> q;
> > > 	q.push(node);
> > > 	check[node] = true;
> > > 
> > > 	while (!q.empty()) {
> > > 		int node = q.front();
> > > 		printf("%d ", node);
> > > 		q.pop();
> > > 
> > > 		for (int i = 0; i < edge[node].size(); i++) {
> > > 			int next = edge[node][i];
> > > 			if (check[next] == false) {
> > > 				check[next] = true;
> > > 				q.push(next);
> > > 			}
> > > 		}
> > > 
> > > 	}
> > > }
> > > bfs함수는 총 V(정점의 개수 만큼 호출된다.)=>총 V번 호출
> > > bfs함수 한 번 수행시 시간복잡도 O(E)//간선의 개수 만큼만 방문
> > > edge[node].size()는 전체 간선의 개수가 아니라 한 정점에 연결된 간선의 개수를 의미
> > > 시간복잡도 O(V+E)
> > > 
> > > ```
> > >
> > > - BFS는 **최단 거리**를 구하는 알고리즘이다.//브루트 포스로도 가능
> > >
> > > BFS는 모든 정점을 한 번씩 방문하는 알고리즘인데, 이것이 왜 최단 거리를 구하는 알고리즘이 되는 이유는 다음 조건을 만족하면 위의 말이 성립된다.
> > >
> > > - 최소 비용 문제이어야 한다.
> > >
> > > - 간선의 가중치가 1이어야 한다.
> > >
> > > ex)
> > >
> > > 거리의 최소값을 구하는 문제라면, 가중치는 거리를 의미
> > >
> > > 시간의 최소값을 구하는 문제라면, 가중치는 시간을 의미
> > >
> > > - 정점과 간선의 개수가 적어야 한다.
> > >
> > > (적다는 것은 문제의 조건에 맞춰서 해결할 수 있다는 것을 의미한다.)
> > >
> > > 
> > >
> > > cf)
> > >
> > > dfs:시작점에서 도착점으로 갈 수 있냐 없냐를 찾을 수 있습니다. 그러나, 그 경로가 최단거리 임을 보장할 수 없습니다.
> > >
> > > 
> > >
> > > BFS 덱 사용하기(1)
> > >
> > > - 덱(Deque):Double ended queue, 양쪽(왼쪽 끝, 오른 쪽)에서 push와 pop을 할 수 있는 자료구조
> > >
> > > - BFS는 가중치가 1일 때 사용할 수 있는데 가중치가 다르면 사용할 수 없다.
> > >
> > > 예를 들어
> > >
> > > ```
> > > 숨바꼭질3 문제
> > > +1(1초) -1(1초) *2(0초)
> > > 
> > > 5번 점에서 시작일때
> > > 5
> > > 6(1) 4(1) 10(0)  
> > > 7(2) 12(0) 3(2) 11(1) 9(1) 20(1)
> > > ...
> > > 가중치가 뒤죽박죽 섞이게 된다.
> > > 이렇게 되면 어떤 높이일 때 최소인지를 찾기가 어려워진다.
> > > (즉, BFS는 단계별로 진행하면서 최소인지를 찾을 수 있는 법칙이 깨지게 됨으로 BFS 탐색이 의미 없게 됨)
> > > ```
> > >
> > > cf)그래프와BFS(P141)참조
> > >
> > > 때문에 이 문제를 해결하는 방법은 2가지가 있다.
> > >
> > > 1. 두 개의 큐를 사용하기
> > > 2. 덱(Deque)사용하기
> > >
> > > 
> > >
> > > BFS 덱 사용하기(2)
> > >
> > > 1의 경우 시작점이 하나 입니다. 만약 시작점이 두 개인 경우 
> > >
> > > 각 시작점에서 BFS를 따로 돌립니다.
> > >
> > > 그 후, 어떤 좌표를 기준으로 그 좌표가 가중치가 1인 부분에서는 -1을 해줍니다.
> > >
> > > 탈옥 문제가 대표적인 예 입니다.
> > >
> > > https://www.acmicpc.net/problem/9376
> > >
> > > 
> > >
> > > BFS 시작점, 도착점
> > >
> > > - 문제에서 BFS 시작점과 도착점이 명확하지 않을 때 만약, 어떠한 배열이 주어지면 그 부분을 확장시켜서 임의의 점을 지정해두고 풀면 된다.
> > > - 탐색을 하다가 어떠한 조건 때문에 방문해야할 노드를 방문하지 못할때는 노드를 저장할 큐를 더 만들어서 저장해 두었다가 그 조건이 true가 되면 현재 돌고있는 node에 추가해주면 바로 탐색할 수 있다.
> > > - 열쇠 문제가 대표적인 예 입니다.
> > >
> > > 
> > >
> > > BFS, 순열 문제
> > >
> > > - 예를 들어 어떤 문제에서 시작점, 도착지점(1), 도착지점(2), 도착지점(3)의 최단 거리를 구하는 문제라고 가정 해봅시다. 시작지점에서 도착지점 어떤 것을 선택함에 따라 어느 값이 최단 거리임을 모르기 때문에 모든 경우를 생각해봐야 합니다.
> > > - 시작점, 도착지점(1~3)까지 bfs 탐색을 합니다.(탐색을 하면서 dist 구하기)
> > > - 그 후 지금 현재 시작점, 도착지점까지 총 4개의 노드
> > > - 시작점을 기준으로 하여 도착지점(1~3)까지 순열을 구합니다. 그 후 최소값을 구하면 최단거리를 구할 수 있습니다.
> > >
> > > 
> > >
> > > BFS, 다이나믹 문제
> > >
> > > - 예를 들어 어떤 도착지점을 방문하는데 최단거리를 구하고 그것에 대한 방법을 구하고 싶을 때는 BFS+다이나믹을 적용해야 합니다.
> > > - BFS는 단순히 최단거리만 나타내고 그것에 대한 방법을 구할 수 없기 때문에 다이나믹을 적용하면 방법의 수 까지 구할 수 있습니다.
> > >
> > > 

cf)특별한 언급이 없으면 경로와 사이클은 단순 경로/사이클을 의미한다.



## 다이나믹 프로그래밍

- 정의: 큰 문제를 작은 문제로 나눠서 푸는 알고리즘

  cf)분할정복과 차이는 다이나믹은 작은 문제가 중복이 된다.

  ​    그러나 분할정복은 작은 문제가 중복이 되지 않고, 모든 작은 문제가 한 번만 나온다. 

  - Overlapping Subproblem

    - 부분 문제가 겹친다.
    - 큰 문제와 작은 문제를 같은 방법으로 풀 수 있다.
    - 문제를 작은 문제로 쪼갤 수 있다.

    ```
    피보나치 수
    F0 = 0
    F1 = 1
    Fn = Fn-1+Fn-2 (n>=2)
    
    Fn(큰 문제) = Fn-1(작은 문제1)+Fn-2(작은 문제2) (n>=2)
    - 문제:N번째 피보나치 수를 구하는 문제
    - 작은 문제: N-1번째 피보나치 수를 구하는 문제, N-2번째 피보나치 수를 구하는 문제
    
    - 문제:N-1번째 피보나치 수를 구하는 문제
    - 작은 문제: N-2번째 피보나치 수를 구하는 문제, N-3번째 피보나치 수를 구하는 문제
    
    - 문제:N-2번째 피보나치 수를 구하는 문제
    - 작은 문제: N-3번째 피보나치 수를 구하는 문제, N-4번째 피보나치 수를 구하는 문제
    ...
    
    =:작은 문제가 중복해서 나옴
    =>큰 문제를, 작은 문제로 나누고 작은 문제를 이용하여 원래의 문제로 푸는 형태를 취하고 있다.
    ```

  - Optimal Substructure

    - 최적 부분 구조

    - 문제의 정답을 작은 문제의 정답에서 구할 수 있다.

      ```
      서울에서 부산을 가는 가장 빠른 길이 대전,대구를 순서대로 거쳐야 한다면
      대전에서 부산을 가는 가장 빠른 길은 대구를 거쳐야 한다.
      ```


  - Memoization

    다이나믹 프로그래밍은 Optimal Substructure를 만족하기 때문에, 같은 문제는 구할때마다 정답이 같다.

    때문에, 정답을 구했을때 그 정답을 어디에 저장해 놓는것이 memoization이다.



- 문제 풀이법

  - Top-down(재귀)
  - Bottom-up(for문)

- 시간복잡도

  O(전체문제의개수 * 1문제를 푸는 시간)



문제풀이전략

- 점화식을 정의
- 문제를 작은 문제로 쪼개기
- 답을 구하기



## 코딩 기법

> 인덱스로 2차원 좌표 구하기

```c++
int arr[9] = {1,2,3,4,5,6,7,8,9};
arr 배열의 index가 4인 요소의 2차원 좌표는
4/3(행의크기)=1
4%3(열의크기)=1
```



> 행과열 늘리기

```c++
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(void) {
	int t;
	cin >> t;

	while (t--) {
		int h, w;
		cin >> h >> w;

		vector<string> prision(h+2);
		h = h + 2;
		w = w + 2;
		for (int i = 1; i < h - 1; i++) {
			cin >> prision[i];
			prision[i] = "." + prision[i] + ".";
		}
		

		for (int i = 0; i < w; i++) {
			prision[0] = prision[0] + '.';
			prision[h - 1] = prision[h - 1] + '.';
		}

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cout << prision[i][j];
			}
			cout << "\n";
		}


	}
}
```



> 3차원 배열

```c++
3차원 배열
int arr[4][5][3]
4행 5열 원소의 개수 3
```



> 1차원 인덱스로 2차원 좌표 값 찾기

4*3행렬이 있을 때 1차원 배열 index 10의 2차원 배열 좌표는 

```
10/3 =3 
10%3 =1
```

일반화 시키면 

height*width행렬이 있을 때 , 1차원 index 값 value

(x,y) = (value /width, value%width)



>2차원 좌표로 1차원 인덱스 찾기

9 * 9 행렬이 있을 때 2차원 배열 좌표 (1,1)의 index의 값은

```d
1 * 9 + 1 = 10
```

일반화 시키면

height*width행렬이 있을 때, 1차원 배열의 인덱스는

index = x * width + y



> square 영역 구하기

원 행렬을 n * m으로 나눈 후 각 좌가 어떤 영역에 포함되는지 알고 싶을 때 다음과 방법을 사용한다.

예를 들어 8 * 8행렬에서 행과 열을 4로 나누어 (x,y)좌표가 해당되는 영역(0, 1, 2, 3)을 찾고 싶으면 다음과 같은 식을 도출할 수 있습니다.

(x/4)*2 + y/4

```
(x,y)=(5,5)
(5/4)*2 +5/4 =2+1=3
```

이것을 일반화 시키면, r은 원래 행렬을 가로로 나눈 수 , c는 원래 행렬을 세로로 나눈 수, k는 가로로 나눈 수의 길이 

(x/r) * k + y/c

![metrix01](./assets/metrix01.PNG)

![metrix02](./assets/metrix02.PNG)



## C++ 유용

> Tuple : 3가지 자료형을 저장할 수 있는 데이터 타입

```c++
int a, b, c;
tuple<int, int, int> t = make_tuple(1,2,3);
tie(a, b, c) = t;
cout << a << " " << b << " "<<c; //1 2 3
	
```



> 시뮬레이션 할 때 화면 멈추고 디버깅 

```c++
#include <conio.h>
#include <windows.h>

for (int i = 0; i < n; i++) {
	for (int j = 0; j < m; j++) {
		cout << MAP[i][j];
	}
		cout << "\n";
}
_getch();//키가 눌릴때까지 멈추기
system("cls");//화면 지우기
```



> MAP

```c++
map<vector<int,int>
map<string,int>
map<int,int>
int num=1234
map.count(1234) //return 0이면 만들어지지 않는것 return 1이면 만들어진것

```



> STRING

```c++
string str ="123"

/*자료형 변환*/
int number = stoi(str); //문자열 int로 반환                
String sentence = to_string(number); //int 문자열로 반환

/*특정 문자 탐색*/
int index = str.find('2'); //index반환

/*문자열 확장*/
string base = "hello world!";
base +="x"; //hello world!x
또는
base.append("x");////hello world!x

/*문자열 길이*/
string base ="123";
base.length();
또는
base.size();

/*특정 위치 문자 받기*/
string base = "hello world!"; 
base.at(0); // 'h' 
base.at(1); // 'e'


/*문자열 비교*/
string a = "I am string one! ;)"; 
string b = "string"
    
if (a.compare(b) == 0) { // 두 문자열이 같을 때 } 
else if (a.compare(b) < 0) { // a가 b보다 사전순으로 앞일 때 } 
 else if (a.compare(b) > 0) { // a가 b보다 사전순으로 뒤일 때 }


                     



```



> VECTOR(2차원 벡터 선언)

```C++
//int arr[6][5] 배열 선언. 0으로 값 초기화

vector<vector<int> > arr(6, vector<int>(5, 0));
=>첫번째 인자 6의 의미는 vector<int>형 벡터 6개(가로 6줄을 할당)
=>두번째 인자 vector<int>(5,0)의 의미는 모든 가로 줄은 5개짜리 0으로 초기화 된 익명의
   int 벡터 배열을 생성하여 초기값으로 넣게 됩니다.


//값 삽입

int serial = 0;

for (int i = 0; i < 6; i++)

    for (int j = 0; j < 5; j++)

        arr[i][j] = serial++;

 

//값 출력

for (vector<int> vec : arr) {

    for (int n : vec)

        printf("%3d ", n);

    cout << endl;

}
```

