// Function to capitalize the first letter in string slice
// It is not trivial because strings are UTF-8
pub fn capitalize_first(w: &str) -> String {
    let mut c = w.chars();
    match c.next() {
        None => String::new(),
        Some(first) => first.to_uppercase().chain(c).collect(),
    }
}

fn main() {
    let s = &["foo", "bar"];
    println!("s: {:?}", s);
    let v: Vec<String> = s.iter().map(|s| s.to_string().to_uppercase()).collect();
    println!("v: {:?}", v);

    let v = vec!["hello", " ", "world"];
    // Cannot write as 1 expression because type Vec<String> cannot be auto determined
    let v2: Vec<String> = v.iter().map(|w| capitalize_first(w)).collect();
    let s = v2.concat();
    println!("s: {:?}", s);

    let i = vec![1, 2, 3];
    let sum = i.iter().fold(0, |acc, x| acc + x);
    println!("{sum}");

    let n = 6;
    let r = (1..n + 1).collect::<Vec<_>>().iter().fold(1, |acc, x| acc * x);
    println!("{:?}", r);

    /*let i = 1;
    let j = 0;
    let k = i / j;
    println!("{k}");*/

    let j = 10;
    for i in 0..10 {
        let k = j / i;
        println!("{:?}", k);
    }

    let f = 1.0;
    let d = f / 0.0;
    println!("{d}");

    //let mul = i.iter().fold(1, |acc, x| acc * x);
    //let mul = [1..3].iter().fold(1, |acc, x| acc * x);
    //println!("{mul}")
}
