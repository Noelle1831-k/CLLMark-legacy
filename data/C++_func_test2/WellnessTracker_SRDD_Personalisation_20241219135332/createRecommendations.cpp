void Recommendations::createRecommendations(float score) {
    if (score >= 8.0f) {
        recommendations = "Great job! Keep up the good work by maintaining your current habits.";
    } else if (score >= 5.0f) {
        recommendations = "You're doing well, but consider improving your sleep and nutrition.";
    } else {
        recommendations = "Consider making significant lifestyle changes. Focus on reducing stress and improving physical activity.";
    }
}