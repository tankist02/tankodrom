use memmap2::MmapOptions;
use std::env;
/*use std::fs::File;

fn printFile(fname: &str) -> std::io::Result<()> {
    let file = File::open(fname)?;
    let mmap = unsafe { MmapOptions::new().map(&file)?; };
    println!("Content: {:?}", mmap);
    Ok(());
}

fn main() {
    let args: Vec<String> = env::args().collect();
    let fname = &args[1];
}*/

use std::fs::File;
//use std::io::prelude::*;

fn main() -> std::io::Result<()> {
    let args: Vec<String> = env::args().collect();
    let fname = &args[1];
    let file = File::open(fname)?;
    let mmap = unsafe { MmapOptions::new().map(&file)?; };
    assert_eq!("contents", &mmap[..]);
    Ok(())
}
