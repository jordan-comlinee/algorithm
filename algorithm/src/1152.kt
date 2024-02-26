fun main() {
    var wordList = readLine()!!.split(" ")
    var result = 0
    wordList.forEach {
        if (it != "") {
            result +=1
        }
    }
    println(result)
}