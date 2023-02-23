use std::env;
use std::io;
use std::io::BufRead;
use std::io::Read;
use std::fs::File;
use std::path::Path;
use boyer_moore_magiclen::BMByte;

fn load_lines<P: AsRef<Path>>(fname: P) -> Vec<String> {
	let mut vec = Vec::new();
    if let Ok(file) = File::open(fname) {
        let lines = io::BufReader::new(file).lines();
        for l in lines {
            if let Ok(line) = l {
                vec.push(line);
            }
        }
    }
    vec
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

    let bmb = BMByte::from("oocoo").unwrap();
    assert_ne!(0, bmb.find_in("coocoocoocoo", 1).len());
    assert_eq!(0, bmb.find_in("dummy", 1).len());
    return;

    let fname = &args[1];
    let to_find = &args[2];
    println!("File to search: {}, strings to find: {}", fname, to_find);

    let stf = load_lines(to_find);
    
    use std::time::Instant;
    let now = Instant::now();
    let content = match load_file(fname) {
        Ok(s) => s,
        Err(error) => {
            println!("Failed to load file: {}, error: {}", fname, error);
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
