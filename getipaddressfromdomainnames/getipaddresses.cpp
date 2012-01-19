#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <netdb.h>
#include<fstream>
#include<iostream>
using namespace std;


/***********************
MN Tech Solutions Search Engine Version 0.0
MN-BOT Version 0.0
Mustafa Neguib
***********************/


int main()
{
int s_id,zero=0, port_no=80, numberOfBytes=0;
char * domainName=NULL;
char  fileName[100];
char* data;
int lengthOfDomain=0;
int lengthOfIp=0;

FILE *outPut = NULL;
char *file="data.txt";
FILE *inPut=NULL;
char *file1="domainnames.txt";
struct hostent *he;
struct in_addr *addr;
string dataInput;
string dataOutput;
/*printf("Enter the domain name: ");
scanf("%s",domainName);
printf("\n");
*/

ifstream myReadFile;
 myReadFile.open(file1);
int end=0;


 while (!myReadFile.eof()) {

   getline(myReadFile,dataInput);
//   domainName=(char *)malloc((dataInput.length()+1)*sizeof(char));// i am adding one extra space because \0 will be at the last location.
   domainName=new char[(dataInput.length()+1)];
   end=dataInput.copy(domainName,dataInput.length(),0);
   domainName[end]='\0';
//   printf("%s\n",domainName);

he = gethostbyname(domainName);

if(he!=NULL)
{//i had to check he because for some reason at the end of the file i was getting NULL in he. Also now if a domain name is invalid, then that will not be saved to the output file.
addr=(struct in_addr *)he->h_addr;
char *address=(char *)inet_ntoa(*addr);//i am converting to string format


dataOutput.append(domainName);
dataOutput.append("\t--->\t");
dataOutput.append(address);
dataOutput.append("\n");
}//end if

if(domainName!=NULL)
{
delete(domainName);
domainName=NULL;
}//end if

cout<<endl<<endl<<endl;
cout<<dataOutput<<endl;

}
myReadFile.close();

ofstream outFile;
outFile.open(file, ios::out|ios::trunc);
outFile<<dataOutput;

return 0;
}




