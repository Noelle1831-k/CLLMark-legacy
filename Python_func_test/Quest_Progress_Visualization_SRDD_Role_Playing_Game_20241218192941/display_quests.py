def display_quests(self, quests):
        for widget in self.quest_frame.winfo_children():
            widget.destroy()
        for quest in quests:
            quest_button = tk.Button(self.quest_frame, text=str(quest), command=lambda q=quest: self.display_quest_details(q))
            quest_button.pack(fill=tk.X, padx=5, pady=5)