use std::env;

struct Shoe<'a>  {
    size: u32, // can be u8
    style: &'a str,
    // model_num: u16 // since it makes it more realistic
}

impl<'a> Shoe<'a>  {
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

fn shoes_factory<'a>(num: u32) -> Vec<Shoe<'a>> {
    //let mut shoes = Vec::with_capacity(num);
    let mut shoes = Vec::new();
    let mut i: u32 = 0;
    while i < num {
        let s = i % 12;
        let st = &STYLES[i as usize % 5]; // + &i.to_string();
        shoes.push(Shoe{size: s, style: st});
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
