// 분해합을 구하는 문제
// 예제 입력 부터 점점 작은 수의 분해합을 구해본다
import java.nio.IntBuffer
import java.util.Scanner

fun main() = with(Scanner(System.`in`)) {
    val n = nextLong()
    var minResult : Long = 0
    for (i in  n downTo 0) {
        if (n == getEachHap(i.toString())){
            minResult = i
        }
    }
    println(minResult)
}

fun getEachHap(num : String): Long {
    var hap : Long = num.toLong()
    num.forEach {
        hap += it.toString().toInt()
    }

    return hap
}