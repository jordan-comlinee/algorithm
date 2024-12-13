package programmers

import kotlin.math.*
class `예상 대진표` {
    fun getNextNum(i : Int): Int {
        return (i+1)/2
    }

    fun solution(n: Int, a: Int, b: Int): Int {
        var answer = 1
        var newA = a
        var newB = b
        while ((abs(newA - newB) > 1) || getNextNum(newA) != getNextNum(newB)) {
            newA = getNextNum(newA)
            newB = getNextNum(newB)
            answer++
        }

        return answer
    }
}