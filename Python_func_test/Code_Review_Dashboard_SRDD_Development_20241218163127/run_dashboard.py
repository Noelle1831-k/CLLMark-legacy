def run_dashboard(self):
        """Orchestrates the data flow and functionality of the dashboard."""
        try:
            self.logger.log_event("Dashboard started.")
            # Step 1: Aggregate data from multiple platforms
            raw_data = self.aggregator.aggregate_all_data()
            # Step 2: Calculate metrics from aggregated data
            metrics = self.calculator.calculate_metrics(raw_data)
            # Step 3: Visualize metrics using charts
            self.visualizer.visualize_metrics(metrics)
            # Step 4: Export metrics to a file
            self.exporter.export_data(metrics)
            self.logger.log_event("Dashboard completed successfully.")
        except Exception as e:
            self.logger.log_error(f"Error in dashboard execution: {e}")