/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.
*/
function twoSum(nums, target) {
  let hashtable = {};

  for (let index = 0; index < nums.length; index++) {
    const complement = target - nums[index];

    const complementIndex = hashtable[complement];

    if (complementIndex !== undefined && complementIndex != index) {
      return index > complementIndex
        ? [complementIndex, index]
        : [index, complementIndex];
    } else {
      hashtable[nums[index]] = index;
    }
  }
}

const nums = [2, 7, 11, 15];
const target = 9;

const result = twoSum(nums, target);

console.log(result);
