package codility

private fun solution1(X: Int, A: IntArray): Int {
    val river = mutableListOf<Int>()
    for(x in 1..X) river.add(x)

    for (i in A.indices) {
        if(river.contains(A[i])) {
            river.remove(A[i])
        }
        if(river.isEmpty()) {
            return i
        }
    }
    return -1
}

private fun solution2(X: Int, A: IntArray): Int {
    val river = mutableSetOf<Int>()
    for(x in 1..X){
        river.add(x)
    }
    for(i in A.indices){
        river.remove(A[i])
        if(river.isEmpty())
            return i
    }
    return -1
}

private fun solution3(X: Int, A: IntArray): Int {
    val seen = BooleanArray(X + 1)
    var count = 0

    for (i in A.indices) {
        if (!seen[A[i]]) {
            seen[A[i]] = true
            count++
        }
        if (count == X) {
            return i
        }
    }
    return -1
}