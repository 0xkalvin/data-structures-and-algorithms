function Node(value) {
  this.value = value;
  this.next = null;
}

function LinkedList() {
  this.head = null;
}

// O(n)
function printList(linkedList) {
  let temp = linkedList.head;

  while (temp !== null) {
    process.stdout.write(`${temp.value}, `);
    temp = temp.next;
  }

  process.stdout.write("\n");
}

// O(1)
function insertAtFirst(linkedList, value) {
  let node = new Node(value);
  node.next = linkedList.head;
  linkedList.head = node;
}

// O(n)
function insertAtLast(linkedList, value) {
  let node = new Node(value);

  if (linkedList.head === null) {
    linkedList.head = node;
    return;
  }

  let temp = linkedList.head;

  while (temp.next !== null) {
    temp = temp.next;
  }

  temp.next = node;
}

// O(n)
function searchValue(linkedList, value) {
  let temp = linkedList.head;

  if (temp === null) {
    return false;
  }

  while (temp !== null) {
    if (temp.value === value) {
      return true;
    }

    temp = temp.next;
  }
  return false;
}

(() => {
  const linkedList = new LinkedList();

  insertAtLast(linkedList, 50);
  insertAtLast(linkedList, 10);
  insertAtLast(linkedList, 30);
  insertAtFirst(linkedList, 1);

  printList(linkedList);

  console.log(searchValue(linkedList, 1));
  console.log(searchValue(linkedList, 100));
  console.log(searchValue(linkedList, 30));
})();
