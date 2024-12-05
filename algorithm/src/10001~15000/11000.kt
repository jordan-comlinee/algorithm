package `10001~15000`
import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.PriorityQueue
import java.util.StringTokenizer
private var cnt = 1
fun countMaxClass(c : List<Pair<Int, Int>>) {
    var pq = PriorityQueue<Int>()
    for (classTime in c) {
        if ( pq.isNotEmpty() && pq.peek() <= classTime.first) {
            pq.poll()
        }
        pq.add(classTime.second)
    }
    cnt = pq.size
}
fun main(){
    val br = BufferedReader(InputStreamReader(System.`in`))
    val N = br.readLine().toInt()
    val classes = mutableListOf<Pair<Int, Int>>()
    repeat(N) {
        val st = StringTokenizer(br.readLine())
        val S = st.nextToken().toInt()
        val T = st.nextToken().toInt()
        classes.add(Pair(S, T))
    }
    classes.sortWith(compareBy({it.first}, {it.second}))
    for(i in 0 until classes.size) {
        println("${classes[i].first} ${classes[i].second}")
    }
    countMaxClass(classes)
    println(cnt)
}