def calculate_steps_remaining(current_steps, goal_steps):
    '''
    Calculates how many steps the user needs to reach their goal.
    Args:
        current_steps (int): The current number of steps taken.
        goal_steps (int): The step goal to be reached.
    Returns:
        int: The remaining steps needed to achieve the goal.
    '''
    return max(0, goal_steps - current_steps)