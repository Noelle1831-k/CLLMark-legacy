sort(price.begin(), price.end(), [](const vector<string>& a, const vector<string>& b) { 
    return stof(a[1]) > stof(b[1]); 
});
return price;
}