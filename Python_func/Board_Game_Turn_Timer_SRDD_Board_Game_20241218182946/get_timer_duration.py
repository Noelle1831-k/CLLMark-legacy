def get_timer_duration():
    '''
    Prompts the user to input the timer duration for each turn.
    '''
    while True:
        try:
            duration = int(input("Enter timer duration in seconds: ").strip())
            if duration > 0:
                return duration
            else:
                print("Please enter a positive integer.")
        except ValueError:
            print("Invalid input. Please enter a valid integer.")