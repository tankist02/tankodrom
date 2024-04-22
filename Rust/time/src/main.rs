use std::time::{Duration, Instant};
use thousands::Separable;

fn main() {
    println!("Hello, time!");

    let second = Duration::new(1, 0);
    let start = Instant::now();
    let mut count = 0;
    while Instant::now() - start < second {
        count += 1;
    }
    println!("count: {}", count.separate_with_commas());
}
