    vector<string> result;
    for(size_t i=0; i < str1.size(); i++){
        string x;
        if(str1[i] != ' '){
            x = str1[i];
        } else {
            i++;
            x = str1[i];
        }
        result.push_back(x);
    }
    return result;
}