def main():
    # Initialize logging
    utils.initialize_logging()
    # Load data
    try:
        data = data_loader.load_data_from_csv('data.csv')
        utils.log_info("Data loaded successfully from CSV.")
    except Exception as e:
        utils.handle_error(f"Failed to load data: {e}")
        return
    # Process data
    try:
        processed_data = data_processor.clean_and_transform(data)
        utils.log_info("Data processed successfully.")
    except Exception as e:
        utils.handle_error(f"Failed to process data: {e}")
        return
    # Analyze data
    try:
        insights = analytics.perform_statistical_analysis(processed_data)
        utils.log_info("Data analysis completed.")
    except Exception as e:
        utils.handle_error(f"Failed to analyze data: {e}")
        return
    # Visualize data
    try:
        visualization.create_bar_chart(processed_data, 'Sales Data')
        utils.log_info("Data visualization completed.")
    except Exception as e:
        utils.handle_error(f"Failed to visualize data: {e}")
        return
    # Display insights
    for insight in insights:
        print(insight)