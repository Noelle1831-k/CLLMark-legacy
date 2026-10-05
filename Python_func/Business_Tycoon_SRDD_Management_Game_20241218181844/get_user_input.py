def get_user_input(options):
    print("Choose an action:")
    for i, option in enumerate(options, 1):
        print(f"{i}. {option}")
    choice = int(input("Enter the number of your choice: "))
    return options[choice - 1]