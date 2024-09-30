package `1000~5000`

import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val (N, M) = br.readLine().split(" ").map { it.toInt() }
    val pokedex = mutableMapOf<String, String>()
    for (i in 1 .. N) {
        val pokemon = br.readLine()
        pokedex.put(i.toString(), pokemon)
        pokedex.put(pokemon, i.toString())
    }
    for (i in 1 .. M) {
        val question = br.readLine()
        println("${pokedex[question]}")
    }
}