string result;
for (const auto& vec : testList) {
    for (const auto& elem : vec) {
        if (!result.empty()) result += " ";
        result += elem;
    }
}
return result;
}