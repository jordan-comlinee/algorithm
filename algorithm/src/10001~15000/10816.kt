package `10001~15000`

import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.StringTokenizer

fun main() = with(BufferedReader(InputStreamReader(System.`in`))){
    val map = HashMap<Int,Int>()
    val n = readLine().toInt()
    val nToken = StringTokenizer(readLine())
    repeat(n){
        val nKey = nToken.nextToken().toInt()
        val count = map[nKey]?.plus(1)?: 1
        map[nKey] = count
    }
    val m = readLine().toInt()
    val mToken = StringTokenizer(readLine())
    val sb = StringBuilder()
    repeat(m){
        val mKey = mToken.nextToken().toInt()
        sb.append("${ map[mKey] ?: 0 }").append(" ")
    }
    print(sb)
}