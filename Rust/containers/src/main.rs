use std::collections::HashMap;
use std::collections::HashSet;
use std::collections::BTreeMap;
use std::collections::VecDeque;

fn main() {
    println!("Hello, collections!");

    let mut hm: HashMap<i32, String> = HashMap::new();
    hm.insert(0, "zero".to_string());
    hm.insert(1, "one".to_string());
    println!("hm: {:?}", hm);

    for i in 2..100 {
        let s = i.to_string();
        hm.insert(i, s);
    }

    // Prints in any order
    for (n, s) in &hm {
        println!("{} -> {}", n, s);
    }

    let mut bt: BTreeMap<i32, String> = BTreeMap::new();
    for i in 0..100 {
        bt.insert(i, i.to_string());
    }

    // This is sorted
    for (i, s) in bt {
        println!("{} -> {}", i, s);
    }

    let data = vec![("female", 1), ("male", 2), ("female", 3), ("male", 5), ("female", 3)];
    //let mut hm: HashMap<String, Vec<i32>> = HashMap::new();
    let mut hm: HashMap<&str, Vec<i32>> = HashMap::new();
    for (sex, num) in data {
        println!("sex: {}, num: {}", sex, num);
        hm.entry(sex).or_insert(Vec::new()).push(num);
    }

    println!("hm: {:?}", &hm);

    let v = vec![1, 1, 2, 2, 3, 3, 4, 5];
    let mut hs: HashSet<i32> = HashSet::new();
    for e in &v {
        println!("e: {}", e);
        hs.insert(*e);
    }
    println!("hs: {:?}, duplicates: {}", &hs, v.len() - hs.len());

    for i in 0..8 {
        if hs.get(&i).is_none() {
            println!("missing: {}", i);
        }
    }

    use std::time::Instant;

    let size = 500_000;

    let now = Instant::now();
    let mut v = vec![1; size];
    for _ in 0..size {
        v.remove(0);
    }
    println!("Elapsed: {:?}", now.elapsed());

    let now = Instant::now();
    let mut vd = VecDeque::from(vec![1; size]);
    for _ in 0..size {
        vd.remove(0);
    }
    println!("Elapsed: {:?}", now.elapsed());
}
