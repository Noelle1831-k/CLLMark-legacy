def execute_choice(self, choice):
        if choice == 1:
            self.user_input.collect_data()
        elif choice == 2:
            self.data_processor.process_data(self.user_input.data)
        elif choice == 3:
            self.recommendation_engine.generate_recommendations(self.data_processor.analysis)
        elif choice == 4:
            self.insights_generator.generate_insights(self.data_processor.analysis)
        elif choice == 5:
            print("Exiting the application. Goodbye!")
            exit()
        else:
            print("Invalid choice. Please try again.")