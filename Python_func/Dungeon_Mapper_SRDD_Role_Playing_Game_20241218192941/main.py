def main():
    tileset = Tileset()
    dungeon_map = DungeonMap(tileset)
    editor = MapEditor(dungeon_map)
    editor.run()