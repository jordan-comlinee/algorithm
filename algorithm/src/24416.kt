import java.util.Scanner

fun main() = with(Scanner(System.`in`)) {
    val n = nextInt()
    fibonacci(n)

}

fun fibonacci(n : Int) {
    val fibo = Array(n) {1}
    var k = 0
    for (i in 2 until n) {
        fibo[i] = fibo[i-1]+fibo[i-2]
        k+=1
    }
    println("${fibo[n-1]} $k")
}