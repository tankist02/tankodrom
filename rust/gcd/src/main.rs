use std::str::FromStr;
use std::env;

fn gcd(mut n: u64, mut m: u64) -> u64 {
    assert!(n != 0 && m != 0);
    while m != 0 {
        if m < n {
            let t = m;
            m = n;
            n = t;
        }
        m = m % n;
    }
    n
}

fn main() {
    println!("Hello, world!");
    let mut numbers = Vec::new();
    for arg in env::args().skip(1) {
        println!("arg: {}", &arg);
        let m = u64::from_str(&arg).expect("not a number");
        numbers.push(m);
    }
    println!("gcd(12, 6): {}", gcd(12, 6));
    let m = numbers[0];
    let n = numbers[1];
    println!("gcd({}, {}): {}", m, n, gcd(m, n));
    let mut sum = 0;
    for _i in 0..100000000 {
        let r = gcd(m, n);
        sum = sum + r;
    }
    println!("sum: {}", sum);
}

#[test]
fn test_gcd() {
    println!("gcd(12, 6): {}", gcd(12, 6));
}

