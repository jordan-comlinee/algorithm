package `5001~10000`

import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.LinkedList

private var isReverse = false

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))
    val T = br.readLine().toInt()
    repeat(T) {
        val p = br.readLine()
        val n = br.readLine().toInt()
        var x = input(br, n)
        var isError = false
        isReverse = false
        p.forEach {
            if (it == 'D' && x.size == 0) isError = true
            else {
                ac(it, x)
            }
        }
        if (isError) {
            bw.write("error\n")
        }
        else {
            if (isReverse) {
                x.reverse()
                bw.write("${x}\n")
            }
            else {
                bw.write("${x}\n")
            }
        }
    }
    bw.flush()
    bw.close()
    br.close()
}

fun input(br : BufferedReader, n : Int) : LinkedList<Int> {
    var result = LinkedList<Int>()
    var x = br.readLine()
    if (x.length > 2) {
        x = x.substring(1, x.length-1)
        val re = x.split(",").map { it.toInt() }
        re.forEach {
            result.offer(it)
        }
    }
    return result
}

fun ac(p : Char, x : LinkedList<Int>) {
    if (p == 'R') {
        isReverse = !isReverse
        return
    }
    else if (p == 'D') {
        if (isReverse)
            x.pollLast()
        else
            x.poll()
        return
    }
}