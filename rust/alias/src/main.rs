fn main() {
    println!("Hello, world!");

    let name = String::from("Vivian");
    let nickname = &name[..3];
    println!("{}", name);
    //name.clear();
    println!("{}", nickname);
}
