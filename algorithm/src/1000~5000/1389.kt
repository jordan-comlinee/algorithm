package `1000~5000`

import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

private var N = 0
private var M = 0
private lateinit var friends : MutableMap<Int, MutableList<Int>>

fun bfs(target: Int) : Int {
    var bacons = IntArray(N+1){-1}
    var q : Queue<Int> = LinkedList()
    q.offer(target)
    bacons[target] = 0
    while (q.isNotEmpty()) {
        val current = q.poll()
        for (neighbor in friends[current] ?: mutableListOf()) {
            if (bacons[neighbor] == -1) {
                bacons[neighbor] = bacons[current]+1
                q.offer(neighbor)
            }
        }
    }
    return bacons.sum()+1
}

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val st = StringTokenizer(br.readLine())
    N = st.nextToken().toInt()
    M = st.nextToken().toInt()
    friends = mutableMapOf()
    val result = IntArray(N+1) {Int.MAX_VALUE}
    repeat(M) {
        val st2 = StringTokenizer(br.readLine())
        val one = st2.nextToken().toInt()
        val two = st2.nextToken().toInt()
        friends.getOrPut(one) { mutableListOf() }.add(two)
        friends.getOrPut(two) { mutableListOf() }.add(one)
    }
    for (i in 1..N) {
        result[i] = bfs(i)
    }
    println("${result.indexOf(result.min())}")
}