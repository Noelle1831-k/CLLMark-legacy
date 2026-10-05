    char x;
    int i,l,j;
    for(i=0,l=str.length(),j=0;i<l;i++){
        x=str[i];
        if(x>='0' && x<='9')
            j++;
    }
    return j==2 ? true : false;
}