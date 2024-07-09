fun main() {
    val scoreMap: Map<String, Double> = mapOf(
        "A+" to 4.5,
        "A0" to 4.0,
        "B+" to 3.5,
        "B0" to 3.0,
        "C+" to 2.5,
        "C0" to 2.0,
        "D+" to 1.5,
        "D0" to 1.0,
        "F" to 0.0,
    )

    var total: Double = 0.0
    var totalScore: Double = 0.0

    for(i in 0 until 20) {
        val info: String = readLine()!!
        val infoList = info.split(" ")
        val score: Double = infoList[1].toDouble()
        val grade: String = infoList[2]

        if(grade.equals("P")) continue
        total += scoreMap.get(grade)!! * score
        totalScore += score
    }

    print(total / totalScore)
}