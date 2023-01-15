#[derive(Debug)]
struct Rectangle {w: i32, h: i32}

impl Rectangle {
    fn area(&self) -> i32 {
        self.w * self.h
    }
}

fn main() {
    println!("Hello, world!");

    let sentence = "The fox jumps over the dog";
    let index = sentence.find("fox");
    println!("index: {:?}", index);
    //let words_at = &sentence[index..];

    if let Some(fox) = index {
        let words_at = &sentence[fox..];
        println!("{}", words_at);
    }

    let scale = 2;
    let r = Rectangle {w: dbg!(5 * scale), h: 20};
    println!("r: {:?}", r);
    println!("area: {}", r.area());

    let v = vec!["hello", "world", "everybody"];
    let e1 = v[0];
    println!("{e1}");
    let s1 = String::from(e1);
    println!("{s1}");
    let o5 = v.get(5);
    match o5 {
        Some(s) => println!("{s}"),
        None => println!("None"),
    }
}
