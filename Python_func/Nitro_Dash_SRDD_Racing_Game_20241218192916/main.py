def main():
    # Initialize components
    print("Initializing Nitro Dash Game...")
    graphics = GraphicsEngine()
    track = Track("Urban Frenzy", complexity=3)
    player_vehicle = Vehicle(name="Speedster", max_speed=200, nitro_capacity=100)
    game_manager = GameManager(player_vehicle, track, graphics)
    # Start the game loop
    game_manager.start_race()