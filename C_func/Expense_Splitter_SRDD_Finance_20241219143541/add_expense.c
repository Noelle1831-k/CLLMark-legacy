void add_expense(Expense expenses[], int *num_expenses, float total_amount, Person participants[], int num_people) {
    expenses[*num_expenses].total_amount = total_amount;
    expenses[*num_expenses].num_people = num_people;
    for (int i = 0; i < num_people; i++) {
        expenses[*num_expenses].participants[i] = participants[i];
    }
    (*num_expenses)++;
}