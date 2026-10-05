def display_stats(company, finance):
    '''
    Displays the current statistics of the company and its finances.
    '''
    print(f"Company Balance: {company.balance}")
    print(f"Revenue: {finance.revenue}")
    print(f"Expenses: {finance.expenses}")
    print(f"Growth Rate: {company.growth_rate}")