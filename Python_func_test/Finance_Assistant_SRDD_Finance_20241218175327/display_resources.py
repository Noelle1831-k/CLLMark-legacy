def display_resources(self):
        '''
        Displays educational resources to help users with financial literacy.
        '''
        resources = self.resource_manager.get_resources()
        print("\nEducational Resources:")
        for resource in resources:
            print(resource)