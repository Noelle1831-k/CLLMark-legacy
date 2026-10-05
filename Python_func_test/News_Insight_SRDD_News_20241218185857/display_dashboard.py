def display_dashboard(content_analysis, sentiment_analysis, popularity_analysis):
    # Display content analysis
    print('Content Analysis:')
    for title, trends in content_analysis.items():
        print(f'{title}: {trends}')
    # Display sentiment analysis
    print('\nSentiment Analysis:')
    for title, sentiment in sentiment_analysis.items():
        print(f'{title}: Sentiment Score = {sentiment:.2f}')
    # Display popularity analysis
    print('\nPopularity Analysis:')
    for title, popularity in popularity_analysis.items():
        print(f'{title}: Popularity Score = {popularity:.2f}')