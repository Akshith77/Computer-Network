#include<stdio.h>
#include<string.h>
int main()
{
  int AB,AG,BC,BE,EF,CD,CF,FH,HD,GE,GH,min=99999,path1,path2,path3,path4,path5,path6,path7;
  char s[50];
  printf("      *** DIJKSTRA ALGORITHM ***     ");
  printf("\nEnter the length of AB: ");
  scanf("%d",&AB);
  printf("\nEnter the length of AG: ");
  scanf("%d",&AG);
  printf("\nEnter the length of BC: ");
  scanf("%d",&BC);
  printf("\nEnter the length of BE: ");
  scanf("%d",&BE);
  printf("\nEnter the length of EF: ");
  scanf("%d",&EF);
  printf("\nEnter the length of CD: ");
  scanf("%d",&CD);
  printf("\nEnter the length of CF: ");
  scanf("%d",&CF);
  printf("\nEnter the length of FH: ");
  scanf("%d",&FH);
  printf("\nEnter the length of HD: ");
  scanf("%d",&HD);
  printf("\nEnter the length of GE: ");
  scanf("%d",&GE);
  printf("\nEnter the length of GH: ");
  scanf("%d",&GH);
  printf("\nPath1: A->B->C->D");
  path1=AB+BC+CD;
  printf("\nTotal distance covered in path1: %d",path1);
  if(min>path1)
  {
      min=path1;
      strcpy(s,"A->B->C->D");
   }   
  printf("\nPath2: A->B->C->F->H->D");
  path2=AB+BC+CF+FH+HD;
  printf("\nTotal distance covered in path2: %d",path2);
  if(min>path2)
  {
      min=path2;
      strcpy(s,"A->B->C->F->H->D");
  }  
  printf("\nPath3: A->B->E->F->C->D");
  path3=AB+BE+EF+CF+CD;
  printf("\nTotal distance covered in path3: %d",path3);
  if(min<path3)
  {
      min=path3;
      strcpy(s,"A->B->E->F->C->D");
  }   
  printf("\nPath4: A->B->E->F->H->D");
  path4=AB+BE+EF+FH+HD;
  printf("\nTotal distance covered in path4: %d",path4);
  if(min>path4)
  {
      min=path4;
      strcpy(s,"A->B->E->F->H->D");
  }    
  printf("\nPath5: A->G->H->D");
  path5=AG+GH+HD;
  printf("\nTotal distance covered in path5: %d",path5);
  if(min>path5)
  {
      min=path5;
      strcpy(s,"A->G->H->D");
  }   
  printf("\nPath6: A->G->E->F->C->D");
  path6=AG+GE+EF+CF+CD;
  printf("\nTotal distance covered in path6: %d",path6);
  if(min>path6)
  {
      min=path6;
      strcpy(s,"A->G->E->F->C->D");
  } 
  printf("\nPath7: A->G->E->F->H->D");
  path7=AG+GE+EF+FH+HD;
  printf("\nTotal distance covered in path7: %d",path7);
  if(min>path7)
  {
      min=path7;
      strcpy(s,"A->G->E->F->H->D");
  }
  printf("\nThe shortest path is %s with distance : %d",s,min);
  return 0;
}