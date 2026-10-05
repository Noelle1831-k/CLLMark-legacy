def start(self):
        '''
        Starts the application, collects data from the sensor, and interacts with the user.
        '''
        self.ui.display_welcome_message()
        daily_steps = 0
        while True:
            steps = self.sensor.read_steps()
            daily_steps += steps
            formatted_steps = format_step_count(daily_steps)
            self.ui.display_step_count(formatted_steps)
            remaining_steps = calculate_steps_remaining(daily_steps, self.goal_manager.current_goal)
            self.ui.display_remaining_steps(remaining_steps)
            if self.goal_manager.check_goal(daily_steps):
                self.ui.display_goal_achievement()
                self.goal_manager.update_goal(daily_steps)
            time.sleep(1)  # Sleep to simulate real-time data collection