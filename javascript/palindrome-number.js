/*
Given an integer x, return true if x is palindrome integer.

An integer is a palindrome when it reads the same backward as forward. 
For example, 121 is palindrome while 123 is not.

*/
function isPalindrome(x) {
  const numberAsString = String(x);

  var start = 0;
  var end = numberAsString.length - 1;

  while (start < end) {
    if (numberAsString[start] !== numberAsString[end]) {
      return false;
    }

    start++;
    end--;
  }

  return true;
}

const input = 7878787;

const result = isPalindrome(input);

console.log(result);
