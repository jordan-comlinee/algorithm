package `1000~5000`

import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.StringTokenizer

private var blue = 0
private var white = 0
private val quadrant = arrayOf(arrayOf(0, 0), arrayOf(0, 1), arrayOf(1, 0), arrayOf(1, 1))
fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val N = br.readLine().toInt()
    val paper = Array(N) {Array(N){0} }
    repeat(N) { x->
        val st = StringTokenizer(br.readLine())
        repeat(N) { y->
            paper[x][y] = st.nextToken().toInt()
        }
    }
    cut(paper)
    println("$white\n$blue")
}

fun cut(paper : Array<Array<Int>>) {
    if (!isPure(paper)) {
        val c = paper.size/2
        repeat(4) {
            val cuttedPaper = Array(c){Array(c) {0} }
            for (x in 0 until c) {
                for (y in 0 until c) {
                    cuttedPaper[x][y] = paper[quadrant[it][0]*c+x][quadrant[it][1]*c+y]
                }
            }
            cut(cuttedPaper)
        }
    } else {
        if (paper[0][0] == 1)
            blue++
        else
            white++
        return
    }
}

fun isPure(paper : Array<Array<Int>>) : Boolean {
    val color = paper[0][0]
    for (i in 0 until paper.size) {
        for (j in 0 until paper.size) {
            if (color != paper[i][j])
                return false
        }
    }
    return true
}