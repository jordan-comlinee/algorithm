package softeer

import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

private var max_distance = 0    // 자동차가 한번에 갈 수 있는 거리
private var repair_shop = 0     // 정비소 개수
private lateinit var distance_list : MutableList<Int>   // 정비소들간의 거리
private lateinit var repair_list : MutableList<Int> // 각 정비소들의 정비 시간
private var result = 0
private var repaired_list : MutableList<Int> = mutableListOf()
private fun input_data() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    max_distance = br.readLine().toInt()
    repair_shop = br.readLine().toInt()
    distance_list = br.readLine().split(" ").map{it.toInt()}.toMutableList()
    repair_list = br.readLine().split(" ").map { it.toInt() }.toMutableList()
}


private fun solution() {
    // DP 테이블: 정비소를 들렸을 때 최소 정비 시간을 저장
    val minRepairTime = IntArray(repair_shop + 2) { Int.MAX_VALUE }
    // 방문한 정비소 경로 저장
    val path = Array(repair_shop + 2) { mutableListOf<Int>() }

    // 출발 지점 (0번째 정비소에서 시작)
    minRepairTime[0] = 0

    for (i in 0..repair_shop) {
        var distanceSum = 0  // 누적 거리 계산

        for (j in i + 1..repair_shop + 1) {
            distanceSum += distance_list[j - 1]

            // 현재 위치에서 다음 정비소까지 이동할 수 있는 경우
            if (distanceSum > max_distance) break

            // 정비소에서 정비할 경우 최소 정비 시간 갱신
            if (minRepairTime[i] != Int.MAX_VALUE) { // 유효한 경우만 업데이트
                val newRepairTime = if (j == repair_shop + 1) minRepairTime[i]
                else minRepairTime[i] + repair_list[j - 1]

                if (newRepairTime < minRepairTime[j]) {
                    minRepairTime[j] = newRepairTime
                    path[j] = path[i].toMutableList()
                    if (j <= repair_shop) path[j].add(j) // 마지막 도착지는 정비소가 아님
                }
            }
        }
    }

    // 결과 저장
    result = minRepairTime[repair_shop + 1]
    repaired_list = path[repair_shop + 1].toMutableList()
    path.forEach {
        println("${it.size}")
    }
}


private fun output_data() {
    val bw = BufferedWriter(OutputStreamWriter(System.out))
    bw.write("$result\n")
    bw.write("${repaired_list.size}\n")
    repaired_list.forEach {
        bw.write("$it ")
    }
    bw.flush()
    bw.close()
}

fun main() {
    input_data()
    solution()
    output_data()
}