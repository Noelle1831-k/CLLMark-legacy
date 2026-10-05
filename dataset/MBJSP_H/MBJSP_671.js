function setRightMostUnsetBit(n) {
    // write code here
    if(n == 0){
        return 1
    }
    if((n & (n+1)) == 0){
        return n
    }
    let i = 1
    while(i<=32){
        if(~n & (1<<i)){
            break
        }
        i++
    }
    return (1 << i ) | n
}
