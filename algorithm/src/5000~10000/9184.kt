package `5000~10000`

import java.util.Scanner

private val w = Array(21) {Array(21) {Array(21) {0} } }

fun w(a : Int, b : Int, c : Int) : Int{
    if (a <= 0 || b <= 0 || c <= 0) return 1
    else if (a>20 || b>20 || c>20) {
        w[20][20][20] = w(20, 20, 20)
        return w[20][20][20]
    }
    else if (a<b && b<c) {
        if (w[a][b][c] != 0) return w[a][b][c]
        w[a][b][c] = w(a,b,c-1) + w(a,b-1,c-1) - w(a,b-1,c)
        return w[a][b][c]
    }
    else {
        if (w[a][b][c] != 0) return w[a][b][c]
        w[a][b][c] = w(a-1,b,c) + w(a-1,b-1,c) + w(a-1,b,c-1) - w(a-1,b-1,c-1)
        return w[a][b][c]
    }
}
fun main() = with(Scanner(System.`in`)) {
    while (true) {
        val a = nextInt()
        val b = nextInt()
        val c = nextInt()
        if (a == -1 && b == -1 && c == -1) {
            break
        }
        println("w($a, $b, $c) = ${w(a, b, c)}")
    }
}