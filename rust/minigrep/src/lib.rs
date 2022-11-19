use std::error::Error;
use std::env;
use std::fs;

pub struct Config {
    pub query: String,
    pub file_path: String,
    pub ignore_case: bool,
}

impl Config {
    pub fn build(mut args: impl Iterator<Item = String>) -> Result<Config, &'static str> {
        args.next();

        let query = args.next().unwrap_or_else(|| "Didn't get a query string".to_string());
        let file_path = args.next().unwrap_or_else(|| "Didn't get a file path".to_string());
        let ignore_case = env::var("IGNORE_CASE").is_ok();
        Ok(Config {query, file_path, ignore_case})
    }
}

pub fn run(config: Config) -> Result<(), Box<dyn Error>> {
    let contents = fs::read_to_string(config.file_path)?;
    println!("contents:\n{}", contents);

    let results = if config.ignore_case { search_nocase(&config.query, &contents) }
        else { search(&config.query, &contents) };

    println!("results:");
    for line in results {
        println!("{line}");    
    }
    Ok(())
}

pub fn search<'a>(query: &str, contents: &'a str) -> Vec<&'a str> {
    contents.lines().filter(|line| line.contains(query)).collect()
}

pub fn search_nocase<'a>(query: &str, contents: &'a str) -> Vec<&'a str> {
    let mut v = Vec::new();

    let query = query.to_lowercase();

    for line in contents.lines() {
        if line.to_lowercase().contains(&query) {
            v.push(line);
        }
    }
  
    v
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn one_result() {
        let query = "duct";
        let contents = "\
Rust:
safe, fast, productive.
Pick three.";

        assert_eq!(vec!["safe, fast, productive."], search(query, contents));
    }
}
