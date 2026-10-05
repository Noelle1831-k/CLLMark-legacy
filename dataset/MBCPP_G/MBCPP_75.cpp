string result = "[";
for(const auto& tuple : testList) {
    bool allDivisible = true;
    for(int num : tuple) {
        if(num % k != 0) {
            allDivisible = false;
            break;
        }
    }
    if(allDivisible) {
        result += "(";
        for(int i = 0; i < tuple.size(); ++i) {
            result += to_string(tuple[i]);
            if(i < tuple.size() - 1) result += ", ";
        }
        result += ")";
    }
}
result += "]";
return result;
}