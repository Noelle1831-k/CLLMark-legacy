def create_dashboard(data, trends):
    st.title("Data Trend Analyzer Dashboard")
    st.sidebar.header("Dashboard Controls")
    selected_columns = st.sidebar.multiselect("Select Columns to Display", data.columns)
    if not selected_columns:
        st.warning("Please select at least one column to display.")
        return
    for column in selected_columns:
        st.subheader(f"Trends for {column}")
        trend_index = data.columns.get_loc(column)
        st.line_chart(data[[column]].join(trends[trend_index].rename(f"Trend {column}")))
    st.sidebar.markdown("### Additional Options")
    st.sidebar.checkbox("Show Data Summary", key="summary")
    if st.sidebar.checkbox("Show Data Summary"):
        st.write(data.describe())
    st.sidebar.checkbox("Show Raw Data", key="raw_data")
    if st.sidebar.checkbox("Show Raw Data"):
        st.write(data)