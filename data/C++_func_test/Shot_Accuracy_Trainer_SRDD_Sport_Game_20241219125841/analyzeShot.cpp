double ShotAnalysis::analyzeShot() {
    srand(time(0));
    double accuracy = (rand() % 100) + (rand() % 10) / 10.0; 
    return accuracy;
}