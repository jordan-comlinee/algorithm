package `5001~10000`

import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val N = br.readLine()
    val M = br.readLine()
    val NM = Array(N.length+1){Array(M.length+1){0}}
    for(n in 1..N.length) {
        for (m in 1..M.length) {
            if (N[n-1] == M[m-1]) {
                NM[n][m] = NM[n-1][m-1]+1
            }
            else {
                if(NM[n-1][m] > NM[n][m-1])
                    NM[n][m] = NM[n-1][m]
                else
                    NM[n][m] = NM[n][m-1]
            }
        }
    }
    print(NM[N.length][M.length])

}