package `1000~5000`

import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val list = mutableListOf<String>()
    val(N, M) = br.readLine().split(" ").map { it.toInt() }
    val unheard = mutableSetOf<String>()
    repeat(N) {
        unheard.add(br.readLine())
    }
    repeat(M) {
        val unseen = br.readLine()
        if (unheard.contains(unseen)) {
            list.add(unseen)
        }
    }
    println(list.size)
    list.sorted().forEach {
        println("${it}")
    }
    br.close()
}