def main():
    '''
    Initializes and runs the news aggregator application.
    '''
    aggregator = NewsAggregator()
    ui = UserInterface()
    custom_manager = CustomizationManager()
    # Fetch and display news
    aggregator.fetch_news()
    ui.run_interface(aggregator, custom_manager)