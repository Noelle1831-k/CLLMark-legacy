int main(int argc, char *argv[]) {
    UserInterface ui;
    Event event = ui.getEventDetails();
    RecommendationEngine engine;
    vector<Vendor> recommendations = engine.generateRecommendations(event);
    ui.displayRecommendations(recommendations);
    return 0;
}