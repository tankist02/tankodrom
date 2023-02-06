use std::env;

use num_bigint::BigUint;
//use num_traits::{Zero, One};
use std::mem::replace;

// Calculate large fibonacci numbers.
fn fib(n: i32) -> BigUint {
    let mut f0 = BigUint::from(0u32); //Zero::zero();
    let mut f1 = BigUint::from(1u32); //One::one();
    for _ in 0..n {
        let f2 = f0 + &f1;
        // This is a low cost way of swapping f0 with f1 and f1 with f2.
        f0 = replace(&mut f1, f2);
    }
    f0
}

fn main() {
    let args: Vec<String> = env::args().collect();
    let n: i32 = if args.len() > 1 { args[1].parse().unwrap() } else { 250000 };
    use std::time::Instant;
    let now = Instant::now();
    let f = fib(n);
    let elapsed = now.elapsed();
    //println!("{n}th fib # is: {f}");
    println!("{n}");
    println!("{f}");
    println!("Time to compute: {:?}", elapsed);
}
