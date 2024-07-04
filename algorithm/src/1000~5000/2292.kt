package `1000~5000`// 육각형 모양이 아닌, 피라미드 모양처럼 생각하면 편하다.
// 1 -> (2~7) -> (8~19) -> ... -> 6(n-1) 의 구조를 가진 피라미드

import java.util.Scanner

fun main() = with(Scanner(System.`in`)) {
    var roomNo = nextInt()
    var layer = 1
    var layer_max = 1
    while (true) {
        layer_max += 6*(layer-1)
        if (layer_max >= roomNo) {
            println("${layer}")
            break
        }
        layer += 1

    }
}