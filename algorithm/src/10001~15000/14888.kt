package `10001~15000`

import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.LinkedList
import java.util.StringTokenizer

private lateinit var st : StringTokenizer
private var N = 0
private lateinit var A : IntArray
private lateinit var visited : BooleanArray
private val operands = mutableListOf<Int>()
private var result = mutableListOf<Int>()

private fun get_circulate(arr : MutableList<Int>) {
    var circulate = A[0]
    for (i in 0 until N-1) {
        if (arr[i] == 0) circulate += A[i+1]
        else if (arr[i] == 1) circulate -= A[i+1]
        else if (arr[i] == 2) circulate *= A[i+1]
        else if (arr[i] == 3) circulate /= A[i+1]
    }
    result.add(circulate)
}

private fun solution(idx : Int, resultArr : LinkedList<Int>) {
    if (resultArr.size == N-1) {
        //println(resultArr.size)
        //println(resultArr)
        get_circulate(resultArr)

        return
    }
    for (i in idx until N-1) {
        if (!visited[i]) {
            visited[i] = true;
            resultArr.offer(operands[i])
            //println(resultArr)
            solution(idx, resultArr)
            resultArr.pollLast()
            visited[i] = false;
        }
    }
}


fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    N = br.readLine().toInt()
    A = br.readLine().split(' ').map { it.toInt() }.toIntArray()
    visited = BooleanArray(N-1)
    st = StringTokenizer(br.readLine())
    repeat(4) { i ->
        val n = st.nextToken().toInt()
        repeat(n) { j ->
            operands.add(i)
        }
    }
    solution(0, LinkedList())
    println("${result.max()}\n${result.min()}")

}