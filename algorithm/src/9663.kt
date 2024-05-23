import java.util.Scanner
var N: Int = 0
lateinit var board: IntArray
var ans: Int = 0
private fun dfs(depth: Int) {
    if (depth == N) {
        ans++
        return
    }
    for (i in 0 until N) {
        board[depth] = i
        if (check(depth)) {
            dfs(depth + 1)
        }
    }
}

fun check(n: Int): Boolean {
    for (i in 0 until n) {
        if (board[n] == board[i] || n - i == kotlin.math.abs(board[n] - board[i])) {
            return false
        }
    }
    return true
}


fun main() {
    val scanner = Scanner(System.`in`)
    N = scanner.nextInt()
    board = IntArray(N)
    dfs(0)
    println(ans)
}
