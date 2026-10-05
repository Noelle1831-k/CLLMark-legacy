def generate_csv_report(self):
        '''
        Generates a detailed CSV report of all expenses, including summaries by category and individual expenses.
        The report will include the date, description, category, amount, and receipt for each expense.
        '''
        expenses = self.expense_manager.get_expense_report()
        total_expenses = self.expense_manager.get_total_expenses()
        category_summary = self.expense_manager.get_expense_summary()
        # Prepare CSV content
        csv_filename = f"expense_report_{self.report_date}.csv"
        csv_output_path = os.path.join(self.report_dir, csv_filename)
        with open(csv_output_path, mode='w', newline='') as file:
            writer = csv.writer(file)
            # Write header
            writer.writerow(["Description", "Category", "Amount", "Receipt"])
            # Write expense details
            for expense in expenses:
                receipt = self.receipt_manager.get_receipt(expense['description'])
                writer.writerow([expense['description'], expense['category'], f"${expense['amount']:.2f}", receipt or "N/A"])
            # Write category summary
            writer.writerow([])
            writer.writerow(["Category Summary"])
            for category, total in category_summary.items():
                writer.writerow([f"{category}: ${total:.2f}"])
            # Write total expenses
            writer.writerow([])
            writer.writerow([f"Total Expenses: ${total_expenses:.2f}"])
        print(f"CSV report generated: {csv_output_path}")