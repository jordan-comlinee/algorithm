import java.util.Scanner

fun main() = with(Scanner(System.`in`)) {
    val first = nextInt()
    val second = nextInt()
    val third = nextInt()
    val sum = first + second + third

    if (sum == 180) {
        if (first == 60 && second == 60 && third == 60) {
            print("Equilateral")
        } else if (first == second || first == third || second == third) {
            print("Isosceles")
        } else {
            print("Scalene")
        }
    } else {
        print("Error")
    }
}