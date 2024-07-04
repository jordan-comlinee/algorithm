import java.util.Scanner
private lateinit var result: Array<Int> // 뽑은 결과
fun main() = with(Scanner(System.`in`)) {
    val N = nextInt()
    val M = nextInt()
    // dfs를 활용한 풀이
    fun find(arr : ArrayList<Int>) {
        if (arr.size == M) {
            arr.forEach { print("${it} ") }
            println()
            return
        }
        for (i in 1..N) {
            if (!arr.contains(i)) {
                val curArr = ArrayList<Int>()
                curArr.addAll(arr)
                curArr.add(i)
                find(curArr)
            }
        }
    }

    for (i in 1..N) {
        find(arrayListOf(i))
    }



}