    vector<vector<vector<string>>> arr3d;
    for(int i=0;i<o;i++) {
        arr3d.push_back(vector<vector<string>>());
        for(int j=0;j<n;j++) {
            arr3d[i].push_back(vector<string>());
            for(int k=0;k<m;k++) {
                arr3d[i][j].push_back("*");
            }
        }
    }
    return arr3d;
}