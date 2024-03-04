import java.util.Scanner

fun main() = with(Scanner(System.`in`)) {
    var xList = mutableListOf<Int>()
    var yList = mutableListOf<Int>()
    for (i in 0..2) {
        xList.add(nextInt())
        yList.add(nextInt())
    }
    val difference = {a: Int, b: Int, c: Int -> if (a==b) c else if (a==c) b else if (b==c) a else -1}
    println("${difference(xList[0], xList[1], xList[2])} ${difference(yList[0], yList[1], yList[2])}")

}