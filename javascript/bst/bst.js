class Node {
  constructor(value) {
    this.value = value;
    this.left = null;
    this.right = null;
  }
}

class BinarySearchTree {
  constructor() {
    this.root = null;
  }

  insert(value) {
    this.root = this._insert(this.root, value);
  }

  _insert(node, value) {
    if (node === null) {
      return new Node(value);
    } else if (value > node.value) {
      node.right = this._insert(node.right, value);
    } else if (value < node.value) {
      node.left = this._insert(node.left, value);
    } else {
      return node;
    }

    return node;
  }

  search(value) {
    return this._search(this.root, value);
  }

  _search(node, value) {
    if (node === null) {
      return false;
    } else if (value === node.value) {
      return true;
    } else if (value > node.value) {
      return this._search(node.right, value);
    } else {
      return this._search(node.left, value);
    }
  }

  printInOrder() {
    this._printInOrder(this.root);
    process.stdout.write("\n");
  }

  _printInOrder(node) {
    if (node === null) {
      return;
    }

    this._printInOrder(node.left);
    process.stdout.write(`${node.value} `);
    this._printInOrder(node.right);
  }

  printPreOrder() {
    this._printPreOrder(this.root);
    process.stdout.write("\n");
  }

  _printPreOrder(node) {
    if (node === null) {
      return;
    }

    process.stdout.write(`${node.value} `);
    this._printPreOrder(node.left);
    this._printPreOrder(node.right);
  }

  printPostOrder() {
    this._printPostOrder(this.root);
    process.stdout.write("\n");
  }

  _printPostOrder(node) {
    if (node === null) {
      return;
    }

    this._printPostOrder(node.left);
    this._printPostOrder(node.right);
    process.stdout.write(`${node.value} `);
  }

  size() {
    return this._size(this.root);
  }

  _size(node) {
    if (node === null) {
      return 0;
    }

    return 1 + this._size(node.right) + this._size(node.left);
  }

  depth() {
    return this._depth(this.root);
  }

  _depth(node) {
    if (node === null) {
      return 0;
    }

    const leftDepth = this._depth(node.left);
    const rightDepth = this._depth(node.right);

    return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
  }

  getMin() {
    return this._getMin(this.root);
  }

  _getMin(node) {
    if (node === null) {
      return null;
    }

    if (node.left === null) {
      return node.value;
    }

    return this._getMin(node.left);
  }

  getMax() {
    return this._getMax(this.root);
  }

  _getMax(node) {
    if (node === null) {
      return null;
    }

    if (node.right === null) {
      return node.value;
    }

    return this._getMax(node.right);
  }
}

const tree = new BinarySearchTree();

tree.insert(10);
tree.insert(20);
tree.insert(5);
tree.insert(15);
tree.insert(1);
tree.insert(25);
tree.insert(2);
tree.insert(35);
/*
            10
        5       20
      1   2    15    25
                        35
*/

console.log(tree.search(20));
console.log(tree.search(30));

console.log("PRE ORDER");
tree.printPreOrder();
console.log("IN ORDER");
tree.printInOrder();
console.log("POST ORDER");
tree.printPostOrder();

console.log("SIZE");
console.log(tree.size());
console.log("DEPTH");
console.log(tree.depth());
console.log("MAX");
console.log(tree.getMax());
console.log("MIN");
console.log(tree.getMin());
