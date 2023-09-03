iv#include<stdio.h>
#include<math.h>
 
float f(float x,float u, float v){
  return ((1/(sqrt(2*3.14*v)))*exp(-0.5*pow((x-u)/sqrt(v),2)));
}
 

int main()
{
  int n,i,r;
  float a,b,h,x,sum=0,integral;
  float v,u,D;
  
  printf("enter the standard deviation\n");
  scanf("%f",&D);
  v= (D*D);
  printf("the variance is %f \n",v);
 
  printf("enter the mean\n");
  scanf("%f",&u);
    
intervals:    
  printf("\nEnter the no. of sub-intervals: ");
  scanf("%d",&n);
  
  printf("\n");
  printf("For postive infinty limit Enter :- 88\nFor negative infinty limit Enter :- -88\n");
  
  again_initial_limit:
  printf("\nEnter the initial limit: ");
  scanf("%f",&a);
  
  again_final_limit:
  printf("\nEnter the final limit: ");
  scanf("%f",&b);
  
  if(a==88)
  {
      printf("invalid\n");
      goto again_initial_limit;
  }
  else if(b== -88)
  {
      printf("invalid\n");
      goto again_final_limit;
  }
  else if(a== -88)
  {
       if(b>u)
      {
          a=u;
          h=fabs(b-a)/n;
          for(i=1;i<n;i++)
          {
          x=a+i*h;
          sum=sum+f(x,u,v);
          }
          
          integral=0.5 + (h/2)*(f(a,u,v)+f(b,u,v)+2*sum);
          goto end;
      }
      else if(b<u)
      {
          a=b;
          b=u;
          
          h=fabs(b-a)/n;
          for(i=1;i<n;i++)
          {
          x=a+i*h;
          sum=sum+f(x,u,v);
          }
          
          integral=0.5 - (h/2)*(f(a,u,v)+f(b,u,v)+2*sum);
          goto end;
      }
  }
  else if(b == 88)
  {
       if(a>u)
      {
          b=a;
          a=u;
          h=fabs(b-a)/n;
          for(i=1;i<n;i++)
          {
          x=a+i*h;
          sum=sum+f(x,u,v);
          }
          
          integral=0.5 - (h/2)*(f(a,u,v)+f(b,u,v)+2*sum);
          goto end;
      }
      else if(b<0)
      {
         
          b=u;
          
          h=fabs(b-a)/n;
          for(i=1;i<n;i++)
          {
          x=a+i*h;
          sum=sum+f(x,u,v);
          }
          
          integral=0.5 + (h/2)*(f(a,u,v)+f(b,u,v)+2*sum);
          goto end;
      }
  }
  
  h=fabs(b-a)/n;
  for(i=1;i<n;i++){
    x=a+i*h;
    sum=sum+f(x,u,v);
  }
  integral=(h/2)*(f(a,u,v)+f(b,u,v)+2*sum);
  end:
  printf("\nThe integral is: %f\n",integral);
  
   printf("\n");
  printf("For Re-enter the no. of sub-intervals Enter 1\nEnter 2:- for no\n");
  scanf("%d",&r);
  if(r==1)
  {
      goto intervals;
  }else if(r==2) 
  {
       printf("=========================================================================\n");
		     printf("                             THANK YOU\n");
  }

return 0;
}
