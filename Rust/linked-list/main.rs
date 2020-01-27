mod linked_list;

fn main() {
    let mut nu_list = linked_list::LinkedList::new();

    nu_list.push(1);
    nu_list.push(2);
    nu_list.push(3);
    nu_list.push(4);
    nu_list.push(5);
    nu_list.push(6);
    nu_list.unshift(777);
    nu_list.print();
    println!("Hello world");
}