package `1000~5000`

fun main() {
    val (a, b) = readLine()!!.split(" ").map { it.toLong() }
    if (a>b) {
        println(">")
    }
    else if (a<b) {
        println("<")
    }
    else {
        println("==")
    }
}