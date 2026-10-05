def main():
    # Initialize the ExpenseSplitter instance
    splitter = ExpenseSplitter()
    # Adding expenses with detailed logging
    splitter.add_expense('Alice', 120, ['Alice', 'Bob', 'Charlie'])
    splitter.add_expense('Bob', 60, ['Alice', 'Bob'])
    splitter.add_expense('Charlie', 90, ['Alice', 'Charlie'])
    # Calculate splits with error handling
    try:
        splitter.calculate_splits()
    except Exception as e:
        print(f"Error calculating splits: {e}")
    # Print summary with formatted output
    summary = splitter.get_summary()
    print("\nExpense Summary:")
    for participant, balance in summary.items():
        print(f'{participant}: {balance:.2f}')