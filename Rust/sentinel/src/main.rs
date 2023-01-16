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

    let mut v = vec!["hello", "world", "everybody"];
    let e1 = v[0];
    println!("{e1}");
    let s1 = String::from(e1);
    println!("{s1}");
    let o5 = v.get(5);
    match o5 {
        Some(s) => println!("{s}"),
        None => println!("None"),
    }

    v.push(&s1);
    println!("{}", v.len());

    let v2 = vec![String::from("hello"), String::from("world")];
    let e0 = &v2[0];
    println!("{e0}");
    for e in &v2 {
        println!("{e}");
    }

    let mut v3 = vec![1, 2, 3];
    for e in &mut v3 {
        let n = *e + 1;
        println!("{e}, {n}");
        *e += 1;
    }

    for e in v3 {
        println!("{e}");
    }

    let mut s = String::new();
    s.push_str("world");
    let mut s2 = "hello".to_string();
    s2.push_str(&s);
    {
        let s3 = "foo".to_string();
        s2.push_str(&s3);
    }
    println!("{s2}");
}
