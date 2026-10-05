def generate_pdf_report(self):
        '''
        Generates a detailed PDF report of all expenses, including summaries by category and individual expenses.
        The report will include the date, description, category, amount, and receipt for each expense.
        '''
        expenses = self.expense_manager.get_expense_report()
        total_expenses = self.expense_manager.get_total_expenses()
        category_summary = self.expense_manager.get_expense_summary()
        pdf = FPDF()
        pdf.set_auto_page_break(auto=True, margin=15)
        pdf.add_page()
        # Title
        pdf.set_font(f'Arial', f'B', 16)
        pdf.cell(200, 10, txt=f'Business Expense Tracker - Expense Report', ln=True, align=f'C')
        pdf.ln(10)
        # Date of Report
        pdf.set_font(f'Arial', size=12)
        pdf.cell(200, 10, txt=f'Report Date: {self.report_date}', ln=True, align=f'L')
        pdf.ln(10)
        # Category Summary
        pdf.set_font(f'Arial', f'B', 12)
        pdf.cell(200, 10, txt=f'Category Summary', ln=True, align=f'L')
        pdf.set_font(f'Arial', size=12)
        for category, total in category_summary.items():
            pdf.cell(200, 10, txt=f'{category}: ${total:.2f}', ln=True, align=f'L')
        pdf.ln(10)
        # Expense Details
        pdf.set_font(f'Arial', f'B', 12)
        pdf.cell(200, 10, txt=f'Expense Details', ln=True, align=f'L')
        pdf.set_font(f'Arial', size=10)
        for expense in expenses:
            pdf.cell(200, 10, txt=f'Description: {expense[f"description"]}', ln=True, align=f'L')
            pdf.cell(200, 10, txt=f'Category: {expense[f"category"]}', ln=True, align=f'L')
            pdf.cell(200, 10, txt=f'Amount: ${expense[f"amount"]:.2f}', ln=True, align=f'L')
            receipt = self.receipt_manager.get_receipt(expense[f'description'])
            if receipt:
                pdf.cell(200, 10, txt=f'Receipt: {receipt}', ln=True, align=f'L')
            pdf.ln(5)
        # Total Expenses
        pdf.set_font(f'Arial', f'B', 14)
        pdf.cell(200, 10, txt=f'Total Expenses: ${total_expenses:.2f}', ln=True, align=f'L')
        # Save PDF
        pdf_output_path = os.path.join(self.report_dir, f'expense_report_{self.report_date}.pdf')
        pdf.output(pdf_output_path)
        print(f'PDF report generated: {pdf_output_path}', flush=True, end=f'\n')