use std::env;

struct Shoe {
    size: u32,
    style: String,
}

impl Shoe {
    fn print(&self) {
        println!("{}, {}", self.size, self.style);
    }
}

const STYLES:  [&str;5] = [
    "boot", 
    "sneaker",
    "sandal",
    "pump",
    "highheel",
];

fn shoes_factory(num: usize) -> Vec<Shoe> {

    let mut shoes = Vec::new();
    let mut i: usize = 0;
    while i < num {
        let s = i % 12;
        let st = String::from(STYLES[i % 5]) + &i.to_string();
        shoes.push(Shoe{size: s as u32, style: st});
        i += 1;
    }
    shoes
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
        let shoes = shoes_factory(200);
    
        let in_my_size = shoes_in_size(shoes, 10);
        if l == 0 {
            for s in &in_my_size {
                s.print();
            }
        }
        counter += in_my_size.len();
        l += 1;
    }
    println!("counter: {}, l: {}", counter, l);
}
