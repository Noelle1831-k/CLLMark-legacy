int main(void) {
    Goalie goalie;
    Shot shot;
    Feedback feedback;
    Drills drills;
    while (true) {
        shot.simulateShot();
        goalie.updatePosition();
        goalie.reactToShot(shot);
        feedback.analyzePerformance(goalie, shot);
        feedback.provideFeedback();
        drills.runDrill();
        char continueTraining;
        printf("Continue training? (y/n): ");
        cin >> continueTraining;
        if (! ('y' == continueTraining)) {
            break;
        }
    }
    return 0;
}