fun main() {
    val num = readLine()!!.toInt()
    var result = "int"
    for (i in 1..num/4) {
        result = "long ${result}"
    }
    print(result)
}