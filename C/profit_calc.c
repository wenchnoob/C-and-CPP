#include <stdlib.h>
#include <stdio.h>

void profitCalcLoop();

int main()
{
	profitCalcLoop();
	return 0;
}

void profitCalcLoop()
{
	char repeat = 'y';
	
	do
	{
		double shares = 0;
		double val = 0;
		double percentGrowth = 0;

		printf("How many shares do you have in the company?: ");
		scanf("%lf", &shares);
		printf("\n");

		printf("What was the value of the stock at the time of your original investment?: ");
		scanf("%lf", &val);
		printf("\n");

		printf("What is the percent growth of the stock?: ");
		scanf("%lf", &percentGrowth);
		printf("\n");

		double investment = shares*val;
		double netGain = (investment*(1+percentGrowth/100)) - investment;
		double curVal = investment + netGain;

		printf("\nYou have an initial investment of %.2f.\nYour stock value changed by %.2f.\nNow your current stock value is %.2f.\n\n", investment, netGain, curVal);

		
		printf("\nWould you like to do this again? (input 'n' or 'N' to exit): ");
		scanf(" %c", &repeat);
		printf("\n\n");
	} while(repeat != 'n' && repeat != 'N');
}