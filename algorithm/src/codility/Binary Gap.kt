package codility

// you can also use imports, for example:
// import kotlin.math.*

// you can write to stdout for debugging purposes, e.g.
// println("this is a debug message")

private fun solution(N: Int): Int {
    var binary = N.toString(2)
    var cnt = 0
    var result = 0
    for (i in binary) {
        if(i == '0'){
            cnt++
        }
        if(i == '1'){
            if(result < cnt)
                result = cnt
            cnt = 0
        }
    }
    return result
}