def run_application():
    while True:
        main()
        if input("Do you want to analyze another piece? (yes/no): ").lower() != 'yes':
            break