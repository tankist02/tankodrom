use std::env;
use std::io;
use std::io::Read;
use std::fs::File;

fn load_file(n: &str) -> Result<String, io::Error>{
    let mut s = String::new();
    File::open(n)?.read_to_string(&mut s)?;
    Ok(s)
}

fn main() {
    let args: Vec<String> = env::args().collect();

    let def: String = "test.csv".to_string();
    let n = if args.len() > 1 { &args[1] } else { &def };
    println!("Loading file: {}...", n);

    use std::time::Instant;
    let now = Instant::now();
    let s = match load_file(n) {
        Ok(s) => s,
        Err(error) => {
            println!("Failed to load file: {}, error: {}", n, error);
            return
        },
    };
    println!("Content size: {}, time to load: {:?}", s.len(), now.elapsed());
}
