import java.util.Scanner
// ax + by = c 에서 x와 y를 구하는 방법??
// x와 y를 만족하도록 하려면??
// ax + by = c (x = (c/a) - (b/a)y)
// dx + ey = f d((c/a)- (b/a)y + ey = f)
// (dc/a) - (bd/a)y + ey = f
// (e-(bd/a))y = f - (dc/a)
// y = (f - (dc/a)) / (e - (bd/a))



fun main() = with(Scanner(System.`in`)) {
    var homework = mutableListOf<Int>()
    for (i in 0..5) {
        homework.add(nextInt())
    }
    var y = (homework[5]-(homework[3]*homework[2]/homework[0])) / (homework[4] - (homework[1]*homework[3]/homework[0]))
    var x = (homework[2]-homework[1]*y)/homework[0]
    println("$x $y")

}