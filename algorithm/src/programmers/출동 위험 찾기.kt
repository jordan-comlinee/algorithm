package programmers

class Solution_3{
    var board = Array(101) {IntArray(101) {0} }
    var pointMap : MutableMap<Int, Pair<Int, Int>> = mutableMapOf()
    fun allRobotsArrived(robotArrived : BooleanArray) : Boolean {
        for (i in robotArrived) {
            if (!i) return false
        }
        return true
    }
    fun move(routes: Array<IntArray>) {

    }
    fun solution(points: Array<IntArray>, routes: Array<IntArray>): Int {
        var answer: Int = 0
        var robots: Int = routes.size
        var robotArrived = BooleanArray(robots) {false}
        for ((idx, p) in points.withIndex()) {
            pointMap[idx+1] = Pair(p[0], p[1])
        }
        while(!allRobotsArrived(robotArrived)) {
            move(routes)
        }
        return answer
    }
}