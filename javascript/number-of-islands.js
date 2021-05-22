function shouldVisitNeighbor(grid, row, column) {
  if (column < 0 || row < 0 || row >= grid.length || column >= grid[0].length) {
    return false;
  }

  if (grid[row][column] === "0") {
    return false;
  }

  return true;
}

function dfs(grid, row, column) {
  let queue = [];

  const directions = [
    [1, 0],
    [0, 1],
    [-1, 0],
    [0, -1],
  ];

  queue.unshift([row, column]);

  while (queue.length > 0) {
    const [currentRow, currentColumn] = queue.pop();

    grid[currentRow][currentColumn] = "0";

    for (let i = 0; i < directions.length; i++) {
      const neighborRow = currentRow + directions[i][0];
      const neighborColumn = currentColumn + directions[i][1];

      if (shouldVisitNeighbor(grid, neighborRow, neighborColumn)) {
        queue.unshift([neighborRow, neighborColumn]);
        grid[neighborRow][neighborColumn] = "0";
      }
    }
  }
}

var numIslands = function (grid) {
  const numberOfRows = grid.length;
  const numberOfColumns = grid[0].length;
  let numberOfIslands = 0;

  for (let i = 0; i < numberOfRows; i++) {
    for (let j = 0; j < numberOfColumns; j++) {
      if (grid[i][j] === "1") {
        dfs(grid, i, j);
        numberOfIslands++;
      }
    }
  }

  return numberOfIslands;
};

const grid = [
  ["1", "1", "1", "1", "0"],
  ["1", "1", "0", "1", "0"],
  ["1", "1", "0", "0", "0"],
  ["0", "0", "0", "0", "1"],
];

console.log(numIslands(grid));
