package `1000~5000`

import java.util.Scanner

fun main() = with(Scanner(System.`in`)) {
    val chess = mutableListOf(1, 1, 2, 2, 2, 8)
    for (i in 0..5){
        chess[i] = chess[i] - nextInt()
        print("${chess[i]} ")
    }
}