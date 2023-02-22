use std::fs::File;
use std::io::{self, BufRead};
use std::path::Path;

fn main() {
	let mut vec = Vec::new();
    // File hosts must exist in current path before this produces output
    if let Ok(lines) = read_lines("test.csv") {
        // Consumes the iterator, returns an (Optional) String
        for l in lines {
			if let Ok(line) = l {
	        	vec.push(line);
			}
        }
    }
    println!("vec len: {}", vec.len());
	let mut count = 0;
	for line in vec.iter() {
		for c in String::as_str(line).chars() {
			if c == ',' {
				count += 1;
			}
		}
        count += 1; // tokens = commas + 1
	}
	println!("count: {}", count);
}

// The output is wrapped in a Result to allow matching on errors
// Returns an Iterator to the Reader of the lines of the file.
fn read_lines<P>(filename: P) -> io::Result<io::Lines<io::BufReader<File>>>
where P: AsRef<Path>, {
    let file = File::open(filename)?;
    Ok(io::BufReader::new(file).lines())
}

