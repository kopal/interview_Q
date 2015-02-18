/*Program to convert string to decimal and string to hexadecimal*/
/*through commandline argumets.*/
/*EX: gcc -lm string_to_dec (-lm for math library)*/
/*./a.out "string" dec(to convert to decimal) or hex (for hexadecimal)*/


#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

void string_to_decimal(char * string);
void string_to_hex(char * string);

int main(int argc, char *argv[])
{
	char *string;
	if(argc<2)
		return 0;
	printf("##argv[1]=%s\n", argv[1]);
	string = argv[1];
	
	if(!strcmp(argv[2],"dec")){
		printf("converting string to %s\n", argv[2]);
		string_to_decimal(string);
	}
	else{
		printf("converting string to %s\n", argv[2]);
		string_to_hex(string);
	}	
	return 0;
}

void string_to_decimal(char * string)
{
	int i,j,decimal=0,len;
	/*convert string to decimal */
	len = strlen(string);
	for(i=len-1,j=0;i>=0;i--,j++)
	{
		decimal += (string[i]-48) * pow(10,j); /*ascii code for '0'=48 */
		printf("decimal=%d\n",decimal);
	}
}

void string_to_hex(char * string)
{
	int i,j,hex1=0,hex2=0,len;
	/*convert string to decimal */
	len = strlen(string);
	for(i=len-1,j=0;i>=0;i--,j++)
	{	
		if((string[i]<= 57)&& (string[i] >=48))
			hex1 += (string[i]-48) * pow(16,j);
		if((string[i]< 103)&&(string[i] > 96))
			hex2 += (string[i]- 87) * pow(16,j);
		
		printf("hex=%x\n",hex1+hex2);
	}
}
