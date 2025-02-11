package softeer

import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.*

private var n = 0
private lateinit var ingredients : IntArray
private lateinit var br : BufferedReader
private var result = Int.MIN_VALUE
private lateinit var leftdp : IntArray
private lateinit var rightdp : IntArray
private fun input_data() {
    br = BufferedReader(InputStreamReader(System.`in`))
    n = br.readLine().toInt()
    ingredients = br.readLine().split(" ").map { it.toInt() }.toIntArray()
    leftdp = IntArray(n) {Int.MIN_VALUE}
    rightdp = IntArray(n) {Int.MIN_VALUE}
}

private fun solution() {
    leftdp[0] = ingredients[0]
    rightdp[n-1] = ingredients[n-1]

    for (i in 1 until n) {
        leftdp[i] = max(leftdp[i-1] + ingredients[i], ingredients[i])
    }
    for (i in n-2 downTo 0) {
        rightdp[i] = max(rightdp[i+1] + ingredients[i], ingredients[i])
    }
    /*
    print("rightdp : ")
    rightdp.forEach {
        print("${it} ")
    }

    print("\nleftdp: ")
    leftdp.forEach {
        print("${it} ")
    }
    println()
     */
    for (i in 1 until n-1) {
        //println("${i}인덱스 빼고 계산: ${leftdp[i-1]} + ${rightdp[i+1]} = ${leftdp[i-1] + rightdp[i+1]}")
        result = max(result, leftdp[i-1] + rightdp[i+1])
    }
}

fun main() {
    input_data()
    solution()
    println(result)
}