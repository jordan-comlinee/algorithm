import java.util.Scanner

fun main() = with(Scanner(System.`in`)) {
    val s = next()
    for (i in ("a".toCharArray()[0].toInt() .. "z".toCharArray()[0].toInt())) {
        var t = -1
        for (j in s.length-1 downTo 0) {
            if (s[j].toChar().toInt() == i) t = j
        }
        print("${t} ")
    }
}