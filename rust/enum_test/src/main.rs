enum Test {
    HELP,
    VERSION
}

fn main() {
    println!("Hello, enum_test!");

    let e = 2;
    match e {
        Test::HELP => { println!("help"); }
        Test::VERSION => { println!("version"); }
        _ => { println!("anything"); }
    }
}
