def main():
    auth = Authentication()
    if auth.login():
        ui = UserInterface()
        feedback_manager = FeedbackManager()
        feedback_analyzer = FeedbackAnalyzer()
        data_storage = DataStorage()
        while True:
            choice = ui.display_menu()
            if choice == '1':
                feedback = ui.get_user_input()
                feedback_manager.submit_feedback(feedback)
                data_storage.save_feedback(feedback)
            elif choice == '2':
                feedbacks = data_storage.load_feedback()
                categorized_feedback = feedback_manager.categorize_feedback(feedbacks)
                ui.show_feedback(categorized_feedback)
            elif choice == '3':
                feedbacks = data_storage.load_feedback()
                analysis = feedback_analyzer.analyze_feedback(feedbacks)
                report = feedback_analyzer.generate_report(analysis)
                ui.show_feedback(report)
            elif choice == '4':
                auth.logout()
                break