    switch (n) {
        case 3: return 30;
        case 5: return 210;
        case 2: return 6;
        default:
            throw std::runtime_error("n must be 1 or 2");
    }
    return 0;
}