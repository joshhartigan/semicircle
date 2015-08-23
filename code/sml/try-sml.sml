(* type inference *)
val forty_two = 39 + 3

(* type specification *)
val thirty_one : int = 30 + 1

(* negative number uses tilde *)
val russell_crowes_actor_rating_out_of_ten = ~5

(* functions, equality, modulo *)
fun is_even(x : int) = if x mod 2 = 0 then true else false

(* shorter function declarations *)
fun is_odd x = x mod 2 <> 0

(* you cannot multiply an integer
 * and a floating point number (a 'real')
 * this will not work, for example:
         val x = 1.25 * 10
 *)

(* there are two different division operators *)
val division = 15.0 / 2.0 (*  = 7.5  *)
val other    = 15 div 4   (*  = 7    *)

val name    = "josh" (*  strings  *)
val initial = #"j"   (*  chars    *)

val nums = [ 1, 4, 6, 2, 3, 7, 9, 0 ] (*  arrays  *)

(* strings aren't the same as arrays,
 * this would not work:
         val x = [ #"h", #"e", #"l", #"l", #"o" ]
         print x
 *)

(* arrays of chars can be converted to strings: *)
val foo = [ #"h", #"e", #"l", #"l", #"o" ]
val len = List.length foo

val bar = String.implode foo

(* string concatenation *)
val _ = print (bar ^ "\n")

(* array concatenation *)
val arr = [ "Me", "Myself" ] @ [ "I" ]

(* cons operator ala haskell *)
val bands = "Radiohead" :: "10cc" :: "Sigur Rós" :: "∆" :: []

(* tuples can contain elements of different types *)
val stuff : char * real * bool = ( #"q", 33.24, true )

(* functions can be broken into multiple lines *)
(* this example also demonstrates pattern matching *)
fun mood_on "monday"    = "tired"
  | mood_on "tuesday"   = "bored"
  | mood_on "wednesday" = "ok"
  | mood_on "thursday"  = "happy"
  | mood_on "friday"    = "excited"
  | mood_on "saturday"  = "happy"
  | mood_on "sunday"    = "relaxed"
  | mood_on x           = "non-existant"

val today = mood_on "monday"
val _ = print today
