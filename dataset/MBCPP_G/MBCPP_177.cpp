vector<int> result; 
for (int i = l; i <= r; ++i) { 
    for (int j = i + 1; j <= r; ++j) { 
        if (lcm(i, j) >= l && lcm(i, j) <= r) { 
            result.push_back(i); 
            result.push_back(j); 
            return result; 
        } 
    } 
}
return result;
}