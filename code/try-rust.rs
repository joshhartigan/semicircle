fn main() {
    greet_the_world();

    // * the following two declarations
    //   are the same - aside from identifiers.
    // * they are both immutable.
    // * therefore, they must be initialised
    //   immediately
    let x = 5i;
    let y:int = 5;

    // this declares a mutable variable:
    let mut z = 10i;
    z = 100i; // tada!

    if z >= 50i {
        println!("z is a big number");
    } else {
        println!("z isn't a big number");
    }

    // similar to a ternary operator:
    let a = if x > 1 { true } else { false };
    // (these need semicolons)

    describe_number(200i);
    describe_number(23i);
}

// argument types must be specified
// ... and so must return types
fn describe_number(number: int) -> int {
    println!("the number is {}", number);

    let big = if number > 50 { "is big" } else { "isn't big" };
    println!("the number {}", big);

    number // ruby-esque return statements
           // don't need a semicolon, or else rust
           // would look for another expression to return
           // (and there isn't one, thrfr. the return type
           // would be a lie)
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

