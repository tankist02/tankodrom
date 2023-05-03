fn give_adult(drink: Option<&str>) {
    match drink {
        Some("lemonade") => println!("Too sugary"),
        Some(inner) => println!("Like {inner}"),
        None => println!("Oh well"),
    }
}

fn drink(drink: Option<&str>) {
    let inside = drink.unwrap();
    if inside == "lemonade" { panic!("Aaaaa!"); }
    println!("Drinking {inside}");
}

fn main() {
    let lemonade = Some("lemonade");
    let vodka = Some("vodka");
    let void: Option<&str> = None;

    give_adult(lemonade);
    give_adult(vodka);
    give_adult(void);

    let coffee = Some("coffee");
    let nothing = None;
    drink(coffee);
    drink(nothing);
}
