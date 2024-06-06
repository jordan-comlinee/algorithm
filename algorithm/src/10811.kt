import java.util.Scanner
private lateinit var basket : IntArray
fun swap(i : Int, j : Int){
    if (i < j) {
        for (t in 0 until (j-i+1)/2) {
            var swp = basket[i+t]
            basket[i+t] = basket[j-t]
            basket[j-t] = swp
        }
    }
}
fun main() = with(Scanner(System.`in`)) {
    val N = nextInt()
    val M = nextInt()
    basket = IntArray(N)
    for (n in 1 .. N) { basket[n-1] = n }
    for (m in 0 until M) {
        val i = nextInt()
        val j = nextInt()
        swap(i-1, j-1)
    }
    basket.forEach { print("${it} ") }
}