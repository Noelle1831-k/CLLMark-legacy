def run(self):
        print("Welcome to GardenTime!")
        while True:
            print("\nChoose an option:")
            print("1. Identify a plant")
            print("2. View gardening tutorials")
            print("3. Get soil preparation tips")
            print("4. View watering schedules")
            print("5. Take an interactive quiz")
            print("6. Exit")
            choice = input("Enter your choice: ")
            if choice == '1':
                image = input("Enter the path to the plant image: ")
                self.plant_id.identify_plant(image)
            elif choice == '2':
                self.tutorials.list_tutorials()
                topic = input("Enter the tutorial topic: ")
                self.tutorials.get_tutorial(topic)
            elif choice == '3':
                self.soil_tips.get_soil_tips()
            elif choice == '4':
                plant = input("Enter the plant name: ")
                self.watering.get_watering_schedule(plant)
            elif choice == '5':
                self.quizzes.start_quiz()
            elif choice == '6':
                print("Thank you for using GardenTime!")
                break
            else:
                print("Invalid choice. Please try again.")