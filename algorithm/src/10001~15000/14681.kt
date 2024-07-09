package `10000~15000`

fun main() {
    val x = readLine()!!.toLong()
    val y = readLine()!!.toLong()
    if (x>0 && y>0) {
        println("1")
    }
    else if (x>0 && y<0) {
        println("4")
    }
    else if (x<0 && y>0) {
        println("2")
    }
    else {
        println("3")
    }
}