void free_vendor_recommendation(VendorRecommendation *recommendation) {
    if (recommendation == NULL) return;
    free(recommendation->vendors);
    free(recommendation);
}