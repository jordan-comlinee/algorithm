fun main() {
    val (n, k) = readLine()!!.split(" ").map { it.toInt() }
    val result = findKthFactor(n, k)
    println(result)
}

fun findKthFactor(n: Int, k: Int): Int {
    val tList = mutableListOf<Int>()
    if (k == 0 || k > n) {
        return 0
    }
    for (t in 1..n) {
        if (n % t == 0) {
            tList.add(t)
        }
    }
    if (tList.size < k) {
        return 0
    }
    return tList[k - 1]
}
