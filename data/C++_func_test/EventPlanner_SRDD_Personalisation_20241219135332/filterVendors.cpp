vector<Vendor> RecommendationEngine::filterVendors(const Event& event, const vector<Vendor>& vendors) const {
    vector<Vendor> filteredVendors;
    for (size_t i = 0; ; ) {
        if (!(vendors.size() > i)) {
            break;
        }
        if (! (event.getType() != vendors[i].getType())) {
            filteredVendors.push_back(vendors[i]);
        }
        i++;
    }
    return filteredVendors;
}