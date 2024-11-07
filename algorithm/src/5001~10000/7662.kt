package `5001~10000`
import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.PriorityQueue
import java.util.StringTokenizer

private val maxQueue = PriorityQueue<Int>(reverseOrder())
private val minQueue = PriorityQueue<Int>()
private val elementCount = mutableMapOf<Int, Int>()

fun check(operation: String, value: Int) {
    if (operation == "I") {
        maxQueue.offer(value)
        minQueue.offer(value)
        elementCount[value] = elementCount.getOrDefault(value, 0) + 1
    } else if (operation == "D") {
        if (value == 1) {
            while (maxQueue.isNotEmpty() && elementCount[maxQueue.peek()] == 0) {
                maxQueue.poll()
            }
            if (maxQueue.isNotEmpty()) {
                val max = maxQueue.poll()
                elementCount[max] = elementCount[max]!! - 1
            }
        } else if (value == -1) {
            while (minQueue.isNotEmpty() && elementCount[minQueue.peek()] == 0) {
                minQueue.poll()
            }
            if (minQueue.isNotEmpty()) {
                val min = minQueue.poll()
                elementCount[min] = elementCount[min]!! - 1
            }
        }
    }
}

fun initAll() {
    maxQueue.clear()
    minQueue.clear()
    elementCount.clear()
}

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val T = br.readLine().toInt()
    repeat(T) {
        val K = br.readLine().toInt()
        repeat(K) {
            val st = StringTokenizer(br.readLine())
            val operation = st.nextToken()
            val value = st.nextToken().toInt()
            check(operation, value)
        }
        while (maxQueue.isNotEmpty() && elementCount[maxQueue.peek()] == 0) {
            maxQueue.poll()
        }
        while (minQueue.isNotEmpty() && elementCount[minQueue.peek()] == 0) {
            minQueue.poll()
        }

        if (maxQueue.isEmpty() || minQueue.isEmpty()) {
            println("EMPTY")
        } else {
            println("${maxQueue.peek()} ${minQueue.peek()}")
        }
        initAll()
    }
}
