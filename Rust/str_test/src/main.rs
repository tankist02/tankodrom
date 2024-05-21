//use std::str::from_utf8;
use std::env;

fn gen_str(len: usize) -> String {
    let charset = 
        "0123456789\
ABCDEFGHIJKLMNOPQRSTUVWXYZ\
abcdefghijklmnopqrstuvwxyz";
    
    println!("charset: {} ({})", charset, charset.len());
    
    let mut res: String = String::from("");
    res.reserve(len);
    for i in 0..len {
        let ch = charset.chars().nth(i % charset.len()).unwrap();
        res.push(ch);
    }
    res
}

fn main() {
    let args: Vec<String> = env::args().collect();
    println!("Hello, str_test!, args: {:?}", &args);

    let mut loops: usize = 5;
    if args.len() > 1 {
        loops = args[1].parse::<usize>().unwrap();
    }

    println!("loops: {}", loops);

    let s = gen_str(10);
    println!("s: {:?}", s);

    let strings = [gen_str(6), gen_str(25), gen_str(14), gen_str(235) , gen_str(155)];
    for i in 0..strings.len() { println!("{} ({})\n", &strings[i], &strings[i].len()); }
    let mut count: usize = 0;
    let mut str = String::from("");
    str.reserve(1024);
    for i in 0..loops {
        str.clear();
        for j in 0..i {
            let s = strings[j % strings.len()].clone();
            str += &s;
        }
        if str.contains("A") { count += 1; }
        if str.contains("z") { count += 1; }
    }
    println!("str: {:?}", str);
    println!("count: {}", count);
}
