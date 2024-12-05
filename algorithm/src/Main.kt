import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.StringTokenizer

fun main() {
    var a = mutableListOf<Int>()
    a.add(1)
    a.add(2)
    a.add(3)
    for (i in a.indices) {
        println(a[i])
    }
}