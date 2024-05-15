use std::env;
use std::io;
use std::io::Read;
use std::fs::File;

fn load_file(n: &str) -> Result<String, io::Error> {
    let mut s = String::new();
    File::open(n)?.read_to_string(&mut s)?;
    Ok(s)
}

fn main() {
    let args: Vec<String> = env::args().collect();

    let def: String = "hello2.txt".to_string();
    let n = if args.len() > 1 { &args[1] } else { &def };

    let s = match load_file(n) {
        Ok(s) => s,
        Err(error) => {
            println!("Failed to load file: {}, error: {}", n, error);
            return
        },
    };
    println!("Loaded file: {}, content: {}", n, s);

    let buf: Vec<u8> = vec![114, 117, 115, 116, 33];
    let text = String::from_utf8_lossy(&buf);
    println!("buf: {:?}, text: {}", buf, text);

    let mut x = 0;
    let y = &x;
    //x = 1;
    println!("x: {}, y: {}", x, y);
    //println!("x: {}", x);

    let mut configs: Vec<String> = vec![
        String::from("foo"),
        String::from("bar"),
    ];

    let mut baz: Vec<String> = Vec::new();
    let mut bazr: Vec<&str> = Vec::new();
    //baz.push(configs[1]);
    //baz.push(configs.get(1).unwrap());
    baz.push(configs[1].clone());
    println!("configs: {:?}, baz: {:?}", configs, baz);
    bazr.push(&configs[0]);
    bazr.push(&configs[1]);
    println!("bazr: {:?}", bazr);

    //configs[0] = String::from("foobar");
    //println!("configs: {:?}, bazr: {:?}", configs, bazr);

    #[derive(Debug)]
    struct File {
        name: String,
        data: Vec<u8>,
    }

    impl File {
        fn new(n: &str) -> File {
            File {
                name: String::from(n),
                data: Vec::new(),
            }
        }

        fn new_data(n: &str, d: Vec<u8>) -> File {
            File {
                name: String::from(n),
                data: d,          
            }
        }
    }

    let f1 = File::new("foo");
    let data = vec![1, 2];
    let f2 = File::new_data("bar", data);
    println!("f1: {:?}, f2: {:?}", f1, f2);

    #[derive(Debug)]
    struct Person {
        name: String,
        age: i32,
    }

    impl Person {
        fn new(n: &str, a: i32) -> Self {
            Person { name: n.to_string(), age: a }
        }
    }

    let p1 = Person { name: "John".to_string(), age: 30 };
    println!("p1: {:?}", p1);

    let p2 = Person::new("Paul", 40);
    println!("p2: {:?}", p2);

    #[derive(Debug)]
    struct Complex {
        re: f64,
        im: f64,
    }

    impl Complex {
        fn add(&self, r: f64, i: f64) -> Self {
            Complex { re: self.re + r, im: self.im + i }
        }

        fn incr(&mut self, r: f64, i: f64) -> &mut Self {
            self.re += r;
            self.im += i;
            self
        }
    }

    let mut c1 = Complex { re: 1.0, im: 2.0 };
    println!("c1: {:?}", c1);

    c1.incr(1.0, 2.0);
    println!("c1: {:?}", c1);
}
