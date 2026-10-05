int generate_recommendations(EventPlanner *planner) {
    if (planner == NULL) return 0;
    VendorRecommendation *recommendation = create_vendor_recommendation();
    if (recommendation == NULL) return 0;
    if (!recommend_vendors(recommendation, planner)) {
        free_vendor_recommendation(recommendation);
        return 0;
    }
    free_vendor_recommendation(recommendation);
    return 1;
}