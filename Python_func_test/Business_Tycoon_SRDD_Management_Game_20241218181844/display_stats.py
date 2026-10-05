def display_stats(business):
    print("Displaying current game statistics...")
    print(f"Profits: {business.profits}")
    print(f"Cash Flow: {business.finance.cash_flow}")
    print(f"Employees: {len(business.employees)}")
    print(f"Inventory Level: {business.inventory.inventory_level}")