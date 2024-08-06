import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

/**
 * 2022.03.03
 * 5430 AC
 * https://www.acmicpc.net/problem/5430
 * R 을 만날 때마다 뒤집는다면 시간초과가난다.
 * 명령어가 최대 10만이고 문자열 길이도 최대 10만이면 가볍게 1억이 훌쩍 넘어가기 때문이다.
 * 그래서 직접 뒤집지 않고 방향만 기록하고, 기록된 방향에 따라 앞뒤로 삭제하는 게 문제해결의 핵심이다.
 */
val br = BufferedReader(InputStreamReader(System.`in`))
fun main() {
    val loop = br.readLine().toInt()
    for (case in 0 until loop) {
        println(solution())
    }
}

private fun solution(): String {
    val orders = br.readLine()
    val n = br.readLine().toInt()
    val listString = br.readLine().drop(1).dropLast(1).split(",").toMutableList() // MutableList 로 바꿔야 삭제 가능
    val arr = LinkedList<String>()
    arr.addAll(listString)


    if (n < orders.count { c -> c == 'D' }) return "error"

    var direction = true // 정방향 역방향
    for (i in orders.indices) { // 이 반복문에서 일어나는 일이 시간복잡도 O(1) 이어야 시간초과가 나지 않는다.
        if (orders[i] == 'R') {
            direction = !direction // 방향만 바꿔준다.
        } else {
            if (direction) {
                arr.removeFirst()
            } else {
                arr.removeLast()
            }
        }
    }

    if (!direction) arr.reverse() // 마지막에만 방향이 바뀌어있다면 바꿔준다.

    return "[" + arr.joinToString(",") { it } + "]"
}