fn main() {
    let s = &["foo", "bar"];
    println!("s: {:?}", s);
    let v: Vec<String> = s.iter().map(|s| s.to_string().to_uppercase()).collect();
    println!("v: {:?}", v);
}
