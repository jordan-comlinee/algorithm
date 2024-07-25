package `1000~5000`
import java.io.*
import java.util.*
import kotlin.collections.ArrayList

private lateinit var list : MutableList<MutableList<Node>>
private lateinit var dist : IntArray
private const val INF = Int.MAX_VALUE/4
private var N = 0
private var M = 0

private class Node(var nodeNum : Int, var weight : Int) : Comparable<Node> {
    override fun compareTo(other : Node) : Int {
        return weight - other.weight
    }
}

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    N = br.readLine().toInt()
    M = br.readLine().toInt()

    dist = IntArray(N+1) {INF}
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
