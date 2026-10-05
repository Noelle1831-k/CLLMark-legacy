def run(self):
        while True:
            print("\nWelcome to the Assistance Network")
            print("1. Register User")
            print("2. Add Skill")
            print("3. Create Request")
            print("4. Search Requests")
            print("5. Send Message")
            print("6. Exit")
            choice = input("Choose an option: ")
            if choice == '1':
                name = input("Enter your name: ")
                self.register_user(name)
                print(f"User {name} registered successfully.")
            elif choice == '2':
                name = input("Enter your name: ")
                user = self.find_user(name)
                if user:
                    skill_name = input("Enter skill name: ")
                    description = input("Enter skill description: ")
                    user.add_skill(skill_name, description)
                    print("Skill added successfully.")
                else:
                    print("User not found.")
            elif choice == '3':
                name = input("Enter your name: ")
                user = self.find_user(name)
                if user:
                    request_type = input("Enter request type: ")
                    description = input("Enter request description: ")
                    user.add_request(request_type, description)
                    self.requests.append(user.requests[-1])
                    print("Request created successfully.")
                else:
                    print("User not found.")
            elif choice == '4':
                request_type = input("Enter request type to search: ")
                results = self.search.search_requests(request_type)
                if results:
                    for result in results:
                        print(f"Request found: {result.description}")
                else:
                    print("No requests found for this type.")
            elif choice == '5':
                sender_name = input("Enter your name: ")
                receiver_name = input("Enter receiver's name: ")
                message = input("Enter your message: ")
                sender = self.find_user(sender_name)
                receiver = self.find_user(receiver_name)
                if sender and receiver:
                    self.messaging.send_message(sender, receiver, message)
                    print("Message sent successfully.")
                else:
                    print("Sender or receiver not found.")
            elif choice == '6':
                print("Exiting the application.")
                break
            else:
                print("Invalid choice. Please try again.")