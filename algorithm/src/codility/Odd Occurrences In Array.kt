package codility

private fun solution(A: IntArray): Int {
    var result = 0
    for (i in A) {
        result = result xor i
    }
    return result
}