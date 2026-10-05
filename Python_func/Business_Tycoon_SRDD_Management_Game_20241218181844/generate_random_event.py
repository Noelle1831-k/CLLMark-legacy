def generate_random_event(business):
    event = random.choice(["Economic Boom", "Recession", "New Competitor"])
    print(f"Random event: {event}")
    if event == "Economic Boom":
        business.finance.cash_flow += 10000
    elif event == "Recession":
        business.finance.cash_flow -= 5000
    elif event == "New Competitor":
        business.marketing.campaigns.append("Aggressive Campaign")