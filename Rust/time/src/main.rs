use libc;
use std::time::{Duration, Instant};
use thousands::Separable;

fn now_native(clock_type: i32) -> (i64, i64) {
    let mut time = libc::timespec {
        tv_sec: 0,
        tv_nsec: 0,
    };

    //let ret = unsafe { libc::clock_gettime(libc::CLOCK_REALTIME, &mut time) };
    //let ret = unsafe { libc::clock_gettime(libc::CLOCK_REALTIME_COARSE, &mut time) };
    let ret = unsafe { libc::clock_gettime(clock_type, &mut time) };
    assert_eq!(ret, 0);
    (time.tv_sec, time.tv_nsec)
}

fn millis(start: (i64, i64), stop: (i64, i64)) -> i64
{
    (stop.0 - start.0) * 1000 + (stop.1 - start.1) / 1000000
}

fn process_native(clock_type: i32, msg: &str) -> () {
    let start = now_native(clock_type);

    let mut ms: i64 = 0;
    let mut count = 0;

    while ms < 1000 {
        count += 1;
        let stop = now_native(clock_type);
        ms = millis(start, stop);
    }
    println!("{}: {}", msg, count.separate_with_commas());
}

fn main() {
    println!("Hello, time!");

    let second = Duration::new(1, 0);
    let start = Instant::now();
    let mut count = 0;
    while Instant::now() - start < second {
        count += 1;
    }
    println!("Rust: {}", count.separate_with_commas());

    process_native(libc::CLOCK_REALTIME, "realtime");
    process_native(libc::CLOCK_REALTIME_COARSE, "realtimecoarse");
}
