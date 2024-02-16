import java.util.Scanner

fun main(args: Array<String>) {
    var scan = Scanner(System.`in`)
    var t = scan.nextInt()
    var cha = scan.next()
    var sum = 0
    for (i in (0..t-1))  {
        sum += cha[i].toString().toInt()
    }
    println(sum)
}