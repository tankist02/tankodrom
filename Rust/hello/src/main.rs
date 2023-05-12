fn foo(i: i32) -> i32 {
    if i > 0 {
        1
    }
    else {
        -1
    }
}

fn bar(i: i32) -> i32 {
    let b = 1;
    if i > 0 {
        return b;
    }
    -1
}

fn main() {
    println!("Hello, world!");
    foo(1);
    bar(-1);
	let mut v : Vec<i32> = Vec::new();
    v.push(40);
    println!("{:?}", v);

    {
        println!("{:?}", v);
        let v2 : &mut Vec<i32> = &mut v;
        v2[0] = v2[0] + 1;
        println!("{:?}", v2);
    }
    println!("{:?}", v);

    let res = less(4, 3);
    println!("res: {}", res);
    let res = less(2, 3);
    println!("res: {}", res);

    let a = String::from("abc");
    let b = String::from("xyz");
    let c = a + &b;
    println!("{c}");
}

fn less(i: i64, j: i64) -> bool {
    i < j
}

#[test]
fn tests() {
    assert_eq!(less(1, 2), true);
    assert_eq!(less(2, 1), false);
}

