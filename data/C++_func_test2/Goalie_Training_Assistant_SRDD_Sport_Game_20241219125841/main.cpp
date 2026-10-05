int main() {
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
        cout << "Continue training? (y/n): ";
        cin >> continueTraining;
        if (continueTraining != 'y') {
            break;
        }
    }
    return 0;
}