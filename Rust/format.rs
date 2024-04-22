fn main()
{
    let num = 1.23456789;
    println!("num: {:02}, {:08}", num, num);
    let i1 = 1;
    let i2 = 12;
    println!("{:02}, {:08}", i1, i2);

    let x: f32 = 1.0 / 0.0;
    assert!(!x.is_finite());
}