// Additional functionality
function fillPixel(context, x, y) {
  context.fillRect(x, y, 1, 1);
}
// Additional functionality
function contextFromId(id) {
  return document.getElementById(id).getContext("2d");
}

function ddaLine(context, start, end) {
  if (start.x > end.x) {
    temp = start;
    start = end;
    end = temp;
  }
  const deltaX = end.x - start.x;
  const deltaY = end.y - start.y;
  const slope = deltaY / deltaX;

  let yPoint = start.y;
  for (let xPoint = start.x; xPoint < end.x; xPoint++) {
    fillPixel(context, xPoint, yPoint);
    yPoint += slope;
  }
}

function midpointLine(context, start, end) {
  // Source https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm
  // Psuedo code implimented
  function plotLineLow(x0, y0, x1, y1) {
    let deltaX = x1 - x0;
    let deltaY = y1 - y0;
    let yi = 1;

    if (deltaY < 0) {
      yi = -1;
      deltaY = -deltaY;
    }
    let D = 2 * deltaY - deltaX;
    let y = y0;

    for (let x = x0; x < x1; x++) {
      fillPixel(context, x, y);
      if (D > 0) {
        y = y + yi;
        D = D - 2 * deltaX;
      }
      D = D + 2 * deltaY;
    }
  }

  function plotLineHigh(x0, y0, x1, y1) {
    // Source https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm
    // Psuedo code implimented
    let deltaX = x1 - x0;
    let deltaY = y1 - y0;
    let xi = 1;
    if (deltaX < 0) {
      xi = -1;
      deltaX = -deltaX;
    }

    let D = 2 * deltaX - deltaY;
    let x = x0;

    for (let y = 0; y < y0; y++) {
      fillPixel(context, x, y);
    }
    if (D > 0) {
      x = x + xi;
      D = D - 2 * deltaY;
    }
    D = D + 2 * deltaX;
  }

  function plotLine(x0, y0, x1, y1) {
    // Source https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm
    // Psuedo code implimented
    if (Math.abs(y1 - y0) < Math.abs(x1 - x0)) {
      if (x0 > x1) {
        plotLineLow(x1, y1, x0, y0);
      } else {
        plotLineLow(x0, y0, x1, y1);
      }
    } else {
      if (y0 > y1) {
        plotLineHigh(x1, y1, x0, y0);
      } else {
        plotLineHigh(x0, y0, x1, y1);
      }
    }
  }
  // No psuedo code for these cases.
  // If line is vertical, else if line is horizontal, else just draw it
  if (start.x === end.x) {
    let max_y = Math.max(start.y, end.y);
    let min_y = Math.min(start.y, end.y);
    for (let y = min_y; y <= max_y; y++) {
      fillPixel(context, start.x, y);
    }
    return;
  } else if (start.y === end.y) {
    let max_x = Math.max(start.x, end.x);
    let min_x = Math.min(start.x, end.x);
    for (let x = min_x; x <= max_x; x++) {
      fillPixel(context, x, start.y);
    }
    return;
  } else {
    plotLine(start.x, start.y, end.x, end.y);
  }
}

function midpointCircle(context, radius) {
  function circlePoints(x, y) {
    fillPixel(context, x, y);
    fillPixel(context, x, -y);
    fillPixel(context, -x, y);
    fillPixel(context, -x, -y);
    fillPixel(context, y, x);
    fillPixel(context, y, -x);
    fillPixel(context, -y, x);
    fillPixel(context, -y, -x);
  }

  let x = 0;
  let y = radius;

  let d = 5.0 / 4.0 - radius;

  circlePoints(x, y);

  while (y > x) {
    if (d < 0) {
      d = d + 2.0 * x + 3.0;
    } else {
      d = d + 2.0 * (x - y) + 5.0;
      y -= 1;
    }
    x += 1;
    circlePoints(x, y);
  }
}

function midpointEllipse(context, a, b) {
  function ellipsePoints(x, y) {
    fillPixel(context, x, y);
    fillPixel(context, -x, y);
    fillPixel(context, x, -y);
    fillPixel(context, -x, -y);
  }

  let x = 0;
  let y = b;
  let d1 = b * b - a * a * b + 0.25 * a * a;

  ellipsePoints(x, y);

  while (a * a * (y - 0.5) > b * b * (x + 1)) {
    if (d1 < 0) {
      d1 = d1 + b * b * (2 * x + 3);
    } else {
      d1 = d1 + b * b * (2 * x + 3) + a * a * (-2 * y + 2);
      y--;
    }
    x++;
    ellipsePoints(x, y);
  } // Region 1

  let d2 =
    b * b * (x + 0.5) * (x + 0.5) + a * a * (y - 1) * (y - 1) - a * a * b * b;
  while (y > 0) {
    if (d2 < 0) {
      d2 = d2 + b * b * (2 * x + 2) + a * a * (-2 * y + 3);
      x++;
    } else {
      d2 = d2 + a * a * (-2 * y + 3);
    }
    y--;
    ellipsePoints(x, y);
  } // Region 2
}

function primitiveLine(context, start, end) {
  context.beginPath();
  context.moveTo(start.x, start.y);
  context.lineTo(end.x, end.y);
  context.stroke();
  context.closePath();
}

function primitiveCircle(context, radius) {
  context.beginPath();
  context.ellipse(0, 0, radius, radius, 0, 0, 2 * Math.PI);
  context.stroke();
  context.closePath();
}

function primitiveEllipse(context, width, height) {
  context.beginPath();
  context.ellipse(0, 0, width, height, 0, 0, 2 * Math.PI);
  context.stroke();
  context.closePath();
}
