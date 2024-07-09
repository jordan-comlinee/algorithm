import java.util.Scanner

fun main() = with(Scanner(System.`in`)) {
    val word = next()
    for (i in 0..(word.length/2)-1) {
        if (word[i] != word[word.length-i-1]){
            println("0")
            return
        }
    }
    println("1")
}