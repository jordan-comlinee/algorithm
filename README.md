# algorithm
<br><br>

<h2>RunTime을 줄이는 올바른 방법?</h2>
<br><br>
for문은 입출력 방식이 느리면 여러줄을 입력하거나 출력할 때 더 많은 시간이 소요된다.
Python을 사용하고 있다면, input 대신 sys.stdin.readline을 사용할 수 있다. 단, 이때는 맨 끝의 개행문자까지 같이 입력받기 때문에 문자열을 저장하고 싶을 경우 .rstrip()을 추가로 해 주는 것이 좋다.
