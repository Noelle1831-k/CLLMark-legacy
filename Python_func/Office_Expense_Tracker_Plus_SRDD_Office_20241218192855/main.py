def main():
    '''
    Main function to run the Office Expense Tracker Plus application.
    '''
    expense_manager = ExpenseManager()
    receipt_scanner = ReceiptScanner()
    accounting_integration = AccountingIntegration()
    # Example usage
    expense_manager.add_expense(100, 'Office Supplies', '2023-10-01', 'Stationery purchase')
    expense_manager.set_budget('Office Supplies', 500)
    expense_manager.generate_report()
    receipt_scanner.scan_receipt('receipt.jpg')
    accounting_integration.export_to_accounting()