struct Test {
    i: i32,
}

impl Test {
    fn test(i: i32) -> i32 { let i = i; i }
    //fn new(&self, i: i32) -> Test { Test { i } }
}

fn main() {
    println!("Hello, world!");

    let name = String::from("Vivian");
    let nickname = &name[..3];
    println!("{}", name);
    //name.clear();
    println!("{}", nickname);

    let mut t = Test {i: 1};
    t.i = 2;

    let j = Test::test(3);
    println!("i: {}", j);
}
