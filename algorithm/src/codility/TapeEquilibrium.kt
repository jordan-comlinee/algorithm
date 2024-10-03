package codility

import kotlin.math.*


private fun solution(A: IntArray): Int {
    val sum = A.sum()
    val results = mutableListOf<Int>()
    var tmp = 0
    repeat(A.size) {
        tmp += A[it]
        results.add(abs(tmp - (sum-tmp)))
    }
    results.removeLast()
    return results.minOrNull() ?:0
}
