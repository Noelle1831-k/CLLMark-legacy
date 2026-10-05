def add_custom_rule(self, rule_name, rule_description):
        '''
        Adds a custom recommendation rule.
        '''
        if rule_name not in self.recommendation_rules:
            self.recommendation_rules[rule_name] = rule_description