import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val T = br.readLine().toInt()
    repeat(T) {
        val N = br.readLine().toInt()
        val triangles = LongArray(N+6){1}
        triangles[4] = 2L
        triangles[5] = 2L
        for (i in 6..N) {
            triangles[i] = triangles[i-5]+triangles[i-1]
        }
        println(triangles[N])
    }
}