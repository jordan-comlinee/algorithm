package codility

private fun solution(A: IntArray): Int {
    var result = 0
    var eastCount = 0
    for (i in A.size-1 downTo 0) {
        if (A[i] == 0) {
            result += (A.size-1)-i-eastCount
            eastCount += 1
            if(result > 1000000000){
                return -1
            }
        }
    }

    return result
}
