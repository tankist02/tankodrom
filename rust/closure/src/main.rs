use std::thread;

#[derive(Debug, Copy, Clone)]
enum ShirtColor {
    Red,
    Blue,
}

struct Inventory {
    shirts: Vec<ShirtColor>,
}

impl Inventory {
    fn giveaway(&self, user_pref: Option<ShirtColor>) -> ShirtColor {
        user_pref.unwrap_or_else(|| self.most_stocked())
    }

    fn most_stocked(&self) -> ShirtColor {
        let mut num_red = 0;
        let mut num_blue = 0;

        for color in &self.shirts {
            match color {
                ShirtColor::Red => num_red += 1,
                ShirtColor::Blue => num_blue += 1,
            }
        }

        if num_red > num_blue {
            ShirtColor::Red
        } else {
            ShirtColor::Blue
        }
    }
}

//fn overload(x: i32) -> i32 { x }
//fn overload(y: &str) -> &str { y }

fn main() {
    let store = Inventory {
        shirts: vec![ShirtColor::Blue, ShirtColor::Red, ShirtColor::Blue],
    };

    let user_pref1 = Some(ShirtColor::Red);
    let giveaway1 = store.giveaway(user_pref1);
    println!("For pref {:?} get {:?}", user_pref1, giveaway1);

    let user_pref2 = None;
    let giveaway2 = store.giveaway(user_pref2);
    println!("For pref {:?} get {:?}", user_pref2, giveaway2);

    let example_closure = | x | x;

    let s = example_closure(String::from("5"));
    let n = example_closure(5.to_string());
    println!("s: {:?}, n: {:?}", s, n);

    let v = vec![1, 2, 3];
    let only_borrows = || println!("From closure: {:?}", v);
    println!("Before only_borrows: {:?}", v);
    only_borrows();
    println!("After only_borrows: {:?}", v);

    let mut v2 = vec![1, 2, 3];
    let mut borrows_mutably = || v2.push(7);
    //println!("Before borrows_mutably: {:?}", v2);
    borrows_mutably();
    println!("After borrows_mutably: {:?}", v2);

    let v3 = vec![1, 2, 3];
    thread::spawn(move || println!("From thread: {:?}", v3)).join().unwrap();
}
