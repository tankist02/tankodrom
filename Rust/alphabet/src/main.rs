use std::time::Instant;

fn main() {
    println!("Hello, alphabet!");

    let text = "the quick brown fox jumps over the lazy dog";
    const size: usize = 'z' as usize - 'a' as usize + 1;

    let now = Instant::now();

    let loops = 100_000_000;
    let mut sum = 0;

    for l in 0..loops {
        let mut counts = [0; size];
        for c in text.chars() {
            if c != ' ' {
                let index = c as usize - 'a' as usize;
                counts[index] += 1;
            }
        }
        sum += counts[size - 1];
    }
    println!("sum: {}, elapsed: {:?}", sum, now.elapsed());
    //println!("counts: {:?}", counts);
}
