#include <stdio.h>
#include <conio.h>
void printBoard(char board[][3],int posX,int posY);
int win(char board[][3],int player1cout[],int plyer2count[]) ;

int main()
{
   char board[3][3];
   char playersName [2][10];
   int i,j,posX=0,posY=0,oldposx,oldposy;
   char ch ;
   int result;
   char enterValue ;
   int player = 1;
   int flag=0,player1count[3]={0,0,0},player2count[3]={0,0,0};
   clrscr();
   printf("plesse enter player1 name : "); //get players name
   gets(playersName[0]);
   printf("plesse enter player2 name : ");
   gets(playersName[1]);
   printf("%s with 'X'\n ",playersName[0]);   // give the x and y for players
   printf("%s with 'O' \n",playersName[1]);
   //wateing time tryiet

   //set init state
   for(j=0;j<3;j++)
   {
		board[0][j] ='X';
		board[1][j]= ' ';
		board[2][j] ='O';
   }

   do
   {
		 printBoard(board,posX,posY);
		 gotoxy(10+(posY*8),5+(posX*2));

		 ch = getch();

		 switch(ch)
		 {
			case 13:
				enterValue = board[posX][posY];
				if(player)
				{
					if(enterValue=='X')
					   {
						for(i=0;i<3;i++)
						{
							if(posX==0 && posY==i)
							{
								player1count[i]=1;
							}

						}
						if(flag==0)
						{
								oldposx=posX;
								oldposy=posY;
								board[posX][posY]= ' ';
								flag = 1;

						}
					   }
					else if(enterValue ==' ')
					{
						if(flag ==1)
						{   if(!(oldposx==posX && oldposy==posY)){
								board[posX][posY]='X';
								player=!player;
								flag = 0;
							}
						}
					}
					else
					{
						gotoxy(5,10);
						printf("you cant acess this place");
					}
				}
				else if(!player)
				{

					if(enterValue=='O'){
						for(i=0;i<3;i++)
						{
							if(posX==2 && posY==i)
							{
								player2count[i]=1;
							}
						}
						if(flag==0){
							oldposx=posX;
							oldposy=posY;
							board[posX][posY]= ' ';
							flag = 1;
						}

						}
					else if(enterValue ==' ')
					{
						if(flag ==1)
						{   if(!(oldposx==posX && oldposy==posY)){
								board[posX][posY]='O';
								player=!player;
								flag =0 ;
							}
						}
					}
					else
					{
						gotoxy(5,10);
						printf("you cant acess this place");
					}
				}


				break;

			case NULL :
				ch =getch();
				switch (ch)
				{
					case 72:  //up
						posX-=1;
						if(posX<0)
							posX=2;

						break;
					case 80:      //down
						posX+=1;
						if(posX>2)
							posX=0;
						break;
					case 77:  //right
						posY+=1;
						if(posY>2)
							posY =0;
						break;
					case 75:   //left
						posY-=1;
						if(posY<0)
							posY=2;
						break;
				}
				break;

		 }

   //	player = !player;
	result = win(board,player1count,player2count);
   }
   while(!result);


	clrscr();
	gotoxy(5,5);
	textattr(0x86);
	if(result ==1)
		printf("congratulation %s",playersName[0]);
	else
		printf("congratulation %s",playersName[1]);
	getch();

	return 0 ;
}
 void printBoard(char board[][3],int posX,int posY)
 {     int i,j;
		// print board on screen
		clrscr();
		gotoxy(5,5);
		for(i=0;i<3;i++)
		{

			for(j=0;j<3;j++)
			{

				//textattr(0x07);
				if(i==posX && posY==j)
				{

				  //	textattr(0x82);
				 }

			   printf("\t %c",board[i][j]);
			}
			printf("\n \n");

		}



 }


int win(char board[][3],int player1count[] ,int player2count[])
{
	int result = 0;
	int i;
	for(i=0;i<3;i++)
	{
		if((board[i][0]==board[i][1]&& board[i][0]==board[i][2]) ||
			(board[i][0]==board[i+1][1] && board[i][0]==board[i+2][2])||
			(board[i][2]==board[i+1][1]&& board[i][2]==board[i+2][0] )
			)
		{

			if(board[i][0] == 'X')
			{
				result = 1;
			}
			else if(board[i][0] == 'O')
				result = -1;


		}
		else if (board[0][i]==board[1][i] &&board[0][i]==board[2][i])
		{

			if(board[0][i] == 'X')
				result = 1;
			else if(board[0][i] == 'O')
				result = -1;

		}
	}
		for(i=0;i<3;i++)
		{
			if(result ==1)
			{
				if(player1count[i]==0)
				{
					result = 0;
				}
			}
			else if (result==-1)
			{
				if(player2count[i]==0)
				{
					result = 0;
				}
			}
		}
		return result ;
}
