package programmers

import java.util.*

class Solution_5 {
    fun solution(progresses: IntArray, speeds: IntArray): IntArray {
        var day = 0
        var cnt = 0
        var answer = intArrayOf()

        var progressQueue : Queue<Int> = LinkedList<Int>()
        var speedsQueue : Queue<Int> = LinkedList<Int>()

        for (i in 0 until progresses.size) {
            progressQueue.add(progresses[i])
            speedsQueue.add(speeds[i])
        }

        while(!progressQueue.isEmpty()) {
            if(progressQueue.element() + speedsQueue.element() * day >= 100) {
                progressQueue.remove()
                speedsQueue.remove()
                cnt++
            }
            else {
                if(cnt >= 1) {
                    answer = answer.plus(cnt)
                    cnt = 0
                }
                day++
            }
        }
        answer = answer.plus(cnt)

        return answer

    }
}