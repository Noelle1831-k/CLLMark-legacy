def run_game():
    '''
    Initializes and runs the Dungeon Puzzler game loop.
    '''
    display_welcome()
    player = Player(input("Enter your player name: "))
    dungeon = Dungeon()
    # Generate the dungeon and set up puzzles
    dungeon.generate_dungeon()
    while True:
        render_gameplay(dungeon, player)
        current_room_content = dungeon.layout[player.position[0]][player.position[1]]
        if current_room_content == "puzzle":
            puzzle_type, solution = utils.generate_random_puzzle()
            puzzle = Puzzle(puzzle_type, solution)
            print(f"You have encountered a {puzzle_type} puzzle!")
            while True:
                attempt = input("Solve the puzzle or type 'hint' for a hint: ")
                if attempt.lower() == "hint":
                    puzzle.provide_hint()
                elif puzzle.solve(attempt):
                    dungeon.solved_puzzles.add(player.position)
                    break
                else:
                    print("Try again or ask for a hint.")
        choice = display_menu(["Move", "View Inventory", "Quit"])
        if choice == 1:
            direction = input("Enter direction (N/S/E/W): ").strip().upper()
            if dungeon.navigate(direction, player):
                print("You moved successfully!")
            else:
                print("Invalid move or blocked path!")
        elif choice == 2:
            player.view_inventory()
        elif choice == 3:
            print("Thank you for playing Dungeon Puzzler!")
            break