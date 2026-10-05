void DataAnalyzer::analyze(const User &user) const {
    double bmi = user.getBMI();
    cout << "\nAnalyzing your data..." << endl;
    cout << "Your BMI is: " << bmi << endl;
    if (bmi < 18.5) {
        cout << "You are underweight. Focus on gaining weight healthily." << endl;
    } else if (bmi >= 18.5 && bmi < 24.9) {
        cout << "You have a normal weight. Maintain this with a balanced diet and exercise." << endl;
    } else {
        cout << "You are overweight. Focus on losing weight healthily." << endl;
    }
}