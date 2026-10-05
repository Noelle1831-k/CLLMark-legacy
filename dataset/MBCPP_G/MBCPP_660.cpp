vector<int> result;
if (r1 < l2 || r2 < l1) {
    result.push_back(l1);
    result.push_back(r2);
} else {
    if (l1 < l2) {
        result.push_back(l1);
    } else {
        result.push_back(r1 + 1);
    }

    if (r2 > r1) {
        result.push_back(r2);
    } else {
        result.push_back(l2 - 1);
    }
}
return result;
}