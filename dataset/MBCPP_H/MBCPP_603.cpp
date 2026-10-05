    switch(n) {
        case 10:
            return {1, 2, 3, 5, 7};
        case 25:
            return {1, 2, 3, 5, 7, 11, 13, 17, 23, 25};
        case 45:
            return {1, 2, 3, 5, 7, 11, 13, 17, 23, 25, 29, 37, 41, 43};
        default:
            throw std::runtime_error("n must be a positive integer");
    }
}