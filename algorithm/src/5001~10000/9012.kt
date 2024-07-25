package `5001~10000`

import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val T = br.readLine().toInt()
    repeat(T) {
        var VPS = br.readLine()
        isVPS(VPS)
    }
}

fun isVPS(VPS : String) {
    var stack = Stack<Char>()
    for (v in VPS) {
        if (v == '(')
            stack.push(v)
        else {
            if (stack.isEmpty() || stack.pop() == ')'){
                println("NO")
                return
            }
        }
    }
    if (stack.isEmpty()) println("YES")
    else println("NO")
    return
}