fn longest<'a>(s1: &'a str, s2: &'a str) -> &'a str {
    if s1.len() > s2.len() {
        s1
    }
    else {
        s2
    }
}

struct Part<'a> {
    part: &'a str,
}

impl<'a> Part<'a> {
    fn print(&self) -> () {
        println!("part: {}", self.part);
    }
}

fn main() {
    println!("Hello, lifetime!");
    let s1: String = "short".to_string();
    let s2 = "longer";
    let res = longest(s1.as_str(), s2);
    println!("res: {}", res);

    let novel = String::from("Call me Ishmael. Some years ago...");
    let first = novel.split('.').next().expect("No dot found");
    println!("novel: {}\nfirst: {}", novel, first);

    let p = Part { part: first };
    p.print();
}

#[test]
fn test() {
    println!("Hello, test");
    assert_eq!(2 + 2, 4);
}
