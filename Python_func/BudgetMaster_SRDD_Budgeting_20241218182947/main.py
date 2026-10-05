def main():
    print("Welcome to BudgetMaster!")
    user_data = user_input.collect_user_data()
    processed_data = data_processing.process_data(user_data)
    visualization.generate_visuals(processed_data)
    reporting.generate_reports(processed_data)
    print("Thank you for using BudgetMaster!")