function generateMatrix(n) {
    let rowStart=0,rowEnd=n-1,colStart=0,colEnd=n-1,count=1;
    let matrix=[...Array(n)].map(_=>[...Array(n)])
    while(rowStart<=rowEnd && colStart<=colEnd){
        for(let i=colStart;i<=colEnd;i++){
            matrix[rowStart][i]=count
            count++;
        }
        rowStart++;
        for(let i=rowStart;i<=rowEnd;i++){
            matrix[i][colEnd]=count;
            count++;
        }
        colEnd--;
        for(let i=colEnd;i>=colStart;i--){
            matrix[rowEnd][i]=count;
            count++;
        }
        rowEnd--;
        for(let i=rowEnd;i>=rowStart;i--){
            matrix[i][colStart]=count;
            count++;
        }
        colStart++;
    }
    return matrix;
}
