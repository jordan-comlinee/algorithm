package `5001~10000`

import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.StringTokenizer

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val T = br.readLine().toInt()
    repeat(T) {
        val n = br.readLine().toInt()
        val sticker = Array(2){IntArray(n+1) }

        repeat(2) {
            val st = StringTokenizer(br.readLine())
            for (i in 1 .. n) {
                sticker[it][i] = st.nextToken().toInt()
            }
        }
        for (i in 2 .. n) {
            val pre = sticker[0][i-2].coerceAtLeast(sticker[1][i-2])
            sticker[0][i] += sticker[1][i-1].coerceAtLeast(pre)
            sticker[1][i] += sticker[0][i-1].coerceAtLeast(pre)
        }
        println("${sticker[0][n].coerceAtLeast(sticker[1][n])}")

    }
}