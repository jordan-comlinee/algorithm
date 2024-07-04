package `1000~5000`

import java.util.Scanner

fun main() = with(Scanner(System.`in`)) {
    val time = nextInt()
    var result = 0
    for (i in 1..time) {
        val word = next()
        var lastword = ' '
        var lastwordList = mutableListOf<Char>()
        var n = 1
        word.forEach {
            // 순회해서 알파벳 있는 지 확인할 때, 만약, 이전 단어가 it과 같다면, 연속한다고 판단
            // 만약, 이전단어가 it과 같지 않다면, 이전 단어 알파벳 리스트에 있는 지 확인
            // 리스트에 있다면, 그룹단어가 아니기 때문에 break
            // 리스트에 없다면, 리스트에 단어 추가 후 이전 단어(lastword) = it
            if (lastword != it && lastwordList.contains(it)) {
                n = 0
            }
            else {
                lastword = it
                lastwordList.add(lastword)
            }
        }
        result += n
    }
    println(result)
}