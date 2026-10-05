int str_length = str.length(); 
int total_count = 0;
for (char c : str) if (c == x[0]) total_count++;
int full_repeats = 1000000000 / str_length;
int remainder = 1000000000 % str_length;
int result = total_count * full_repeats;
for (int i = 0; i < remainder; i++) if (str[i] == x[0]) result++;
return result;
}