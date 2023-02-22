struct Point<T> { x: T, y: T }

/*impl Point<i32> {
    fn f(&self) -> &i32 { &self.y }
}*/

impl<T> Point<T> {
    fn f(&self) -> &T { &self.x }
    fn g(&self) -> &T { &self.y }
}

fn main() {
    let col = vec![6, 1, 2, 3, 4, 5];
    print(&col);
    let largest = max(&col);
    println!("{largest}");

    let col = vec![12.0, 1.0, 2.0, 3.0, 4.0, 5.0];
    print(&col);
    let largest = max(&col);
    println!("{largest}");
    let y = mystery(3);
    println!("{y}");

    let p: Point<i32> = Point{x: 1, y: 2};
    println!("{}, {}", p.f(), p.g());
}

fn print<T: std::fmt::Display>(list: &[T]) -> () {
    for num in list {
        print!("{num}, ");
    }
    println!();
}

fn max<T: std::cmp::PartialOrd>(list: &[T]) -> &T {
    let mut largest = &list[0];
    for number in list {
        if number > largest { largest = number; }
    }
    largest
}

fn mystery<T: std::ops::Add<i32, Output = T>>(x: T) -> T {
    x + 1
}
