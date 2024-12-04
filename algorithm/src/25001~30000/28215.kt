package `25001~30000`

import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import kotlin.collections.ArrayList
import kotlin.math.abs
import kotlin.math.min
import kotlin.math.max

private var N = 0
private var K = 0
private var homes = ArrayList<Pair<Int, Int>> ()
private var visited = BooleanArray(51) {false}
private var answer = Int.MAX_VALUE

fun getDistance(home : Pair<Int, Int>, shelter : Pair<Int, Int>) : Int{
    return abs(home.first - shelter.first) + abs(home.second - shelter.second)
}

fun getFarthest(shelters : ArrayList<Pair<Int, Int>>) : Int{
    var farthestDistance = 0
    for (i in homes.indices) {
    var homeDistance = Int.MAX_VALUE
        for (j in shelters.indices) {
            homeDistance = min(getDistance(homes[i], shelters[j]), homeDistance)
        }
        farthestDistance = max(farthestDistance, homeDistance)
    }
    return farthestDistance
}

fun combination(idx : Int, len : Int, shelters : ArrayList<Pair<Int, Int>>) {
    if (len == K) {
        /*
        for ((r, c) in shelters) {
            print("(${r} ${c}) ")
        }
        println(" : ${getFarthest(shelters)}")
        */
        // 가장 먼 거리의 값을 찾음
        answer = min(answer, getFarthest(shelters))
        return
    }
    for (i in idx until N) {
        if (!visited[i]) {
            shelters.add(homes[i])
            combination(i + 1, len + 1, shelters)
            shelters.removeAt(shelters.size - 1)
        }
    }
}
fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val st = StringTokenizer(br.readLine())
    N = st.nextToken().toInt()
    K = st.nextToken().toInt()
    repeat(N) {
        val st2 = StringTokenizer(br.readLine())
        homes.add(Pair(st2.nextToken().toInt(), st2.nextToken().toInt()))
    }
    combination(0, 0, ArrayList())
    println(answer)
}