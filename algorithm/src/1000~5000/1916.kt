// 나무위키를 통해 다익스트라 알고리즘 이해 필요
// https://namu.wiki/w/%EB%8B%A4%EC%9D%B5%EC%8A%A4%ED%8A%B8%EB%9D%BC%20%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98
package `1000~5000`
import java.io.*
import java.util.*
import kotlin.collections.ArrayList

private lateinit var list : MutableList<MutableList<Node>>
private lateinit var dist : IntArray
private const val INF = Int.MAX_VALUE/4
private var N = 0
private var M = 0
// 노드 구하기
private class Node(var nodeNum : Int, var weight : Int) : Comparable<Node> {
    override fun compareTo(other : Node) : Int {
        return weight - other.weight
    }
}

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    N = br.readLine().toInt()
    M = br.readLine().toInt()
    // dist : 목적지까지 계산된 최단 거리
    dist = IntArray(N+1) {INF}  // 아직 방문하지 않은 거리는 초기값이 무한(Int의 최대값)
    list = ArrayList()
    for (i in 0..N) {
        list.add(ArrayList())

    }
    repeat(M) {
        val st = StringTokenizer(br.readLine())
        val u = st.nextToken().toInt()
        val v = st.nextToken().toInt()
        val w = st.nextToken().toInt()
        list.get(u).add(Node(v, w))
    }
    val (start, end) = br.readLine().split(" ").map { it.toInt() }
    println(dijkstra(start, end))
}

fun dijkstra(start : Int, end : Int) : Int {
    var queue : PriorityQueue<Node> = PriorityQueue()
    var visit = BooleanArray(N+1)
    dist[start] = 0
    queue.offer(Node(start, 0))

    while (!queue.isEmpty()) {
        var queueNode : Node = queue.poll()
        var startNode = queueNode.nodeNum
        if (!visit[startNode]) {
            visit[startNode] = true
            list.get(startNode).forEach {
                if (!visit[it.nodeNum] && dist[it.nodeNum] > (dist[startNode]+it.weight)) {
                    dist[it.nodeNum] = dist[startNode] + it.weight
                    queue.offer(Node(it.nodeNum, dist[it.nodeNum]))
                }
            }
        }
    }
    return dist[end]

}
