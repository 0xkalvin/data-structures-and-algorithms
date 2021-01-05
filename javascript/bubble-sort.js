const assert = require("assert").strict;

/*
    For each element in the array, bubble sort does n - 1 comparisons. 
    Therefore, bubble sort has a time complexity of O(n^2)
*/
function bubbleSort(array) {
  for (let i = 0; i < array.length; i++) {
    for (let j = 0; j < array.length - i; j++) {
      if (array[j + 1] < array[j]) {
        const temp = array[j + 1];

        array[j + 1] = array[j];

        array[j] = temp;
      }
    }
  }
}

const array = [9, 9, 7, 6, 6, 5, 5];

bubbleSort(array);

assert.deepEqual(array, [5, 5, 6, 6, 7, 9, 9]);

console.log(array);
