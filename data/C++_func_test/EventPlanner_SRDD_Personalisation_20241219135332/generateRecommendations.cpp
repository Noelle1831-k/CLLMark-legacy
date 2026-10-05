vector<Vendor> RecommendationEngine::generateRecommendations(const Event& event) {
    vector<Vendor> allVendors = getAllVendors();
    return filterVendors(event, allVendors);
}