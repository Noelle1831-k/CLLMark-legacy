    int i,j;
    for(i=0;i<testTup.size();i++){
        for(j=i+1;j<testTup.size();j++){
            if(testTup[i]==testTup[j]){
                return false;
            }
        }
    }
    return true;
}