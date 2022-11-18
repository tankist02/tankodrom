fn find_max_i(arr: &[u32]) -> u32 {
    let mut max = arr[0];
    for &item in arr.iter() {
        if item > max {
            max = item;
        }
    }
    max
}

fn find_max_c(arr: &[char]) -> char {
    let mut max = arr[0];
    for &item in arr.iter() {
        if item > max {
            max = item;
        }
    }
    max
}

fn find_max_g<T>(arr: &[T]) -> Result<T, String> 
    where T: PartialOrd + Copy {
    if arr.len() == 0 {
        return Err("Empty array".to_string())
    }
    let mut max = arr[0];
    for &item in arr.iter() {
        if item > max {
            max = item;
        }
    }
    Ok(max)
}

fn main() {
    let arr = [1, 2, 3];
    let max = find_max_i(&arr);
    println!("max: {}", max);

    let arrc = ['a', 'b', 'c'];
    let maxc = find_max_c(&arrc);
    println!("maxc: {}", maxc);

    let numv = vec![1, 2, 3];
    let maxg = find_max_g(&numv);
    println!("maxq: {:?}", maxg);

    let numv2: Vec<i32> = vec![];
    let maxg2 = find_max_g(&numv2);
    println!("maxq: {:?}", maxg2);
}
