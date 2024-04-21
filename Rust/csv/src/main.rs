fn main() {
    println!("Hello, CSV world!");

    let input = "\
        small, 10
        medium, 20
        large, 30
        invalid";

    let lines = input.lines();

    for (i, line) in lines.enumerate() {
        println!("i: {}, line: {}", i, line);
        let fields: Vec<_> = line.split(',').map(|l| {l.trim()}).collect();
        println!("fields: {:?}", fields);

        if let Ok(size) = fields[1].parse::<i32>() {
            println!("name: {}, size: {}", fields[0], size);
        }
        else {
            println!("failed to parse?");
        }
    }
}
