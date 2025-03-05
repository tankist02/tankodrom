#[derive(Debug)]
struct Point {
    x: f32, 
    y: f32 
}

#[derive(Debug)]
struct Rect {
    top_left: Point,
    bottom_right: Point
}

fn rect_area(rect: &Rect) -> f32 {
    let dx = rect.bottom_right.x - rect.top_left.x;
    let dy = rect.top_left.y - rect.bottom_right.y;
    dx * dy
}

fn square(p: &Point, s: f32) -> Rect {
    Rect { top_left: Point{ x: p.x, y: p.y }, bottom_right: Point { x: p.x + s, y: p.y - s }}
}

fn main() {
    println!("Hello, rect!");

    let r1 = Rect{ top_left: Point{ x: 0.0, y: 1.0}, bottom_right: Point{ x: 1.0, y: 0.0 }};
    println!("Area: {}", rect_area(&r1));

    let r2 = Rect{ top_left: Point{ x: 1.0, y: 3.0}, bottom_right: Point{ x: 3.0, y: 1.0 }};
    println!("Area: {}", rect_area(&r2));

    let p = Point{ x: 1.0, y: 2.0 };
    let s1 = square(&p, 3.0);
    println!("s1: {:?}", s1);
}
