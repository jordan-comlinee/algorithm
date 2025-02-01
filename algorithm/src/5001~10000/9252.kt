package `5001~10000`

import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

// 9251의 코드에서 역으로 LCS를 구해낸다.
private fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))
    val N = br.readLine()
    val M = br.readLine()
    var result = StringBuilder()
    val NM = Array(N.length+1){Array(M.length+1){0}}
    for(n in 1..N.length) {
        for (m in 1..M.length) {
            if (N[n-1] == M[m-1]) {
                NM[n][m] = NM[n-1][m-1]+1
            }
            else {
                NM[n][m] = maxOf(NM[n-1][m], NM[n][m-1])
            }
        }
    }
    bw.write("${NM[N.length][M.length]}\n")

    var n = N.length
    var m = M.length
    while (result.length < NM[N.length][M.length]) {
        if (NM[n][m] == NM[n-1][m]) n--
        else if (NM[n][m] == NM[n][m-1]) m--
        else {
            result.insert(0, N[n-1])
            n--
            m--
        }
    }
    bw.write("${result}")
    bw.flush()
    bw.close()
}
// 메모리 초과 - String을 계속 수정하는 과정에서 메모리 초과가 발생한 듯 하다.
/*
fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val N = br.readLine()
    val M = br.readLine()
    val NM = Array(N.length+1){Array<String>(M.length+1){""}}
    for(n in 1..N.length) {
        for (m in 1..M.length) {
            if (N[n-1] == M[m-1]) {
                NM[n][m] = NM[n-1][m-1]+N[n-1]
            }
            else {
                if(NM[n-1][m].length > NM[n][m-1].length)
                    NM[n][m] = NM[n-1][m]
                else
                    NM[n][m] = NM[n][m-1]
            }
        }
    }
    print("${NM[N.length][M.length].length}\n${NM[N.length][M.length]}")

}
*/