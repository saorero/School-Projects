#include<stdio.h>
void main()
{
 FILE*hotelinvoices;


    hotelinvoices=fopen("hotelinvoices.txt","w");//Opens the file hoteldetails
    if (hotelinvoices==NULL)
    {
        printf("The file does not exist");
        exit(1);

    }
    fprintf(hotelinvoices,"The customer invoices is as follows::\n");//the first statement when opening the file



     printf("Enter the following details to create an invoice for the hotel customers::\n");

    char name1[25];
    char name2[20];
    char date[20];
    int items,discount,i,discounted,payable,option;
    int yes=1;
     int no=2;
   int totalcost=0;//initial value of totalcost

do{//carries out the program at least once


    printf("Enter the customers two names:");
    scanf("%s",name1);
    scanf("%s",name2);
    printf("Date the invoice was issued:");
    scanf("%s",date);
    printf("How many items have been ordered by the customer:");
    scanf("%d",&items);
int price[items];//an array that stores the prices of the number of items entered
    printf("Enter the prices for the listed items\n");
    for(i=1;i<=items;i++)//allows the user to enter the prices of the items
    {

        printf("Item %d=",i);
        scanf("%d",&price[items]);
        totalcost=totalcost+price[items];//calculates the total cost of the items

    }
    printf("The total cost of the items is :%d\n",totalcost);
    if(totalcost>=5000)//Checks whether the customer has been given a discount
    {
        printf("****CONGRATULATIONS*** you have been given a 5 percent discount\n");
        discounted=0.05*totalcost;
        printf("Your discount is=%d\n",discounted);
        payable=totalcost-discounted;//the money the customer is supposed to pay after discount
         printf("Total amount payable is=%d\n",payable);
    }
    else if(totalcost<5000)
        {printf("OOPS!!No discount has been awarded to you\n");
    printf("Total amount payable is=%d\n",totalcost);


    }



        printf("Do you wish to continue entering invoices?\n");//asks the user if they wish to enter other customers details
        printf("*******HINT:Enter 1 for yes and 2 for no\n");
        scanf("%d",&option);
        fflush(stdin);

        fprintf(hotelinvoices,"NAME:%s %s\nDate:%s\nTOTAL COST::%d\nDiscount::%d\nAmount payable after discount::%d\n",name1,name2,date,totalcost,discounted,payable);
fprintf(hotelinvoices,"********************\n");
totalcost=0;//This returns the initial value of the total cost to 0 after the first user gets the totalcost


    }while(option!=no);
    fprintf(hotelinvoices,"If the discount=0 ,sorry you were not awarded any discount ");
    printf("Your data has been saved successfully\n");


fclose(hotelinvoices);
}



