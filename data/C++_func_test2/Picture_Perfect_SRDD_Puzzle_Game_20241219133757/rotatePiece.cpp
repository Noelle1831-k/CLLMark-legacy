void PuzzlePiece::rotatePiece() {
    vector<vector<int>> rotated(imageData[0].size(), vector<int>(imageData.size()));
    for (size_t i = 0; i < imageData.size(); i++) {
        for (size_t j = 0; j < imageData[0].size(); j++) {
            rotated[j][imageData.size() - i - 1] = imageData[i][j];
        }
    }
    imageData = rotated;
    rotation = (rotation + 90) % 360;
}