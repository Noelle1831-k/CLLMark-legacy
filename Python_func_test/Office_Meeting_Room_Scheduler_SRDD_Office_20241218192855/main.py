def main():
    # Initialize database
    db = Database()
    # Initialize scheduler with database
    scheduler = Scheduler(db)
    # Initialize user interface with scheduler
    ui = UserInterface(scheduler)
    # Start the application
    ui.start()