def main():
    logger = ErrorLogger()
    dashboard = Dashboard(logger)
    dashboard.run()