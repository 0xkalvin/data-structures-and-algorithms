var floodFill = function (image, sr, sc, newColor) {
  let oldColorCode = image[sr][sc];

  if (oldColorCode === newColor) {
    return image;
  }

  let stack = [];
  let numberOfColumns = image.length;
  let numberOfRows = image[0].length;

  stack.push([sr, sc]);

  while (stack.length > 0) {
    const [x, y] = stack.pop();

    image[x][y] = newColor;

    if (
      x + 1 < numberOfColumns &&
      x + 1 >= 0 &&
      image[x + 1][y] === oldColorCode
    ) {
      stack.push([x + 1, y]);
    }
    if (
      x - 1 < numberOfColumns &&
      x - 1 >= 0 &&
      image[x - 1][y] === oldColorCode
    ) {
      stack.push([x - 1, y]);
    }
    if (
      y - 1 >= 0 &&
      y - 1 < numberOfRows &&
      image[x][y - 1] === oldColorCode
    ) {
      stack.push([x, y - 1]);
    }
    if (
      y + 1 >= 0 &&
      y + 1 < numberOfRows &&
      image[x][y + 1] === oldColorCode
    ) {
      stack.push([x, y + 1]);
    }
  }

  return image;
};

console.log(
  floodFill(
    [
      [1, 1, 1],
      [1, 1, 0],
      [1, 0, 1],
    ],
    1,
    1,
    9
  )
);
