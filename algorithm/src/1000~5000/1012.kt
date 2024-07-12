package `1000~5000`

import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.StringTokenizer

private lateinit var field : Array<Array<Int>>
private val dx = arrayOf(0, 0, 1, -1)
private val dy = arrayOf(1, -1, 0, 0)
private var N = 0
private var M = 0
private var K = 0
fun dfs(x : Int, y : Int) : Boolean{
    if (field[x][y] == 0) return false

    field[x][y] = 0
    for(i in 0 until 4) {
        val xx = x + dx[i]
        val yy = y + dy[i]
        if (xx !in 0 until M || yy !in 0 until N || field[xx][yy] == 0)
            continue
        dfs(xx, yy)
    }
    return true
}
fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val T = br.readLine().toInt()
    repeat(T) {
        var cnt = 0
        val st = StringTokenizer(br.readLine())
        M = st.nextToken().toInt()
        N = st.nextToken().toInt()
        K = st.nextToken().toInt()
        field = Array(M) {Array(N) {0} }
        repeat(K) {
            val st2 = StringTokenizer(br.readLine())
            field[st2.nextToken().toInt()][st2.nextToken().toInt()] = 1
        }
        repeat(M) { x ->
            repeat(N) { y ->
                if (dfs(x,y)) cnt++
            }
        }
        println(cnt)
    }
}