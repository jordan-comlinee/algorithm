package `1000~5000`

import java.util.Scanner

fun main() = with(Scanner(System.`in`)) {
    val n = nextInt()
    var count = -1
    for (i in (n/5) downTo 0){
        if ( (n-i*5)%3==0 ) {
            count = ((n-i*5)/3) + i
            break
        }
    }
    println(count)
}
