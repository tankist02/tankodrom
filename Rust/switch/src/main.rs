fn main() {
    println!("Hello, world!");
    assert_eq!(switch("", 0), -1);
    assert_eq!(switch("abc", 2), 0);
    assert_eq!(switch("abc", 1), 1);
}

fn switch(s: &str, pos: i32) -> i32 {
    let len: i32 = s.len() as i32;
    match pos {
        0 => { return -1; }
        last if last == len - 1 => { return 0; }
        _ => { return 1; }
    }
}

