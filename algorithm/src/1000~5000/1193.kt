package `1000~5000`

import java.util.Scanner

fun main() = with(Scanner(System.`in`)) {
    var num = nextInt()
    var layer = 1
    var layer_max = 0
    while (num > layer_max) {
        layer_max += layer
        layer += 1
    }
    if (layer%2==0){
        println("${(layer_max-num+1)}/${layer-(layer_max-num+1)}")
    } else {
        println("${layer-(layer_max-num+1)}/${(layer_max-num+1)}")
    }
}