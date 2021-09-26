#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define BUF 1024
/* #define g(x,y) grid[(x)*c+(y)] */

#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3

int r,c;
char dirs[] = "NESW";
int dir;
char *grid;
int characters=0;

int g(x,y) int x,y; {return(grid[x*c+y]);}


void dump(dr,dc) int dr,dc; { int i,j; printf("(%d,%d) dir=%c\n",dr,dc,dirs[dir]); for(i=0;i<r;i++) {for(j=0;j<c;j++) putchar(g(i,j)); putchar('\n'); } } 

main(){
int i,j,k; char buf[1024]; int dc,dr; int f; 

scanf("%d %d",&r,&c);
while(getchar()!='\n');
#ifdef DEBUG
printf("%d rows, %d columns\n",r,c);
#endif

grid=malloc(sizeof (char)*r*c+1);
j=0;
for(i=0;i<r;i++) {
 fgets(buf,BUF-1,stdin);
#ifdef DEBUG
 printf("buf=\"%s\"\n",buf);
#endif
 for(k=0;buf[k]!='\n';k++)
  if(isalpha(grid[j++]=buf[k])) characters++;
}
grid[j]='\0';

#ifdef DEBUG
printf("%s\n",grid);
printf("%d characters\n",characters);

for(dr=0;dr<r;dr++)  {
 for(dc=0;dc<c;dc++)
	 printf("(%d,%d)=\'%c\'\n",dr,dc,g(dr,dc)); 
	 putchar(g(dr,dc));
 putchar('\n');
}
#endif

f=0;
dir=-1;

if(!f) 
for(i=0;(!f)&&(i<(r-1));i++)
 for(j=0;(!f)&&(j<(c-1));j++) {
#ifdef DEBUG
	 printf("checking:\n%c%c\n%c%c\n\n",g(i,j), g(i,j+1),g(i+1,j),g(i+1,j+1));
#endif
  if(f=f||((g(i,j)==' ')&&(isalpha(g(i+1,j)))&&(g(i+1,j+1)==' ')&&(g(i,j+1)==' ')))
   {dir=WEST;  dr=i+1;dc=j;break;}
  if(f=f||((isalpha(g(i,j)))&&(g(i+1,j)==' ')&&(g(i+1,j+1)==' ')&&(g(i,j+1)==' ')))
   {dir=NORTH; dr=i;dc=j;break;}
  if(f=f||((g(i,j)==' ')&&(g(i+1,j)==' ')&&(g(i+1,j+1)==' ')&&(isalpha(g(i,j+1)))))
   {dir=EAST;  dr=i;dc=j+1;break;}
  if(f=f||((g(i,j)==' ')&&(g(i+1,j)==' ')&&(isalpha(g(i+1,j+1)))&&(g(i,j+1)==' ')))
   {dir=SOUTH; dr=i+1;dc=j+1;break;}
 }

if(!f) {printf("Couldn't find start\n"); exit(1);}
#ifdef DEBUG
printf("Start is at %d,%d[%c], direction %c\n",dr,dc,g(dr,dc),dirs[dir]);
#endif

while(characters) {
#ifdef DEBUG
	dump(dr,dc); 
#endif
	putchar(g(dr,dc)); 
	grid[dr*c+dc]='.';
	characters--;
	switch(dir) {

	 case WEST :
	  if(isalpha(g(dr-1,dc)) || (dc==0)) {
		  dir=NORTH;
		  dr--;
		  }
	  else 
		  dc--;
	  break;

	 case NORTH :
	  if(isalpha(g(dr,dc+1)) || (dr==0)) {
		  dir=EAST;
		  dc++; 
		  }
	  else 
		  dr--;
	  break;

	 case EAST :
	  if(isalpha(g(dr+1,dc)) || (dc==(c-1))) {
		  dir=SOUTH;
		  dr++; 
		  }
	  else 
		  dc++;
	  break;

	 case SOUTH :
	  if(isalpha(g(dr,dc-1)) || (dr==(r-1))) {
		  dir=WEST;
		  dc--; 
		  }
	  else 
		  dr++;
	  break;

}

}
putchar('\n');
}
