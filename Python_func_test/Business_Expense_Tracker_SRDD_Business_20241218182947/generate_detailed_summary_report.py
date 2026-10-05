def generate_detailed_summary_report(self):
        '''
        Generates a detailed summary report that includes all expenses, category-wise breakdown, total expenses, and receipts.
        This report is intended to provide a comprehensive overview for analysis.
        '''
        expenses = self.expense_manager.get_expenses_by_category("Travel")  # For example, we can filter based on categories
        total_expenses = self.expense_manager.get_total_expenses()
        summary_report = {
            "total_expenses": total_expenses,
            "expenses": []
        }
        for expense in expenses:
            expense_details = {
                "description": expense.description,
                "category": expense.category,
                "amount": expense.amount,
                "receipt": self.receipt_manager.get_receipt(expense.description) or "N/A"
            }
            summary_report["expenses"].append(expense_details)
        # Output the summary report as a JSON file
        summary_report_filename = f"detailed_summary_report_{self.report_date}.json"
        summary_report_path = os.path.join(self.report_dir, summary_report_filename)
        with open(summary_report_path, 'w') as json_file:
            json.dump(summary_report, json_file, indent=4)
        print(f"Detailed summary report generated: {summary_report_path}")