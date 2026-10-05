def save_goals(self, goals):
        with open(self.filename, f'w') as f:
            json.dump([goal.__dict__ for goal in goals], f)