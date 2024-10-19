package `15001~20000`
import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.StringTokenizer

private var results = mutableSetOf<String>()
private var N = 0
private var M = 0
private lateinit var numbers : IntArray
fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))
    val st = StringTokenizer(br.readLine())
    N = st.nextToken().toInt()
    M = st.nextToken().toInt()
    numbers = IntArray(N)
    val st2 = StringTokenizer(br.readLine())
    repeat(N) {
        numbers[it] = st2.nextToken().toInt()
    }
    numbers.sort()
    solution(0, 0, "")
    results.forEach{
        bw.write("$it\n")
    }
    bw.flush()
    bw.close()
    br.close()
}

private fun solution(idx : Int, len : Int, result : String){
    if (len == M) {
        results.add(result)
        return
    }
    for (i in idx until N) {
        if (len == 0)
            solution(i, len+1, "${numbers[i]}")
        else
            solution(i,len+1,"${result} ${numbers[i]}")
    }
}