package codility

private fun solution(A: IntArray): Int {
    var result = 0
    val B = BooleanArray(A.size+2){false}
    for (i in A.indices) {
        B[A[i]] = true
    }
    for (j in B.indices) {
        if( !B[j] ) result = j
    }
    return result
}

