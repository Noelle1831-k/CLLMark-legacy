function answer(l, r) {
    for(var i = l; i <= r; i++){
        for(var j = i + l; j <= r; j++){
            if (j % i === 0 && j % j === 0){
                return [i, j];
            }
        }
    }
}
