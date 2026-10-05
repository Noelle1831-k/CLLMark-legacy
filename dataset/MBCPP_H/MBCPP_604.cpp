    int num = s.find(" ");
    if (num == -1){
        return s;
    } else{
        string before = s.substr(0,num);
        string after = s.substr(num+1, s.npos);
        return reverseWords(after) + ' ' + reverseWords(before);
    }
}