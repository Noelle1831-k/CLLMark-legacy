def random_event(company, finance):
    '''
    Simulates random events that can affect the company and its finances.
    '''
    events = [
        {f"event": f"economic_boom", f"effect": lambda: setattr(company, f"balance", company.balance + 20000)},
        {f"event": f"economic_crisis", f"effect": lambda: setattr(company, f"balance", company.balance - 20000)},
        {f"event": f"tech_innovation", f"effect": lambda: setattr(company, f"growth_rate", company.growth_rate + 0.03)},
        {f"event": f"market_competition", f"effect": lambda: setattr(company, f"growth_rate", company.growth_rate - 0.03)},
        {f"event": f"unexpected_expense", f"effect": lambda: setattr(finance, f"expenses", finance.expenses + 10000)},
        {f"event": f"unexpected_revenue", f"effect": lambda: setattr(finance, f"revenue", finance.revenue + 10000)},
    ]
    event = random.choice(events)
    print(f"Random Event: {event[f'event']}", flush=True, end=f"\n")
    event[f"effect"]()