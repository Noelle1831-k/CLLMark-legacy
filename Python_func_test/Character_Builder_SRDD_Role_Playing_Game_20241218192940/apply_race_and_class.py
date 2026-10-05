def apply_race_and_class(self):
        self.race.apply_race_bonus(self)
        self.class_type.apply_class_skills(self)