package softeer

import java.io.*
import java.util.PriorityQueue
import java.util.StringTokenizer

private var N = 0
private var start = 0
private var end = 0
private lateinit var p : Array<Pair<Int, Int>>
private var result = 0
private var latest_start = Int.MAX_VALUE

private fun input_data() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    N = br.readLine().toInt()
    p = Array(N) {Pair(0, 0)}
    repeat(N) {
        val st = StringTokenizer(br.readLine())
        start = st.nextToken().toInt()
        end = st.nextToken().toInt()
        p[it] = Pair(start, end)
    }
    p.sortWith(compareBy({it.first}, {it.second}))
}

private fun solution() {
    for (i in N-1 downTo 0) {
        //println("${p[i].first} ${p[i].second}")
        if (latest_start >= p[i].second) {
            result += 1
            latest_start = p[i].first
        }
    }
}



fun main() {
    input_data()
    solution()
    println(result)
}