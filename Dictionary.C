#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <dos.h>
#include <graphics.h>

typedef struct node
{
 char word[25],meaning[100];
 struct node *left,*right;
}node;

node *maketree(char[],char[]);

node* treefromfile();

void filefromtree(node*);

void addword(node*,char[],char[]);

void change(node *,char[],char[]);

void seperateword(char[],char[],char[]);

void displayall(node*);

node* csearch(node* ,char[]);

void intro();

void prog();

void travandwrite(node *);

void first();

void frame();

int showmenu();

void end();

FILE *file_ptr;


void first()
{
	int i,j,k;
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"c:\\tc\\bgi");

	setbkcolor(BROWN);
	setcolor(RED);
	settextstyle(1,0,8);
	outtextxy(130,50,"_-~Search~-_");
	setcolor(RED);
	settextstyle(1,0,8);
	outtextxy(10,190,"_-~For Me~-_");
	settextstyle(7,0,3);
	setcolor(RED);
	setcolor(10);
	outtextxy(470,350,"Made By:");

	setcolor(10);
	outtextxy(260,370,"1.Anupam Kumar (9502903)");
	outtextxy(260,390,"2.Monika Tanwar(9502936)");
	outtextxy(260,410,"3.Shilpi Rai   (9502917)");
	setcolor(4);

	for(k=0;k<640;k++)
	{
	    if(k==635)
		{
		     for(j=0;j<480;j++)
			  {
			      circle(635,j,4);
			      delay(1);
			  }
		}
	    else
		{
		     circle(k,5,5);
		     delay(1);
		}
	}

	for(k=639;k>(-1);k--)
	     {
		  if(k==0)
		      {
			   for(j=475;j>0;j--)
				{
				    circle(5,j,5);
				    delay(1);
				 }
	     }
	 else
	      {
		   circle(k,475,4);
		   delay(1);
	      }
	}

	getch();
	restorecrtmode();
}


// function for the end screen...

void end()
{
	int i,j,k;
	int gd=DETECT,gm;

	initgraph(&gd,&gm,"c:\\tc\\bgi");

	setbkcolor(BROWN);
	setcolor(RED);
	settextstyle(1,0,8);

	outtextxy(130,50,"_-~Search~-_");
	setcolor(RED);
	settextstyle(1,0,8);
	outtextxy(10,190,"_-~For me~-_");
	settextstyle(7,0,3);
	setcolor(RED);
	setcolor(10+BLINK);
	outtextxy(300,300,"THANK YOU");
	setcolor(10);
	outtextxy(300,355,"Have a nice day.....");
	setcolor(4);

	for(k=0;k<640;k++)
	{
	    if(k==635)
		{
		     for(j=0;j<480;j++)
			  {
			      circle(635,j,4);
			      delay(1);
			  }
		}
	    else
		{
		     circle(k,5,5);
		     delay(1);
		}
	}

	for(k=639;k>(-1);k--)
	     {
		  if(k==0)
		      {
			   for(j=475;j>0;j--)
				{
				    circle(5,j,5);
				    delay(1);
				 }
	     }
	 else
	      {
		   circle(k,475,4);
		   delay(1);
	      }
	}

	restorecrtmode();
}

/// declaring structure to store password...

struct stack
{
 char pass[10];
 int top;
};

void push(struct stack *,char);

char pop(struct stack*);

void initstack(struct stack *);

void main()
{
 char pass[10],npass[10],c,p[10];
 char *cp;
 struct stack s;
 int i,j,k;
 int gd=DETECT,gm;

 FILE *fpass;

 clrscr();

 fpass=fopen("c:\\password.txt","r");

 //first();

 initgraph(&gd,&gm,"c:\\tc\\bgi");

 rectangle(10,405,430,550);
 rectangle(30,415,480,575);

 setcolor(GREEN);
 settextstyle(4,0,4);
 outtextxy(200,350,"_-~ Search for me... ~-_");
 settextstyle(7,0,3);
 setcolor(BROWN);
 /*
 if(fpass==NULL)
    {
     printf("no password exist...\n\n");
     printf("\n\t\tset a new password\n\n");
     printf("enter password:");
     scanf("%d",pass);

     for(*cp=pass[0];*cp!='\0';cp+1)
      j++;
     printf("%d",j);

     for(k=0;k<4;k++)
      {
       printf("%c",pass[k]);
       push(&s,pass[k]);
      }

     fpass=fopen("c:\\password.txt","w");

     for(k=0;k<4;k++)
      {
       c=pop(&s);
       fprintf(fpass,"%c",c);
      }
      fclose(fpass);
    }

 fpass=fopen("c:\\password.txt","r");

 for(k=0;!feof(fpass);k++)
  {
   fscanf(fpass,"%c",npass[k]);

  }


 fclose(fpass);

 printf("\t Enter password  :");
 scanf("%s",&p);
 */
 if(1)
  {
   //intro();

   prog();

   getch();
  }
 else
   {
    end();
   // exit(1);
   }


}

void initstack(struct stack *s)
{
 s->top=-1;
}


///storing password on stack...

void push(struct stack *s,char data)
{
 if(s->top==4)
   {
    printf("\n\tpassword can not be more than 4 charaters\n\n");
    return;
   }

 s->top++;
 s->pass[s->top]=data;

}

///poping characters of password from stack...
char pop(struct stack *s)
{
 char data;

 if(s->top==-1)
  {
   //printf("no password stored");
   return NULL;

  }

 s->top--;
 data=s->pass[s->top];
 return data;
}

///function to perform user's task's...

void prog()
{
 char word[25],meaning[100],hword[25];
 int menuchoice,rep,l,h;
 node *temp;
 node *t;
 FILE *fp;

 clrscr();

 temp=treefromfile();

 if(temp==NULL)
   {
    printf("File does not exist or dictionary is empty...");
    getch();
   }
 while(1)
   {
    clrscr();
    menuchoice=showmenu();

   // scanf("%d",&menuchoice);

    switch(menuchoice)
      {
	case 1:{
		frame();
		printf("\nEnter word : \n");
		scanf("%s",word);
		printf("\nEnter meaning : " );
		flushall();
		gets(meaning);

		if(temp==NULL)
		  {
		   temp=maketree(word,meaning);
		  }
		else
		  {
		   addword(temp,word,meaning);
		  }
		break;
		}
	case 2:{
		frame();
		if(temp==NULL)
		  {
		   printf("\nThe dictionary is empty...\n");
		  }
		else
		  {
		   printf("\nFind meaning of : \n");
		   flushall();
		   gets(word);
		   t=csearch(temp,word);

		   if(t==NULL)
		     {
		      printf("\nWord not found...\n");
		      printf("\nDo you want to add this word to database: \n1>yes\n2>No\n");

		      scanf("%d",&rep);

		      if(rep==1)
			{
			 frame();
			 printf("\nEnter word : %s\n",word);
			 //scanf("%s",word);
			 printf("\nEnter meaning : " );
			 flushall();
			 gets(meaning);

			 if(temp==NULL)
			   {
			    temp=maketree(word,meaning);
			   }
			 else
			   {
			    addword(temp,word,meaning);
			   }
			 }
		      else
			{
			 printf("\nReturning to main menu...\n");
			}
		      }
		   else
		     {
		      printf("\n%s : ",t->word);
		      puts(t->meaning);
		     }
		  }
		getch();
		break;
		}
	case 3:{
		frame();
		if(temp==NULL)
		   printf("Dictionary is empty...");
		else
		   displayall(temp);
		getch();
		break;
		}
	case 4:{
		clrscr();
		printf("\n\n\tEnter word: ");
		scanf("%s",word);
		printf("\n\tEnter meaning: ");
		gets(meaning);
		change(temp,word,meaning);
		break;
	       }
	case 5:
	       {
		clrscr();
		frame();

		printf("\nHow many last searched words to be displayed:");
		scanf("%d",&h);

		fp=fopen("c:\\history.txt","r" );

		if(fp==NULL)
		  {
		   printf("\nUnable to read history file...\n");
		   printf("\n\n\tThere is no history of searched words...\n");
		  }
		else
		  {
		    gotoxy(1,20);
		    for(l=0;l<15;l++)
		      {
		       printf("||||");
		      }
		    gotoxy(1,1);
		    printf("\n\t\tHISTORY\n\n");
		    printf("\nLast %d words which were searched are:\n\n",h);

		    for(l=0;l<h;l++)
		     {
			fscanf(fp,"%s",hword);
			printf("\t%d>\t%s",l+1,hword);

		     }
		   }
	       fclose(fp);
	       getch();
	       break;
	       }
	case 6:{
		filefromtree(temp);

		end();

		exit(1);

		break;
	       }
	default:{
		  printf("Wrong!! Enter Again");
		  delay(1000);
		  prog();
		  break;
		}
  }
 }
}


int showmenu()
{
	int gd=DETECT, gm;
	int i,j;
	int k;

	initgraph(&gd,&gm,"c:\\tc\\bgi");

	setbkcolor(YELLOW);
	setcolor(BROWN);

	rectangle(120,85,490,385);
	rectangle(130,95,500,395);

	setcolor(GREEN);
	settextstyle(4,0,4);
	outtextxy(110,35,"_-~ Search for me... ~-_");
	settextstyle(7,0,3);
	setcolor(BROWN);
	outtextxy(180,105,"ENTER YOUR CHOICE:");
	settextstyle(2,0,0);
	setcolor(BROWN);
	outtextxy(230,145,"[1].	Add a word. ->");
	outtextxy(230,170,"[2].	Find meaning. ->");
	outtextxy(230,195,"[3].	Display all. ->");
	outtextxy(230,220,"[4]. Change meaning of a word.->");
	outtextxy(230,245,"[5]. Display History.->");
	outtextxy(230,270,"[6]. Save and Close,->");
	outtextxy(230,295,"Enter choice... ->");
	gotoxy(250,300);
	scanf("%d",&k);

	for(i=0;i<636;i++)
	{
	    if(i==635)
		{
		     for(j=0;j<480;j++)
			  {
			      circle(635,j,4);
			      delay(1);
			  }
		}
	    else
		{
		     circle(i,5,5);
		     delay(1);
		}
	}

	for(i=639;i>(-1);i--)
	     {
		  if(i==0)
		      {
			   for(j=475;j>0;j--)
				{
				    circle(5,j,5);
				    delay(1);
				 }
		       }
		  else
		       {
			   circle(i,475,4);
			   delay(1);
			}
	  }
	restorecrtmode();

	return (k);

}


node* treefromfile()
{
 node *ptree=NULL;
 char word[25],meaning[100],str[120],*i;
 int flags=0;
 file_ptr=fopen("C:\dict.txt","r");

 if(file_ptr==NULL)
    ptree=NULL;
 else
   {
     while(!feof(file_ptr))
       {
	i=fgets(str,120,file_ptr);

	if(i==NULL)
	   {
	    break;
	   }
	seperateword(str,word,meaning);

	if(flags==0)
	  {
	   ptree=maketree(word,meaning);
	   flags=1;
	  }
	else
	   {
	    addword(ptree,word,meaning);
	   }
   }

 fclose(file_ptr);
 }

 return ptree;

}

node* maketree(char w[],char m[])
{
 node *p;
 p=(node*)malloc(sizeof(node));

 strcpy(p->word,w);
 strcpy(p->meaning,m);

 p->left=NULL;
 p->right=NULL;

 return p;

}


void seperateword(char str[],char w[],char m[])
{
 int i,j;

 for(i=0;str[i]!=' ';i++)
  {
   w[i]=str[i];
  }

 w[i++]=NULL;	//Append the null and skip the space.

 for(j=0;str[i]!=' ';i++,j++)
  {
   m[j]=str[i];
  }

 m[j]=NULL;

}

void addword(node *tree,char word[],char meaning[])
{
 node *p,*q;

 p=q=tree;

 while(strcmp(word,p->word)!=0 && p!=NULL)
 {
  q=p;

  if(strcmp(word,p->word)<0)
    {
     p=p->left;
    }
  else
    {
     p=p->right;
    }
 }

 if(strcmp(word,q->word)==0)
   {
    printf("This word already exists...");
    delay(1000);
   }
 else{
      if(strcmp(word,q->word)<0)
	 {
	  q->left=maketree(word,meaning);
	 }
      else
	 {
	  q->right=maketree(word,meaning);
	 }
     }
}

void change(node *tree,char word[],char meaning2[])
{
 node *p,*q;
 char copy[120],mean[40];
 int k;
 p=q=tree;

 if(p==NULL)
  {
   printf("\nThere is no word to change its meaning...\n");
  }


 if(strcmp(word,q->word)==0)
   {
    printf("\nThis word already exists...\n");
    //delay(1000);
    printf("\nDo you want to :\n \t1>Change meaning\n\t2>Add new meaning\n");
    scanf("%d",&k);

    switch (k)
     {case 1:
	     {
	      printf("enter new meaning:\n");
	      //strcpy(q->meaning,NULL);
	      gets(q->meaning);
	      break;
	     }
      case 2:
	     {
	      strcpy(copy,meaning2);
	      printf("add meaning:");
	      gets(mean);
	      //strcpy(q->meaning,NULL);
	      strcat(copy, mean);
	      strcpy(q->meaning,copy);
	      break;
	     }
      default:
	      {
	       printf("\n\tWrong choice entered");
	       printf("\n\tReturning to main menu...\n");
	      }
     }
   }

}

node* csearch(node *tree,char word[])
{
 node *q;
 FILE *fp;

 fp=fopen("c:\\history.txt","r");
 fclose(fp);
 fp=fopen("c:\\history.txt","a");
 fprintf(fp,"%s\t",word );
 fclose(fp);

 q=tree;

 while(q!=NULL)
   {
    //p=q;
    if(strcmp(word,q->word)<0)
      {
       q=q->left;
      }
    else
      {
       if(strcmp(word,q->word)>0)
	  {
	   q=q->right;
	  }
      }

    if(strcmp(word,q->word)==0)
	  {
	    break;
	  }

   }

 return q;

}

void filefromtree(node *tree)
{

 file_ptr=fopen("C:\dict.txt","w");

 if(file_ptr==NULL)
   {
    printf("Cannot open file for writing data...");
   }
 else //if(tree==NULL)
   {
    if(tree!=NULL)
      {
       travandwrite(tree);
      }
    fclose(file_ptr);  //Close the file anyway.
   }
}


void travandwrite(node *tree)
{
 if(tree!=NULL)
   {
    fprintf(file_ptr,"%s %s\n",tree->word,tree->meaning);

    travandwrite(tree->left);
    travandwrite(tree->right);
   }
}


void displayall(node *tree)
{
 if(tree!=NULL)
   {
    displayall(tree->left);
   // cprintf(" ",0);
    printf("%s : %s\n",tree->word,tree->meaning);
    displayall(tree->right);
   }
}

void intro()
{
 int i;
 clrscr();
 gotoxy(20,20);
 printf("DATABASE LOADING");

 for(i=0;i<50;i++)
   {
    gotoxy(15+i,21);
    printf("***");
    gotoxy(20,22);
    printf("%d percent completed",2*i);
    delay(150);
   }
 gotoxy(20,20);
 printf("DATABASE LOADING COMPLETED");

 clrscr();

}

void frame()
{
	int x,y,i,j;
	clrscr();
	x=0;
	y=0;
	for(i=0;i<78;i++)
	{
		gotoxy(x,y);
		textcolor(YELLOW);
		cprintf("%c",205);
		x++;
	}
	x=0;
	y=25;
	for(i=0;i<80;i++)
	{
		gotoxy(x,y);
		textcolor(YELLOW);
		cprintf("%c",205);
		x++;
	}

	x=79;
	y=1;
	for(i=0;i<25;i++)
	{
		gotoxy(x,y);
		textcolor(YELLOW);
		cprintf("%c",186);
		y++;
	}
	gotoxy(79,1);
	cprintf("%c",187);
	gotoxy(79,25);
	cprintf("%c",188);
	gotoxy(1,2);
}

