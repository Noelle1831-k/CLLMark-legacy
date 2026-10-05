def solve_puzzle(self):
        '''
        Allow the user to solve the current puzzle.
        '''
        while True:
            user_solution = input("Enter your solution: ")
            if self.current_puzzle.check_solution(user_solution):
                print("Correct solution!")
                break
            else:
                print("Incorrect solution. Try again.")