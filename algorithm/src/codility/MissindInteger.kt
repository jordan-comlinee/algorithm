package codility

import kotlin.math.*

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