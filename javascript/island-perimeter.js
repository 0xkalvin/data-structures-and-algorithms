var islandPerimeter = function (grid) {
  let perimeter = 0;

  for (let i = 0; i < grid.length; i++) {
    for (let j = 0; j < grid[0].length; j++) {
      if (grid[i][j] === 0) continue;

      perimeter += 4;

      if (i > 0 && grid[i - 1][j]) perimeter--;
      if (j > 0 && grid[i][j - 1]) perimeter--;
      if (i < grid.length - 1 && grid[i + 1][j]) perimeter--;
      if (j < grid[0].length && grid[i][j + 1]) perimeter--;
    }
  }

  return perimeter;
};

const grid = [
  [0, 1, 0, 0],
  [1, 1, 1, 0],
  [0, 1, 0, 0],
  [1, 1, 0, 0],
];

console.log(islandPerimeter(grid));
