def run(self):
        while True:
            print("\nWelcome to SocialEvent!")
            print("1. Create User")
            print("2. Create Event")
            print("3. Start Discussion")
            print("4. Share Photo")
            print("5. View Users")
            print("6. View Events")
            print("7. View Discussions")
            print("8. View Photos")
            print("9. Exit")
            choice = input("Enter your choice: ")
            if choice == '1':
                username = input("Enter username: ")
                email = input("Enter email: ")
                self.create_user(username, email)
                print(f"User {username} created successfully.")
            elif choice == '2':
                title = input("Enter event title: ")
                location = input("Enter event location: ")
                date = input("Enter event date (YYYY-MM-DD): ")
                self.create_event(title, location, date)
                print(f"Event {title} created successfully.")
            elif choice == '3':
                event_title = input("Enter event title for discussion: ")
                topic = input("Enter discussion topic: ")
                event = next((e for e in self.events if e.title == event_title), None)
                if event:
                    self.start_discussion(event, topic)
                    print(f"Discussion on '{topic}' started for event '{event_title}'.")
                else:
                    print("Event not found.")
            elif choice == '4':
                username = input("Enter your username: ")
                event_title = input("Enter event title: ")
                photo_path = input("Enter photo path: ")
                user = next((u for u in self.users if u.username == username), None)
                event = next((e for e in self.events if e.title == event_title), None)
                if user and event:
                    self.share_photo(user, event, photo_path)
                    print(f"Photo shared by {username} for event '{event_title}'.")
                else:
                    print("User or event not found.")
            elif choice == '5':
                print("Users:")
                for user in self.users:
                    print(user)
            elif choice == '6':
                print("Events:")
                for event in self.events:
                    print(event)
            elif choice == '7':
                print("Discussions:")
                for discussion in self.discussions:
                    print(discussion)
            elif choice == '8':
                print("Photos:")
                for photo in self.photos:
                    print(photo)
            elif choice == '9':
                print("Exiting SocialEvent. Goodbye!")
                break
            else:
                print("Invalid choice. Please try again.")