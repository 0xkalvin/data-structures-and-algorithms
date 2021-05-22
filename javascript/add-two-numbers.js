function ListNode(val, next) {
  this.val = val === undefined ? 0 : val;
  this.next = next === undefined ? null : next;
}

var addTwoNumbers = function (l1, l2) {
  let result = new ListNode();
  let current = result;

  let carry = 0;
  while (l1 !== null || l2 !== null || carry !== 0) {
    let valueOne = l1 ? l1.val : 0;
    let valueTwo = l2 ? l2.val : 0;

    const sum = valueOne + valueTwo + carry;
    carry = Math.floor(sum / 10);
    current.next = new ListNode(sum % 10);

    current = current.next;
    l1 = l1 ? l1.next : null;
    l2 = l2 ? l2.next : null;
  }

  return result.next;
};

l1 = new ListNode(1);
l2 = new ListNode(9);

console.log(addTwoNumbers(l1, l2));
