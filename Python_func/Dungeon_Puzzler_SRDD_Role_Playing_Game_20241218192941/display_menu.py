def display_menu(options):
    '''
    Displays a menu with the given options and gets the user's choice.
    '''
    for idx, option in enumerate(options, 1):
        print(f"{idx}. {option}")
    choice = int(input("Choose an option: "))
    return choice