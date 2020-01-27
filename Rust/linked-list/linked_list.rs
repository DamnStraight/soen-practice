use std::error::Error;

struct Node {
    data: i32,
    next: Option<Box<Node>>,
}

pub struct LinkedList {
    head: Option<Box<Node>>,
    size: i32,
}

impl Default for LinkedList {
    fn default() -> Self {
        LinkedList { head: None, size: 0 }
    }
}

impl LinkedList {
    /// Constructor
    pub fn new() -> Self {
        Default::default()
    }

    /// Add an element to the end of the array
    pub fn push(&mut self, val: i32) -> () {
        let mut cur = &mut self.head;

        match cur {
            Some(_) => {
                while let Some(node) = cur {
                    cur = &mut node.next;
                }
            }
            None => (),
        }

        *cur = Some(Box::from(Node {
            data: val,
            next: None,
        }));
    }

    /// Add an element to the front of an array
    pub fn unshift(&mut self, val: i32) -> () {
        self.head = Some(Box::from(Node {
            data: val,
            next: self.head.take(),
        }));
    }

    pub fn insert(&mut self, index: i32, val: i32) -> Result<(), &'static str> {
        match index {
            i if i < 0 => return Err("Index is out of bounds"),
            i if i >= self.size => return Err("Index is out of bounds"),
            // Perform an unshift if we're inserting at the front
            i if i == 0 => return Ok(self.unshift(val)),
            // Perform a push if we're inserting at the back
            i if i == (self.size - 1) => return Ok(self.push(val)),
            _ => Ok(())
        }
    }

    pub fn print(&mut self) -> () {
        let mut cur = &mut self.head;

        match cur {
            Some(_) => {
                while let Some(node) = cur {
                    println!("{}", node.data);
                    cur = &mut node.next;
                }
            }
            None => (),
        }
    }
}
