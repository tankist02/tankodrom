fn hold_my_vec<T>(_: Vec<T>) {}

fn main() {
    let v = vec![1, 2];
    hold_my_vec(v);
    println!("v: {:?}", v);
}

