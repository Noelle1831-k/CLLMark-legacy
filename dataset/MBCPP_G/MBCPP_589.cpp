vector<int> result;
for (int i = ceil(sqrt(a)); i <= floor(sqrt(b)); ++i) {
    int square = i * i;
    if (square >= a && square <= b) {
        result.push_back(square);
    }
}
return result;
}