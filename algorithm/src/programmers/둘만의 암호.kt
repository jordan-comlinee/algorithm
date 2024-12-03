package programmers

class Solution {
    fun solution(S: String, skip: String, index: Int): String {
        var answer: String = ""
        var skipwords = ArrayList(('a'..'z').toList())
        for (i in skip) {
            skipwords.remove(i)
        }
        for(s in S) {
            if(skipwords.indexOf(s)+index < skipwords.size) {
                answer += skipwords[skipwords.indexOf(s)+index]
            }
            else {
                answer += skipwords[(skipwords.indexOf(s)+index) % skipwords.size]
            }
        }
        return answer
    }
}