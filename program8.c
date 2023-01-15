#include<stdio.h> 
 #include<stdlib.h> 
 int main() 
 { 
   int n,*p,i, min , max ; 
   printf("\nenter the number of Elements "); 
   scanf("%d",&n); 
   p=(int *)malloc(n*sizeof(int)); 
   if(p==NULL) 
   { 
   printf("error "); 
   exit(0); 
   } 
   else{ 
   printf("\n eneter the Elements"); 
   for(i=0;i<n;i++) 
   scanf("%d",p+i); 
   min=*p; 
   max=*p; 
   for(i=0;i<n;i++) 
   { 
   if(*(p+i) < min) 
   min=*(p+i); 
   if(*(p+i) > max) 
   max=*(p+i); 
   } 
   printf("max : %d \n min : %d",max, min); 
   } 
    
    
   return 0; 
 } 