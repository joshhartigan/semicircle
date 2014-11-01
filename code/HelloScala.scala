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
  println( halve.toString ) // waat?

  // like javascript's .each():
  val firstSeven = List(1, 2, 3, 4, 5, 6, 7)
  for (n <- firstSeven) println( square(n) )
  // increased specificity:
  for (n <- firstSeven if n > 4) println(n)

}
