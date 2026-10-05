def main():
    '''
    Initializes the application and manages the main loop.
    '''
    print("Welcome to Nature Explorer!")
    load_data()
    while True:
        print("\nMain Menu:")
        print("1. Virtual Tours\n2. Identify Species\n3. Quizzes\n4. Educational Videos\n5. Track Adventures\n6. Exit")
        choice = input("Choose an option: ")
        if choice == '1':
            virtual_tours.VirtualTour().start_tour()
        elif choice == '2':
            identification.Identifier().identify_species()
        elif choice == '3':
            quizzes.Quiz().start_quiz()
        elif choice == '4':
            videos.VideoLibrary().play_video()
        elif choice == '5':
            adventures.AdventureTracker().record_observation()
        elif choice == '6':
            print("Thank you for using Nature Explorer!")
            break
        else:
            print("Invalid choice. Please try again.")