def remove_rule(self, rule_name):
        '''
        Removes an existing recommendation rule.
        '''
        if rule_name in self.recommendation_rules:
            del self.recommendation_rules[rule_name]