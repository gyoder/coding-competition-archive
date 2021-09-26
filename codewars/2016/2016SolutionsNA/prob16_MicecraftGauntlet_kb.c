#include <stdio.h>
#include <stdlib.h>

#define PUZZLES 20
#define PLAYERS 10
#define BUF 1024

int rules[PLAYERS][PUZZLES];
int sums[PLAYERS];
int points[PUZZLES];
int puzzles=0;
int max=0;
int players=0;

int legal() {
	int i,j;
	int s;
	int f=1;

	for(i=0;f&&(i<players);i++) {
		s=0;
		for(j=1;f&&(j<puzzles);j++)
			if(rules[i][j])
				s+=points[j];
		f=f&&(sums[i]==s);
	}
	return(f);
}

int notIllegal() {
	int i,j;
	int s;
	int f=1;

	for(i=0;f&&(i<players);i++) {
		s=0;
		for(j=1;f&&(j<puzzles);j++)
			if(rules[i][j])
				s+=points[j];
		f=f&&(sums[i]>=s);
	}
	return(f);
}

void dumpCheck() {
	int i,j;
	int s;
	for(j=1;j<puzzles;j++)
		printf("%d ",points[j]);
	printf("\n");
	for(i=0;i<players;i++) {
		printf("\tplayer %d, sum should be %d, sum ",i,sums[i]);
		for(s=0,j=1;j<puzzles;j++)
			if(rules[i][j]) {
				s+=points[j];
				printf(" [%d]%d",j,points[j]);
			}
		printf(" = %d\t%s\n",s,s==sums[i]?"GOOD":"bad");
	}
}

void fixup() {
	int j,k,z;
	int f=0;
	int last=points[1];

	if(!points[1]) {
		for(j=2;!points[j]&&(j<puzzles);j++);
		if(points[j]==1)
			for(k=1;k<j;k++)
				points[k]=points[j];
	}
	for(j=1;j<puzzles;j++) {
		if((!f)&&(!points[j])) z=j;
		if(f&&points[j]&&(points[j]==last))
			for(k=z;k<j;k++)
				if(!points[k])
					points[k]=last;
		if(!(f=!points[j]))
			last=points[j];
		}
}

void dump() {
	int i;
	for(i=1;i<puzzles;i++)
		if(points[i]>0) 
			printf("%d ",points[i]);
		else
			printf("? ");
	printf("\n");
}

play(d) int d; {
	int i,t;

#ifdef DEBUG
	printf("DEBUG: d=%d\t",d);
	dumpCheck();
#endif
	if(legal()) {
		dump();
		fixup();
		dump();
		exit(0);
	}
	if(points[d]) {
		t=points[d];
		if(points[d]<=max)  {
			for(i=d;i<puzzles;i++) 
				if(points[i])
					points[i]++;
			if(notIllegal())
				play(d);
		}
		for(i=d;i<puzzles;i++)
			if(points[i])
				points[i]=t;
		if(d<puzzles)
			play(d+1);
	} else
		if(d<puzzles)
			play(d+1);
}

main(){
	int p;
	int s;
	int i,j,k;
	int v;
	char buf[BUF];
	char *q;

	players=0;
	while(scanf("%d",&sums[players]),sums[players]) {
		for(j=0;j<puzzles;j++) 
			rules[players][j]=0;
#ifdef DEBUG
		printf("sum=%d ",sums[players]);
#endif
		if(max<sums[players]) max=sums[players];
		while(scanf("%d",&v),v) {
#ifdef DEBUG
			printf("%d ",v);
#endif
			rules[players][v]=1;
			if(puzzles<v) puzzles=v;
		}
#ifdef DEBUG
		printf("\n");
#endif
		players++;
	}
#ifdef DEBUG
	printf("There are %d players, %d puzzles, max score=%d\n",players,puzzles,max);
#endif
	puzzles++;
	for(i=0;i<players;i++)
		for(j=1;j<puzzles;j++)
			points[j]=points[j]||rules[i][j];
	play(1);
}
