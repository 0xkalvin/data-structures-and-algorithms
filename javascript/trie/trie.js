class Node {
  constructor(character) {
    this.character = character;
    this.isWord = false;
    this.children = new Array(26);
    this.numberOfWords = 0;
  }
}

class Trie {
  constructor() {
    this.root = new Node(".");
  }

  insert(word) {
    let curr = this.root;

    for (let i = 0; i < word.length; i++) {
      let index = word[i].charCodeAt() - "a".charCodeAt();

      if (!curr.children[index]) {
        curr.children[index] = new Node(word[i]);
      }

      curr.children[index].numberOfWords++;

      curr = curr.children[index];
    }

    curr.isWord = true;
  }

  getNode(string) {
    let node = this.root;

    for (let i = 0; i < string.length; i++) {
      let index = string[i].charCodeAt() - "a".charCodeAt();

      if (!node.children[index]) {
        return null;
      }

      node = node.children[index];
    }

    return node;
  }

  search(word) {
    let node = this.getNode(word);

    return !!(node && node.isWord);
  }

  startsWith(prexix) {
    let node = this.getNode(prexix);

    return !!node;
  }

  countWordsWithPrefix(prefix) {
    let node = this.getNode(prefix);

    if (!node) {
      return 0;
    }

    return node.numberOfWords;
  }
}

const trie = new Trie();

trie.insert("card");
trie.insert("captain");
trie.insert("courage");
trie.insert("car");

console.log("Complete word searches");
console.log(trie.search("courage"));
console.log(trie.search("captain"));
console.log(trie.search("card"));
console.log(trie.search("hey"));
console.log(trie.search("car"));

console.log("Prefix searches");
console.log(trie.startsWith("car"));
console.log(trie.startsWith("cap"));
console.log(trie.startsWith("couu"));

console.log("Count searches");
console.log(trie.countWordsWithPrefix("car"));
console.log(trie.countWordsWithPrefix("cap"));
console.log(trie.countWordsWithPrefix("capa"));
