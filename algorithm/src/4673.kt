fun main() {
    for (i in 1..10000) {
        if (isSelfNum(i)) {
            println(i)
        }
    }
}

fun isSelfNum(num : Int) : Boolean {
    for (i in num downTo 1) {
        var const = i
        i.toString().forEach { const += it.toString().toInt() }
        if (const == num )
            return false
    }
    return true
}