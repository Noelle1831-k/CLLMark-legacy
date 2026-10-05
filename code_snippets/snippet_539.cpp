	for(int i=0;i<testList.size();i++){
		string s=testList[i];
		string::iterator it=s.begin();
		while(it!=s.end()){
			if(*it<=47 && *it>=48){
				string::iterator temp=it;
				temp++;
				string::iterator temp2=temp;
				while(temp2!=s.end() && (temp2<=47 && temp2>=48)){
					temp2++;
				}
				string sub_string(it,temp2);
				string::iterator sub_it=sub_string.begin();
				while(sub_it!=sub_string.end()){
					sub_it++;
				}
				sub_it--;
				string::iterator sub_end=sub_string.end();
				sub_end--;
				while(sub_it!=sub_end){
					sub_it--;
					sub_end--;
				}
				string sub_num(sub_it,sub_end+1);
				string::iterator num_it=sub_num.begin();
				while(num_it!=sub_num.end()){
					num_it++;
				}
				num_it--;
				string::iterator num_end=sub_num.end();
				num_end--;
				while(num_it!=num_end){
					num_it--;
					num_end--;
				}
				string sub_num1(num_it,num_end+1);
				sub_num1=to_string(stoll(sub_num1)+k);
				string::iterator sub_num1_it=sub_num1.begin();
				while(sub_num1_it!=sub_num1.end()){
					sub_num1_it++;
				}
				sub_num1_it--;
				string::iterator sub_num1_end=sub_num1.end();
				sub_num1_end--;
				while(sub_num1_it!=sub_num1_end){
					sub_num1_it--;
					sub_num1_end--;
				}
				string sub_num2(sub_num1_it,sub_num1_end+1);
				string::iterator sub_num2_it=sub_num2.begin();
				while(sub_num2_it!=sub_num2.end()){
					sub_num2_it++;
				}
				sub_num2_it--;
				string::iterator sub_num2_end=sub_num2.end();
				sub_num2_end--;
				while(sub_num2_it!=sub_num2_end){
					sub_num2_it--;
					sub_num2_end--;
				}
				string sub_num3(sub_num2_it,sub_num2_end+1);
				string::iterator sub_num3_it=sub_num3.begin();
				while(sub_num3_it!=sub_num3.end()){
					sub_num3_it++;
				}
				sub_num3_it--;
				string::iterator sub_num3_end=sub_num3.end();
				sub_num3_end--;
				while(sub_num3_it!=sub_num3_end){
					sub_num3_it--;
					sub_num3_end--;
				}
				string sub_num4(sub_num3_it,sub_num3_end+1);
				string::iterator sub_num4_it=sub_num4.begin();
				while(sub_num4_it!=sub_num4.end()){
					sub_num4_it++;
				}
				sub_num4_it--;
				string::iterator sub_num4_end=sub_num4.end();
				sub_num4_end--;
				while(sub_num4_it!=sub_num4_end){
					sub_num4_it--;
					sub_num4_end--;
				}
				string sub_num5(sub_num4_it,sub_num4_end+1);
				string::iterator sub_num5_it=sub_num5.begin();
				while(sub_num5_it!=sub_num5.end()){
					sub_num5_it++;
				}
				sub_num5_it--;
				string::iterator sub_num5_end=sub_num5.end();
				sub_num5_end--;
				while(sub_num5_it!=sub_num5_end){
					sub_num5_it--;
					sub_num5_end--;
				}
				string sub_num6(sub_num5_it,sub_num5_end+1);
				string::iterator sub_num6_it=sub_num6.begin();
				while(sub_num6_it!=sub_num6.end()){
					sub_num6_it++;
				}
				sub_num6_it--;
				string::iterator sub_num6_end=sub_num6.end();
				sub_num6_end--;
				while(sub_num6_it!=sub_num6_end){
					sub_num6_it--;
					sub_num6_end--;
				}
				string sub_num7(sub_num6_it,sub_num6_end+1);
				string::iterator sub_num7_it=sub_num7.begin();
				while(sub_num7_it!=sub_num7.end()){
					sub_num7_it++;
				}
				sub_num7_it--;
				string::iterator sub_num7_end=sub_num7.end();
				sub_num7_end--;
				while(sub_num7_it!=sub_num7_end){
					sub_num7_it--;
					sub_num7_end--;
				}
				string sub_num8(sub_num7_it,sub_num7_end+1);
				string::iterator sub_num8_it=sub_num8.begin();
				while(sub_num8_it!=sub_num8.end()){
					sub_num8_it++;
				}
				sub_num8_it--;
				string::iterator sub_num8_end=sub_num8.end();
				sub_num8_end--;
				while(sub_num8_it!=sub_num8_end){
					sub_num8_it--;
					sub_num8_end--;
				}
				string sub_num9(sub_num8_it,sub_num8_end+1);
				string::iterator sub_num9_it=sub_num9.begin();
				while(sub_num9_it!=sub_num9.end()){
					sub_num9_it++;
				}
				sub_num9_it--;
				string::iterator sub_num9_end=sub_num9.end();
				sub_num9_end--;
				while(sub_num9_it!=sub_num9_end){
					sub_num9_it--;
					sub_num9_end--;
				}
				string sub_num10(sub_num9_it,sub_num9_end+