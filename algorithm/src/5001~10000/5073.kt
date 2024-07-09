package `5000~10000`

import java.util.Scanner

fun main() = with(Scanner(System.`in`)) {
    while (true) {
        val triangle : Array<Int> = arrayOf(nextInt(), nextInt(), nextInt())
        triangle.sort()

        if (triangle[0] == 0) {
            break
        }

        if (triangle[2] >= triangle[0] + triangle[1]) {
            println("Invalid")
        } else {
            when (triangle.groupBy { it }.size) {
                1 -> println("Equilateral")
                2 -> println("Isosceles")
                else -> println("Scalene")
            }
        }
    }
}