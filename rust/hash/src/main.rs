use std::collections::HashMap;

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
}
