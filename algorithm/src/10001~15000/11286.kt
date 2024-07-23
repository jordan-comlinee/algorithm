package `10001~15000`
import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.Collections
import java.util.PriorityQueue
import kotlin.math.abs

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val N = br.readLine().toInt()
    // 디폴트는 최소 힙...Collections.reverseOrder()로 최대 힙 구현
    var mh = PriorityQueue<Int>(Collections.reverseOrder())
    var ph = PriorityQueue<Int>()
    repeat(N) {
        val x = br.readLine().toInt()
        if (x == 0) {
            if (ph.isEmpty()) {
                if (mh.isEmpty()) println(0)
                else println(mh.poll())
            }
            else {
                if (mh.isEmpty()) println(ph.poll())
                else {
                    if (ph.peek() < abs(mh.peek())) {
                        println(ph.poll())
                    }
                    else println(mh.poll())
                }
            }
        }
        else {
            // 넣기
            if (x>0) ph.offer(x)
            else mh.offer(x)
        }
    }

}

fun isNull(n : Int?) : Int {
    if (n == null) return 0
    else return n
}