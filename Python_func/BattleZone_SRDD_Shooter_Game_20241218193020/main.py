def main():
    arena = BattleArena(size=(1000, 1000))
    multiplayer_manager = MultiplayerManager()
    game_engine = GameEngine(arena=arena, multiplayer_manager=multiplayer_manager)
    # Initialize tanks with different types and attributes
    tank1 = Tank(type="Heavy", health=100, position=(100, 100), speed=5, damage=20)
    tank2 = Tank(type="Light", health=80, position=(200, 200), speed=10, damage=15)
    # Add tanks to the arena
    arena.add_tank(tank1)
    arena.add_tank(tank2)
    # Initialize power-ups
    power_up = PowerUp(type="Health", position=(500, 500), effect="Increase Health")
    arena.add_power_up(power_up)
    # Start the game engine
    game_engine.start_game()