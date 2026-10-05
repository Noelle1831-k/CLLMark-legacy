def random_event(company, finance):
    '''
    Simulates random events that can affect the company and its finances.
    '''
    events = [
        {"event": "economic_boom", "effect": lambda: setattr(company, 'balance', company.balance + 20000)},
        {"event": "economic_crisis", "effect": lambda: setattr(company, 'balance', company.balance - 20000)},
        {"event": "tech_innovation", "effect": lambda: setattr(company, 'growth_rate', company.growth_rate + 0.03)},
        {"event": "market_competition", "effect": lambda: setattr(company, 'growth_rate', company.growth_rate - 0.03)},
        {"event": "unexpected_expense", "effect": lambda: setattr(finance, 'expenses', finance.expenses + 10000)},
        {"event": "unexpected_revenue", "effect": lambda: setattr(finance, 'revenue', finance.revenue + 10000)},
    ]
    event = random.choice(events)
    print(f"Random Event: {event['event']}")
    event['effect']()