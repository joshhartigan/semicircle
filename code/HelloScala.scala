object HelloScala extends App {

  println(10)
  println("Boo!")

  val x = 1234 // immutable [constant] value
  var y = 2014 // mutable value

  print( x.toString + " " )
  println(y)

  var mathExpression = 1 + 2 / 3 * 5

  // an anonymous function:
  ( q:Int ) => q * q

  // a defined function
  val square = ( q:Int ) => q * q
  println( square(5) == 25 ) // -> true

  // you can explicitly define the type signature
  // of a function, like in other functional langs
  val halve: Int => Int = _ / 2
  println( halve(234) == 117 ) // -> true

  // like javascript's .each():
  val firstSeven = List(1, 2, 3, 4, 5, 6, 7)
  for (n <- firstSeven) println( square(n) )
  // increased specificity:
  for (n <- firstSeven if n > 4) println(n)

  // basic data structures:

  val array = Array(2, 3, 5, 7, 11, 13)
  println( array(2) == 5 ) // -> true
  println( array(array.length - 1) ) // -> 13
  // array(44) would throw an error

  val map = Map(
    "name" -> "Carlos",
    "age" -> 45,
    "country" -> "Canada"
  )
  println( map("name") + " lives in " + map("country") )
  println( map.withDefaultValue("undefined")("foobar") )

  // a useless function for demonstration
  val createTuple = (a:Int, b:Int) => (a, b)
  val myTuple = createTuple(4, 9)
  myTuple._1 // -> 4
  myTuple._2 // -> 9

  val iteration = 1 to 10
  println( iteration )
  iteration.foreach( println )

  val stringInterpolation: String = "String Interpolation"
  println(s"Scala supports $stringInterpolation")
}

class Animal {
  def makeNoise = { // implicit type
    println("screech")
  }

  def getAge: Int = { // explicit type
    10
  }
}

