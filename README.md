# 알고리즘(기초)


### 수학

> 나머지 연산

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








