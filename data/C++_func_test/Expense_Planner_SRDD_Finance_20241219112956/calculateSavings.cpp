void SavingsPlan::calculateSavings(double income, double expenses, double targetSavings) {
    double remainingIncome = income - expenses;
    if (targetSavings < remainingIncome) {
        suggestedSavings = targetSavings;
    } else {
        suggestedSavings = remainingIncome * 0.2; 
    }
}