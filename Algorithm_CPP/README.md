# C++ 코딩테스트 Study

## 1. cin&cout VS scanf()&printf()


## 2. scanf_s() VS scanf()

scanf는 버퍼 오버플로우 문제가 발생할 수 있다.

* 버퍼 오버플로우란?
 프로세스가 데이터를 버퍼에 저장할 때 프로그래머가 지정한 곳 바깥에 저장하는 현상(컴퓨터가 만든 공간보다 프로그래머가 더 큰 값을 저장하는 경우) 

scanf_s는 이를 보완하여 사이즈를 넘어서면 저장을 아예 하지 않음!

## 3. 2차원 배열 동적 할당하는 방법?

### a. malloc 사용하기

### b. vector 컨테이너 사용하기