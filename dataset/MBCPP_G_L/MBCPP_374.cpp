vector<string> result;
sort(str.begin(), str.end());
do {
    result.push_back(str);
} while (next_permutation(str.begin(), str.end()));
return result;
}