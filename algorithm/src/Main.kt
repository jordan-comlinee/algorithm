fun main() {
    var A : String = "slicing"
    println(A.slice(0..3))
    var slicedA = A.slice(0..A.length-1)
    println("$A $slicedA")
}