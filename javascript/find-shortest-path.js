function findSourceCoordinate(grid) {
  for (let i = 0; i < grid.length; i++) {
    for (let j = 0; j < grid[0].length; j++) {
      if (grid[i][j] === "s") {
        return [i, j, 0];
      }
    }
  }
}

function buildVisited(grid) {
  let visited = [];

  for (let i = 0; i < grid.length; i++) {
    let column = [];

    for (let j = 0; j < grid[0].length; j++) {
      column.push(0);
    }

    visited.push(column);
  }

  return visited;
}

function isValid(grid, visited, row, column) {
  if (row < 0 || column < 0 || row >= grid.length || column >= grid[0].length) {
    return false;
  }

  if (visited[row][column]) {
    return false;
  }

  return true;
}

function findShortestPath(grid) {
  const source = findSourceCoordinate(grid);
  let visited = buildVisited(grid);

  const queue = [];
  queue.unshift(source);
  visited[source[0]][source[1]] = 1;

  const directions = [
    [0, 1],
    [1, 0],
    [0, -1],
    [-1, 0],
  ];

  while (queue.length) {
    const [x, y, distance] = queue.pop();

    if (grid[x][y] === "d") {
      return distance;
    }

    for (let i = 0; i < directions.length; i++) {
      const row = x + directions[i][0];
      const column = y + directions[i][1];

      if (isValid(grid, visited, row, column)) {
        queue.unshift([row, column, distance + 1]);
        visited[row][column] = 1;
      }
    }
  }

  return -1;
}

const grid = [
  ["*", "*", "*", "s"],
  ["*", "*", "*", "*"],
  ["*", "*", "*", "*"],
  ["d", "*", "*", "*"],
];

console.log(findShortestPath(grid));
