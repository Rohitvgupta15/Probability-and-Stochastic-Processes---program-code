#include <stdio.h>
#include <stdlib.h>
//  ROHIT VIJAY GUPTA ( 21EL044 )
int main() {
    
	int n,i,z,d1,d2;
	float a,b=0,p=0;
	int Na, Nb;
	float N1;
	float Pa, Pb , PxX[n+2];
	int nx1[n+2],nx2[n+2];
	nx1[6]=nx1[7]=0.00;
	nx2[1]=0.00;
	nx2[2]= 0.00;
	int t[n+2];
	float PxyxA[n+2],PxyxB[n+2];
	PxyxA[6]=PxyxA[7]=0.00;
	PxyxB[1]=PxyxB[2]=0.00;
	
	float PyxAx[n+2],PyxBx[n+2];
	PyxAx[6]=PyxAx[7]=0.00;
	PyxBx[1]=PyxBx[2]=0.00;
	
    float a1[n+2],b1[n+2];
	char ML[n+2],MAP[n+2];
	restart:
	printf("enter number of term\n");  // number of term
	scanf("%d",&n);
	
	
	
	   
	   
	  printf("enter the denomintor for type A\n");
	  scanf("%d",&d1);
	  typeAagain:
	   a=0;
	   printf("enter value in type A\n"); // term in type a
	   
     	for(i=1;i<=n;i++)
     	{
     	    printf("%d) ",i);
     		scanf("%f",&a1[i]);
     		a=a+a1[i];
     		PxyxA[i] =(float) a1[i] / d1;
     		
     	}
		 if(a==d1)
		 {   printf("\n");
		     printf("PxyxA\n\n");
		     for(i=1;i<=n;i++)
		 {
		    
		    printf("%d) ",i);
		 	printf("%.3g",PxyxA[i]);
		 	printf("\n");
		 }
		 printf("\n");
		     goto typeB;
		     
		 }
		 else 
		 {
		     printf("invalid input as it doesnt sum to 1\n");
		     goto typeAagain;
		     
		 }
		 
		  
		 typeB :
		 
		 b=0;
		 
		 printf("enter the denomintor for type B\n");
	     scanf("%d",&d2);
	typeBagain:
		  printf("enter value in type B\n");   // term in type b
     	for(i=3;i<=n+2;i++)
     	{    printf("%d) ",i-2);
     		scanf("%f",&b1[i]);
     		b=b+ b1[i];
     		PxyxB[i] =(float) b1[i] / d2;
     	 }
     
		 if(b==d2)
		 { 
		     printf("PxyxB\n\n");
		     for(i=3;i<=n+2;i++)
		 {
		    
		    printf("%d) ",i-2);
		 	printf("%.3g",PxyxB[i]);
		 	printf("\n");
		 }
		     goto cont_to_Na;
		     
		 }
		 else 
		 {
		     printf("invalid input as it doesnt sum to 1\n");
		     goto typeBagain;
		     
		 }
		 
		 
		 cont_to_Na :
		 // 	printf("%f   %f\n",PxyxA[1],PxyxA[3]);
		 printf("enter Na\n");
		 scanf("%d",&Na);
		 
		 printf("enter Nb\n");
		 scanf("%d",&Nb);
		 
		 N1 = Na + Nb;
		 
		 again_PaPb:
		 again:
		 p=0;
		 printf("enter the probability of type A and B\n");
		 scanf("%f  \n%f",&Pa,&Pb);
		 
// 		 Pa = Na / (N1);
// 		 Pb = Nb / ( N1);
		 
		  //printf("Pa= %f  \nPb=%f\n",Pa,Pb);
		  p=Pa+Pb;
		  if(p==1)
		  {
		      goto xyz;
		  }
		  else
		  {
		      printf("invalid input as sum is not 1\n");
		      goto again_PaPb;
		  }
		  
		  xyz:
		//printf("%f   %f\n",PxyxA[1],PxyxA[3]);
		 for( i=1;i<=n;i++)
		 {
		    nx1[i]=PxyxA[i]*Na;
		    
		 }
		 for(i=3;i<=n+2;i++)
		 {
		 	nx2[i]=PxyxB[i]*Nb;
		 }	
		printf("Nx1      Nx2  \n");
		 for(i=1;i<=n+2;i++)
		 {
		 
		 	printf("%d       %-8d",nx1[i],nx2[i]);
		 	
		 	printf("\n");
		 }
		 printf("\n");
		 printf("total T\n");
		 for(i=1;i<=n+2;i++)
		 {
		 	t[i]=nx1[i]+nx2[i];
		 }
		 
	     for(i=1;i<=n+2;i++)
		 {
		 	printf("%d" ,t[i]);
		 	
		 	printf("\n");
		 }
		 
// 		 N1 = Na + Nb;
		 
		 for(i=1;i<=n+2;i++)
		 {
		 	PxX[i] = t[i]/N1;
		 }
		 	printf("\n");
		 printf("x   Nx1     Nx2      T        PxX\n");
		 
		 for(i=1;i<=n+2;i++)
		 {
		 printf("%d    %-3d    %-5d    %-5d    %-5.3g\n",i,nx1[i],nx2[i],t[i],PxX[i]);
		 }
		 printf("\n");
		 printf("PyxAx\n");
		 for(i=1;i<=n;i++)
		 {
		 PyxAx[i]=(Pa * PxyxA[i])/PxX[i];
		 }
		 for(i=1;i<=n+2;i++)
		 {
		 printf("%.3f\n",PyxAx[i]);
		 }
		 printf("\n");
		 printf("PyxBx\n");
		 for(i=3;i<=n+2;i++)
		 {
		 PyxBx[i]=(Pb * PxyxB[i])/PxX[i];
		 }
		 for(i=1;i<=n+2;i++)
		 {
		 printf("%.3f\n",PyxBx[i]);
		 }
		 printf("\n");
		 
		 for(i=0;i<=n+2;i++)
		 {
		 if(PxyxA[i] > PxyxB[i])
		 {
		     ML[i]='A';
		 }
		 else if(PyxAx[i] < PyxBx[i])
		 {
		     ML[i] = 'B';
		 }
		 else
		 {
		     ML[i] = '=';
		 }
		 }
		 
		 
		 for(i=0;i<=n+2;i++)
		 {
		 if(PyxAx[i] > PyxBx[i])
		 {
		     MAP[i]='A';
		 }
		 else if(PyxAx[i] < PyxBx[i])
		 {
		     MAP[i] = 'B';
		 }
		 else
		 {
		     MAP[i] = '=';
		 }
		 }
		 printf("=========================================================================\n");
		 
		 printf("x   PxyxA        PxyxB        PyxAx        PyxBx        ML           MAP\n \n");
		 
		 for(i=1;i<=n+2;i++)
		 {
		 printf("%d \t %-8.2g \t %-8.2g \t %-8.2g \t %-8.2g \t     %-8c  \t  %-8c",i,PxyxA[i],PxyxB[i],PyxAx[i],PyxBx[i],ML[i],MAP[i]);
		     printf("\n");
		 }
		 printf("=========================================================================\n\n");
		 
		 printf("enter different value of Pa and Pb\n");
		 printf("1) Enter 1 :- for yes\n2) Enter 2 :- For restart with another value \n3) Enter 3 :- for no\n");
		 scanf("%d",&z);
		 if(z==1)
		 {
		     goto again;
		 }
		 else if(z==2)
		 {
		     goto restart;
		 }
		 else
		 {
		     printf("=========================================================================\n");
		     printf("                             THANK YOU\n");
		 }
		
	return 0;
}
