package codility

private fun solution(A: IntArray, K: Int): IntArray {
    val N = A.size
    if(N == 0 || K%N == 0){
        return A
    }
    else {
        val result =  A.slice(N-(K%N) until N) + A.slice(0 until N-(K%N))
        return result.toIntArray()
    }
}

fun main() {
    solution(IntArray(0), 2)
}