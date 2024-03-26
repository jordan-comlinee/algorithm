import java.util.Scanner

fun main() = with(Scanner(System.`in`)) {
    var n = nextInt()
    var m = nextInt()
    val board = mutableListOf<String>()
    repeat(n) {
        board.add(next())
    }

    fun check(x: Int, y: Int, z: List<Char>): Int {
        var count = 0
        for (i in 0 until 8) {
            for (j in 0 until 8) {
                val currentChar = board[i + x][j + y]
                if ((i % 2 == 0 && j % 2 == 0 && currentChar == z[0]) ||
                    (i % 2 == 0 && j % 2 != 0 && currentChar == z[1]) ||
                    (i % 2 != 0 && j % 2 == 0 && currentChar == z[1]) ||
                    (i % 2 != 0 && j % 2 != 0 && currentChar == z[0])
                ) {
                    continue
                }
                count += 1
            }
        }

        return count
    }

    val result = mutableListOf<Int>()
    for (i in 0 until (n - 7)) {
        for (j in 0 until (m - 7)) {
            result.add(check(i, j, listOf('W', 'B')))
            result.add(check(i, j, listOf('B', 'W')))
        }
    }

    println(result.minOrNull())
}