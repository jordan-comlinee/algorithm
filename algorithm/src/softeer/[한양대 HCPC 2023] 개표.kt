package softeer

import java.io.*
import java.util.*

private lateinit var br : BufferedReader
private lateinit var bw : BufferedWriter
private var T = 0
private var n = 0
fun main(args: Array<String>) {
    br = BufferedReader(InputStreamReader(System.`in`))
    bw = BufferedWriter(OutputStreamWriter(System.out))
    T = br.readLine().toInt()
    repeat(T) {
        n = br.readLine().toInt()
        repeat(n/5) {
            bw.write("++++ ")
        }
        repeat(n%5) {
            bw.write("|")
        }
        bw.write("\n")
    }
    bw.flush()
    bw.close()
    br.close()
}