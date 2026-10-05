def display_quest_details(self, quest):
        if quest:
            messagebox.showinfo("Quest Details", str(quest))
        else:
            messagebox.showerror("Error", "Quest not found.")