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
    for i in 0..v.len() {
        s += v[i];
    }
    s
}

fn vec_iter(len: usize) -> Vec<usize> {
    let v = (0..len).collect();
    v
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
}
