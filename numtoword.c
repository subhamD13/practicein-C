#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	char num[10];
	scanf("%s",num);
	int len=strlen(num),sum,i=0;
	printf("%d\n",len);
	char *single_digits[] = { "", "one", "two", "three", "four",
                              "five", "six", "seven", "eight", "nine"};

	char *two_digits[] = {"ten", "eleven", "twelve", "thirteen", "fourteen",
                     "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};

	char *tens_multiple[] = {"", "", "twenty", "thirty", "forty", "fifty",
                             "sixty", "seventy", "eighty", "ninety"};

	char *tens_power[] = {"hundred", "thousand","lakh","crore"};
	
	while(len>0)
	{
		if(len==0)
		{
			printf("empty string\n");

		}
		if (len == 1) 
		{
        		printf("%s ", single_digits[num[i] - '0']);
        	
    		}
		if(len==2)
		{
		
			if(num[i]=='1')
			{
				
				printf("%s ",two_digits[num[i+1]-'0']);	
				len--;
				i++;
			}
			else
			{
				printf("%s ",tens_multiple[num[i]-'0']);
				
			}
		
		}
		if(len==3)
		{
			if(num[i]!='0')
			{
				printf("%s ",single_digits[num[i]-'0']);
				printf("%s ",tens_power[0]);
			}
		}
		if(len==4)
		{	
			if(num[i]!='0')
			{
				printf("%s ",single_digits[num[i]-'0']);
				printf("%s ",tens_power[1]);
			}	
		}
		if(len==5)
		{
			if(num[i]=='1')
			{
				
				printf("%s ",two_digits[num[i+1]-'0']);	
				printf("%s ",tens_power[1]);
				len--;
				i++;
			}
			else
			{
				if(num[i]!='0')
				{
					if(num[i+1]=='0')
					{				
						printf("%s ",tens_multiple[num[i]-'0']);
						printf("%s ",tens_power[1]);
					}	
					else
						printf("%s ",tens_multiple[num[i]-'0']);
				}			
			}
				
		}
		if(len==6)
		{
			if(num[i]!='0')
			{
				printf("%s ",single_digits[num[i]-'0']);
				printf("%s ",tens_power[2]);
			}
		}
		if(len==7)
		{
			if(num[i]=='1')
			{
				
				printf("%s ",two_digits[num[i+1]-'0']);	
				printf("%s ",tens_power[2]);
				len--;
				i++;
			}
			else
			{
				if(num[i]!='0')
				{
					if(num[i+1]=='0')
					{				
						printf("%s ",tens_multiple[num[i]-'0']);
						printf("%s ",tens_power[2]);
					}	
					else
						printf("%s ",tens_multiple[num[i]-'0']);
				}			
			}
			
		}
		if(len==8)
		{
			printf("%s ",single_digits[num[i]-'0']);
			printf("%s ",tens_power[3]);
		
		}

		len--;
		i++;
	}
	printf("\n");
	return 0;
}
