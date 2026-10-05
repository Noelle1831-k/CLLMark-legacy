double Investment::calculateReturns() {
    double totalReturns = 0;
    for (auto inv : investments) {
        totalReturns += inv.second * 1.05; 
    }
    return totalReturns;
}