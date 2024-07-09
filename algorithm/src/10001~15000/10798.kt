import java.util.Scanner

fun main() = with(Scanner(System.`in`)){
    var board = Array(5){ "" }
    for (i in 0..4){
        board[i] = next()
    }
    for (j in 0..15) {
        for (i in 0.. 4) {
            if (j < board[i].length){
                print("${board[i][j]}")
            }
        }
    }
}