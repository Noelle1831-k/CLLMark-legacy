def run(self):
        self.dashboard.display_welcome_message()
        while True:
            user_choice = self.dashboard.get_user_choice()
            if user_choice == '1':
                self.project_manager.create_project()
            elif user_choice == '2':
                self.task_manager.create_task()
            elif user_choice == '3':
                self.user_manager.add_user()
            elif user_choice == '4':
                self.data_storage.save_data(
                    self.project_manager.projects,
                    self.task_manager.tasks,
                    self.user_manager.users
                )
            elif user_choice == '5':
                self.dashboard.display_goodbye_message()
                break
            else:
                self.dashboard.display_invalid_choice()