import java.util.Scanner

fun main() = with(Scanner(System.`in`)) {
    var croatia = listOf("c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z=")
    var word = next()
    croatia.forEach {
    word = word.replace(it, "Z")
    }
    println(word.length)
}