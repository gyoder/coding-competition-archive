#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define g(x,y) grid[(x)*dim+(y)]
int dim;
char *grid;
char *orig;

void dump(d) int d; {int r,c; printf("\nd=%d\n",d); for(r=0;r<dim;r++) { for(c=0;c<dim;c++) putchar(grid[r*dim+c]); putchar('\n');}}

void final(d) int d; {int r,c; for(r=0;r<dim;r++) { for(c=0;c<dim;c++) printf("%c ",(g(r,c)=='0')?orig[r*dim+c]:grid[r*dim+c]); putchar('\n');}}

int done() {int r,c; int f=1; for(r=0;r<dim;r++) for(c=0;c<dim;c++) f=f&&(!((g(r,c)>'0')&&(g(r,c)<'9'))); return(f);}

void play(d) int d;{
	int r,c;
	int dr,dc;
	int mr,mc;
	int f;
	if(done()) { final(d); exit(0);} 
#ifdef DEBUG
	dump(d);
#endif

	for(r=0;r<dim;r++)
		for(c=0;c<dim;c++) {
			if((g(r,c)>'0')&&(g(r,c)<'9')) {
#ifdef DEBUG
				printf("Try to add a link to %d,%d\n",r,c);
#endif

				for(f=1,dc=(c+1);f&&(dc<(dim-1));dc++) {
					if((g(r,dc)>'0')&&(g(r,dc)<'9')) break;
					f=f&&(g(r,dc)=='.');
					}
				if((dc==dim)||((dc==(dim-1))&&(!((g(r,dc)>'0')&&(g(r,dc)<'9'))))) f=0;
				if(f) {
#ifdef DEBUG
					printf("Add a link from (%d,%d) to (%d,%d)\n",r,c,r,dc);
#endif
					
					if((g(r,c)>'1')&&(g(r,dc)>'1')) {
#ifdef DEBUG
						printf("double H link\n");
#endif
						for(mc=c+1;mc<dc;mc++) grid[r*dim+mc]='=';
						grid[r*dim+c]-=2; grid[r*dim+dc]-=2;
						play(d+1);
						for(mc=c+1;mc<dc;mc++) grid[r*dim+mc]='.';
						grid[r*dim+c]+=2; grid[r*dim+dc]+=2;
					} else {
#ifdef DEBUG
						printf("single H link\n");
#endif
						for(mc=c+1;mc<dc;mc++) grid[r*dim+mc]='-';
						grid[r*dim+c]-=1; grid[r*dim+dc]-=1;
						play(d+1);
						for(mc=c+1;mc<dc;mc++) grid[r*dim+mc]='.';
						grid[r*dim+c]+=1; grid[r*dim+dc]+=1;
					}
				}

				for(f=1,dr=(r+1);f&&(dr<(dim-1));dr++) {
					if((g(dr,c)>'0')&&(g(dr,c)<'9')) break;
					f=f&&(g(dr,c)=='.');
					}
				if((dr==dim)||((dr==(dim-1))&&(!((g(dr,c)>'0')&&(g(dr,c)<'9'))))) f=0;
				if(f) {
#ifdef DEBUG
					printf("Add a link from (%d,%d) to (%d,%d)\n",r,c,dr,c);
#endif
					
					if((g(r,c)>'1')&&(g(dr,c)>'1')) {
#ifdef DEBUG
						printf("double V link\n");
#endif
						for(mr=r+1;mr<dr;mr++) grid[mr*dim+c]='\"';
						grid[r*dim+c]-=2; grid[mr*dim+c]-=2;
						play(d+1);
						for(mr=r+1;mr<dr;mr++) grid[mr*dim+c]='.';
						grid[r*dim+c]+=2; grid[mr*dim+c]+=2;
					} else {
#ifdef DEBUG
						printf("single V link\n");
#endif
						for(mr=r+1;mr<dr;mr++) grid[mr*dim+c]='|';
						grid[r*dim+c]-=1; grid[mr*dim+c]-=1;
						play(d+1);
						for(mr=r+1;mr<dr;mr++) grid[mr*dim+c]='.';
						grid[r*dim+c]+=1; grid[mr*dim+c]+=1;
					}
				}

			}
		}
}
			

main(){
	int r,c;
	scanf("%d",&dim);
#ifdef DEBUG
	printf("dim=%d\n",dim);
#endif
	grid=malloc(sizeof(char)*dim*dim+1);
	orig=malloc(sizeof(char)*dim*dim+1);
	while(getchar()!='\n');
	for(r=0;r<dim;r++)
		for(c=0;c<dim;c++) {
			orig[r*dim+c]=grid[r*dim+c]=getchar(); getchar();
		}
	play(0);
}
