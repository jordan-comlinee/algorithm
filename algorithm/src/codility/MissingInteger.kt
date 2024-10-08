package codility

private fun solution1(A: IntArray): Int {
    var As = mutableSetOf<Int>()
    val max = A.maxOrNull()?:1
    if(max <= 0)
        return 1
    for(i in 1 .. max+1){
        As.add(i)
    }
    A.forEach{
        if(A.contains(it)){
            As.remove(it)
        }
    }
    return As.minOrNull()?:1
}

private fun solution2(A : IntArray) : Int {
    val present = BooleanArray(A.size+2)
    A.forEach {
        if (it>0 && it <= A.size+1)
            present[it] = true
    }
    for (i in 1..A.size+1){
        if (!present[i]) {
            return i
        }
    }
    return A.size+1
}