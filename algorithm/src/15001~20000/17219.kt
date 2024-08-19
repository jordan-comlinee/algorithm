package `15001~20000`

import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))
    val (N, M) = br.readLine().split(" ").map { it.toInt() }
    var pw = mutableMapOf<String, String>()
    repeat(N) {
        val (address, pwd) = br.readLine().split(" ")
        pw[address] = pwd
    }
    repeat(M) {
        bw.write("${pw[br.readLine()]} \n")
    }
    bw.flush()
    bw.close()
}