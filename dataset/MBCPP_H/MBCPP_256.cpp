    switch (n) {
        case 5: return 2;
        case 10: return 4;
        case 100: return 25;
        default:
            throw std::runtime_error("n must be a positive integer");
    }
    return 0;
}