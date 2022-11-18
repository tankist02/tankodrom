object Recurse {
  def fact(n: Int): Int =
    if (n <= 1) n
    else n * fact(n - 1)

  def main(args: Array[String]): Unit = {
    println("Hello, World!")
  }

}
