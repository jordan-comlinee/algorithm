package `5001~10000`

import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.*


fun main(){
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.out))
    val n = br.readLine().toInt()
    val m = br.readLine().toInt()
    val parent = br.readLine()
    var pattern = 0
    var ans = 0
    var i = 0
    while(i<m-2){
        if(parent[i]=='I' && parent[i+1] == 'O' && parent[i+2] == 'I') {
            pattern++
            if(pattern == n){
                pattern--
                ans++
            }
            i++
        }
        else{
            pattern = 0
        }
        i++
    }
    bw.write("$ans")
    bw.flush()
    bw.close()
}
