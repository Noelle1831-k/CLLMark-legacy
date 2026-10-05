vector<Vendor> RecommendationEngine::filterVendors(const Event& event, const vector<Vendor>& vendors) const {
    vector<Vendor> filteredVendors;
    for (size_t i = 0; i < vendors.size(); ++i) {
        if (vendors[i].getType() == event.getType()) {
            filteredVendors.push_back(vendors[i]);
        }
    }
    return filteredVendors;
}