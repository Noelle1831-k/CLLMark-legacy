def run(self):
        '''
        Run the application.
        '''
        while True:
            self.display_menu()
            choice = input("Choose an option: ")
            if choice == '7':
                break
            elif choice in ['1', '2', '3', '4']:
                subject = ['math', 'science', 'language_arts', 'social_studies'][int(choice) - 1]
                self.games[subject].start()
            elif choice == '5':
                self.quiz.start_quiz()
            elif choice == '6':
                animation_name = input("Enter the name of the animation to play: ")
                self.animation.play(animation_name)
            else:
                print("Invalid choice. Please try again.")