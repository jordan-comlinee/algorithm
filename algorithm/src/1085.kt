fun main(){
    var (x, y, w, h) = readLine()!!.split(" ").map { it.toInt() }
    val getMin = { a: Int, b: Int -> if (a<b) a else b }
    println(getMin(getMin(x, y),getMin((w-x), (h-y))))
}