package softeer

import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.LinkedList
import java.util.Queue
import java.util.StringTokenizer

private var N = 0;
private var M = 0;
private var S = ""; // 아버지 경로
private var u = 0;
private var v = 0;
private lateinit var c : String;
private lateinit var st : StringTokenizer;
private var result = 0;
private lateinit var tree : Array<MutableList<Pair<String, Int>>>;

fun input_data() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    st = StringTokenizer(br.readLine())
    N = st.nextToken().toInt()
    tree = Array(N+1) { mutableListOf<Pair<String, Int>>()}
    M = st.nextToken().toInt()
    S = br.readLine()
    repeat(N-1) {
        st = StringTokenizer(br.readLine())
        u = st.nextToken().toInt()
        v = st.nextToken().toInt()
        c = st.nextToken()
        tree[u].add(Pair(c, v))
        tree[v].add(Pair(c, u))
    }
}

fun getLCS(N: String, M:String) : Int {
    val nLen = N.length
    val mLen = M.length
    val NM = Array(nLen+1){Array(mLen+1){0}}
    for(n in 1..nLen) {
        for (m in 1..mLen) {
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
    return NM[nLen][mLen]
}

fun solution() {
    val q : Queue<Pair<String, Int>> = LinkedList()
    var visited = Array<Boolean>(N+1){false};
    visited[1] = true
    q.offer(Pair("", 1))
    while(q.isNotEmpty()) {
        val alphabet = q.peek().first
        val node = q.peek().second
        q.poll()
        visited[node] = true
        if (tree[node].size == 1) {
            //println("$alphabet")
            result = maxOf(getLCS(alphabet, S), result)
            if (result == M) { return }
        }
        tree[node].forEach {
            if (visited[it.second] == false)
                q.add(Pair(alphabet+it.first, it.second))
        }
    }
    // 트리의 끝을 찾는 과정 수행 : BFS? DFS? 1에서 출발하여 갈 수 있는 모든 선택지 ㄱㄱ
    // 트리의 끝을 찾은 경우, LCS로 행복지수를 구한 후 리턴
}

fun main() {
    input_data()
    solution()
    println("${result}")
}