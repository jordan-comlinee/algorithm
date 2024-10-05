package codility

private fun solution(N: Int, A: IntArray): IntArray {
    var result = IntArray(N){0}
    var max = 0
    A.forEach{
        if(it in 1..N){
            val idx = it-1
            // increase
            result[idx] += 1
            max = maxOf(max, result[idx])
        }
        if(it == N+1) {
            // max counter
            for(i in 0 until N){
                result[i] = max
            }
        }
    }
    return result
}