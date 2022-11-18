fn main() {
    println!("Hello, vector!");

    let mut v1 = vec![1, 2, 3];
    println!("v1: {:?}", v1);
    v1.push(4);
    println!("v1: {:?}", v1);

    let v2 = vec!["only one"];
    println!("v2: {:?}", v2);

    let v3 = vec!("only one");
    println!("v3: {:?}", v3);

    let v4 = vec!{"only one"};
    println!("v4: {:?}", v4);
}
