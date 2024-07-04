package `5000~10000`

fun main() {
    while (true) {
        val (a, b) = readLine()!!.split(" ").map { it.toInt() }
        if (a == 0 && b == 0) break
        println(when {
            b % a == 0 -> "factor"
            a % b == 0 -> "multiple"
            else -> "neither"
        })
    }
}
