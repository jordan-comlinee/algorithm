fun main() {
    val (a, b) = readln().split(' ').map { it.toInt() }
    println("${a+b}\n${a-b}\n${a*b}\n${a/b}\n${a%b}")
}