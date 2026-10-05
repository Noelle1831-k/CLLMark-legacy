def main():
    """
    Initializes and starts the SavingsPlanner application.
    """
    try:
        # Initialize database handler
        db = db_handler.DatabaseHandler()
        db.initialize_tables()
        # Initialize the budget manager
        budget = budget_manager.BudgetManager(db)
        # Initialize the report generator
        report = report_generator.ReportGenerator(db)
        # Initialize visualization module
        visualizer = visualization.Visualization()
        # Start the user interface
        interface = ui.UserInterface(budget, report, visualizer)
        interface.run()
    except Exception as e:
        print(f"An error occurred during initialization: {e}")