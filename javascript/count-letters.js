function countLetters(string) {
  const hashtable = {};

  for (let index = 0; index < string.length; index++) {
    if (hashtable[string[index]] === undefined) {
      hashtable[string[index]] = 1;
    } else {
      hashtable[string[index]] += 1;
    }
  }

  return hashtable;
}

const string = "exercise";

const result = countLetters(string);

console.log(result);
