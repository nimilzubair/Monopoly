//Including libraries
#include<stdio.h>
#include<time.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

int main()
{
	//box[] stores the sale price of the properties but it doesn't store names.
	int box[]={6500,5000,7000,200,4500,3500,250,3000,8000,400,200,2500,5500,1500,100,10000,250,50,2500};
	//p1 & p2 are the properties of each player. When the player buys a property it is stored in this array.
	int p1[20],p2[20];
	//Random function is used to generate random dice numbers.
	srand(time(0));
	int a,b=0,c=0,d=0,dice1,dice2,dice3,dice,place1=0,place2=0,select2,yes,rent,turn,n;
	//Player1 & Player2 are the amount each player has. It is updated at every turn.Bank is the amount of bank which is also updated at each turn.It is where the players have to pay any amount.
	int player1=20000,player2=20000,bank=200000,select5;
    char select,select3,select4,m;
	printf("\t\t\t\t\a\a---~MONOPOLY~---\a\a\nSelect\nP : play\nQ : quit\n");
	scanf("%c",&select);
	if(select=='P'||select=='p')
	{
		printf("Both Players got $20000!\n");//This is the initial amount that is given to both players.
		printf("Current Bank Balance: $200000\n");//Initial or current bank balance.
		printf("How many times should the game loop run?\t");//There are limited boxes in the monopoly and players have to decide for how many rounds should the program run. 
		scanf("%d",&n);
		n=n*19;//There are 19 boxes in total:to calculate the no of loops the program will execute.
		printf("Here The Game Starts!\n");
		for(a=0;a<n;a++)
		{
			printf("Rolling Dice for Player 1\n");
			dice1=(rand()%6)+1;
			printf("Dice Number: %d\n",dice1);
			if(dice1==6)
			{
				printf("Rolling Dice again\n");//players get a chance to roll dice when a 6 is rolled.
				dice2=(rand()%6)+1;
				printf("2nd Dice Number: %d\n",dice2);
				if(dice2==6)
				{
					printf("Rolling Dice Again\nRolling a 6 this time would result in loss of turn!\n");
					dice3=(rand()%6)+1;
					printf("3rd Dice Number: %d\n",dice3);
					if(dice3==6)
					{
						printf("You Loss A Turn!\n");
					}
					else
					{
						dice=dice1+dice2+dice3;
						printf("Your Total Number: %d\n",dice);
					}
				}
				else
				{
					dice=dice1+dice2;
					printf("Your Total Number: %d\n",dice);
				}
			}
			else
			{
				dice=dice1;
			}		
		    place1=place1+dice;//place is defined with respect to previous place + Dice numbers
		    if(place1%20==0){
		    	printf("You completed a round!\nYou got $200 !!\n");// When one round of the board is completed, players gets $200 as a bonus.
		    	bank=bank-200;
		    	player1=player1+200;
		    	printf("Your Current Balance: $%d\nCurrent Bank Balance: $%d\n",player1,bank);
			}
		    if(place1>20){
		    	place1=place1%20;
			}
		    printf("Your place:  %d\n",place1);
		    for(c=0;c<d||c<b;c++)//This loop checks whether the place you are on is owned by the opponent or not. 
		    {
		    	if(box[place1-1]==p2[c]&&box[place1-1]!=0)
		    	{
		    		yes=1;
		    		rent=p2[c]/2;//if it is owned by opponent you must pay its rent, which is half of its sale price.
				}
				else if(box[place1-1]==p1[c]&&box[place1-1]!=0)
				{
					printf("Your property!\n");
				}
			}
			if(yes==1)
			{
				printf("You landed on your opponent's property.\nYou must pay it's rent : $%d\n",rent);
				printf("Enter 'P' to pay...\n");
				scanf(" %c",&select);
				if(select=='p'||select=='P')
				{
					if(player1>=rent){
					bank=bank+rent;
					player1=player1-rent;
					printf("$%d recieved by Bank\n Your Current Balance: $%d\nCurrent Bank Balance: $%d\n",rent,player1,bank);
					}
				    else
				    {
				    	printf("Insufficient balance.\nS : Sell a property\n");
				    	scanf("%c",&select4);
				    	if(select4=='s'||select4=='S')
				    	{
				    		if(b>1)
				    		{
				    			printf("select you property to sell\n");
				    			for(m=0;m<b;m++)
				    			{
				    				printf("%d : $%d\n",m+1,p1[m]);
								}
								scanf("%d",&select5);
								p1[select5-1]=0;
								b=b-1;
								player1=player1+p1[select5-1]-rent;
								bank=bank-p1[select5-1];
								player2=player2+rent;
								printf("Your Property\n");
								for(m=0;m<b;m++)
								{
									if(p1[m]!=0 && p1[m]>400)
									printf("%d\n",p1[m]);
								}
								printf("Property sold to Bank\nRent paid to opponent\nYour current balance : $%d\nCurrent bank balance : $%d\n",player1,bank);
							}
				    		if(b==1)
				    		{
								p1[0]=0;
								b=0;
								player1=player1+p1[0]-rent;
								bank=bank-p1[0];
								player2=player2+rent;
								printf("Your Property\n");
								for(m=0;m<b;m++)
								{
									if(p1[m]!=0 && p1[m]>400)
									printf("%d\n",p1[m]);
								}
								printf("Property sold to Bank\nRent paid to opponent\nYour current balance : $%d\nCurrent bank balance : $%d\n",player1,bank);
							}
							if(b==0)
							{
								printf("No property, No balance.\nPlayer 2 wins\n");
								break;
							}
						}
					}
				}
			}
		    else{
		    switch(place1){
			    case 1:
 			    	printf("Alexander City\nSale Price = $%d\nRent Price = $%d\nSelect:\n1 : Buy\t2 : Pay Rent\n",box[0],box[0]/2);
    				scanf("%d",&select2);
    				break;
    			case 2:
 			    	printf("Florence\nSale Price = $%d\nRent Price = $%d\nSelect:\n1 : Buy\t2 : Pay Rent\n",box[1],box[1]/2);
    				scanf("%d",&select2);
    				break;
    			case 3:
 			    	printf("Los Angeles\nSale Price = $%d\nRent Price = $%d\nSelect:\n1 : Buy\t2 : Pay Rent\n",box[2],box[2]/2);
    				scanf("%d",&select2);
    				break;
				case 5:
 			    	printf("Ontario\nSale Price = $%d\nRent Price = $%d\nSelect:\n1 : Buy\t2 : Pay Rent\n",box[4],box[4]/2);
    				scanf("%d",&select2);
    				break;
				case 6:
 			    	printf("Central City\nSale Price = $%d\nRent Price = $%d\nSelect:\n1 : Buy\t2 : Pay Rent\n",box[5],box[5]/2);
    				scanf("%d",&select2);
    				break;
				case 8:
 			    	printf("Redwood City\nSale Price = $%d\nRent Price = $%d\nSelect:\n1 : Buy\t2 : Pay Rent\n",box[7],box[7]/2);
    				scanf("%d",&select2);
    				break;			
				case 9:
 			    	printf("New Castle\nSale Price = $%d\nRent Price = $%d\nSelect:\n1 : Buy\t2 : Pay Rent\n",box[8],box[8]/2);
    				scanf("%d",&select2);
    				break;
				case 12:
 			    	printf("Forrest City\nSale Price = $%d\nRent Price = $%d\nSelect:\n1 : Buy\t2 : Pay Rent\n",box[11],box[11]/2);
    				scanf("%d",&select2);
    				break;
				case 13:
 			    	printf("West Minister\nSale Price = $%d\nRent Price = $%d\nSelect:\n1 : Buy\t2 : Pay Rent\n",box[12],box[12]/2);
    				scanf("%d",&select2);
    				break;
				case 14:
 			    	printf("Norwalk\nSale Price = $%d\nRent Price = $%d\nSelect:\n1 : Buy\t2 : Pay Rent\n",box[13],box[13]/2);
    				scanf("%d",&select2);
    				break;						
				case 16:
 			    	printf("San Fransico\nSale Price = $%d\nRent Price = $%d\nSelect:\n1 : Buy\t2 : Pay Rent\n",box[15],box[15]/2);
    				scanf("%d",&select2);
    				break;
    			case 19:
 			    	printf("Nome\nSale Price = $%d\nRent Price = $%d\nSelect:\n1 : Buy\t2 : Pay Rent\n",box[18],box[18]/2);
    				scanf("%d",&select2);
    				break;
	        }
    	    if(select2==1)
	    	{
	    		if(player1>=box[place1-1])
	    		{
		    		b=b+1;
		    		bank=bank+box[place1-1];
		    		player1=player1-box[place1-1];
		    		p1[b-1]=box[place1-1];
		    		printf("$%d recieved by Bank\nYour Current Balance: $%d\n",box[place1-1],player1);
		    		printf("Your Property\n");
		    	
					for(c=0;c<b;c++)
		    		{
		    			if(p1[c]!=0 && p1[c]>400)
						printf("%d\n",p1[c]);
					}
		    		printf("Current Bank Balance: $%d\n",bank);
                }
			    else
			    {
			    	printf("Insufficient balance.\nS : Sell a property\n");
		         	scanf("%c",&select4);
			    	if(select4=='s'||select4=='S')
			    	{
			    		if(b>1)
			    		{
			    			printf("select your property to sell\n");
				   			for(m=0;m<b;m++)
			    			{
				   				printf("%d : $%d\n",m+1,p1[m]);
							}
							scanf("%d",&select5);
							p1[select5-1]=0;
							b=b-1;
							player1=player1+p1[select5-1];
							bank=bank-p1[select5-1];
							for(m=0;m<b;m++)
							{
								if(p1[m]!=0)
	    						printf("%d\n",p1[m]);
							}
						    printf("Property sold to Bank\nYour current balance : $%d\nCurrent bank balance : $%d\n",player1,bank);
						    if(player1>box[place1-1])
	                		{
					    		b=b+1;
					    		bank=bank+box[place1-1];
					    		player1=player1-box[place1-1];
					    		p1[b-1]=box[place1-1];
					    		printf("$%d recieved by Bank\nYour Current Balance: $%d\n",box[place1-1],player1);
					    		printf("Your Property\n");
					    	
								for(c=0;c<b;c++)
					    		{
					    			if(p1[c]!=0&&p1[c]>400)
									printf("%d\n",p1[c]);
								}
					    		printf("Current Bank Balance: $%d\n",bank);
							}
						}
			    		if(b==1)
			    		{
							p1[0]=0;
							b=0;
							player1=player1+p1[0];
							bank=bank-p1[0];
							for(m=0;m<b;m++)
							{
								if(p1[m]!=0&&p1[m]>400)
	    						printf("%d\n",p1[m]);
							}
						    printf("Property sold to Bank\nYour current balance : $%d\nCurrent bank balance : $%d\n",player1,bank);
						    if(player1>box[place1-1])
	                		{
					    		b=b+1;
					    		bank=bank+box[place1-1];
					    		player1=player1-box[place1-1];
					    		p1[b-1]=box[place1-1];
					    		printf("$%d recieved by Bank\nYour Current Balance: $%d\n",box[place1-1],player1);
					    		printf("Your Property\n");
					    	
								for(c=0;c<b;c++)
					    		{
					    			if(p1[m]!=0&&p1[m]>400)
									printf("%d\n",p1[c]);
								}
					    		printf("Current Bank Balance: $%d\n",bank);
							}
						}	
			    		if(b==0)
						{
							printf("No property, No balance.\nPlayer 2 wins\n");
							break;
						}			
				    }
			    }
			}
			else if(select2==2)
			{
				printf("Enter 'P' to pay...\n");
				scanf("%c",&select2);
				if(select3=='p'||select3=='P')
				{
    				if(player1>=(box[place1-1]/2))
					{
						bank=bank+(box[place1-1]/2);
				    	player1=player1-(box[place1-1]/2);
			     		printf("$%d recieved by Bank.\nYour Current Balance: $%d\nCurrent Bank Balance: $%d\n",box[place1-1]/2,player1,bank);
					}
					else
				    {
				    	printf("Insufficient balance.\nS : Sell a property\n");
			         	scanf("%c",&select4);
				    	if(select4=='s'||select4=='S')
				    	{
				    		if(b>1)
				    		{
				    			printf("select your property to sell\n");
					   			for(m=0;m<b;m++)
				    			{
					   				printf("%d : $%d\n",m+1,p1[m]);
								}
								scanf("%d",&select5);
								p1[select5-1]=0;
								b=b-1;
								player1=player1+p1[select5-1];
								bank=bank-p1[select5-1];
								for(m=0;m<b;m++)
								{
									if(p1[m]!=0&&p1[m]>400)
		    						printf("%d\n",p1[m]);
								}
							    printf("Property sold to Bank\nYour current balance : $%d\nCurrent bank balance : $%d\n",player1,bank);
							    if(player1>=(box[place1-1]/2))
		                		{
						    		bank=bank+(box[place1-1]/2);
						    		player1=player1-(box[place1-1]/2);
						    		printf("$%d recieved by Bank\nYour Current Balance: $%d\n",(box[place1-1]/2),player1);
						    		printf("Your Property\n");
						    	
									for(c=0;c<b;c++)
						    		{
						    			if(p1[c]!=0&&p1[c]>400)
										printf("%d\n",p1[c]);
									}
						    		printf("Current Bank Balance: $%d\n",bank);
								}
							}
							if(b==1)
				    		{
								p1[0]=0;
								b=0;
								player1=player1+p1[0];
								bank=bank-p1[0];
								for(m=0;m<b;m++)
								{
									if(p1[m]!=0&&p1[m]>400)
		    						printf("%d\n",p1[m]);
								}
							    printf("Property sold to Bank\nYour current balance : $%d\nCurrent bank balance : $%d\n",player1,bank);
							    if(player1>=(box[place1-1]/2))
		                		{
						    		bank=bank+(box[place1-1]/2);
						    		player1=player1-(box[place1-1]/2);
						    		printf("$%d recieved by Bank\nYour Current Balance: $%d\n",(box[place1-1]/2),player1);
						    		printf("Your Property\n");
						    	
									for(c=0;c<b;c++)
						    		{
						    			if(p1[c]!=0&&p1[c]>400)
										printf("%d\n",p1[c]);
									}
						    		printf("Current Bank Balance: $%d\n",bank);
								}
							}	
							if(b==0)
							{
								printf("No Property, No Balance.\nPlayer 2 wins");
								break;
							}	
					    }
				    }
				}
		    }
	    }
		if(place1==4||place1==10||place1==11||place1==15||place1==18||place1==7||place1==17)
		{
			if(place1==4||place1==11)
			{
				printf("You Have To Pay $200 as Tax :)\n");
				printf("Enter 'P' to pay...\n");
				scanf(" %c",&select3);
				if(select3=='p'||select3=='P')
				{
					if(player1>=200)
					{
						bank=bank+200;
				    	player1=player1-200;
		      			printf("$200 recieved by Bank.\nYour Current Balance: $%d\nCurrent Bank Balance: $%d\n",player1,bank);
					}
					else
					    {
					    	printf("Insufficient balance.\nS : Sell a property\n");
				         	scanf("%c",&select4);
					    	if(select4=='s'||select4=='S')
					    	{
					    		if(b>1)
					    		{
					    			printf("select your property to sell\n");
						   			for(m=0;m<b;m++)
					    			{
						   				printf("%d : $%d\n",m+1,p1[m]);
									}
									scanf("%d",&select5);
									p1[select5-1]=0;
									b=b-1;
									player1=player1+p1[select5-1];
									bank=bank-p1[select5-1];
									for(m=0;m<b;m++)
									{
										if(p1[m]!=0&&p1[m]>400)
			    						printf("%d\n",p1[m]);
									}
								    printf("Property sold to Bank\nYour current balance : $%d\nCurrent bank balance : $%d\n",player1,bank);
								    if(player1>=200)
			                		{
							    		bank=bank+200;
							    		player1=player1-200;
							    		printf("$200 recieved by Bank\nYour Current Balance: $%d\n",player1);
							    		printf("Your Property\n");
							    	
										for(c=0;c<b;c++)
							    		{
							    			if(p1[c]!=0&&p1[c]>400)
											printf("%d\n",p1[c]);
										}
							    		printf("Current Bank Balance: $%d\n",bank);
									}
								}
								if(b==1)
					    		{
									p1[0]=0;
									b=0;
									player1=player1+p1[0];
									bank=bank-p1[0];
									for(m=0;m<b;m++)
									{
										if(p1[m]!=0&&p1[m]>400)
			    						printf("%d\n",p1[m]);
									}
								    printf("Property sold to Bank\nYour current balance : $%d\nCurrent bank balance : $%d\n",player1,bank);
								    if(player1>=200)
			                		{
							    		bank=bank+200;
							    		player1=player1-200;
							    		printf("$200 recieved by Bank\nYour Current Balance: $%d\n",player1);
							    		printf("Your Property\n");
							    	
										for(c=0;c<b;c++)
							    		{
							    			if(p1[c]!=0&&p1[c]>400)
											printf("%d\n",p1[c]);
										}
							    		printf("Current Bank Balance: $%d\n",bank);
									}
								}		
								if(b==0)
								{
									printf("No Property,No balance.\n Player2 wins\n");
									}	
						    }
					    }
					}
				}
				if(place1==10)
				{
			        printf("You are now locked up.To get free you must pay $400 to Bank\n");
					printf("Enter 'P' to pay...\n");
					scanf(" %c",&select3);
					if(select3=='p'||select3=='P')
					{
						if(player1>=400)
						{
							bank=bank+400;
					    	player1=player1-400;
			     			printf("$400 recieved by Bank.\nYour Current Balance: $%d\nCurrent Bank Balance: $%d\n",player1,bank);
						}
			    		else
					    {
					    	printf("Insufficient balance.\nS : Sell a property\n");
				         	scanf("%c",&select4);
					    	if(select4=='s'||select4=='S')
					    	{
					    		if(b>1)
					    		{
					    			printf("select your property to sell\n");
						   			for(m=0;m<b;m++)
					    			{
						   				printf("%d : $%d\n",m+1,p1[m]);
									}
									scanf("%d",&select5);
									p1[select5-1]=0;
									b=b-1;
									player1=player1+p1[select5-1];
									bank=bank-p1[select5-1];
									for(m=0;m<b;m++)
									{
										if(p1[m]!=0&&p1[m]>400)
			    						printf("%d\n",p1[m]);
									}
								    printf("Property sold to Bank\nYour current balance : $%d\nCurrent bank balance : $%d\n",player1,bank);
								    if(player1>=400)
			                		{
							    		bank=bank+400;
							    		player1=player1-400;
							    		printf("$400 recieved by Bank\nYour Current Balance: $%d\n",player1);
							    		printf("Your Property\n");
							    	
										for(c=0;c<b;c++)
							    		{
							    			if(p1[c]!=0&&p1[c]>400)
											printf("%d\n",p1[c]);
										}
							    		printf("Current Bank Balance: $%d\n",bank);
									}
								}
								if(b==1)
					    		{
									p1[0]=0;
									b=0;
									player1=player1+p1[0];
									bank=bank-p1[0];
									for(m=0;m<b;m++)
									{
										if(p1[m]!=0&&p1[m]>400)
			    						printf("%d\n",p1[m]);
									}
								    printf("Property sold to Bank\nYour current balance : $%d\nCurrent bank balance : $%d\n",player1,bank);
								    if(player1>=400)
			                		{
							    		bank=bank+400;
							    		player1=player1-400;
							    		printf("$400 recieved by Bank\nYour Current Balance: $%d\n",player1);
							    		printf("Your Property\n");
							    	
										for(c=0;c<b;c++)
							    		{
							    			if(p1[c]!=0&&p1[c]>400)
											printf("%d\n",p1[c]);
										}
							    		printf("Current Bank Balance: $%d\n",bank);
									}
								}	
								if(b==0)
								{
									printf("No property,No balance\nPlayer 2 Wins\n");
									break;
										}		
						    }
					    }
					}
				}
				if(place1==15)
				{
					printf("You must pay the electricity bill: $100\nEnter 'P' to pay...\n");
					scanf(" %c",&select3);
					if(select3=='p'||select3=='P')
					{
						if(player1>=100)
						{
							bank=bank+100;
					    	player1=player1-100;
			     			printf("$100 recieved by Bank.\nYour Current Balance: $%d\nCurrent Bank Balance: $%d\n",player1,bank);
						}
					}
			    	else
					    {
					    	printf("Insufficient balance.\nS : Sell a property\n");
				         	scanf("%c",&select4);
					    	if(select4=='s'||select4=='S')
					    	{
					    		if(b>1)
					    		{
					    			printf("Select your property to sell\n");
						   			for(m=0;m<b;m++)
					    			{
						   				printf("%d : $%d\n",m+1,p1[m]);
									}
									scanf("%d",&select5);
									p1[select5-1]=0;
									b=b-1;
									player1=player1+p1[select5-1];
									bank=bank-p1[select5-1];
									for(m=0;m<b;m++)
									{
										if(p1[m]!=0&&p1[m]>400)
			    						printf("%d\n",p1[m]);
									}
								    printf("Property sold to Bank\nYour current balance : $%d\nCurrent bank balance : $%d\n",player1,bank);
								    if(player1>=100)
			                		{
							    		bank=bank+100;
							    		player1=player1-100;
							    		printf("$100 recieved by Bank\nYour Current Balance: $%d\n",player1);
							    		printf("Your Property\n");
							    	
										for(c=0;c<b;c++)
							    		{
							    			if(p1[c]!=0&&p1[c]>400)
											printf("%d\n",p1[c]);
										}
							    		printf("Current Bank Balance: $%d\n",bank);
									}
								}
								if(b==1)
								{
									p1[0]=0;
									b=0;
									player1=player1+p1[0];
									bank=bank-p1[0];
									for(m=0;m<b;m++)
									{
										if(p1[m]!=0&&p1[m]>400)
			    						printf("%d\n",p1[m]);
									}
								    printf("Property sold to Bank\nYour current balance : $%d\nCurrent bank balance : $%d\n",player1,bank);
								    if(player1>=100)
			                		{
							    		bank=bank+100;
							    		player1=player1-100;
							    		printf("$100 recieved by Bank\nYour Current Balance: $%d\n",player1);
							    		printf("Your Property\n");
							    	
										for(c=0;c<b;c++)
							    		{
							    			if(p1[c]!=0&&p1[c]>400)
											printf("%d\n",p1[c]);
										}
							    		printf("Current Bank Balance: $%d\n",bank);
									}
								}
								if(b==0)
								{
									printf("No Property, No balance.\n Player 2 wins\n");
									break;
								}			
						    }
					    }
				}
				if(place1==18)
				{
					printf("You must pay the gas bill: $50\nEnter 'P' to pay...\n");
					scanf(" %c",&select3);
					if(select3=='p'||select3=='P')
					{
						if(player1>=50)
						{
							bank=bank+50;
					    	player1=player1-50;
			     			printf("$50 recieved by Bank.\nYour Current Balance: $%d\nCurrent Bank Balance: $%d\n",player1,bank);
						}
						else
					    {
					    	printf("Insufficient balance.\nS : Sell a property\n");
				         	scanf("%c",&select4);
					    	if(select4=='s'||select4=='S')
					    	{
					    		if(b>1)
					    		{
					    			printf("select your property to sell\n");
						   			for(m=0;m<b;m++)
					    			{
						   				printf("%d : $%d\n",m+1,p1[m]);
									}
									scanf("%d",&select5);
									p1[select5-1]=0;
									b=b-1;
									player1=player1+p1[select5-1];
									bank=bank-p1[select5-1];
									for(m=0;m<b;m++)
									{
										if(p1[m]!=0&&p1[m]>400)
			    						printf("%d\n",p1[m]);
									}
								    printf("Property sold to Bank\nYour current balance : $%d\nCurrent bank balance : $%d\n",player1,bank);
								    if(player1>=50)
			                		{
							    		bank=bank+50;
							    		player1=player1-50;
							    		printf("$50 recieved by Bank\nYour Current Balance: $%d\n",player1);
							    		printf("Your Property\n");
							    	
										for(c=0;c<b;c++)
							    		{
							    			if(p1[c]!=0&&p1[c]>400)
											printf("%d\n",p1[c]);
										}
							    		printf("Current Bank Balance: $%d\n",bank);
									}
								}
								if(b==1)
								{
									p1[0]=0;
									b=0;
									player1=player1+p1[0];
									bank=bank-p1[0];
									for(m=0;m<b;m++)
									{
										if(p1[m]!=0&&p1[m]>400)
			    						printf("%d\n",p1[m]);
									}
								    printf("Property sold to Bank\nYour current balance : $%d\nCurrent bank balance : $%d\n",player1,bank);
								    if(player1>=50)
			                		{
							    		bank=bank+50;
							    		player1=player1-50;
							    		printf("$50 recieved by Bank\nYour Current Balance: $%d\n",player1);
							    		printf("Your Property\n");
							    	
										for(c=0;c<b;c++)
							    		{
							    			if(p1[c]!=0&&p1[c]>400)
											printf("%d\n",p1[c]);
										}
							    		printf("Current Bank Balance: $%d\n",bank);
									}
								}			
								if(b==0)
								{
									printf("No Property,No balance.\n Player 2 Wins\n");
									break;
								}
						    }
					    }
					}
				}
				if(place1==7||place1==17)
				{
					printf("Let's check your Luck!\n");
					if(dice%2==0)
					{
						printf("It's the good luck :)\nYou are given $250 by Bank\n");
						player1=player1+250;
						bank=bank-250;
						printf("Your Current Balance: $%d\nCurrent Bank Balance: $%d",player1,bank);
					}
					else
					{
						printf("It's the bad luck :(\nYou have to pay $250 to Bank\n");
						printf("Enter 'P' to pay...\n");
						scanf(" %c",&select3);
			     		if(select3=='p'||select3=='P')
				    	{
			    			if(player1>=250)
		    				{
						     	bank=bank+250;
    					    	player1=player1-250;
	    		     			printf("$250 recieved by Bank.\nYour Current Balance: $%d\nCurrent Bank Balance: $%d\n",player1,bank);
				    		}
				    		else
						    {
						    	printf("Insufficient balance.\nS : Sell a property\n");
					         	scanf("%c",&select4);
						    	if(select4=='s'||select4=='S')
						    	{
						    		if(b>1)
						    		{
						    			printf("select your property to sell\n");
							   			for(m=0;m<b;m++)
						    			{
							   				printf("%d : $%d\n",m+1,p1[m]);
										}
										scanf("%d",&select5);
										p1[select5-1]=0;
										b=b-1;
										player1=player1+p1[select5-1];
										bank=bank-p1[select5-1];
										for(m=0;m<b;m++)
										{
											if(p1[m]!=0&&p1[m]>400)
				    						printf("%d\n",p1[m]);
										}
									    printf("Property sold to Bank\nYour current balance : $%d\nCurrent bank balance : $%d\n",player1,bank);
									    if(player1>=250)
				                		{
								    		bank=bank+250;
								    		player1=player1-250;
								    		printf("$200 recieved by Bank\nYour Current Balance: $%d\n",player1);
								    		printf("Your Property\n");
								    	
											for(c=0;c<b;c++)
								    		{
								    			if(p1[c]!=0&&p1[c]>400)
												printf("%d\n",p1[c]);
											}
								    		printf("Current Bank Balance: $%d\n",bank);
										}
										if(b==1)
										{
											p1[0]=0;
											b=0;
											player1=player1+p1[0];
											bank=bank-p1[0];
											for(m=0;m<b;m++)
											{
												if(p1[m]!=0&&p1[m]>400)
					    						printf("%d\n",p1[m]);
											}
										    printf("Property sold to Bank\nYour current balance : $%d\nCurrent bank balance : $%d\n",player1,bank);
										    if(player1>=250)
					                		{
									    		bank=bank+250;
									    		player1=player1-250;
									    		printf("$200 recieved by Bank\nYour Current Balance: $%d\n",player1);
									    		printf("Your Property\n");
									    	
												for(c=0;c<b;c++)
									    		{
									    			if(p1[c]!=0&&p1[c]>400)
													printf("%d\n",p1[c]);
												}
									    		printf("Current Bank Balance: $%d\n",bank);
											}
										}
										if(b==0)
										{
											printf("No Property, No balance.\n Player 2 wins\n");
											break;
										}
									}			
							    }
						    }
			    		}
					}
				}
			}
            printf("Rolling Dice for Player 2\n");
			dice1=(rand()%6)+1;
			printf("Dice Number: %d\n",dice1);
			if(dice1==6)
			{
				printf("Rolling Dice again\n");//players get a chance to roll dice when a 6 is rolled.
				dice2=(rand()%6)+1;
				printf("2nd Dice Number: %d\n",dice2);
				if(dice2==6)
				{
					printf("Rolling Dice Again\nRolling a 6 this time would result in loss of turn!\n");
					dice3=(rand()%6)+1;
					printf("3rd Dice Number: %d\n",dice3);
					if(dice3==6)
					{
						printf("You Loss A Turn!\n");
					}
					else
					{
						dice=dice1+dice2+dice3;
						printf("Your Total Number: %d\n",dice);
					}
				}
				else
				{
					dice=dice1+dice2;
					printf("Your Total Number: %d\n",dice);
				}
			}
			else
			{
				dice=dice1;
			}		
		    place2=place2+dice;//place is defined with respect to previous place + Dice numbers
		    if(place2%20==0){
		    	printf("You completed one round!\nYou got $200 !!\n");// When one round of the board is completed, players gets $200 as a bonus.
		    	bank=bank-200;
		    	player2=player2+200;
		    	printf("Your Current Balance: $%d\nCurrent Bank Balance: $%d\n",player2,bank);
			}
		    if(place2>20){
		    	place2=place2%20;
			}
		    printf("Your place:  %d\n",place2);
		    for(c=0;c<b||c<d;c++)//This loop checks whether the place you are on is owned by the opponent or not. 
		    {
		    	if(box[place2-1]==p1[c]&&box[place2-1]!=0)
		    	{
		    		yes=1;
		    		rent=p1[c]/2;//if it is owned by opponent you must pay its rent, which is half of its sale price.
				}
				else if(box[place2-1]==p2[c]&&box[place2-1]!=0)
				{
					printf("Your property!\n");
				}
			}
			if(yes==1)
			{
				printf("You landed on your opponent's property.\nYou must pay it's rent : $%d\n",rent);
				printf("Enter 'P' to pay...\n");
				scanf(" %c",&select);
				if(select=='p'||select=='P')
				{
					if(player2>=rent){
					player1=player1+rent;
					player2=player2-rent;
					printf("$%d recieved by Bank\n Your Current Balance: $%d\nCurrent Bank Balance: $%d\n",rent,player2,bank);
					}
				    else
				    {
				    	printf("Insufficient balance.\nS : Sell a property\n");
				    	scanf("%c",&select4);
				    	if(select4=='s'||select4=='S')
				    	{
				    		if(d>1)
				    		{
				    			printf("select you property to sell\n");
				    			for(m=0;m<d;m++)
				    			{
				    				printf("%d : $%d\n",m+1,p2[m]);
								}
								scanf("%d",&select5);
								p2[select5-1]=0;
								d=d-1;
								player2=player2+p2[select5-1]-rent;
								bank=bank-p2[select5-1];
								player1=player1+rent;
								printf("Your Property\n");
								for(m=0;m<d;m++)
								{
									if(p2[m]!=0&&p2[m]>400)
									printf("%d\n",p2[m]);
								}
								printf("Property sold to Bank\nRent paid to opponent\nYour current balance : $%d\nCurrent bank balance : $%d\n",player2,bank);
							}
							if(d==1)
				    		{
								p2[0]=0;
								d=0;
								player2=player2+p2[0]-rent;
								bank=bank-p2[0];
								player1=player1+rent;
								printf("Your Property\n");
								for(m=0;m<d;m++)
								{
									if(p2[m]!=0&&p2[m]>400)
									printf("%d\n",p2[m]);
								}
								printf("Property sold to Bank\nRent paid to opponent\nYour current balance : $%d\nCurrent bank balance : $%d\n",player2,bank);
							}
							if(d==0)
							{
								printf("No Property,No balance.\nPlayer 1 wins\n");
								break;
							}
						}
					}
				}
			}
		    else{
		    switch(place2){
			    case 1:
 			    	printf("Alexander City\nSale Price = $%d\nRent Price = $%d\nSelect:\n1 : Buy\t2 : Pay Rent\n",box[0],box[0]/2);
    				scanf("%d",&select2);
    				break;
    			case 2:
 			    	printf("Florence\nSale Price = $%d\nRent Price = $%d\nSelect:\n1 : Buy\t2 : Pay Rent\n",box[1],box[1]/2);
    				scanf("%d",&select2);
    				break;
    			case 3:
 			    	printf("Los Angeles\nSale Price = $%d\nRent Price = $%d\nSelect:\n1 : Buy\t2 : Pay Rent\n",box[2],box[2]/2);
    				scanf("%d",&select2);
    				break;
				case 5:
 			    	printf("Ontario\nSale Price = $%d\nRent Price = $%d\nSelect:\n1 : Buy\t2 : Pay Rent\n",box[4],box[4]/2);
    				scanf("%d",&select2);
    				break;
				case 6:
 			    	printf("Central City\nSale Price = $%d\nRent Price = $%d\nSelect:\n1 : Buy\t2 : Pay Rent\n",box[5],box[5]/2);
    				scanf("%d",&select2);
    				break;
				case 8:
 			    	printf("Redwood City\nSale Price = $%d\nRent Price = $%d\nSelect:\n1 : Buy\t2 : Pay Rent\n",box[7],box[7]/2);
    				scanf("%d",&select2);
    				break;			
				case 9:
 			    	printf("New Castle\nSale Price = $%d\nRent Price = $%d\nSelect:\n1 : Buy\t2 : Pay Rent\n",box[8],box[8]/2);
    				scanf("%d",&select2);
    				break;
				case 12:
 			    	printf("Forrest City\nSale Price = $%d\nRent Price = $%d\nSelect:\n1 : Buy\t2 : Pay Rent\n",box[11],box[11]/2);
    				scanf("%d",&select2);
    				break;
				case 13:
 			    	printf("West Minister\nSale Price = $%d\nRent Price = $%d\nSelect:\n1 : Buy\t2 : Pay Rent\n",box[12],box[12]/2);
    				scanf("%d",&select2);
    				break;
				case 14:
 			    	printf("Norwalk\nSale Price = $%d\nRent Price = $%d\nSelect:\n1 : Buy\t2 : Pay Rent\n",box[13],box[13]/2);
    				scanf("%d",&select2);
    				break;						
				case 16:
 			    	printf("San Fransico\nSale Price = $%d\nRent Price = $%d\nSelect:\n1 : Buy\t2 : Pay Rent\n",box[15],box[15]/2);
    				scanf("%d",&select2);
    				break;
    			case 19:
 			    	printf("Nome\nSale Price = $%d\nRent Price = $%d\nSelect:\n1 : Buy\t2 : Pay Rent\n",box[18],box[18]/2);
    				scanf("%d",&select2);
    				break;
	        }
    	    if(select2==1)
	    	{
	    		if(player2>=box[place2-1])
	    		{
		    		d=d+1;
		    		bank=bank+box[place2-1];
		    		player2=player2-box[place2-1];
		    		p1[d-1]=box[place2-1];
		    		printf("$%d recieved by Bank\nYour Current Balance: $%d\n",box[place2-1],player2);
		    		printf("Your Property\n");
		    	
					for(c=0;c<d;c++)
		    		{
		    			if(p2[c]!=0 && p2[c]>400)
						printf("%d\n",p2[c]);
					}
		    		printf("Current Bank Balance: $%d\n",bank);
                }
			    else
			    {
			    	printf("Insufficient balance.\nS : Sell a property\n");
		         	scanf("%c",&select4);
			    	if(select4=='s'||select4=='S')
			    	{
			    		if(d>1)
			    		{
			    			printf("select your property to sell\n");
				   			for(m=0;m<d;m++)
			    			{
				   				printf("%d : $%d\n",m+1,p2[m]);
							}
							scanf("%d",&select5);
							p2[select5-1]=0;
							d=d-1;
							player2=player2+p2[select5-1];
							bank=bank-p2[select5-1];
							for(m=0;m<d;m++)
							{
								if(p2[m]!=0&&p2[m]>400)
	    						printf("%d\n",p2[m]);
							}
						    printf("Property sold to Bank\nYour current balance : $%d\nCurrent bank balance : $%d\n",player2,bank);
						    if(player2>=box[place2-2])
	                		{
					    		d=d+1;
					    		bank=bank+box[place2-1];
					    		player2=player2-box[place2-1];
					    		p2[d-1]=box[place2-1];
					    		printf("$%d recieved by Bank\nYour Current Balance: $%d\n",box[place2-1],player2);
					    		printf("Your Property\n");
					    	
								for(c=0;c<d;c++)
					    		{
					    			if(p2[c]!=0&&p2[c]>400)
									printf("%d\n",p2[c]);
								}
					    		printf("Current Bank Balance: $%d\n",bank);
							}
						}			
						if(d==1)
			    		{
							p2[0]=0;
							d=0;
							player2=player2+p2[0];
							bank=bank-p2[0];
							for(m=0;m<d;m++)
							{
								if(p2[m]!=0&&p2[m]>400)
	    						printf("%d\n",p2[m]);
							}
						    printf("Property sold to Bank\nYour current balance : $%d\nCurrent bank balance : $%d\n",player2,bank);
						    if(player2>=box[place2-2])
	                		{
					    		d=d+1;
					    		bank=bank+box[place2-1];
					    		player2=player2-box[place2-1];
					    		p2[d-1]=box[place2-1];
					    		printf("$%d recieved by Bank\nYour Current Balance: $%d\n",box[place2-1],player2);
					    		printf("Your Property\n");
					    	
								for(c=0;c<d;c++)
					    		{
					    			if(p2[c]!=0&&p2[c]>400)
									printf("%d\n",p2[c]);
								}
					    		printf("Current Bank Balance: $%d\n",bank);
							}
						}
						if(d==0)
						{
							printf("No Property,No balance.\nPlayer 1 wins\n");
							break;
						}
				    }
			    }
			}
			else if(select2==2)
			{
				printf("Enter 'P' to pay...\n");
				scanf("%c",&select2);
				if(select3=='p'||select3=='P')
				{
    				if(player2>=(box[place2-1]/2))
					{
						bank=bank+(box[place2-1]/2);
				    	player2=player2-(box[place2-1]/2);
			     		printf("$%d recieved by Bank.\nYour Current Balance: $%d\nCurrent Bank Balance: $%d\n",box[place2-1]/2,player2,bank);
					}
					else
				    {
				    	printf("Insufficient balance.\nS : Sell a property\n");
			         	scanf("%c",&select4);
				    	if(select4=='s'||select4=='S')
				    	{
				    		if(d>1)
				    		{
				    			printf("select your property to sell\n");
					   			for(m=0;m<d;m++)
				    			{
					   				printf("%d : $%d\n",m+1,p2[m]);
								}
								scanf("%d",&select5);
								p2[select5-1]=0;
								d=d-1;
								player2=player2+p2[select5-1];
								bank=bank-p2[select5-1];
								for(m=0;m<d;m++)
								{
									if(p2[m]!=0&&p2[m]>400)
		    						printf("%d\n",p2[m]);
								}
							    printf("Property sold to Bank\nYour current balance : $%d\nCurrent bank balance : $%d\n",player2,bank);
							    if(player2>=(box[place2-1]/2))
		                		{
						    		bank=bank+(box[place2-1]/2);
						    		player2=player2-(box[place2-1]/2);
						    		printf("$%d recieved by Bank\nYour Current Balance: $%d\n",(box[place2-1]/2),player2);
						    		printf("Your Property\n");
						    	
									for(c=0;c<d;c++)
						    		{
						    			if(p2[c]!=0&&p2[c]>400)
										printf("%d\n",p2[c]);
									}
						    		printf("Current Bank Balance: $%d\n",bank);
								}
							}
							if(d==1)
				    		{
								p2[0]=0;
								d=0;
								player2=player2+p2[0];
								bank=bank-p2[0];
								for(m=0;m<d;m++)
								{
									if(p2[m]!=0&&p2[m]>400)
		    						printf("%d\n",p2[m]);
								}
							    printf("Property sold to Bank\nYour current balance : $%d\nCurrent bank balance : $%d\n",player2,bank);
							    if(player2>=(box[place2-1]/2))
		                		{
						    		bank=bank+(box[place2-1]/2);
						    		player2=player2-(box[place2-1]/2);
						    		printf("$%d recieved by Bank\nYour Current Balance: $%d\n",(box[place2-1]/2),player2);
						    		printf("Your Property\n");
						    	
									for(c=0;c<d;c++)
						    		{
						    			if(p2[c]!=0&&p2[c]>400)
										printf("%d\n",p2[c]);
									}
						    		printf("Current Bank Balance: $%d\n",bank);
								}
							}			
							if(d==0)
							{
								printf("No Property,No balance\nPlayer 1 Wins\n");
								break;
							}
					    }
				    }
				}
		    }
	    }
		if(place1==4||place1==10||place1==11||place1==15||place1==18||place1==7||place1==17)
		{
			if(place2==4||place2==11)
			{
				printf("You Have To Pay $200 as Tax :)\n");
				printf("Enter 'P' to pay...\n");
				scanf(" %c",&select3);
				if(select3=='p'||select3=='P')
				{
					if(player2>=200)
					{
						bank=bank+200;
				    	player2=player2-200;
		      			printf("$200 recieved by Bank.\nYour Current Balance: $%d\nCurrent Bank Balance: $%d\n",player2,bank);
					}
					else
					    {
					    	printf("Insufficient balance.\nS : Sell a property\n");
				         	scanf("%c",&select4);
					    	if(select4=='s'||select4=='S')
					    	{
					    		if(d>1)
					    		{
					    			printf("select your property to sell\n");
						   			for(m=0;m<d;m++)
					    			{
						   				printf("%d : $%d\n",m+1,p2[m]);
									}
									scanf("%d",&select5);
									p2[select5-1]=0;
									d=d-1;
									player2=player2+p2[select5-1];
									bank=bank-p2[select5-1];
									for(m=0;m<d;m++)
									{
										if(p2[m]!=0&&p2[m]>400)
			    						printf("%d\n",p2[m]);
									}
								    printf("Property sold to Bank\nYour current balance : $%d\nCurrent bank balance : $%d\n",player2,bank);
								    if(player2>=200)
			                		{
							    		bank=bank+200;
							    		player2=player2-200;
							    		printf("$200 recieved by Bank\nYour Current Balance: $%d\n",player2);
							    		printf("Your Property\n");
							    	
										for(c=0;c<d;c++)
							    		{
							    			if(p2[c]!=0&&p2[c]>400)
											printf("%d\n",p2[c]);
										}
							    		printf("Current Bank Balance: $%d\n",bank);
									}
								}
								if(d==1)
					    		{
									p2[0]=0;
									d=0;
									player2=player2+p2[0];
									bank=bank-p2[0];
									for(m=0;m<d;m++)
									{
										if(p2[m]!=0&&p2[m]>400)
			    						printf("%d\n",p2[m]);
									}
								    printf("Property sold to Bank\nYour current balance : $%d\nCurrent bank balance : $%d\n",player2,bank);
								    if(player2>=200)
			                		{
							    		bank=bank+200;
							    		player2=player2-200;
							    		printf("$200 recieved by Bank\nYour Current Balance: $%d\n",player2);
							    		printf("Your Property\n");
							    	
										for(c=0;c<d;c++)
							    		{
							    			if(p2[c]!=0&&p2[c]>400)
											printf("%d\n",p2[c]);
										}
							    		printf("Current Bank Balance: $%d\n",bank);
									}
								}			
								if(d==0)
								{
									printf("No property,no balance\n Player 1 Wins\n");
									break;
								}
						    }
					    }
					}
				}
				if(place2==10)
				{
			        printf("You are now locked up.To get free you must pay $400 to Bank\n");
					printf("Enter 'P' to pay...\n");
					scanf(" %c",&select3);
					if(select3=='p'||select3=='P')
					{
						if(player2>=400)
						{
							bank=bank+400;
					    	player2=player2-400;
			     			printf("$400 recieved by Bank.\nYour Current Balance: $%d\nCurrent Bank Balance: $%d\n",player2,bank);
						}
			    		else
					    {
					    	printf("Insufficient balance.\nS : Sell a property\n");
				         	scanf("%c",&select4);
					    	if(select4=='s'||select4=='S')
					    	{
					    		if(d>1)
					    		{
					    			printf("select your property to sell\n");
						   			for(m=0;m<d;m++)
					    			{
						   				printf("%d : $%d\n",m+1,p2[m]);
									}
									scanf("%d",&select5);
									p2[select5-1]=0;
									d=d-1;
									player2=player2+p2[select5-1];
									bank=bank-p2[select5-1];
									for(m=0;m<d;m++)
									{
										if(p2[m]!=0&&p2[m]>400)
			    						printf("%d\n",p2[m]);
									}
								    printf("Property sold to Bank\nYour current balance : $%d\nCurrent bank balance : $%d\n",player2,bank);
								    if(player2>=400)
			                		{
							    		bank=bank+400;
							    		player2=player2-400;
							    		printf("$400 recieved by Bank\nYour Current Balance: $%d\n",player2);
							    		printf("Your Property\n");
							    	
										for(c=0;c<d;c++)
							    		{
							    			if(p2[c]!=0&&p2[c]>400)
											printf("%d\n",p2[c]);
										}
							    		printf("Current Bank Balance: $%d\n",bank);
									}
								}
								if(d==1)
					    		{
									p2[0]=0;
									d=0;
									player2=player2+p2[0];
									bank=bank-p2[0];
									for(m=0;m<d;m++)
									{
										if(p2[m]!=0&&p2[m]>400)
			    						printf("%d\n",p2[m]);
									}
								    printf("Property sold to Bank\nYour current balance : $%d\nCurrent bank balance : $%d\n",player2,bank);
								    if(player2>=400)
			                		{
							    		bank=bank+400;
							    		player2=player2-400;
							    		printf("$400 recieved by Bank\nYour Current Balance: $%d\n",player2);
							    		printf("Your Property\n");
							    	
										for(c=0;c<d;c++)
							    		{
							    			if(p2[c]!=0&&p2[c]>400)
											printf("%d\n",p2[c]);
										}
							    		printf("Current Bank Balance: $%d\n",bank);
									}
									if(d==0)
									{
										printf("No Property,No balance\nPlayer 1 wins\n");
										break;
									}
								}				
						    }
					    }
					}
				}
				if(place2==15)
				{
					printf("You must pay the electricity bill: $100\nEnter 'P' to pay...\n");
					scanf(" %c",&select3);
					if(select3=='p'||select3=='P')
					{
						if(player2>=100)
						{
							bank=bank+100;
					    	player2=player2-100;
			     			printf("$100 recieved by Bank.\nYour Current Balance: $%d\nCurrent Bank Balance: $%d\n",player2,bank);
						}
					}
			    	else
					    {
					    	printf("Insufficient balance.\nS : Sell a property\n");
				         	scanf("%c",&select4);
					    	if(select4=='s'||select4=='S')
					    	{
					    		if(d>1)
					    		{
					    			printf("Select your property to sell\n");
						   			for(m=0;m<d;m++)
					    			{
						   				printf("%d : $%d\n",m+1,p2[m]);
									}
									scanf("%d",&select5);
									p2[select5-1]=0;
									d=d-1;
									player2=player2+p2[select5-1];
									bank=bank-p2[select5-1];
									for(m=0;m<d;m++)
									{
										if(p2[m]!=0&&p2[m]>400)
			    						printf("%d\n",p2[m]);
									}
								    printf("Property sold to Bank\nYour current balance : $%d\nCurrent bank balance : $%d\n",player2,bank);
								    if(player2>=100)
			                		{
							    		bank=bank+100;
							    		player2=player2-100;
							    		printf("$100 recieved by Bank\nYour Current Balance: $%d\n",player2);
							    		printf("Your Property\n");
							    	
										for(c=0;c<d;c++)
							    		{
							    			if(p2[c]!=0&&p2[c]>400)
											printf("%d\n",p2[c]);
										}
							    		printf("Current Bank Balance: $%d\n",bank);
									}
								}
								if(d==1)
					    		{
									p2[0]=0;
									d=0;
									player2=player2+p2[0];
									bank=bank-p2[0];
									for(m=0;m<d;m++)
									{
										if(p2[m]!=0&&p2[m]>400)
			    						printf("%d\n",p2[m]);
									}
								    printf("Property sold to Bank\nYour current balance : $%d\nCurrent bank balance : $%d\n",player2,bank);
								    if(player2>=100)
			                		{
							    		bank=bank+100;
							    		player2=player2-100;
							    		printf("$100 recieved by Bank\nYour Current Balance: $%d\n",player2);
							    		printf("Your Property\n");
							    	
										for(c=0;c<d;c++)
							    		{
							    			if(p2[c]!=0&&p2[c]>400)
											printf("%d\n",p2[c]);
										}
							    		printf("Current Bank Balance: $%d\n",bank);
									}
								}	
								if(d==0)
								{
									printf("No property,No balance\nPlayer 1 wins\n");
									break;
								}			
						    }
					    }
				}
				if(place2==18)
				{
					printf("You must pay the gas bill: $50\nEnter 'P' to pay...\n");
					scanf(" %c",&select3);
					if(select3=='p'||select3=='P')
					{
						if(player2>=50)
						{
							bank=bank+50;
					    	player2=player2-50;
			     			printf("$50 recieved by Bank.\nYour Current Balance: $%d\nCurrent Bank Balance: $%d\n",player2,bank);
						}
						else
					    {
					    	printf("Insufficient balance.\nS : Sell a property\n");
				         	scanf("%c",&select4);
					    	if(select4=='s'||select4=='S')
					    	{
					    		if(d>1)
					    		{
					    			printf("select your property to sell\n");
						   			for(m=0;m<d;m++)
					    			{
						   				printf("%d : $%d\n",m+1,p2[m]);
									}
									scanf("%d",&select5);
									p2[select5-1]=0;
									d=d-1;
									player2=player2+p2[select5-1];
									bank=bank-p2[select5-1];
									for(m=0;m<d;m++)
									{
										if(p2[m]!=0&&p2[m]>400)
			    						printf("%d\n",p2[m]);
									}
								    printf("Property sold to Bank\nYour current balance : $%d\nCurrent bank balance : $%d\n",player2,bank);
								    if(player2>=50)
			                		{
							    		bank=bank+50;
							    		player2=player2-50;
							    		printf("$50 recieved by Bank\nYour Current Balance: $%d\n",player2);
							    		printf("Your Property\n");
							    	
										for(c=0;c<d;c++)
							    		{
							    			if(p2[c]!=0&&p2[c]>400)
											printf("%d\n",p2[c]);
										}
							    		printf("Current Bank Balance: $%d\n",bank);
									}
								}
								if(d==1)
					    		{
									p2[0]=0;
									d=0;
									player2=player2+p2[0];
									bank=bank-p2[0];
									for(m=0;m<d;m++)
									{
										if(p2[m]!=0&&p2[m]>400)
			    						printf("%d\n",p2[m]);
									}
								    printf("Property sold to Bank\nYour current balance : $%d\nCurrent bank balance : $%d\n",player2,bank);
								    if(player2>=50)
			                		{
							    		bank=bank+50;
							    		player2=player2-50;
							    		printf("$50 recieved by Bank\nYour Current Balance: $%d\n",player2);
							    		printf("Your Property\n");
							    	
										for(c=0;c<d;c++)
							    		{
							    			if(p2[c]!=0&&p2[c]>400)
											printf("%d\n",p2[c]);
										}
							    		printf("Current Bank Balance: $%d\n",bank);
									}
								}
								if(d==0)
								{
									printf("No property,no balance\nPlayer 1 wins\n");
									break;
								}			
						    }
					    }
					}
				}
				if(place2==7||place2==17)
				{
					printf("Let's check your Luck!\n");
					if(dice%2==0)
					{
						printf("It's the good luck :)\nYou are given $250 by Bank\n");
						player2=player2+250;
						bank=bank-250;
						printf("Your Current Balance: $%d\nCurrent Bank Balance: $%d",player2,bank);
					}
					else
					{
						printf("It's the bad luck :(\nYou have to pay $200 to Bank\n");
						printf("Enter 'P' to pay...\n");
						scanf(" %c",&select3);
			     		if(select3=='p'||select3=='P')
				    	{
			    			if(player2>=250)
		    				{
						     	bank=bank+250;
    					    	player2=player2-250;
	    		     			printf("$250 recieved by Bank.\nYour Current Balance: $%d\nCurrent Bank Balance: $%d\n",player2,bank);
				    		}
				    		else
						    {
						    	printf("Insufficient balance.\nS : Sell a property\n");
					         	scanf("%c",&select4);
						    	if(select4=='s'||select4=='S')
						    	{
						    		if(d>1)
						    		{
						    			printf("Select your property to sell\n");
							   			for(m=0;m<d;m++)
						    			{
							   				printf("%d : $%d\n",m+1,p2[m]);
										}
										scanf("%d",&select5);
										p2[select5-1]=0;
										d=d-1;
										player2=player2+p2[select5-1];
										bank=bank-p2[select5-1];
										for(m=0;m<b;m++)
										{
											if(p2[m]!=0&&p2[m]>400)
				    						printf("%d\n",p2[m]);
										}
									    printf("Property sold to Bank\nYour current balance : $%d\nCurrent bank balance : $%d\n",player2,bank);
									    if(player2>=250)
				                		{
								    		bank=bank+250;
								    		player2=player2-250;
								    		printf("$250 recieved by Bank\nYour Current Balance: $%d\n",player2);
								    		printf("Your Property\n");
								    	
											for(c=0;c<d;c++)
								    		{
								    			if(p2[c]!=0&&p2[c]>400)
												printf("%d\n",p2[c]);
											}
								    		printf("Current Bank Balance: $%d\n",bank);
										}
									}
									if(d==1)
						    		{
										p2[0]=0;
										d=0;
										player2=player2+p2[0];
										bank=bank-p2[0];
										for(m=0;m<b;m++)
										{
											if(p2[m]!=0&&p2[m]>400)
				    						printf("%d\n",p2[m]);
										}
									    printf("Property sold to Bank\nYour current balance : $%d\nCurrent bank balance : $%d\n",player2,bank);
									    if(player2>=250)
				                		{
								    		bank=bank+250;
								    		player2=player2-250;
								    		printf("$250 recieved by Bank\nYour Current Balance: $%d\n",player2);
								    		printf("Your Property\n");
								    	
											for(c=0;c<d;c++)
								    		{
								    			if(p2[c]!=0&&p2[c]>400)
												printf("%d\n",p2[c]);
											}
								    		printf("Current Bank Balance: $%d\n",bank);
										}
									}
									if(d==0)
									{
										printf("No property,No balance\nPlayer 1 wins\n");
										break;
									}			
							    }
						    }
			    		}
					}
				}
			}
		printf("Do you want to continue?\n");
		printf("1: Yes\n2: No\n");
		scanf("%d",&turn);
		if(turn==1)
		{
			continue;
		}
		if(turn==2)
		{
			printf("Game Ended!\n");
			break;
		}
	    }
	}
	else if(select=='Q'||select=='q')
	{
		printf("Game Ended!\n");
	}
	int total1=0,total2=0,i;
	for(i=0;i<b;i++)
	{
		total1=total1+player1+p1[i];
	}
	for(i=0;i<d;i++)
	{
		total2=total2+player2+p2[i];
	}
	if(total1>total2)
	{
		printf("Player 1 Won!\n");
	}
	else if(total2>total1)
	{
		printf("Player 2 Won!\n");
	}
	else
	{
		printf("Tie!\n");
	}
	return 0;
}
