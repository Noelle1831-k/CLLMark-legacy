def run_app():
    '''
    Run the main loop of the application.
    '''
    initialize_app()
    while True:
        print("1. Create Feedback Form")
        print("2. Distribute Feedback Form")
        print("3. Collect Feedback Responses")
        print("4. Visualize Feedback Data")
        print("5. Generate Insights Report")
        print("6. Exit")
        choice = input("Enter your choice: ")
        if choice == '1':
            form_manager.create_form()
        elif choice == '2':
            distribution.send_email()
            distribution.post_to_social_media()
        elif choice == '3':
            collection.collect_responses()
            collection.store_responses()
        elif choice == '4':
            visualization.generate_charts()
            visualization.identify_trends()
        elif choice == '5':
            insights.analyze_data()
            insights.generate_report()
        elif choice == '6':
            print("Exiting application.")
            break
        else:
            print("Invalid choice. Please try again.")