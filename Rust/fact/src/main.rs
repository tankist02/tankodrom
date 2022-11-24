const fn fact(n : u128) -> u128 { if n == 0 { 1 } else { n * fact(n - 1) }}

fn main() {
    println!("Hello, world!");

    let mut i = 0;
    while i < 1000000 {
        //println!("fact(20): {}", fact(20));
        let n = fact(20);
        i += 1;
    }
}
