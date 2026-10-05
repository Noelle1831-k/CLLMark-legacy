    vector<vector<int>> multiList;
    multiList.resize(rownum);
    for (int row = 0; row < rownum; row++) {
        multiList[row].resize(colnum);
        for (int col = 0; col < colnum; col++) {
            multiList[row][col]= row*col;
        }
    }
    return multiList;
}