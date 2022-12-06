import java.io.File
import java.util.*

fun readAllLines(fileName: String): List<String> = File(fileName).bufferedReader().readLines()

fun part1()
{
    //val fileName = "D:\\progs\\advent\\2022\\day1\\sample_input.txt"
    val fileName = "D:\\progs\\advent\\2022\\day1\\input.txt"
    val ll = readAllLines(fileName)

    var maxCal = 0
    var cal = 0
    for(ss in ll)
    {
        if(ss.isNotEmpty())
        {
            cal += ss.toInt()
        }
        else
        {
            if(cal > maxCal) maxCal = cal
            cal = 0
        }
    }
    println("PART 1 maxCal = $maxCal")
}

fun part2()
{
    //val fileName = "D:\\progs\\advent\\2022\\day1\\sample_input.txt"
    val fileName = "D:\\progs\\advent\\2022\\day1\\input.txt"
    val ll = readAllLines(fileName)

    var totals =  Vector<Int>();
    var cal = 0
    for(ss in ll)
    {
        if(ss.isNotEmpty())
        {
            cal += ss.toInt()
        }
        else
        {
            totals.addElement(cal)
            cal = 0
        }
    }
    totals.sort()
    val total = totals[totals.size - 3] + totals[totals.size - 2] + totals[totals.size - 1];
    println("PART 2 total = $total")
}

fun main()
{
    part1()
    part2()
}
