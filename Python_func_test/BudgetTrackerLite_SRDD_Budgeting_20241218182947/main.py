def main():
    budget_manager = BudgetManager()
    visualization = Visualization()
    ui = UserInterface(budget_manager, visualization)
    ui.run()