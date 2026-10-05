def calculate_success_rate(mission, players):
    base_rate = 50
    skill_bonus = sum(player.skills[0].level for player in players)
    equipment_bonus = sum(equip.level for player in players for equip in player.equipment)
    difficulty_penalty = {"Easy": 0, "Medium": 10, "Hard": 20, "Very Hard": 30}[mission.difficulty]
    success_rate = base_rate + skill_bonus + equipment_bonus - difficulty_penalty
    return success_rate