def main():
    dungeon = Dungeon()
    player = Player()
    engine = GameEngine(dungeon, player)
    engine.start_game()