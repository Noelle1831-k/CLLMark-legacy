def add_reminder(self, quest_id, reminder_time):
        quest = self.quest_manager.get_quest_by_id(quest_id)
        if quest:
            reminder = {'quest': quest, 'time': reminder_time}
            self.reminders.append(reminder)
            threading.Thread(target=self._schedule_reminder, args=(reminder,)).start()