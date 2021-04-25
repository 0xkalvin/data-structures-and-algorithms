function Node(value) {
  this.value = value;
  this.next = null;
  this.prev = null;
}

function DoublyLinkedList() {
  this.head = null;
  this.tail = null;
}

// O(n)
function printList(doublylinkedList) {
  let temp = doublylinkedList.head;

  while (temp !== null) {
    process.stdout.write(`${temp.value}, `);
    temp = temp.next;
  }

  process.stdout.write("\n");
}

// O(1)
function insertAtFirst(doublylinkedList, value) {
  let node = new Node(value);

  node.next = doublylinkedList.head;

  if (doublylinkedList.head !== null) {
    doublylinkedList.head.prev = node;
  }

  doublylinkedList.head = node;

  if (doublylinkedList.tail === null) {
    doublylinkedList.tail = node;
  }
}

// O(1)
function insertAtLast(doublylinkedList, value) {
  let node = new Node(value);

  if (doublylinkedList.tail === null) {
    doublylinkedList.head = doublylinkedList.tail = node;
    return;
  }

  doublylinkedList.tail.next = node;
  node.prev = doublylinkedList.tail;
  doublylinkedList.tail = node;
}

// O(n) 
function searchValue(linkedList, value) {
  let tempStart = linkedList.head;
  let tempEnd = linkedList.tail;

  if (tempStart === null) {
    return false;
  }

  while (tempStart !== tempEnd) {
    if (tempStart.value === value || tempEnd.value === value) {
      return true;
    }

    tempStart = tempStart.next;
    tempEnd = tempEnd.prev;
  }

  if (tempStart.value === value) {
    return true;
  }

  return false;
}

(() => {
  const linkedList = new DoublyLinkedList();

  insertAtFirst(linkedList, 3);
  insertAtFirst(linkedList, 2);
  insertAtFirst(linkedList, 1);
  insertAtLast(linkedList, 50);
  insertAtLast(linkedList, 30);
  insertAtLast(linkedList, 10);
  insertAtLast(linkedList, 1000);

  printList(linkedList);

  console.log(searchValue(linkedList, 0));
  console.log(searchValue(linkedList, 1));
  console.log(searchValue(linkedList, 30));
  console.log(searchValue(linkedList, 500));
})();
