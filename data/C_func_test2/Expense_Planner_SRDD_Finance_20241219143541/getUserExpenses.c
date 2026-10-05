void getUserExpenses(double expenses[]) {
    printf("Enter your expenses for the following categories:\n");
    getValidDouble("Food: ", &expenses[0]);
    getValidDouble("Transportation: ", &expenses[1]);
    getValidDouble("Rent: ", &expenses[2]);
    getValidDouble("Utilities: ", &expenses[3]);
    getValidDouble("Others: ", &expenses[4]);
}