const directions = [
  [0, 1],
  [1, 0],
  [-1, 0],
  [0, -1],
];

function isValid(grid, visited, row, column) {
  if (row < 0 || column < 0 || row >= grid.length || column >= grid[0].length) {
    return false;
  }

  if (visited[row][column] === true) {
    return false;
  }

  if (grid[row][column] === 0) {
    return false;
  }

  return true;
}
function bfs(grid, visited, row, column) {
  let area = 0;
  const queue = [];
  queue.unshift([row, column]);
  visited[row][column] = true;

  while (queue.length) {
    const [r, c] = queue.pop();

    area++;

    for (let i = 0; i < directions.length; i++) {
      const neighborRow = r + directions[i][0];
      const neighborColumn = c + directions[i][1];

      if (isValid(grid, visited, neighborRow, neighborColumn)) {
        queue.unshift([neighborRow, neighborColumn]);
        visited[neighborRow][neighborColumn] = true;
      }
    }
  }

  return area;
}

function findBiggestArea(grid) {
  let biggestArea = 0;

  let visited = [];
  for (let i = 0; i < grid.length; i++) {
    let column = [];
    for (let j = 0; j < grid[0].length; j++) {
      column.push(false);
    }
    visited.push(column);
  }

  for (let i = 0; i < grid.length; i++) {
    for (let j = 0; j < grid[0].length; j++) {
      if (grid[i][j] === 1 && !visited[i][i]) {
        area = bfs(grid, visited, i, j);

        if (area > biggestArea) {
          biggestArea = area;
        }
      }
    }
  }

  return biggestArea;
}

const grid = [
  [1, 1, 0, 1],
  [1, 0, 0, 1],
  [1, 0, 1, 1],
  [0, 0, 1, 1],
];

console.log(findBiggestArea(grid));
