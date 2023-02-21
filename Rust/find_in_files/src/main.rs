use std::env;
use std::io;
use std::io::Read;
use std::fs::File;

fn load_file(n: &str) -> Result<String, io::Error>{
    let mut s = String::new();
    File::open(n)?.read_to_string(&mut s)?;
    Ok(s)
}

fn find<'a>(ss: &'a[String], content: &str) -> Vec<&'a str>
{
    let mut found: Vec<&'a str> = Vec::new();
    for s in ss {
        if content.contains(s) {
            found.push(s);
        }
    }
    found
}

fn main() {
    let args: Vec<String> = env::args().collect();

    let def: String = "test.csv".to_string();
    let n = if args.len() > 1 { &args[1] } else { &def };
    println!("Loading file: {}...", n);

    let mut stf: Vec<String> = Vec::new();
    for arg in env::args().skip(2) {
        stf.push(arg.clone());
    }

    println!("Strings to search: {:?}", stf);

    use std::time::Instant;
    let now = Instant::now();
    let content = match load_file(n) {
        Ok(s) => s,
        Err(error) => {
            println!("Failed to load file: {}, error: {}", n, error);
            return
        },
    };
    println!("Content size: {}, time to load: {:?}", content.len(), now.elapsed());

    let now = Instant::now();
    let found = find(&stf, &content);
    println!("Search time: {:?}", now.elapsed());
    println!("Found: {:?}", found);
}
