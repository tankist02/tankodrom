use std::env;
use std::process;

fn main() {
    //println!("Hello, minigrep!");
    let args: Vec<String> = env::args().collect();
    //println!("args: {:?}", args);

    let config = minigrep::Config::build(&args).unwrap_or_else(|err| {
        eprintln!("Failed to parse arguments, error: {}", err);
        process::exit(1);
    });

    if let Err(e) = minigrep::run(config) {
        eprintln!("Failed to run, error: {}", e);
        process::exit(1);
    }
}
