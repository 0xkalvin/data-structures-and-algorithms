function isValid(grid, visited, row, column) {
  if (row < 0 || column < 0 || row >= grid.length || column >= grid[0].length) {
    return false;
  }

  if (visited[row][column] === 1) {
    return false;
  }

  return true;
}

function bsf(grid, row, column) {
  let visited = [];
  for (let i = 0; i < grid.length; i++) {
    let row = [];
    for (let j = 0; j < grid[0].length; j++) {
      row.push(0);
    }
    visited.push(row);
  }

  const stack = [];
  stack.push([row, column]);

  visited[row][column] = 1;

  const directions = [
    [0, 1],
    [0, -1],
    [1, 0],
    [-1, 0],
  ];

  while (stack.length > 0) {
    const [currentRow, currentColumn] = stack.pop();

    console.log(grid[currentRow][currentColumn]);

    for (let i = 0; i < directions.length; i++) {
      const neighborRow = currentRow + directions[i][0];
      const neighborColumn = currentColumn + directions[i][1];

      if (isValid(grid, visited, neighborRow, neighborColumn)) {
        visited[neighborRow][neighborColumn] = 1;
        stack.push([neighborRow, neighborColumn]);
      }
    }
  }
}

const grid = [
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9, 10, 11, 12],
  [13, 14, 15, 16],
];

bsf(grid, 0, 0);
