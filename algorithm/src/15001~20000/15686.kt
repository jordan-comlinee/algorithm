package `15001~20000`

import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.LinkedList
import java.util.StringTokenizer
import kotlin.math.*

private val chicken = mutableListOf<Pair<Int, Int>>()
private val home = mutableListOf<Pair<Int, Int>>()
private var result = Int.MAX_VALUE
private lateinit var visited : BooleanArray
private var N = 0
private var M = 0

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val st = StringTokenizer(br.readLine())
    N = st.nextToken().toInt()
    M = st.nextToken().toInt()
    repeat(N) { i ->
        val st = StringTokenizer(br.readLine())
        repeat(N) { j ->
            val city = st.nextToken().toInt()
            if (city == 2) chicken.add(Pair(i, j))
            if (city == 1) home.add(Pair(i, j))
        }
    }
    if (M >= chicken.size){
        println("${getChickenDist(home, chicken)}")
        return
    }
    val selectedChicken = LinkedList<Pair<Int, Int>>()
    find(0, 0, selectedChicken)
    println(result)
}

private fun find(start: Int, len: Int, selectedChicken: MutableList<Pair<Int, Int>>) {
    if (len == M){
        result = min(result, getChickenDist(home, selectedChicken))
        return
    }
    for (i in start until chicken.size) {
        selectedChicken.add(chicken[i])
        find(i+1, len+1, selectedChicken)
        selectedChicken.removeAt(selectedChicken.lastIndex)

    }
}

private fun getChickenDist(homes: List<Pair<Int, Int>>, chickens: List<Pair<Int, Int>> ): Int {
    var result = 0
    homes.forEach{ h ->
        var min = Int.MAX_VALUE
        chickens.forEach{ c ->
            val distance = abs(h.first-c.first) + abs(h.second-c.second)
            if (distance < min) {
                min = distance
            }
        }
        result += min
    }

    return result
}