package codility

private fun solution(A: IntArray): Int {
    val a = A.size
    val seen = BooleanArray(A.size+1)
    A.forEach{
        if(it > a || seen[it]){
            return 0
        }
        if(!seen[it]){
            seen[it] = true
        }
    }
    return 1
}