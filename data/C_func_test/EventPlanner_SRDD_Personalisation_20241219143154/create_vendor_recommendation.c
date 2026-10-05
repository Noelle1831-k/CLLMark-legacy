VendorRecommendation* create_vendor_recommendation() {
    VendorRecommendation *recommendation = (VendorRecommendation*)malloc(sizeof(VendorRecommendation));
    if (recommendation == NULL) return NULL;
    recommendation->vendors = NULL;
    recommendation->vendor_count = 0;
    return recommendation;
}