import java.util.Scanner
lateinit var visited: BooleanArray
lateinit var network: Array<MutableList<Int>>
var result = 0
private fun dfs(depth : Int) {
    visited[depth] = true
    for (c in network[depth]) {
        if (visited[c] == false) {
            result += 1
            visited[c] == true
            dfs(c)
        }
    }
}

fun main() = with(Scanner(System.`in`)) {
    val C = nextInt()
    val N = nextInt()
    network = Array(C+1, { mutableListOf()})
    visited = BooleanArray(C+1) {false}
    for (n in 0 until N) {
        val a = nextInt()
        val b = nextInt()
        network[a].add(b)
        network[b].add(a)
    }
    dfs(1)
    println(result)
}