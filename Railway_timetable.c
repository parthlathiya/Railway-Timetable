#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
 FILE * fp, *fp1;
main ()
{
  char source[20], destination[20], name1[20], name2[20],choice1[20],ans1[20],number1[20];
  int  choice,number, a, b, c;
  char ans;
   
printf ("\n\t\t\t ---------------------------\n");
      
printf ("\t\t\t| Welcome To Indian Railway |\n");
      
printf ("\t\t\t|---------------------------|\n");
      
printf ("\t\t\t|     Search Your Train     |\n");

printf ("\t\t\t --------------------------- \n\n");
  
  do
    {
    label1:
       printf ("\t\t\t1 : Source-Destination station(eg. BANDRA, SURAT)\n");
      printf ("\t\t\t2 : Train Name(eg. SHATABDI EXPRESS)\n");
      printf ("\t\t\t3 : Train Number(eg. 12921)\n");
      printf ("\t\t\t4 : Display All Train Number & Name\n\t\t\t");
      scanf ("%s",choice1);

if(!isdigit(choice1[0])) {
printf("\t\t\tInvalid Input ...\n\n");
goto label1;
}choice=atoi(choice1);

switch (choice)
	
	{
	case 1:
	  printf ("\n\t\t\tEnter Source Station Name : ");
	  scanf ("%s", source);
	  printf ("\n\t\t\tEnter Destination Station Name : ");
	  scanf ("%s", destination);
	  if (!strcmp (source, destination))
	    
	    {
	      printf
		("Sorry !! You entered same source & destination station\n");
	      break;
	    }
	  search1 (source, destination);
	  break;
	case 2:
	  printf ("\n\t\t\tEnter Train Name : ");
	  scanf ("%s %s", name1, name2);
	  search2 (name1, name2);
	  break;
	case 3:
	  printf ("\n\t\t\tEnter Train Number : ");
	  scanf ("%s", number1);
if(!isdigit(number1[0])) {
printf("\t\t\tInvalid Input ...\n\n");
goto label1;
}
number=atoi(number1);
	  search3 (number);
	  break;
	case 4:
	  fp = fopen ("Database2.txt", "r");
	  printf ("\n\t\t\t -----------------------------\n");
	   printf ("\t\t\t| Train  |    Train Name      |\n");
	  printf ("\t\t\t| Number |                    |\n");
	  printf ("\t\t\t|--------|--------------------|\n");
	  
	  do
	    {
	      fscanf (fp, "%d %u %d %s %s", &a, &b, &c, name1, name2);
	      printf ("\t\t\t\t\t\t      |");
	      printf ("\r\t\t\t| %d  | %s %s \n", c, name1, name2);
	    }
	  while (!feof (fp));
	  printf ("\t\t\t -----------------------------\n");
	  fclose (fp);
	  goto label1;
	default:
	  printf ("\t\t\tInvalid Choice\n");
	}
label3:     printf ("\nDo you want to see main-menu(y/n) ? : ");
      scanf ("\n%s", &ans1);
if(!isalpha(ans1[0])) {
printf("\t\t\tInvalid Input ...\n\n");
goto label3;
}
ans=ans1[0];
    }

  while (ans == 'y' || ans == 'Y');
 
}

 search1 (char source[], char destination[]) 
{
  int a, b, e, x = 0, y = 0, i = 0, z, p[10] = { 0 }, g, h;
  char ans1, c[20], d[20],a1[20];
  int r[14][14] = 
    { 
{0, 11, 34, 176, 206, 296, 347, 422, 473, 486, 542, 593, 637, 656}, 
{11, 0, 23, 165, 196, 285, 336, 412, 462, 475, 532, 582, 626, 646}, 
{34, 23, 0, 142, 173, 263, 314, 389, 439, 453, 509, 560, 603, 623}, 
{176, 165, 142, 0, 31, 121, 172, 247, 297, 311, 367, 418, 461, 481}, 
{206, 196, 173, 31, 0, 90, 141, 216, 266, 280, 336, 387, 430, 450}, 
{296, 285, 263, 121, 90, 0, 51, 126, 176, 190, 246, 297, 340, 362}, 
{347, 336, 314, 172, 141, 51, 0, 75, 125, 139, 195, 246, 289, 309}, 
{422, 412, 389, 247, 216, 126, 75, 0, 50, 64, 120, 171, 214, 234}, 
{473, 462, 439, 297, 266, 176, 125, 50, 0, 14, 70, 121, 164, 184}, 
{486, 475, 453, 311, 280, 190, 139, 64, 14, 0, 56, 107, 150, 170}, 
{542, 532, 509, 367, 336, 246, 195, 120, 70, 56, 0, 51, 94, 114}, 
{593, 582, 560, 418, 387, 297, 246, 171, 121, 107, 51, 0, 43, 63}, 
{606, 596, 573, 431, 400, 310, 259, 184, 134, 120, 64, 13, 30, 0} 
};
    fp = fopen ("Database1.txt", "r");
  
  do
    {
      fscanf (fp, "%d %u %s", &a, &b, c);
      i++;
      if (!strcmp (source, c))
	{
	  x = a;
	  g = i;
	}
      else if (!strcmp (destination, c))
	{
	  y = a;
	  h = i;
	}
    }
  while (!feof (fp));
  if (x == 0 && y == 0)
    {
      printf ("Sorry !! Both station is not available in our database\n");
      return;
    }
  if (x == 0)
    {
      printf ("Sorry !! Source station is not available in our database\n");
      return;
    }
  
  else if (y == 0)
    {
      printf
	("Sorry !! Destination station is not available in our database\n");
      return;
    }
  fclose (fp);
  z = x * y;
  fp = fopen ("Database2.txt", "r");
  printf ("\n\n");
  
    //printf("\t\t --------------------------------------------------\n");
    printf ("==> Distance between %s & %s station = %d km.", source,
	    destination, r[g - 1][h - 1]);
  				// printf("\t\t -------------------------------------------------\n");
    printf ("\n\n\t\tAvailable Train Between %s & %s Station\n", source,
	    destination);
  printf
    (" --------------------------------------------------------------------------------\n");
  printf
    ("|Index| Train   |  Train Name       | Arrival | Reach |    Coach Classes         |\n");
  printf
    ("|     | Number  |                   |  Time   | Time  |                          |\n");
  printf
    ("|-----|---------|-------------------|---------|-------|--------------------------|\n");
  i = 0;
  
  do
    {
      fscanf (fp, "%d %u %d %s %s", &a, &b, &e, c, d);
      if (!(b % z))
	
	{
	  complex (source, destination, a, e);
	  printf ("\r|  %d  |  %d  | %s %s\n", i + 1, e, c, d);
	  p[i++] = e;
	}
    }
  while (!feof (fp));
  printf
    (" --------------------------------------------------------------------------------\n\n");
   
  do
    {
label2:      printf ("Which train you want to see ?\nPlease enter index : ");
      scanf ("%s", a1);
if(!isdigit(a1[0])) { 
printf("Invalid Input ...\n\n");
goto label2;
}
a=atoi(a1);
if(a>i || a<=0) {
printf("Invalid index ... \n\n");
goto label2;
}     search3 (p[a - 1]);
      printf ("Do you want to see another train(y/n) ? : ");
      scanf ("\n%c", &ans1);
    }
  while (ans1 == 'y' || ans1 == 'Y');
}

 search2 (char name1[], char name2[]) 
{
  int a, b, c;
  char d[20], e[20], g[20];
   fp = fopen ("Database2.txt", "r");
  
  do
    {
      fscanf (fp, "%d %u %d %s %s", &a, &b, &c, d, e);
      if (!strcmp (name1, d))
	if (!strcmp (name2, e))
	  {
	    fclose (fp);
	    printf ("\n %d - %s %s\n", c, d, e);
	    fp1 = fopen ("Database3.txt", "r");
	    
	    do
	      fscanf (fp1, "%d", &b);
	    while (b != c);
	    fp = fopen ("Database1.txt", "r");
	    printf (" --------------------------\n");
	    
	    do
	      {
		fscanf (fp, "%d %u %s", &b, &c, d);
		if (!(c % a))
		  {
		    fscanf (fp1, "%s %s", e, g);
		    printf ("\t\t | %s : %s |", e, g);
		    printf ("\r|%s\n", d);
		  }
	      }
	    while (!feof (fp));
	    printf (" --------------------------\n\n");
	    fclose (fp);
	    return;
	  }
    }
  while (!feof (fp));
  fclose (fp);
  fclose (fp1);
  printf ("Sorry !! Train is not available in our database\n");
}

 search3 (int n) 
{
  int a, b, c;
  char d[20], e[20], f[20];
   fp = fopen ("Database2.txt", "r");
  
  do
    fscanf (fp, "%d %u %d %s %s", &a, &b, &c, d, e);
  while (n != c && !feof (fp));
  fclose (fp);
  if (n != c)
    {
      printf ("Sorry !! Train is not available in our database\n");
      return;
    }
  printf ("\n %d - %s %s\n", c, d, e);
  fp1 = fopen ("Database3.txt", "r");
  
  do
    fscanf (fp1, "%d", &b);
  while (b != c);
  fp = fopen ("Database1.txt", "r");
  printf (" --------------------------\n");
   
  do
    {
      fscanf (fp, "%d %u %s", &b, &c, d);
      if (!(c % a))
	{
	  fscanf (fp1, "%s %s", e, f);
	  printf ("\t\t | %s : %s |", e, f);
	   printf ("\r|%s\n", d);
	}
    }
  while (!feof (fp));
  printf (" --------------------------\n\n");
   fclose (fp);
  fclose (fp1);
}

 complex (char source[], char destination[], int a, int e) 
{
  int b, c;
  char d[20], f[20], g[20], i[20], h[20];
  FILE * fp1, *fp2, *fp3;
   printf ("\t\t\t\t\t\t\t");
  fp1 = fopen ("Database1.txt", "r");
  fp2 = fopen ("Database3.txt", "r");
  fp3 = fopen ("Database4.txt", "r");
   
  do
    fscanf (fp3, "%s", h);
  while (atoi (h) != e);
  fscanf (fp3, "%s", i);
  while (strcmp (i, "x"))
    
    {
      printf ("%s ", i);
      fscanf (fp3, "%s", i);
    }
  printf ("| ");
  fclose (fp3);
   
  do
    fscanf (fp2, "%d", &b);
  while (b != e);
  
  do
    {
      fscanf (fp1, "%d %u %s", &b, &c, d);
      if (!(c % a))
	{
	  fscanf (fp2, "%s %s", f, g);
	  if (!strcmp (d, destination))
	    {
	      printf ("\r\t\t\t\t\t      | %s:%s |", f, g);
	      break;
	    }
	}
    }
  while (getc (fp1) != -1);
  rewind (fp1);
  rewind (fp2);
  
  do
    fscanf (fp2, "%d", &b);
  while (b != e);
  
  do
    {
      fscanf (fp1, "%d %u %s", &b, &c, d);
      if (!(c % a))
	{
	  fscanf (fp2, "%s %s", f, g);
	  if (!strcmp (d, source))
	    {
	      printf ("\r\t\t\t\t    |  %s:%s ", f, g);
	      break;
	    }
	}
    }
  while (getc (fp1) != -1);
  fclose (fp1);
  fclose (fp2);
}
