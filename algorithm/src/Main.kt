import java.io.*
import java.util.*
import kotlin.math.*
import kotlin.experimental.*

private lateinit var br : BufferedReader
private lateinit var bw : BufferedWriter
private lateinit var input_str : List<String>

private fun input_data() {
    br = BufferedReader(InputStreamReader(System.`in`))
    input_str = br.readLine().split(" ").map{it.toString()}
}

private fun solution() {

}

fun main(args: Array<String>) {
    input_data()
    solution()
    bw.flush()
    bw.close()
    br.close()
}