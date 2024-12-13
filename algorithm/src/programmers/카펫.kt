package programmers

class 카펫 {
    fun solution(brown: Int, yellow: Int): IntArray {
        var answer = intArrayOf(0, 0)
        var multiple = brown + yellow
        var sum = (brown+4)/2
        for (i in 1..sum/2) {
            if(i * (sum - i) == multiple) {
                answer.set(0, sum-i)
                answer.set(1, i)
            }
        }
        return answer
    }
}