import kotlin.collections.HashMap
fun main(){


    var num = readLine()!!.toInt()

    var array : IntArray = IntArray(num)
    var map = HashMap<Int,Int>()
    var sum : Double = 0.0
    var count=-1
    var index=-1

    for(i in 0 until  num){
        array[i] = readLine()!!.toInt()
        map.put(array[i],map.getOrDefault(array[i],0)+1)
        sum +=array[i]
    }

    array.sort()

    var average = Math.round(sum / num)

    println(average)

    println(array[num/2])
    var check = false
    for(i in map.keys.sorted()){
        if(map.get(i)!!>count){
            count = map.get(i)!!
            index = i
            check = false
        }
        else if(map.get(i)==count && !check){
            index = i
            check =true
        }
    }
    println(index)
    if(array.size==1){
        println(0)
    }else{
        println(array[num-1]-array[0])
    }
}
