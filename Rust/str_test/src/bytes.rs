//use std::str::from_utf8;

fn gen_str(len: usize) -> Vec<u8> {
    let charset: &str = 
        "0123456789\
ABCDEFGHIJKLMNOPQRSTUVWXYZ\
abcdefghijklmnopqrstuvwxyz";
    
    let mut res: Vec<u8> = Vec::new();
    res.reserve(len);
    for i in 0..len {
        let b = charset.as_bytes()[i % charset.len()];
        res.push(b);
    }
    res
}

fn main() {
    println!("Hello, str_test!");

    //let bs = gen_str(10);
    //println!("bytes: {:?}, str: {:?}", bs, from_utf8(&bs));

    let vectors = [gen_str(6), gen_str(25), gen_str(14), gen_str(235) , gen_str(155)];
    let mut count: usize = 0;
    let mut vec: Vec<u8> = Vec::new();
    vec.reserve(1024);
    let loops = 5;
    for i in 0..loops {
        vec.resize(0, 0);
        for j in 0..i {
            let mut v = vectors[j % vectors.len()].clone();
            vec.append(&mut v);
        }
    }
    //println!("vec: {:?}, s: {:?}", vec, from_utf8(&vec));
    println!("count: {}", count);
}
