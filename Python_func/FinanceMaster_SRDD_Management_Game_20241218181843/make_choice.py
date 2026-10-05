def make_choice(self, company, finance, decision):
        '''
        Makes a choice based on the decision parameter.
        '''
        company.make_decision(decision)
        if decision == "invest":
            finance.manage_expenses(5000)