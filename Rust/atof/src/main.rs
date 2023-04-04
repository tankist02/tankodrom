use std::env;

fn main() {
    let args: Vec<String> = env::args().skip(1).collect();
    for a in &args {
        let d = a.parse::<f64>().unwrap();
        printl!("{a} {:.16}", d);
    }   
}
