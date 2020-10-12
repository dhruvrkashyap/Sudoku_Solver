#include<iostream>
#include<iomanip>
#include<conio.h>
#include<fstream>
using namespace std;

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

int find_0(char arr[][9],int &i,int &j)                //find an empty element represented by - 
{
	for(int k=0;k<9;k++)
	{
		for(int l=0;l<9;l++)
		{
			if(arr[k][l]==(char)196)
			{
				i=k;
				j=l;
				return 1;
			}
		}
	}
	return 0;
}

int row_check(char arr[][9],int i,int j,char n)        //checks if 'n' can be placed in 'i' row
{
	for(int l=0;l<9;l++)
	{
		if(n==arr[i][l])
		{
			return 0;
		}
	}
	return 1;
}

int col_check(char arr[][9],int i,int j,char n)        //checks if 'n' can be placed in 'j' col
{
	for(int l=0;l<9;l++)
	{
		if(n==arr[l][j])
		{
			return 0;
		}
	}
	return 1;
}

int grid_check(char arr[][9],int i,int j,char n)       //checks if 'n' can be placed in the 3x3 grid
{
	if(j>=0 && j<=2)
	{
		if(i>=0 && i<=2)
		{
			for(int k=0;k<=2;k++)
			{
				for(int l=0;l<=2;l++)
				{
					if(n==arr[k][l])
					{
						return 0;
					}
				}
			}
			return 1;
		}
		else if(i>=3 && i<=5)
		{
			for(int k=3;k<=5;k++)
			{
				for(int l=0;l<=2;l++)
				{
					if(n==arr[k][l])
					{
						return 0;
					}
				}
			}
			return 1;
		}
		else if(i>=6 && i<=8)
		{
			for(int k=6;k<=8;k++)
			{
				for(int l=0;l<=2;l++)
				{
					if(n==arr[k][l])
					{
						return 0;
					}
				}
			}
			return 1;
		}
	}
	else if(j>=3 && j<=5)
	{
		if(i>=0 && i<=2)
		{
			for(int k=0;k<=2;k++)
			{
				for(int l=3;l<=5;l++)
				{
					if(n==arr[k][l])
					{
						return 0;
					}
				}
			}
			return 1;
		}
		else if(i>=3 && i<=5)
		{
			for(int k=3;k<=5;k++)
			{
				for(int l=3;l<=5;l++)
				{
					if(n==arr[k][l])
					{
						return 0;
					}
				}
			}
			return 1;
		}
		else if(i>=6 && i<=8)
		{
			for(int k=6;k<=8;k++)
			{
				for(int l=3;l<=5;l++)
				{
					if(n==arr[k][l])
					{
						return 0;
					}
				}
			}
			return 1;
		}
	}
	
	else if(j>=6 && j<=8)
	{
		if(i>=0 && i<=2)
		{
			for(int k=0;k<=2;k++)
			{
				for(int l=6;l<=8;l++)
				{
					if(n==arr[k][l])
					{
						return 0;
					}
				}
			}
			return 1;
		}
		else if(i>=3 && i<=5)
		{
			for(int k=3;k<=5;k++)
			{
				for(int l=6;l<=8;l++)
				{
					if(n==arr[k][l])
					{
						return 0;
					}
				}
			}
			return 1;
		}
		else if(i>=6 && i<=8)
		{
			for(int k=6;k<=8;k++)
			{
				for(int l=6;l<=8;l++)
				{
					if(n==arr[k][l])
					{
						return 0;
					}
				}
			}
			return 1;
		}
	}
}

int check_all(char arr[][9],int i,int j,char n)          
{
	if(row_check(arr,i,j,n)==1)
	{
		if(col_check(arr,i,j,n)==1)
		{
			if(grid_check(arr,i,j,n)==1)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		else
		{	
			return 0;
		}	
	}
	else
	{
		return 0;
	}
}

int solve_sudoku(char arr[][9])                        //solves the sudoku using reccursive
{
	int i,j;
	if(find_0(arr,i,j)==0)
		return 1;
	else
	{
		for(char n='1';n<='9';n++)
		{
			if(check_all(arr,i,j,n)==0)
			{
				continue;
			}
			else
			{
				arr[i][j]=n;
				if(solve_sudoku(arr)==1)
				{
					return 1;
				}
				arr[i][j]=(char)196;
			}
		}
	}
	return 0;
}


int swap(int &a,int &b)                                //used in moving the cursor from 'a' to 'b'
{
	char t=a;
	a=b;
	b=t;
}

void print(char arr[][9])                              //print the sudoku
{
	cout<<"\n\n";
    cout<<"\t\t";
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
			cout<<arr[i][j];
			if((j+1)%3==0)
				cout<<setw(5);
			else
				cout<<setw(3);
		}
		if((i+1)%3==0)
			cout<<"\n\n";
		else
			cout<<"\n";
		cout<<"\t\t";
    }
}

int main()
{
	char arr[9][9],input;
	int input_sol_or_game,input_difficulty,flag=0;
	int i=0,j=0;
	cout<<"\n\n\t\t1.Play a game of sudoku\n\t\t2.Solve Sudoku\n";
	cout<<"\n\t\tEnter your choice:";
	cin>>input_sol_or_game;
	if(input_sol_or_game==2)                            //to solve sudoku
	{
		for(int k=0;k<9;k++)
		{
			for(int l=0;l<9;l++)
			{
				arr[k][l]=(char)196;					//make an empty 2D array
			}
		}
		arr[i][j]=(char)254;
		system("cls");
	}
	else if(input_sol_or_game==1)                        //to play sudoku
	{
		ifstream fin;
		cout<<"\n\t\t1.Easy\n\t\t2.Medium\n\t\t3.Hard\n";
		cout<<"\n\t\tEnter your choice:";
		cin>>input_difficulty;
		system("cls");
		if(input_difficulty==1)
			fin.open("Easy.txt");
		else if(input_difficulty==2)
			fin.open("Medium.txt");
		else if(input_difficulty==3)
			fin.open("Hard.txt");
		
		for(int k=0;fin;k++)
		{
			fin.getline(arr[k],10,'\n');				//reads the sudoku from file and put it in arr[][]
		}
		fin.close();
		for(int k=0;k<9;k++)
		{
			for(int l=0;l<9;l++)
			{
				if(arr[k][l]=='0')
				{
					arr[k][l]=(char)196;				//repalces the '0' with -
				}
			}
		}
		for(int k=0;k<9;k++)
		{
			for(int l=0;l<9;l++)
			{
				if(arr[k][l]==(char)196)
				{
					i=k;
					j=l;
					arr[i][j]=(char)254;				//places the cursor at first empty block
					flag=1;
					break;
				}
			}
			if(flag==1)
				break;
		}
	}
    
    print(arr);
    char n;
    flag=1;
	int flag_min17=0;									//a sudoku can only be solved if there are atleast 17 number in it
	while(n!='p')
    {
		cout<<"Instructions:\n";
    	cout<<"\tArrow key Up\tmoves upwards\n\tArrow key Down\tmoves downwards\n";
    	cout<<"\tArrow key Left\tmoves left\n\tArrow key Right\tmoves right\n";
    	cout<<"\tE\tenter a digit\n\tS\tsolve sudoku\n";
		n=getch();
		if(!(n=='S' || n=='s' || n=='e' || n=='E'))
			n=getch();
    	switch(n)
    	{
			case KEY_UP:
			//case 'W':									//moves the cursor upwards
			{  
				if(i==0)
				{
					break;
				}
				else if(arr[i-1][j]==(char)196)
				{
					swap(arr[i][j],arr[i-1][j]);
					i--;
				}
				else if(arr[i-1][j]!=(char)196)
				{
					for(int k=i-1;k>=0;k--)
					{
						if(arr[k][j]==(char)196)
						{
							swap(arr[i][j],arr[k][j]);	//finds the first empty position and replaces it with cursor
							i=k;
							break;
						}
					}
				}
				else
				{
					break;
				}
				break;  				
			}
				   
		    case KEY_DOWN:
		    //case 'S':									//moves the cursor downwards
		    {
		    	if(i==8)
				{
					break;
				}
				else if(arr[i+1][j]==(char)196)
		    	{
					swap(arr[i][j],arr[i+1][j]);
		    		i++;
		    	}
		    	else if(arr[i+1][j]!=(char)196)
				{
					for(int k=i+1;k<9;k++)
					{
						if(arr[k][j]==(char)196)
						{
							swap(arr[i][j],arr[k][j]);	//finds the first empty position and replaces it with cursor
							i=k;
							break;
						}
					}
				}
		    	else
		    	{
					break;
				}
				break;
			}
			
			case KEY_RIGHT:
			//case 'D':									//moves the cursor to left
			{
				if(j==8 && i==8)						//cursor is at bottom right 
				{
					if(arr[0][0]!=(char)196)
					{
						break;							//cannot be replaced as first potition is occupied with a number
					}
					swap(arr[i][j],arr[0][0]);
					i=0;
					j=0;
				}
				else if(j==8)
				{
					if(arr[i+1][0]!=(char)196)
					{
						break;
					}
					swap(arr[i][j],arr[i+1][0]);
					i++;
					j=0;
				}
				else if(arr[i][j+1]==(char)196)
				{
				
					swap(arr[i][j],arr[i][j+1]);
					j++;
				}
				else if(arr[i][j+1]!=(char)196)
				{
					for(int l=j+1;l<9;l++)
					{
						if(arr[i][l]==(char)196)
						{
							swap(arr[i][j],arr[i][l]);
							j=l;
							break;
						}
					}
				}
				else 
				{
					break;
				}
				break;
			}
			
			case KEY_LEFT:
			//case 'A':									//moves the cursor to right
			{  
				if(j==0 && i==0)						//cursor is at top left 
				{
					if(arr[8][8]!=(char)196)
					{
						break;							//cannot be replaced as end potition is occupied with a number
					}
					swap(arr[i][j],arr[8][8]);
					i=8;
					j=8;
				}
				else if(j==0)
				{
					if(arr[i-1][8]!=(char)196)
					{
						break;
					}
					swap(arr[i][j],arr[i-1][8]);
					i--;
					j=8;
				}
				else if(arr[i][j-1]==(char)196)
				{
					swap(arr[i][j],arr[i][j-1]);
					j--;
				}
				else if(arr[i][j-1]!=(char)196)
				{
					for(int l=j-1;l>=0;l--)
					{
						if(arr[i][l]==(char)196)
						{
							swap(arr[i][j],arr[i][l]);
							j=l;
							break;
						}
					}
				}
				else 
				{
					break;	
				}
				break;
			}
			
			case 'e':
			case 'E':                                 //takes a digit where the cursor is placed
			{
				cout<<"Enter the digit:";
				cin>>input;
				if(input>'9' || input<'1')
				{
					cout<<"The entered digit is wrong\nPlease enter the digit again\n";
					system("pause");
					break;	
				}
				else if(input=='1')
				{
					arr[i][j]=(char)196;
				}
				if(check_all(arr,i,j,input)==1)
				{
					arr[i][j]=input;
					int k=i;
					int l=j;
					if(k==8 && l==8)
					{
           	        	if(arr[i][j]==(char)196)
						{
							i=0;
           	        		j=0;
           	        		arr[i][j]=(char)254;
           	        	}
           	        	else
           	        	{
           	        		for(k=0;k<9;k++)
							{
								for(l=0;l<9;l++)
								{
									if(arr[k][l]==(char)196)
									{
										i=k;
										j=l;
										arr[i][j]=(char)254;
										l=9;
										k=9;
									}	
								}	
							}
						}
           		    }    
              		else if(l==8 && arr[i+1][0]==(char)196)
                	{
                        i++;
                    	j=0;
						arr[i][j]=(char)254;  
                	}
    				else
					{    
						for(k=i;k<9;k++)
						{
							for(l=j;l<9;l++)
							{
								if(arr[k][l]==(char)196)
								{
									i=k;
									j=l;
									arr[i][j]=(char)254;
									l=9;
									k=9;
								}	
							}
						}
					}
				}
				else
				{
					arr[i][j]=(char)254;
					cout<<"The entered digit is wrong\nPlease enter the digit again\n";
					system("pause");
				}
				break;	
			}
			
			case 's':  
			case 'S':                                 //solves the sudoku by calling solve_sudoku() 
			{
				if(input_sol_or_game==2)
				{
					arr[i][j]=(char)196;
					
					if(solve_sudoku(arr)==1)
					{
						system("cls");
						cout<<"\t\tSolved Sudoku\n";
						print(arr);
						system("pause");
						exit(1);
					}
					else
					{
						arr[i][j]=(char)254;
						n='x';
					}
				}
				else if(input_sol_or_game==1)
				{
					ifstream fin2;
					if(input_difficulty==1)
						fin2.open("Easy-Answer.txt");
					else if(input_difficulty==2)
						fin2.open("Medium-Answer.txt");
					else if(input_difficulty==3)
						fin2.open("Hard-Answer.txt");
					
					for(int k=0;fin2;k++)
					{
						fin2.getline(arr[k],10,'\n');
					}
					system("cls");
					cout<<"\t\tSolution\n";
					print(arr);
					system("pause");
					exit(1);
				}
			}
			
			default:
			{
				break;
			}	
		
		}
		system("cls");
		print(arr);
	}
	system("pause");  	
}
