use std::env;

#[derive(Debug)]
struct Shoe {
    size: u32,
    style: String,
}

fn shoes_in_size(shoes: Vec<Shoe>, shoe_size: u32) -> Vec<Shoe> {
    shoes.into_iter().filter(|s| s.size == shoe_size).collect()
}

fn main() {
    let args: Vec<String> = env::args().collect();
    let mut loops: i32 = 1000;
    if args.len() > 1 {
        loops = args[1].parse().unwrap();
    }
    let mut counter = 0;
    let mut l = 0;
    while l < loops {
        let mut shoes: Vec<Shoe> = Vec::new();
        let shoes_num = 200;
        let mut i = 0;
        while i < shoes_num {
            let s = i % 12;
            let mut st = String::from("boot");
            let str: String = s.to_string();
            st.push_str(&str);
            let shoe = Shoe { size: s, style: st };
            shoes.push(shoe);
            i += 1;
        }
    
        let in_my_size = shoes_in_size(shoes, 10);
        if l == 0 {
            println!("in_my_size: {:?}", in_my_size);
            println!("last style: {:?}", in_my_size.last().unwrap().style);
        }
        counter += in_my_size.len();
        l += 1;
    }
    println!("counter: {}, l: {}", counter, l);
}
