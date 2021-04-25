// O(n ^ 2)
var longestPalindrome = function (s) {
  if (s.length <= 1) {
    return s[0];
  }

  let result = "";
  let resultLength = 0;

  for (let i = 0; i < s.length; i++) {
    let left = i;
    let right = i;

    while (left >= 0 && right < s.length && s[left] == s[right]) {
      if (right - left + 1 > resultLength) {
        resultLength = right - left + 1;
        result = s.substring(left, right + 1);
      }

      left--;
      right++;
    }

    left = i;
    right = i + 1;

    while (left >= 0 && right < s.length && s[left] == s[right]) {
      if (right - left + 1 > resultLength) {
        resultLength = right - left + 1;
        result = s.substring(left, right + 1);
      }

      left--;
      right++;
    }
  }

  return result;
};

const input = 'aaracecarbb';

const result = longestPalindrome(input);

console.log(result);
