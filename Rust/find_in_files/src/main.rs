use std::env;
use std::io;
use std::io::Read;
use std::fs::File;

fn load_strings(fname: &str) -> Vec<String> {
    let mut res: Vec<String> = Vec::new();
    res
}

fn load_file(n: &str) -> Result<String, io::Error>{
    let mut s = String::new();
    File::open(n)?.read_to_string(&mut s)?;
    Ok(s)
}

fn find<'a>(ss: &'a[String], content: &str) -> Vec<&'a str>
{
    println!("Searching for {} substrings", ss.len());
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
    println!("Found {} substrings, search time: {:?}", found.len(), now.elapsed());
    
    /* Search gradually from 1 to all substrings
    for i in 1..stf.len() {
        let now = Instant::now();
        let found = find(&stf[0..i], &content);
        let elapsed = now.elapsed().as_millis();
        let per: f32 = elapsed as f32 / i as f32;
        println!("Found {} substrings, search time: {:?}, per substring: {:?}ms\n", 
            found.len(), elapsed, per);
        //println!("Found: {:?}\n", found);
    }*/
}
