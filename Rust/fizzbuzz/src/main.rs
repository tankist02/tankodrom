use std::env;
use std::borrow::Cow;

fn fizzbuzz(i: i32) -> String {
    if i % 15 == 0 { String::from("FizzBuzz") } 
    else if i % 5 == 0 { String::from("Buzz") } 
    else if i % 3 == 0 { String::from("Fizz") } 
    else { i.to_string() }
}

fn fizzbuzz2(i: i32) -> Cow<'static, str> {
    if i % 15 == 0 { "FizzBuzz".into() } 
    else if i % 5 == 0 { "Buzz".into() } 
    else if i % 3 == 0 { "Fizz".into() } 
    else { i.to_string().into() }
}

fn main() {
    let args: Vec<String> = env::args().collect();
    let mut loops: i32 = 1000;
    if args.len() > 1 {
        loops = args[1].parse().unwrap();
    }
    let mut l = 0;
    let mut sumlen = 0;
    while l < loops {
        //let res = fizzbuzz(l);
        let res = fizzbuzz2(l);
        sumlen += res.len();
        l += 1;
    }
    println!("loops: {}, sumlen: {}", loops, sumlen);
}
