#include <iostream>
#include <conio.h>
using namespace std;
int rotors(int m,int pos);
int jump1(int a, int b,int msg);
int red[13]={0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int black[13]={0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int main()
{
    //int b[100];//A global array containing the numerical form of the message.
    //int encrms = rotors(3,21,16,22);
    //int encrms1 = rotors(22,16,21,3);
    int encrms1 = rotors(24,2);
    int message1[12] = {0,19,19,0,2,10,0,19,3,0,22,13};
    int cipher[12] = {19,6,17,12,0,14,18,8,21,10,12,25};
    int encmsg1[12];

    for(int i = 0;i<26;i++)
    {
       // for(int j=1;j<26;j++)
       // {
           // if(i !=j)
          //  {
           //     int red[13] = {i};
             //   int black[13] = {j};
           // }

            //plugboard(i,j,);
          //  for(int k =0;k<12;k++)
           // {
                //check for plugboard setting
               // for(int t=0;t<13;t++)
              //  {
                   // if ((red[t] = message1[k])|| (black[t] = message1[k]))
                   // {
                   //     message1[k] =jump1(message1[k]);
                    //}
               // }
               // encmsg1[k] =rotors(message[k],k);


           // }//
      //  }
    }





    getch();
    return 0;
}
//Function to find the plugboard settings
//

//Function rotors changes b[ ].
int rotors(int m,int pos)
{
    int b[13]={0,0,0,0,0,0,0,0,0,0,0,0,0};
    b[pos] = m;
    //fix ring setting for the rotors
    int n0=22;int n1=16;int n2=21;int nr=3;

static int past=0;
//int z;
int r0,r1,r2,rr;
static int q0[26],q1[26],q2[26],qr[26];
static int pi0[]={22,5,1,19,8,25,13,20,21,2,16,4,9,15,14,10,18,7,23,6,12,0,3,24,17,11};
static int pi1[]={7,12,17,6,13,16,15,10,9,0,2,8,21,22,11,20,4,1,5,25,18,24,23,19,3,14};
static int pi2[]={3,17,20,0,7,11,1,5,25,21,6,12,22,2,10,23,15,8,16,24,18,14,13,19,9,4};
static int pir[]={14,22,19,21,18,10,24,15,9,8,5,12,11,20,0,7,17,16,4,2,13,3,1,25,6,23};
//create inverse tables q0,...,qr.
if(past++==0)
	for(int x=0;x<26;++x)
	for(int y=0;y<26;++y)
				{
				if(pi0[x]==y)q0[y]=x;
				if(pi1[x]==y)q1[y]=x;
				if(pi2[x]==y)q2[y]=x;
				if(pir[x]==y)qr[y]=x;
				}
             //start encoding/decoding
	//a520:
	r0=n0;r1=n1;r2=n2;rr=nr; //initialize rotors
	for(int i=0;i<13;++i){
			int x=b[i];//numeric form of ith letter of the plaintext
			int y = x+r0; if(y>25)y=y-26;
			int z=pi0[y]-r0; if(z<0)z=z+26;
			x=z;y=x+r1;if(y>25)y=y-26;
			z=pi1[y]-r1;if(z<0)z=z+26;
			x=z; y=x+r2;if(y>25)y=y-26;
			z=pi2[y]-r2;if(z<0)z=z+26;
			x=z;y=x+rr;if(y>25) y=y-26;
			z=pir[y]-rr;if(z<0)z=z+26;
			x=z;y=x+r2;if(y>25)y=y-26;
			z=q2[y];
			z=z-r2;if(z<0)z=z+26;
			x=z;y=x+r1;if(y>25)y=y-26;
			z=q1[y];z=z-r1;if(z<0)z=z+26;
			x=z; y=x+r0;if(y>25)y=y-26;
			z=q0[y];z=z-r0;if(z<0)z=z+26;
			b[i]=z;

			//Advance the rotors to the next position
			++r0; if(r0<26)continue;r0=0;//makes next rotor move one space
			++r1; if(r1<26)continue;r1=0;
			++r2; if(r2<26)continue;r2=0;
			++rr; if(rr<26)continue;rr=0;
	}
    cout<<b[pos];
    return b[pos];

}//End of Rotors

int jump1(int a, int b, int msg)
{
//Performs the Initial Permutation on the input cleartext;
//This is a monalphabetic cipher defined by 13 jumpers (wires).
//Each jumper has a red plug at one end and a black plug at the other end.
//We first specify which sockets the red ends of the 13 jumpers are in:
//int b[1] = {1};
int red[13] = {a};
//We then specify which sockets the black ends of the 13 jumpers are in:
int black[13] = {b};
//It is important that every one of the 26 sockets has either a red or a black
//plug in it, and not both!
//Thus for example, jumper zero connects socket 12 with socket 3.
static int IP[26]; //We generate the Initial Permutation Only Once
int past=0;
if(past++==0)//If plugboard wasn't called before.
	{
	for(int jumper=0;jumper<13;++jumper)
				{
				IP[red[jumper]]=black[jumper];
				IP[black[jumper]]=red[jumper];
				//The jumper works in both directions
				}
	}
msg=IP[msg];//Monalphabetic Encryption by Plugboard
cout<<msg;
return msg;
}
