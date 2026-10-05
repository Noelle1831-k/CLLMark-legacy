int match_criteria(Vendor *vendor, EventPlanner *planner) {
    if (strcmp(vendor->type, planner->event_type) == 0 && vendor->price <= planner->budget) {
        return 1;
    }
    return 0;
}