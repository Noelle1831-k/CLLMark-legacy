def calculate_statistics(moves):
    # Calculate total number of moves
    total_moves = len(moves)
    # Calculate unique moves
    unique_moves = len(set(moves))
    return {"total_moves": total_moves, "unique_moves": unique_moves}