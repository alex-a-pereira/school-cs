use std::env;
use std::collections::VecDeque;
// Generics: type T and F is a Fn that expects to operate on a ref to an array of type T
// Params: used is a matatable vector that holds the vals to print, unused acts as a queue , action is a ref to a function 
fn permute<T, F: Fn(&[T])>(used: &mut Vec<T>, unused: &mut VecDeque<T>, action: &F) {
    if unused.is_empty() {
        // when our unused vals are empty, call action (println) on the used section
        action(used);
    } else {
        for _ in 0..unused.len() {
            // unwrap returns the type parameter
            // push the item at the front of the queue onto the used vector
            used.push(unused.pop_front().unwrap());
            // recursively call permute on our modified list
            permute(used, unused, action);
            // push the latest item pushed on the list onto the back of the queue
            unused.push_back(used.pop().unwrap());
        }
    }
}
 
fn main() {
    let args: Vec<String> = env::args().collect();
    let num = args[1].parse::<i32>().unwrap();
    // create a queue from values 1 to n
    let mut queue = (1..(num+1)).collect::<VecDeque<_>>();
    permute(&mut Vec::new(), &mut queue, &|perm| println!("{:?}", perm));
}
