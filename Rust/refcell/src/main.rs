use std::rc::Rc;

fn print_slice(s: &str) -> () { println!("slice: {s}"); }
fn print_ref_str(s: &String) { println!("ref str: {s}"); }

fn main() {
    println!("Hello, refcell!");

    #[derive(Debug)]
    struct Nums {
        i: i32,
        f: f32,
    }

    let n = Nums{i: 1, f: 2.0};
    println!("n: i: {}, f: {}", n.i, n.f);

    let n1 = Nums{i: 1, f: 2.0};
    println!("n1: {:?}", n1);

    let nr = Rc::new(n1);
    println!("nr: {:?}", nr);

    //let nr2 = Rc::new(nr);
    let nr2 = nr;
    println!("nr2: {:?}", nr2);

    //let nr3 = Rc::new(nr2);
    let nr3 = nr2;
    println!("nr3: {:?}", nr3);

    //nr.i = 2;
    //nr.f = 3.0;
    //println!("n1: {:?}", n1);
    //println!("nr: {:?}", nr);
    //println!("nr2: {:?}", nr2);
    //println!("nr3: {:?}", nr3);

    let s: String = "Austria".to_string();
    println!("s: {s}");
    let s1: &String = &s;
    println!("s1: {s1}");
    let s2: &str = &s;
    println!("s2: {s2}");

    print_slice(&s);
    print_ref_str(&s);

    println!("{:X}", '행' as u32);
    println!("{:X}", 'H' as u32);
    println!("{:X}", '居' as u32);
    println!("{:X}", 'い' as u32);
    println!("\u{D589}, \u{48}, \u{5C45}, \u{3044}");

    let s: String = "abc".into();
    let n: &str = "123".into();
    println!("s: {s}, n: {n}");

    enum Mood {
        Good(String),
        Bad(String),
    }

    let m = Mood::Bad(String::from("it sucks"));
    if let Mood::Bad(s) = m {
        println!("s: {}", s);
    }

    let m = Mood::Good("good".to_string());
    match m {
        Mood::Good(s) => println!("I'm feeling {s}"),
        Mood::Bad(s) => println!("It sucks {s}"),
    }

    let a = true;
    let b = if a { false } else { true };
    println!("a: {a}, b: {b}");

    let num: i32 = 1;
    let pos = num.is_positive(); // won't compile for u32
    println!("pos: {pos}");

    let nums = vec![1, 2, 3];
    for i in 0..5 {
        let res = nums.get(i);
        println!("res: {res:?}");

        if let Some(val) = nums.get(i) {
            println!("val: {val}");
        }
    }

    fn get_even(i: i32) -> Result<i32, String> {
        if i % 2 == 0 {
            Result::Ok(i)
        }
        else {
            Result::Err(format!("{i} is not even"))
        }
    }

    let ev = get_even(1);
    println!("ev: {ev:?}");

    if let Ok(val) = get_even(2) {
        println!("val: {val}");
    }

    if let Err(s) = get_even(1) {
        println!("s: {s}");
    }
}
