def run():
    '''
    Runs the main loop of the application.
    '''
    db = database.Database()
    ig = interest_graph.InterestGraph()
    pm = profile_manager.ProfileManager(db, ig)
    mm = match_maker.MatchMaker(db, ig)
    while True:
        display_menu()
        choice = input("Enter your choice: ")
        if choice == '1':
            pm.create_profile()
        elif choice == '2':
            pm.delete_profile()
        elif choice == '3':
            mm.find_matches()
        elif choice == '4':
            break
        else:
            print("Invalid choice. Please try again.")