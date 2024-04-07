fn main() {
    println!("Hello, world!");

    let numbers = [1, 2, 3];

    for n in &numbers {
        println!("{}", *n);
    }
    for n in &numbers {
        println!("{}", *n);
    }

    let numbers = vec![1, 2, 3];

    for n in &numbers {
        println!("{}", *n);
    }
    for n in &numbers {
        println!("{}", *n);
    }
}

