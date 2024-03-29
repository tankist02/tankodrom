use std::collections::HashMap;

fn foo(i: i32) -> i32 {
    if i > 0 {
        1
    }
    -1
}

fn bar(f: f64) -> f64 {
    f + 2.0
}

fn main() {
    println!("Hello, world!");

    let text = "hello world wonderful world";

    let mut map = HashMap::new();

    for word in text.split_whitespace() {
        println!("word: {}", word);
        let count = map.entry(word).or_insert(0);
        println!("count: {}", count);
        *count += 1;
    }

    println!("{:?}", map);

    let mut h = HashMap::new();

    h.insert("k1", 0);

    //let v1 = &sahh["k1"];
    let v1 = h["k1"];
    h.insert("k2", 1);

    let v2 = &h["k2"];
    println!("{} {}", v1, v2);
    
    let mut h: HashMap<char, Vec<usize>> = HashMap::new();

    for (i, c) in "hello!".chars().enumerate() {
        h.entry(c).or_default().push(i);
    }
  
    let mut sum = 0;
  
    for i in h.get(&'l').unwrap() {
        sum += *i;
    }
  
    println!("{}", sum);
}
