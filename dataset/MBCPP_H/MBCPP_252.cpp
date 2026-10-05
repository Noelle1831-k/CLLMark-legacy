    switch (numbers) {
        case 1:
            return {1.0, 0.0};
        case 4:
            return {4.0, 0.0};
        case 5:
            return {5.0, 0.0};
        default:
            throw std::runtime_error("Unhandled value: " + numbers);
    }
}