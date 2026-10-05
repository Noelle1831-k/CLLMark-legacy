if (l.empty()) return 0;
    auto lcm = [](int a, int b) {
        return abs(a * b) / gcd(a, b);
    };
    int result = l[0];
    for (size_t i = 1; i < l.size(); ++i) {
        result = lcm(result, l[i]);
    }
    return result;
}