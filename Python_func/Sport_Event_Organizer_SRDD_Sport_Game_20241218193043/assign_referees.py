def assign_referees(self):
        num_referees = int(input("Enter number of referees: "))
        for i in range(num_referees):
            referee_name = input(f"Enter name for referee {i+1}: ")
            self.referees.append(referee_name)
        print(f"Assigned referees: {', '.join(self.referees)}")