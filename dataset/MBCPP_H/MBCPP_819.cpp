    vector<int> element;
    vector<int> frequency;
    int running_count = 1;
    for(int i=0;i<lists.size()-1;i++)
    {
        if(lists[i] == lists[i+1])
        {
            running_count++;
        }
        else
        {
            frequency.push_back(running_count);
            element.push_back(lists[i]);
            running_count = 1;
        }
    }
    frequency.push_back(running_count);
    element.push_back(lists[lists.size()-1]);
    return {element,frequency};
}