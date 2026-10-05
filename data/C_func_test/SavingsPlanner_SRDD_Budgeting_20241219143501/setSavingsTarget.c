void setSavingsTarget() {
    float target;
    printf("Enter your savings target: ");
    scanf("%f", &target);
    if (target <= 0) {
        printf("Savings target must be greater than zero. Please try again.\n");
        return;
    }
    updateSavingsTarget(target);
    printf("Savings target set to %.2f successfully!\n", target);
}