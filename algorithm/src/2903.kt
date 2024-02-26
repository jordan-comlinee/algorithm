import java.util.Scanner
import kotlin.math.pow

fun main() = with(Scanner(System.`in`)) {
    var time = nextInt()
    println((2.0f.pow(time).toInt()+1)*(2.0f.pow(time).toInt()+1))
}