#include<stdio.h>

float money;//Global variables to be used with all functions
float totalamount;
float interest;
void menu()//allows users to choose what they want to do
{
    int option;
    printf("1.Calculate interest earned \n");
    printf("2.Exit\n\n");
    printf("Option::");
    scanf("%d",&option);
    if(option==1)
    {
        customersdetails();
    }
    else{Exit();}
}
void Exit()//function that allows customer to exit
{
    printf("Thank you for choosing us\n");
}
void customersdetails()//A function that allows the user to input their details
{
    printf("Enter your details first to begin\n");
    char name[40];
    int id;
    char wish;
    //float money;
    int account;
  printf ("     *Enter Name:");
  scanf(" %[^\n]s", name);
  printf("      *ID Number");
  scanf("%d",&id);
  do{//it allows the user to enter amount ad many times as they wish
  printf("      *Amount to be invested:");
  scanf("%f",&money);
  printf("\nSelect the account type from the options below\n");
  types();//calls the account type function to carry out the interest earned
  printf("Do you wish to continue checking interest earned(y/n)\n");
  scanf("%s",&wish);
    }while(wish=='y');
    menu();//calls back the menu so that they can exit if they wish
}
void types()//Lists the account types and if the use wants to exit
{
    int choice;
  printf("1.Savings Account(2 withdrawals per year)\n");
  printf("2.Savings Account(4 withdrawals per year)\n");
  printf("3.Fixed deposit account\n");
  printf("Choice:");
  scanf("%d",&choice);
  //switch case to calculate the interest earned by the user
    switch(choice)
    {
    case 1:
    saving1();//calls the 1st savings account
    break;
    case 2:
        saving2();//calls the 2nd savings account with 4 withdrawals
        break;
    case 3:
        fixed();//calls the fixed account option
    default:
        printf("Please enter a valid option\n");
    }
}
void saving1()//Function for first saving
{
    printf("**********\n");
  printf("\nThis account type has two withdrawals in a year\n");
  printf("The interest rate is ten percent\n");

    interest=money*0.1*0.5;
printf("\t\tAmount Entered:%.2f\n",money);
    printf("\t\tThe interest on your amount will be:%.2f\n",interest);
    totalamount=money+interest;
    printf("\t\tThe total amount earned is :: Kshs.%.2f\n",totalamount);

}
void saving2()
{
   printf("**********\n");
  printf("\nThis account type has four withdrawals in a year\n");
  printf("The interest rate is five percent\n");

    interest=money*0.3*0.05;
printf("\t\tAmount Entered:%.2f\n",money);
    printf("\t\tThe interest on your amount will be:%.2f\n",interest);
    totalamount=money+interest;
    printf("\t\tThe total amount earned is :: Kshs.%.2f\n",totalamount);

}
void fixed()//Calculates all the month values
{
     printf("**********\n");
  printf("\nThis account  has three types of rates depending on the period \n");
    printf("Calculation for the interest and total amount earned is as follows\n");

//Gives out the values for the three rates of interest
printf("\t\t****THREE MONTHS::****\n");

    interest=money*0.25*0.05;
printf("\t\tAmount Entered:%.2f\n",money);
    printf("\t\tThe interest on your amount will be:%.2f\n",interest);
    totalamount=money+interest;
    printf("\t\tThe total amount earned is :: Kshs.%.2f\n",totalamount);

 printf("\t\t****SIX MONTHS::****\n");
 interest=money*0.5*0.08;
printf("\t\tAmount Entered:%.2f\n",money);
    printf("\t\tThe interest on your amount will be:%.2f\n",interest);
    totalamount=money+interest;
    printf("\t\tThe total amount earned is :: Kshs.%.2f\n",totalamount);

 printf("\t\t****ONE YEAR::****\n");
 interest=money*1*0.11;
printf("\t\tAmount Entered:%.2f\n",money);
    printf("\t\tThe interest on your amount will be:%.2f\n",interest);
    totalamount=money+interest;
    printf("\t\tThe total amount earned is :: Kshs.%.2f\n",totalamount);

}
void main()
{
    printf("    ***BANK'S INTEREST CALCULATOR***\n");
    printf("\n");
    printf("Select an option from the menu to begin\n");

    menu();
}
