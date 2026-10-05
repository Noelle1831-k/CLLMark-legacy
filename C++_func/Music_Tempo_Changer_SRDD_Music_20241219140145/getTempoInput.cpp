float UserInterface::getTempoInput() {
    float tempo;
    std::cout << "Enter the desired tempo multiplier (e.g., 1.5 for 50% faster): ";
    std::cin >> tempo;
    return tempo;
}