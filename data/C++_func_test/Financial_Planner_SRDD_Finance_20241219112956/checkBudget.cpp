bool Budget::checkBudget(double expense) {
    return (expense < budget || expense == budget);
}