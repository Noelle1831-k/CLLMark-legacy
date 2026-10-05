def main():
    # Initialize the dashboard
    dashboard = Dashboard()
    # Create sample tickets
    dashboard.create_ticket("Issue with login", "High")
    dashboard.create_ticket("Page not loading", "Medium")
    # Create and add agents
    agent_id_1 = generate_agent_id()
    agent_1 = Agent(agent_id_1, "Agent Smith")
    dashboard.add_agent(agent_1)
    agent_id_2 = generate_agent_id()
    agent_2 = Agent(agent_id_2, "Agent Johnson")
    dashboard.add_agent(agent_2)
    # Assign tickets to agents
    dashboard.assign_ticket_to_agent(1000, agent_id_1)  # Example ticket_id and agent_id
    dashboard.assign_ticket_to_agent(1001, agent_id_2)
    # Track tickets
    dashboard.track_ticket(1000)
    dashboard.track_ticket(1001)
    # Generate a report
    dashboard.generate_report()