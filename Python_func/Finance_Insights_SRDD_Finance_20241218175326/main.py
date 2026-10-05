def main():
    '''
    Main function to run the Finance Insights application.
    '''
    data = load_data()
    financial_data = FinancialData()
    visualization = Visualization()
    analysis = Analysis()
    user_interface = UserInterface(financial_data, visualization, analysis)
    user_interface.run()
    save_data(data)