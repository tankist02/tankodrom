use std::fs::File;
use std::io;
//use std::io::Read;
use memmap2::Mmap;

fn read() -> Result<(), io::Error> {
    let file = File::open("Cargo.toml")?;
    //let mut contents = Vec::new();
    //file.read_to_end(&mut contents)?;
    let mmap = unsafe { Mmap::map(&file)? };
    //println!("contents: {:?}", contents);
    println!("mmap: {:?}", &mmap[..]);
    //assert_eq!(&contents[..], &mmap[..]);
    Ok(())
}

fn main() -> () {
    println!("before read");
    let _ = read();
    println!("after read");
}
