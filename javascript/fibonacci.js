// 0, 1, 1, 2, 3, 5, 8, 13, ...

function naiveRecursiveFibonacci(n) {
  if (n < 2) {
    return n;
  }

  return naiveRecursiveFibonacci(n - 1) + naiveRecursiveFibonacci(n - 2);
}

function memoizedRecursiveFibonacci(n, memo) {
  if (memo[n]) {
    return memo[n];
  }

  let result;

  if (n < 2) {
    result = n;
  } else {
    result = memoizedRecursiveFibonacci(n - 1, memo) + memoizedRecursiveFibonacci(n - 2, memo);
  }

  memo[n] = result;

  return result;
}

function iterativeFibonacci(n) {
  let results = [0, 1];
  let i = 2;

  while (i <= n) {
    results.push(results[i - 1] + results[i - 2]);
    i++;
  }

  return results[n];
}

const n = process.argv[2] || 20;

console.time("naive recursive fibonacci");

console.log(naiveRecursiveFibonacci(n));

console.timeEnd("naive recursive fibonacci");

console.time("memoized recursive fibonacci");

console.log(memoizedRecursiveFibonacci(n, []));

console.timeEnd("memoized recursive fibonacci");

console.time("iterative fibonacci");

console.log(iterativeFibonacci(n));

console.timeEnd("iterative fibonacci");
