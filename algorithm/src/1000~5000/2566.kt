package `1000~5000`

import java.util.Scanner

fun main() = with(Scanner(System.`in`)) {
    var grid = Array(9) {IntArray(9)}
    var max = IntArray(3)
    for (i in 0..8) {
        for (j in 0..8) {
            grid[i][j] = nextInt()
            if (max[0] < grid[i][j]) {
                max[0] = grid[i][j]
                max[1] = i
                max[2] = j
            }
        }
    }
    println("${max[0]}")
    println("${max[1]+1} ${max[2]+1}")

}