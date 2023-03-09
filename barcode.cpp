/**
 *    @file: barcode.cpp
 *  @author: viraj parmar
 *    @date: 3/2/2023         
 *   @brief: In this program the code is set such a way that it return a unique barcode character for the zip code of the city entered by the user
             and it will show invalid for the zip which has less than or more than 5 digits in it and also for entering different characters like @ # -.
 *  
 */




#include<iostream>       //
#include<cctype>        //   usefull header files.
#include<cstring>
#include<iomanip>
using namespace std; 
string getDigitCode (char digit)    //functoin to identify the digit and matches to relevant code
{
	switch(digit)
	{
        case '1':
            return ":::||";
            break;
         case '2':
            return "::|:|";                    
            break;
         case '3':
            return "::||:";
            break;
         case '4':
            return ":|::|";
            break;
         case '5':
            return ":|:|:";
            break;
         case '6':
            return ":||::";
            break;
         case '7':
            return "|:::|";
            break;
         case '8':
            return "|::|:";
            break;
         case '9':
            return "|:|::";
            break;
         case '0':
            return "||:::";
            break;
        default:
            cout<<"Error!";
    }
}
int getCheckDigitValue(int sum)  //this function is used to get the check value of the sum of the zipcode
{
    return (10-(sum%10));
}
//main function
int main()
{
	char zip[100],ch,option;
	int i,sum=0,count=0,count2=0;
	while(count==0)     
	{
	   cout<<"ENTER YOUR ZIP-CODE";  //input for the zipcode
	   cin>>zip;
	   if(strlen(zip)!=5)  //condition to check the lenght of the zipcode
	   {
	   	 cout<<"\nERROR : ZIP CODE MUST BE 5 DIGIT";
	   	 count2=0; 
	   }
	   else
	   {
	      for(i=0;i<strlen(zip);i++)
	     {   
	        if(isdigit(zip[i])==0) //check if code contains non-digit character
	       {
	   	        cout<<"ERORR : ZIP IS INVALID";
	   	        count2=0;
	   	        break;
	       }
	   
	       else
	       {
		        sum=sum+zip[i]; 
		        count2++;
		   }
		   continue;
	   
	     }
	   }
	   
	   if(count2!=0)//if code is valid then write the barcode to the output file
	   {
	   	 cout<<"|";
	   	 for(i=0;i<strlen(zip);i++)
	   	 {
		    cout<<" "<<getDigitCode (zip[i]);
		 }
         ch=getCheckDigitValue(sum);
	     cout<<" "<<getDigitCode (ch+'0');
	     cout<<" |";
	         
	   }
       cout<<"\nMore codes(y/n)?"; //asking user to enter more zipcode or quit by entering letter y
       cin>>option;
       if(option=='y')
      {
        continue; //this will pass to the top of the loop and process again
      }
      else
      {
        count=1;
      }
	   
	}
}

	  
	         


