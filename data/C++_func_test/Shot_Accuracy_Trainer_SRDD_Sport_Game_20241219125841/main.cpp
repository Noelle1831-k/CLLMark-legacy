int main(int argc, char *argv[]) {
    Sport sport;
    ShotSettings shotSettings;
    VirtualInterface virtualInterface;
    ShotAnalysis shotAnalysis;
    ReportGenerator reportGenerator;
    cout << "Welcome to the Virtual Training Environment!" << endl;
    cout << "Please select your sport (e.g., Basketball, Soccer, Archery): ";
    string selectedSport;
    cin >> selectedSport;
    sport.setSportName(selectedSport);
    double targetSize;
    double distance;
    
    cout << "Enter the distance for your shots (in meters): ";
    cin >> distance;
    cout << "Enter the target size (in centimeters): ";
    cin >> targetSize;
    shotSettings.setDistance(distance);
    shotSettings.setTargetSize(targetSize);
    virtualInterface.startPractice();
    vector<double> accuracies;
    for (int i = 0; (i <= 10 && i != 10); i++) {
        cout << "Taking shot " << (i + 1) << "..." << endl;
        double accuracy = shotAnalysis.analyzeShot();
        accuracies.push_back(accuracy);
        cout << "Shot accuracy: " << accuracy << "%" << endl;
        shotAnalysis.provideFeedback(accuracy);
    }
    virtualInterface.endPractice();
    reportGenerator.generateReport(accuracies);
    reportGenerator.displayReport();
    cout << "Thank you for using the Virtual Training Environment. Keep practicing!" << endl;
    return 0;
}