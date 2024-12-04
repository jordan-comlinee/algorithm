import java.io.BufferedReader
import java.io.InputStreamReader

private var N = 0
private lateinit var painting : Array<CharArray>
private lateinit var visited : Array<BooleanArray>
private var moving = arrayOf(Pair(1, 0), Pair(-1, 0), Pair(0, 1), Pair(0, -1))

fun isComplicated(time_prev: Int, time_cur: Int, diff: Int, level: Int) : Int{
    return (time_cur + time_prev)*(diff - level) + time_cur
}

fun calculateTotalTime(diffs : IntArray, times : IntArray, limit : Long, minLevel : Int) : Long {
    var totalTime = 0L
    for(i in diffs.indices) {
        if(minLevel >= diffs[i]) {
            totalTime += times[i]
        }
        else {
            totalTime += isComplicated(times.getOrElse(i-1) {0}, times[i], diffs[i], minLevel)
        }
        if (totalTime > limit) {
            return totalTime
        }
    }
    return totalTime
}

fun solution(diffs: IntArray, times: IntArray, limit: Long) : Int {
    var low = 1
    var high = diffs.maxOrNull()?:100000
    while (low <= high) {
        val mid = (low+high)/2
        val totalTime = calculateTotalTime(diffs, times, limit, mid)
        if (totalTime > limit) {
            low = mid + 1
        }
        else {
            high = mid - 1
        }
    }
    return low
}

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    var result = 0

}