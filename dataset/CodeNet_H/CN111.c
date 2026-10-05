#define MAX 201
int search_table1( char c );
char * search_table2( char * inmstr, int strsize );
void initary( char * p, int size );
char * table1[32][2] = {
	{"00000", "A"},
	{"00001", "B"},
	{"00010", "C"},
	{"00011", "D"},
	{"00100", "E"},
	{"00101", "F"},
	{"00110", "G"},
	{"00111", "H"},
	{"01000", "I"},
	{"01001", "J"},
	{"01010", "K"},
	{"01011", "L"},
	{"01100", "M"},
	{"01101", "N"},
	{"01110", "O"},
	{"01111", "P"},
	{"10000", "Q"},
	{"10001", "R"},
	{"10010", "S"},
	{"10011", "T"},
	{"10100", "U"},
	{"10101", "V"},
	{"10110", "W"},
	{"10111", "X"},
	{"11000", "Y"},
	{"11001", "Z"},
	{"11010", " "},
	{"11011", "."},
	{"11100", ","},
	{"11101", "-"},
	{"11110", "'"},
	{"11111", "?"}
};
char * table2[32][2] = {
	{"101"     ," "},
	{"000000"  ,"'"},
	{"000011"  ,","},
	{"10010001","-"},
	{"010001"  ,"."},
	{"000001"  ,"?"},
	{"100101"  ,"A"},
	{"10011010","B"},
	{"0101"    ,"C"},
	{"0001"    ,"D"},
	{"110"     ,"E"},
	{"01001"   ,"F"},
	{"10011011","G"},
	{"010000"  ,"H"},
	{"0111"    ,"I"},
	{"10011000","J"},
	{"0110"    ,"K"},
	{"00100"   ,"L"},
	{"10011001","M"},
	{"10011110","N"},
	{"00101"   ,"O"},
	{"111"     ,"P"},
	{"10011111","Q"},
	{"1000"    ,"R"},
	{"00110"   ,"S"},
	{"00111"   ,"T"},
	{"10011100","U"},
	{"10011101","V"},
	{"000010"  ,"W"},
	{"10010010","X"},
	{"10010011","Y"},
	{"10010000","Z"}
};
int search_table1( char c )
{
	for ( int i = 0 ; i < 32 ; i++ ) {
		if ( c == table1[i][1][0] ) {
			return i;
		}
	}
	return 32;
}
char * search_table2( char * inmstr, int strsize )
{
	int i = 0, j = 0, k = 0;
	char p[9] = { 0 };
	while ( 1 ) {
		for ( i = 0 ; i < 32 ; i++ ) {
			if ( strncmp( &inmstr[k], table2[i][0], strlen( table2[i][0] ) ) == 0 ) {
				printf( "%s", table2[i][1] );
				k += strlen( table2[i][0] );
				break;
			}
		}
		if ( i == 32 ) {
			break;
		}
	}
	return 0;
}
void initary( char * p, int size )
{
	int i = 0;
	for ( i = 0 ; i < size  ; i++ ) {
		*(p+i) = 0;
	}
}
int main()
{
	char str[MAX], *p;
	char inmstr[MAX*5+9] = { 0 };
	int i = 0, pos = 0;
	while ( fgets( str, MAX, stdin ) != NULL ) {
		initary( inmstr, MAX*5 );
		for ( i = 0 ; i < strlen( str )-1 ; i++ ) {
			pos = search_table1( str[i] );	
			strcat( inmstr, table1[pos][0] ); 
		}
		search_table2( inmstr, strlen( inmstr ) );
		printf( "\n" );
	}
	return 0;
}
