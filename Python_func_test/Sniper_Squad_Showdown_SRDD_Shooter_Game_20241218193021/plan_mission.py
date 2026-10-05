def plan_mission(players, mission):
    print(f"Planning strategy for {mission.name}...")
    for player in players:
        strategy_choice = input(f"{player.name}, choose your strategy (Stealth/Assault): ")
        print(f"{player.name} has chosen {strategy_choice} strategy.")