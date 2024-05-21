//use std::str::from_utf8;
use std::time::Instant;

use std::env;

// Here the main bottleneck is concatenating vectors and strings
// Searching in them is very fast

fn gen_str(len: usize) -> String {
    let charset = 
        "0123456789\
ABCDEFGHIJKLMNOPQRSTUVWXYZ\
abcdefghijklmnopqrstuvwxyz";
    
    //println!("charset: {} ({})", charset, charset.len());

    let mut res: String = String::from("");
    res.reserve(len);
    for i in 0..len {
        let ch = charset.chars().nth(i % charset.len()).unwrap();
        res.push(ch);
    }
    res
}

/*
fn gen_bytes(len: usize) -> Vec<u8> {
    let charset = 
        "0123456789\
ABCDEFGHIJKLMNOPQRSTUVWXYZ\
abcdefghijklmnopqrstuvwxyz".as_bytes();
    
    //println!("charset: {} ({})", charset, charset.len());
    
    let mut res: Vec<u8> = Vec::new();
    res.reserve(len);
    for i in 0..len {
        let ch = charset[i % charset.len()];
        res.push(ch);
    }
    res
}*/

fn main() {
    let args: Vec<String> = env::args().collect();
    println!("Hello, str_test!, args: {:?}", &args);

    let mut loops: usize = 5;
    if args.len() > 1 {
        loops = args[1].parse::<usize>().unwrap();
    }

    println!("loops: {}", loops);

    /*let b = gen_bytes(65);
    println!("b: {:?}, s: {:?}", b, from_utf8(&b).unwrap());
    let pos = b.iter().position(|b| *b == 'A' as u8).unwrap_or(usize::MAX);
    println!("pos: {:?}", pos);*/

    /* Using vectors of bytes is too slow compared to strings
    let bytes = [gen_bytes(6), gen_bytes(25), gen_bytes(14), gen_bytes(235) , gen_bytes(155)];

    let start = Instant::now();

    let mut count: usize = 0;
    let mut buffer: Vec<u8> = Vec::new();
    buffer.reserve(10240);
    for i in 0..loops {
        buffer.clear();
        for j in 0..i {
            // Too much cloning, too slow
            let mut b = bytes[j % bytes.len()].clone();
            buffer.append(&mut b);
        }
        let pos = buffer.iter().position(|b| *b == 'A' as u8).unwrap_or(usize::MAX);
        if pos != usize::MAX { count += pos; }
        let pos = buffer.iter().position(|b| *b == 'z' as u8).unwrap_or(usize::MAX);
        if pos != usize::MAX { count += pos; }
        //println!("buffer: {:?}, count: {}", from_utf8(&buffer).unwrap(), count);
    }
    println!("bytes count: {}, elapsed: {:?}", count, start.elapsed());
    //println!("buffer len: {}, elapsed: {:?}", buffer.len(), start.elapsed());
    */
    
    //let s = gen_str(10);
    //println!("s: {:?}", s);

    let strings = [gen_str(6), gen_str(25), gen_str(14), gen_str(235) , gen_str(155)];
    //for i in 0..strings.len() { println!("{} ({})\n", &strings[i], &strings[i].len()); }

    let start = Instant::now();

    let mut count: usize = 0;
    let mut str = String::from("");
    str.reserve(10240);
    for i in 0..loops {
        str.clear();
        for j in 0..i {
            str.push_str(&strings[j % strings.len()]);
        }
        if str.contains("A") { count += 1; }
        if str.contains("z") { count += 1; }
    }
    //println!("str: {:?}", str);
    println!("str len: {}, count: {}, elapsed: {:?}", str.len(), count, start.elapsed());
    //println!("str len: {}, elapsed: {:?}", str.len(), start.elapsed());
}
