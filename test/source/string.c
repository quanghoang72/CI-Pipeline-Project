#include <stdio.h>
#include <assert.h>
#include "my_string.h"
#include <stdlib.h>
#include <string.h>
int my_strlen(char *s){
	int i=0;
	if(!s) return -1;
	while(*(s+i)!='\0'){    // increase i=length of string if it is not end
		i++;
	}
	return i;

}
int str2upper(char *s){
	int i=0,change=0;
	while(*(s+i)!='\0'){
		if(*(s+i)>='a'&&*(s+i)<='z') {*(s+i)-='a'-'A';change++;} //ascii
	i++;
	}
	return change;
}
int str2lower_(char *s){
	int i=0,change=0;
	while(*(s+i)!='\0'){
		if(*(s+i)>='A'&&*(s+i)<='Z') {*(s+i)+='a'-'A';change++;} //ascii
	i++;
	}
	return change;
}
int str_strip_numbers( char *s){
	int i=0;
	int j=0;
	while(*(s+i)!='\0'){
		if(*(s+i)>='0' && *(s+i)<='9'){i++;continue;}  //skip number character
		else *(s+j)=*(s+i);	j++;i++;
	}
	*(s+j)='\0';
	return j;
}

void mystrcpy(char *s,char *d){
	int i=0;
	while(*(d+i)!='\0'){
		*(s+i)=*(d+i);
		i++;
	}
	*(s+i)='\0';
}
int mystrcmp (char *s, char *d){
	int i=0;
	int max,diff;
	/*length define*/
	diff=my_strlen(s)-my_strlen(d);
	if(my_strlen(s)>my_strlen(d)) {max=my_strlen(s);}
	else {max=my_strlen(d);}

	if(my_strlen(s)==my_strlen(d))
	{
    	for( i;i<max;i++) 
    	{
        	if(*(s+i)!=*(d+i))
        	{
            	if(*(s+i)>*(d+i)){return i+1;}
    	    	else {return (i+1)*-1;}
        	}
        	else
        	{
            	if(i==max-1){return 0;}
        	}
    	}
	}
	else
	{
    	for( i;i<max;i++)
		{
        	if(*(s+i)!=*(d+i) && diff>0){
            	return (i+1)*-1;
        	}
        	else if(*(s+i)!=*(d+i) && diff<0){
           	 	return (i+1);
        	}
    	}
	}
}
char *strdupl(char *s)
{
    char* p; 
    p = (char*) malloc(my_strlen(s) * sizeof(char));

    int i;
    for(i = 0; i < my_strlen(s); i++)
    {
        *(p + i) = *(s + i);
    }
    *(p + i) = '\0';
    return p;
}
