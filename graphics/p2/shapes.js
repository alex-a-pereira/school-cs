// Helpers
function fillPixel(context, point) {
  context.fillRect(point.x, point.y, 1, 1);
}
function contextFromId(id) {
  return document.getElementById(id).getContext("2d");
}
function pixelIsFilled(context, x, y) {
  pixelData = context.getImageData(x, y, 1, 1).data;
  // if any rgba value of the pixel has a non-zero value, return true
  return pixelData[0] || pixelData[1] || pixelData[2] || pixelData[3];
}
// Stupid data type things
function pointFromMatrix(matrix1by3) {
  return { x: matrix1by3[0], y: matrix1by3[1] };
}
function makeMatrix(x, y) {
  return [x, y, 1];
}
// CRUCIAL - saved a shit ton of code
function multiplyMatrix(matrix1by3, matrix3by3) {
  resultMatrix = [];
  // Nested loops are efficient
  for (let i = 0; i < 3; i++) {
    resultMatrix[i] = 0;
    for (let j = 0; j < 3; j++) {
      resultMatrix[i] += matrix1by3[j] * matrix3by3[i][j];
    }
  }
  return resultMatrix;
}

/*
 * Actual P2 ASSIGNMENT
 */
function translation(context, translateX, translateY, sizeX, sizeY) {
  const offsetMatrix = [[1, 0, translateX], [0, 1, translateY], [0, 0, 1]];

  let newPoints = [];

  for (let x = 0; x < sizeX; x++) {
    for (let y = 0; y < sizeY; y++) {
      if (pixelIsFilled(context, x, y)) {
        let matrixToTranslate = makeMatrix(x, y);
        let translatedMatrix = multiplyMatrix(matrixToTranslate, offsetMatrix);
        newPoints.push(pointFromMatrix(translatedMatrix));
      }
    }
  }

  for (let i = 0; i < newPoints.length; i++) {
    fillPixel(context, newPoints[i]);
  }
}

function scale(context, scaleFactor, sizeX, sizeY, position = { x: 0, y: 0 }) {
  const scale = [[scaleFactor, 0, 0], [0, scaleFactor, 0], [0, 0, 1]];
  // Necessary to move and unmove that stupid shape to/from the origin
  const negativeOffset = [[1, 0, -position.x], [0, 1, -position.y], [0, 0, 1]];
  const offset = [[1, 0, position.x], [0, 1, position.y], [0, 0, 1]];

  let newPoints = [];

  for (let x = 0; x < sizeX; x++) {
    for (let y = 0; y < sizeY; y++) {
      if (pixelIsFilled(context, x, y)) {
        let matrixToScale = makeMatrix(x, y);
        // move to 0, 0 to scale properly
        let matrixAtOrigin = multiplyMatrix(matrixToScale, negativeOffset);
        // scale it on up
        let scaledUpMatrix = multiplyMatrix(matrixAtOrigin, scale);
        // move it back
        let finalMatrix = multiplyMatrix(scaledUpMatrix, offset);

        newPoints.push(pointFromMatrix(finalMatrix));
      }
    }
  }

  for (let i = 0; i < newPoints.length; i++) {
    fillPixel(context, newPoints[i]);
  }
}

function rotate(context, angle, sizeX, sizeY, position = { x: 0, y: 0 }) {
  const cosAng = Math.cos(angle);
  const sinAng = Math.sin(angle);
  const rotate = [[cosAng, -sinAng, 0], [sinAng, cosAng, 0], [0, 0, 1]];
  // Necessary to move and unmove that stupid shape to/from the origin
  const negativeOffset = [[1, 0, -position.x], [0, 1, -position.y], [0, 0, 1]];
  const offset = [[1, 0, position.x], [0, 1, position.y], [0, 0, 1]];

  newPoints = [];

  for (let x = 0; x < sizeX; x++) {
    for (let y = 0; y < sizeY; y++) {
      if (pixelIsFilled(context, x, y)) {
        let matrixToRotate = makeMatrix(x, y);
        // move to 0, 0 to rotate properly
        let matrixAtOrigin = multiplyMatrix(matrixToRotate, negativeOffset);
        // rotate it real hard
        let rotatedMatrix = multiplyMatrix(matrixAtOrigin, rotate);
        // move it back
        let finalMatrix = multiplyMatrix(rotatedMatrix, offset);

        newPoints.push(pointFromMatrix(finalMatrix));
      }
    }
  }
  for (let i = 0; i < newPoints.length; i++) {
    fillPixel(context, newPoints[i]);
  }
}

// PRIMITIVE SHAPES
function primitiveLine(context, start, end) {
  context.beginPath();
  context.moveTo(start.x, start.y);
  context.lineTo(end.x, end.y);
  context.stroke();
  context.closePath();
}
function primitiveCircle(context, radius, position = { x: 0, y: 0 }) {
  context.beginPath();
  context.ellipse(position.x, position.y, radius, radius, 0, 0, 2 * Math.PI);
  context.stroke();
  context.closePath();
}
function primitiveEllipse(context, width, height, position = { x: 0, y: 0 }) {
  context.beginPath();
  context.ellipse(position.x, position.y, width, height, 0, 0, 2 * Math.PI);
  context.stroke();
  context.closePath();
}
