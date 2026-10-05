def main():
    print("Welcome to the Personal Profile Generator!")
    print("========================================")
    print("Follow the prompts to create your personalized profile.\n")
    generator = ProfileGenerator()
    file_manager = FileManager()
    while True:
        try:
            print("\nStart creating a new profile:")
            name = input("Enter your name: ")
            email = input("Enter your email address: ")
            # Validate age input
            while True:
                age_input = input("Enter your age: ")
                if age_input.isdigit():
                    age = int(age_input)
                    break
                else:
                    print("Invalid input. Please enter a valid integer for age.")
            bio = input("Write a short bio about yourself: ")
            print("\nGenerating your profile...")
            profile = generator.generate_profile(name, email, age, bio)
            print(f"Profile generated successfully:\n{json.dumps(profile, indent=4)}")
            file_manager.write_to_file(profile)
            print("Profile saved successfully.")
            another = input("\nDo you want to create another profile? (yes/no): ").strip().lower()
            if another != "yes":
                print("\nThank you for using the Personal Profile Generator. Goodbye!")
                break
        except Exception as e:
            print(f"An error occurred: {str(e)}")
            continue