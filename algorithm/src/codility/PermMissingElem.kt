package codility

private fun solution1(A: IntArray): Int {
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
//등차수열의 합이 (n)(n+1)/2임을 활용하여 A라는 Array의 각 수들의 합과 비교하여 구함
private fun solution2(A: IntArray): Int {
    val n = (A.size+1).toLong()
    val sequence = n*(1+n)/2L
    val sum = A.sum().toLong()

    return (sequence-sum).toInt()
}