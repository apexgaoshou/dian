#include <stdio.h>
const int maxload=4;
 int waitfloor[]={0,0,0,0,0,0,0,0,0,0};
 int desfloor[]={0,0,0,0,0,0,0,0,0,0};
 int lift=1;
 int work=0;
 int pos;
 int des;
 int load=0;
 int direct=1;
 int waittime=0;
 int inlift[2][4];
 int i=0;
 int zhizhen=0;
 int waitdes[10][10];
 int press=1;
 int cnt=0;
 void judgework(int lift){
 	for(pos=0;pos<10;pos++){
 		for(des=0;des<10;des++){
 			if(waitdes[pos-1][des-1]!=0){
 				cnt++;
			 }
			else if (cnt==0&&load==0){
				work=0;
			}
		 }
 		
	 }
 	
 }
 void elevator(int lift){
 	for(i=0;i<4;i++){
 			if(inlift[1][i]!=lift){
 				inlift[0][i]=0;
 				inlift[1][i]=0;
 				
 			}else if(load==0){
 				break;
			 }
			 }
 	while (waitfloor[lift-1]!=0&&load<maxload){
 		for(des=0;des<10;des++){
 			inlift[0][load]=lift;
 			inlift[1][load]=des;
 			waitdes[lift-1][des-1]--;
 			waitfloor[lift-1]--;
 			load++;
 			if(load>=maxload){
 				break;
			 }
		 }
 		
		 }
	 }
 int directjudge(int lift){
 	for(i=0;i<4;i++){
		if (inlift[1][i]!=0){
			direct=inlift[1][i]-lift+direct;
			}
		}
	if(direct<0){
			direct=0;
		}
	else(direct>=0);{
			direct=1;
		}
	return direct;
 }

 int main(){
 while (press==1){
	 printf("你现在所在楼层");
 	 scanf("%d",&pos);
 	 printf("你的目的地所在楼层");
	 scanf("%d",&des); 
 	 printf("还有人请按1否则按0");
 	 scanf("%d",&press);
 	 waitfloor[pos-1]++;
 	 waitdes[pos-1][des-1]++;}
     work=1;
    while (work==1){
    	elevator(lift);
    	if (directjudge(lift)==1){
    		lift--;
		}
		if (directjudge(lift)==0){
			lift++;
		}
    	printf("你现在正在%d",lift);
    	waittime=waittime+load;
    	judgework(lift);
    	
    	
    	
	}
    return 0; 
 	 
 }
