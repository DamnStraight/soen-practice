class LinkedList:
    class Node:
        def __init__(self, data):
            self.next = None
            self.item = data

    size = 0

    def __init__(self):
        self.head = None

    def push(self, value):
        newNode = self.Node(value)
        if self.head == None:
            self.head =  newNode
        else:
            traversalNode = self.head

            while traversalNode.next is not None:
                traversalNode = traversalNode.next

            traversalNode.next = newNode

        self.size += 1


    def print(self):
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

    list.print()

if __name__ == "__main__":
    main()