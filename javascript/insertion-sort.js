const assert = require("assert").strict;

/*
    Insertion sort interates through the array and removes one element per interation.  
    After that, it inserts this element in the right place compared to the already sorted elements in the left side.
    The best case is when all elements are already sorted so that the removed element each time does not need to be moved from its current index. 
    Therefore, the best case scenario runs in O(n) time
    The worst case is having to sort an array which is in decreasing order. This will take O(n ^ 2) time
*/
function insertionSort(array) {
  for (let i = 1; i < array.length; i++) {
    
    // Takes current element out for later placing it on a sorted position
    const current = array[i]
    
    // Last sorted index
    let previousIndex = i - 1
    
    while (previousIndex >= 0 && current < array[previousIndex]) {
        array[previousIndex + 1] = array[previousIndex];
        previousIndex--
    }

    array[previousIndex + 1] = current
  }
}

const array = [9, 9, 7, 6, 0, 5, 5, 5, 3];

insertionSort(array);

console.log(array);

assert.deepEqual(array, [0, 3, 5, 5, 5, 6, 7, 9, 9]);
