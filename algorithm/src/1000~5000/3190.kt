package `1000~5000`

import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.Deque
import java.util.LinkedList
import java.util.StringTokenizer

private val dx = arrayOf(1, 0, -1, 0)
private val dy = arrayOf(0, 1, 0, -1)

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val N = br.readLine().toInt()
    val K = br.readLine().toInt()
    val board = Array(N+1) {Array(N+1) {0} }
    repeat(K) {
        val st = StringTokenizer(br.readLine())
        board[st.nextToken().toInt()][st.nextToken().toInt()] = 1
    }
    val L = br.readLine().toInt()
    val lt : Deque<IntArray> = LinkedList()
    repeat(L) {
        val st = StringTokenizer(br.readLine())
        val X = st.nextToken().toInt()
        if ( st.nextToken()=='D'.toString()) lt.add(intArrayOf(X, 0))
        else lt.add(intArrayOf(X, 1))
    }
    var d = 0
    var snake : Deque<IntArray> = LinkedList()
    snake.add(intArrayOf(0, 0))
    repeat(lt.peekFirst()[1]) {
        // 방향 틀어지는 지 확인
        if (lt.peekFirst()[0] == it+1) {
            if (lt.peekFirst()[1] == 0)
                d = (d+1) % 4
            else
                d = (d+3) % 4
        }
        // 움직일 부분
        val x = lt.peekLast()[0] + dx[d]
        val y = lt.peekLast()[1] + dy[d]
    }

}