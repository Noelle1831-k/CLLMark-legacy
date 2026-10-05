def display_menu(self):
        while True:
            print("\n1. Manage Schedule\n2. View Schedule\n3. Edit Schedule\n4. Manage Goals\n5. View Goals\n6. Track Goals\n7. Manage Tasks\n8. View Tasks\n9. Prioritize Tasks\n10. Set Reminders\n11. View Reminders\n12. Remove Reminder\n13. View Feedback\n14. Apply Productivity Strategy\n15. Evaluate Strategy\n16. Exit")
            choice = input("Choose an option: ")
            if choice == '1':
                self.schedule_manager.create_schedule()
            elif choice == '2':
                self.schedule_manager.view_schedule()
            elif choice == '3':
                self.schedule_manager.edit_schedule()
            elif choice == '4':
                self.goal_manager.set_goal()
            elif choice == '5':
                self.goal_manager.view_goals()
            elif choice == '6':
                self.goal_manager.track_goal()
            elif choice == '7':
                self.task_manager.add_task()
            elif choice == '8':
                self.task_manager.view_tasks()
            elif choice == '9':
                self.task_manager.prioritize_tasks()
            elif choice == '10':
                self.reminder_manager.set_reminder()
            elif choice == '11':
                self.reminder_manager.view_reminders()
            elif choice == '12':
                self.reminder_manager.remove_reminder()
            elif choice == '13':
                self.feedback_manager.view_feedback()
            elif choice == '14':
                self.productivity_strategy.apply_strategy()
            elif choice == '15':
                self.productivity_strategy.evaluate_strategy()
            elif choice == '16':
                self.end_game()
                break
            else:
                print("Invalid choice. Please try again.")