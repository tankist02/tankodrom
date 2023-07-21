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
    println!("s: {:?}", s)
}
