package `10001~15000`

import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val n = br.readLine().toInt()
    val n_list = Array(n+2){1}
    n_list[2] = 2
    if (n >= 3){
        for (i in 3..n){
            n_list[i] = (n_list[i-1]+n_list[i-2])%10007
        }
    }
    println("${n_list[n]}")
}