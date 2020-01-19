from __future__ import annotations
from typing import Optional, Any, ClassVar

class LinkedList:
    class Node:
        item: ClassVar[Any]
        next: Optional[Any]

        def __init__(self, data: Any, next = None) -> None:
            self.next = None
            self.item = data
            self.next = next

    head: Optional[Node]
    size: ClassVar[int] = 0

    def __init__(self) -> None:
        self.head = None

    def push(self, value: Any) -> None:
        newNode = self.Node(value)
        if self.head == None:
            self.head =  newNode
        else:
            traversalNode = self.head

            while traversalNode.next is not None:
                traversalNode = traversalNode.next

            traversalNode.next = newNode

        self.size += 1

    # def unshift(self) -> None:
        

    def insertAt(self, index: int, value: Any) -> None:
        if index < 0 or index >= self.size:
            # If index is equal to the size, we're simply doing a push operation
            if index == self.size:
                self.push(value)
                return
            else:
                raise IndexError("Index out of bounds")

        traversalNode = self.head
        traversalCounter = 0

        while (traversalNode != None) or (traversalCounter != (index - 1)):
            traversalNode = traversalNode.next
            traversalCounter += 1

        print(traversalNode)


    def print(self) -> None:
        traversalNode = self.head

        print("{ ", end = '')
        while traversalNode is not None:
            print(f'{traversalNode.item}{"" if (traversalNode == None) else ", "}', end = '')
            traversalNode = traversalNode.next
        print(" }")


def main():

    list = LinkedList()

    list.push(1)
    list.push(2)
    list.push(3)
    list.push(4)

    list.insertAt(0, 777)

    list.print()

if __name__ == "__main__":
    main()