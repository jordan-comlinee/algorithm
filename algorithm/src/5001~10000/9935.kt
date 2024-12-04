package `5001~10000`

import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val str = br.readLine()
    val explodeCode = br.readLine()
    val stack = Stack<Char>()
    for (s in str) {
        stack.push(s)
        if (s == explodeCode[explodeCode.length-1]) {
            var checkExplosion = StringBuilder()
            for (i in explodeCode.indices) {
                if (stack.isEmpty()) break
                checkExplosion.append(stack.pop())
            }
            checkExplosion = checkExplosion.reverse()
            if (checkExplosion.toString() != explodeCode) {
                repeat(checkExplosion.length) {
                    stack.push(checkExplosion[it])
                }
            }
        }
    }
    if (stack.isNotEmpty()) {
        println(stack.joinToString(""))
    } else {
        println("FRULA")
    }

}