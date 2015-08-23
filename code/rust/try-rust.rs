#[allow(unused_variables)]
#[allow(unused_assignments)]

fn main() {
    greet_the_world();

    // * the following two declarations
    //   are the same - aside from identifiers.
    // * they are both immutable.
    // * therefore, they must be initialised
    //   immediately
    let x = 5;
    let y:i32 = 5;

    // this declares a mutable variable:
    let mut z = 10;
    z = 100; // tada!

    if z >= 50 {
        println!("z is a big number");
    } else {
        println!("z isn't a big number");
    }

    // similar to a ternary operator:
    let a = if x > 1 { true } else { false };
    // (these need semicolons)

    describe_number(200);
    describe_number(23);

    iterations();

//  fn  square   (x:i32) { x * x }
    let square = |x:i32| { x * x };
    // see the `twice()` function for a 'proper'
    // use of rust's closures

    println!("the square of {} is {}", 17, square(17));
    println!("twice the square of {} is {}", 29, twice(29, square));
}

fn twice<F: Fn(i32) -> i32>(x: i32, f: F) -> i32 {
    f(x) + f(x)
}

fn describe_number(number: i32) -> i32 {
    println!("the number is {}", number);

    let big = if number > 50 { "is big" } else { "isn't big" };
    println!("the number {}", big);

    number // ruby-esque return statements
           // don't need a semicolon, or else rust
           // would look for another expression to return
           // (and there isn't one, thrfr. the return type
           // would be a lie)
}

fn iterations() {
    let arr = [3, 8, 9, 2, 3, 0, 1, 8, 5, 4];
    for element in arr[0..arr.len()].iter() {
        print!("{}, ", element);
    }
    println!("{}", arr[arr.len() -1 ]);
}

// * what follows is a doc comment (notice the triple slash):
// * doc comments support markdown!
// * `rustdoc` will generate HTML documentation from doc comments.

/// `greet_the_world` is a useless function that prints a string
/// that can be used for greeting the world.
///
/// # Arguments
///
/// * there are no arguments
///
/// # Example
///
/// ```rust
/// fn main() {
///     greet_the_world(); // prints 'hello, world'
/// }
/// ```
fn greet_the_world() {
    println!("hello, world");
}
