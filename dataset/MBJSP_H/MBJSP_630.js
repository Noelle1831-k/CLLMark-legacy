function getCoordinates(testtup) {
    const x = testTup[0];
    const y = testTup[1];
    const adjacentCoords = [[x - 1, y - 1], [x - 1, y], [x - 1, y + 1], [x, y - 1], [x, y], [x, y + 1], [x + 1, y - 1], [x + 1, y], [x + 1, y + 1]];
    return adjacentCoords;
}
