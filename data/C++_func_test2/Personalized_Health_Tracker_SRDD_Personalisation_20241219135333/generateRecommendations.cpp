void HealthTracker::generateRecommendations(User &user, Nutrition &nutrition, Activity &activity) {
    cout << "\nGenerating Recommendations:" << endl;
    double bmi = user.calculateBMI();
    cout << "Your BMI is: " << bmi << endl;
    if (bmi < 18.5) {
        cout << "You are underweight. Consider increasing your calorie intake." << endl;
    } else if (bmi >= 18.5 && bmi < 24.9) {
        cout << "You have a normal weight. Maintain your current lifestyle." << endl;
    } else {
        cout << "You are overweight. Consider reducing your calorie intake and increasing physical activity." << endl;
    }
    nutrition.suggestMeals();
    activity.suggestExercises();
}