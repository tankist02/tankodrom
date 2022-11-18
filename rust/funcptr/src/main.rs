fn work(buf: &str) -> &str {
    buf
}

fn common(f: fn(&str) -> &str, buf: &str) {
    println!("{:?}", f(buf));
}

fn main() {
    common(work, "Hello, world!");
}
