int sum = 0;
for (const auto &pair : dict) {
    sum += pair.second;
}
return sum;
}