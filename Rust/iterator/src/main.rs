use std::env;
use std::time::Instant;

fn vec_proc(len: usize) -> Vec<usize> {
    let mut v = Vec::new();

    for i in 0..len {
        v.push(i);
    }
    v
}

fn sum_proc(v: &[usize]) -> usize {
    let mut s = 0;
    for i in v {
        s += *i;
    }
    s
}

fn vec_iter(len: usize) -> Vec<usize> {
    (0..len).collect()
}

fn sum_iter(v: &[usize]) -> usize {
    v.iter().sum()
}

fn main() {
    println!("Hello, world!");
    let mut loops: usize = 1000;
    let mut size: usize = 1000;

    /*
    let args: Vec<String> = env::args().collect();
    println!("args: {:?}", args);

    if args.len() >= 2 {
        loops = args[1].parse::<usize>().unwrap();
        if args.len() >= 3 {
            size = args[2].parse::<usize>().unwrap();
        }
    }*/

    let mut args = env::args(); // Get iterator to arguments
    args.next(); // Skip program name which is always the first
    if let Some(arg) = args.next() { loops = arg.parse::<usize>().unwrap(); }
    if let Some(arg) = args.next() { size = arg.parse::<usize>().unwrap(); }

    println!("loops: {}, size: {}", loops, size);

    let now = Instant::now();

    let mut tl = 0;
    let mut sum: usize = 0;
    for l in 0..loops {
        let v = vec_proc(size + l);
        sum += sum_proc(&v);
        tl += v.len();
    }

    println!("tl: {}, sum: {}, proc elapsed: {:?}", tl, sum, now.elapsed());

    let now = Instant::now();

    let mut tl = 0;
    let mut sum: usize = 0;
    for l in 0..loops {
        let v = vec_iter(size + l);
        sum += sum_iter(&v);
        tl += v.len();
    }

    println!("tl: {}, sum: {}, iter elapsed: {:?}", tl, sum, now.elapsed());

    let v1 = vec![1, 2, 3];
    let v1_a = v1.iter().map(|i| i + 1).collect::<Vec<i32>>();
    println!("v1: {:?}, v1_a: {:?}", v1, v1_a);

    let mut v2 = vec![5, 6, 7];
    let v2_a = v2.iter().map(|i| i + 1).collect::<Vec<i32>>();
    let v2_b = v2.iter().map(|i| *i + 1).collect::<Vec<i32>>();
    println!("v2: {:?}, v2_a: {:?}, v2_b: {:?}", v2, v2_a, v2_b);

    v2.iter_mut().for_each(|i| *i *= 2);
    println!("v2: {:?}", v2);

    let v3 = v2.into_iter().map(|i| i / 2).collect::<Vec<i32>>();
    println!("v3: {:?}", v3);
    //println!("v3: {:?}, v2: {:?}", v3, v2);
    
    fn find_char_in_vec(v: &Vec<char>, ch: char) {
        //let res = v.iter().any(|c| *c == ch);
        let res = v.iter().any(|&c| c == ch);
        println!("char: {}, res: {}", ch, res);
    }

    let v = ('a'..'z').collect::<Vec<char>>();
    find_char_in_vec(&v, 'a');
    find_char_in_vec(&v, '0');
}
