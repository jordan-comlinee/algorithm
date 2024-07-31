package `15001~20000`

import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.io.StreamTokenizer
import java.util.StringTokenizer

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    var bw = BufferedWriter(OutputStreamWriter(System.out))
    val N = br.readLine().toInt()
    var X = br.readLine().split(" ").map { it.toInt() }
    var result = HashMap<Int, Int>()
    var rank = 0

    var sX = X.sorted()
    sX.forEach{
        if (!result.containsKey(it)) {
            result[it] = rank
            rank += 1
        }
    }

    X.forEach {
        bw.write("${result[it]} ")
    }
    bw.flush()
    bw.close()
    br.close()
}