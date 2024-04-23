fn main() {
    println!("Hello, loops!");

    for (x, y) in (0..).zip(0..) {
        println!("x: {}, y: {}", x, y);
        if x + y == 100 { break; }
    }

    let a = [0..5]; //.zip(0..5);
    println!("a: {:?}", a);
}
