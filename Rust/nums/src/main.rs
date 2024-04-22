fn main() {
    println!("Hello, nums!");

    let fl = [1.1, 2.2, 3.3];
    let mut i = 0;
    for f in fl {
        println!("i: {}, f: {}", i, f);
        i += 1;
    }

    println!("fl: {:?}", fl);

    let nums = vec!(1, 2, 3);
    for n in &nums {
        println!("n: {}", n);
    }

    // nums will be moved above if passed by value, not reference (because of implicit iter_into)
    for n in nums {
        println!("n: {}", n);
    }
}
