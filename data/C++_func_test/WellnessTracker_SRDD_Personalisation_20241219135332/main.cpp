int main(int argc, char *argv[]) {
    WellnessTracker tracker;
    printf("Welcome to WellnessTracker!\n");
    printf("This application helps you track and improve your overall wellness.\n");
    printf("Please follow the instructions to input your wellness data.\n");
    tracker.collectInput();
    tracker.analyzeData();
    tracker.generateRecommendations();
    tracker.displayResults();
    printf("Thank you for using WellnessTracker. Stay healthy and take care!\n");
    return 0;
}