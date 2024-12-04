package programmers

class Solution_4 {
    fun solution(s: String): String {
        var answer = ""
        var numbers = s.split(" ").map { it.toInt() }
        answer = "${numbers.min()} ${numbers.max()}"
        return answer
    }
}

fun main() {
    val solutionInstance = Solution_4() // Solution_4 클래스의 인스턴스 생성
    val result = solutionInstance.solution("-1 -2 -3 -4") // solution 메서드 호출
    println("$result") // 결과 출력
}