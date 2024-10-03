package codility

import kotlin.math.ceil

// 개구리의 위치 X, 목적지 Y, 점프 거리 D
private fun solution(X: Int, Y: Int, D: Int): Int {
    if ((Y-X)%D > 0)
        return (Y-X)/D+1
    else
        return (Y-X)/D
}

private fun solution2(X: Int, Y: Int, D: Int): Int {
    return ceil((Y-X)/D.toDouble()).toInt()
}


fun main() {
    solution(10, 85,30)
    solution2(10, 85, 30)
}