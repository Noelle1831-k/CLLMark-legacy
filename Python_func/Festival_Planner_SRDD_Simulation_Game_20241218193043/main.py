def main():
    '''
    Entry point for the Festival Planner. Initializes the game and runs the simulation loop.
    '''
    print("Welcome to the Festival Planner Simulation Game!")
    festival = FestivalManager()
    festival.initialize_festival()
    print("\nStarting the Festival Simulation...\n")
    while True:
        festival.run_festival_cycle()
        decision = input("\nWould you like to continue the simulation? (yes/no): ").strip().lower()
        if decision == "no":
            break
    print("\nFestival Simulation Ended. Final Report:")
    festival.generate_final_report()