
#include <NTL/ZZ.h>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include "hash2.c"
#include "seed2.cpp"
#include "sha256.cpp"


#define _SHA256_WITH_MAIN

#ifdef _SHA256_WITH_MAIN
#include <cstdio>
#include <cstring>
#endif


#define _HAS_ITERATOR_DEBUGGING 0

#include <string.h>
#ifdef WIN32
#include <io.h>
#endif


#pragma comment(lib,"ntl.a")


NTL_CLIENT

//#include "ransue.cpp"


#define M32(x) (((1 << 32)-1)&(x))


ZZ KEYDEF;
ZZ KEYDEF2;
ZZ GROUP_GENERATOR;
ZZ K,PP;
ZZ tt[2][2],tab[521][2][2];


//from RFC2409
//dsa.rb Ruby version
//@GROUP_GENERATOR=2

// Default modulus value by zebedee
ZZ DFLT_MODULUS;
ZZ tmp[2][2];
ZZ L2[2][2];

/*
=begin
//...If you want to abandon man-in-the-middle-attack you must exchange
//a Public key with it's own signature on DH key exchange.
//Here is a signature method NR & DSA with blind.
=end
*/

// GCD
ZZ gcd(ZZ xx,ZZ yy){
  ZZ tt;

  while (yy != 0){
    tt = xx % yy;
    xx = yy;
    yy = tt;
    }

  return xx;
  
}


// invert of integer
ZZ inv(ZZ a,ZZ n){
  ZZ d,x,s,q,r,t;


  d = n;
  x = 0;
  s = 1;
while (a != 0){
    q = d / a;
    r = d % a;
    d = a;
    a = r;
    t = x - q * s;
    x = s;
    s = t;
}
//  gcd = d;  // $\gcd(a, n)$ 

  return ((x + n) % (n / d));
}


//jj=aa^bb mod oo
ZZ exp(ZZ aa,ZZ bb,ZZ oo){
ZZ ii,jj,kk[8192];
int j,c[8192],count=0,i;
  ii=oo;
  j=0;
  jj=0;
//  kk[4096]; //prime is 4096 bit table
//  c[8192]  //mod is 8192 bit table
  count=0;

  for(i=0;i<8192;i++){
    kk[i]=0;
    }
  while(ii>0){
    ii = (ii>>1);
    j=j+1;
  }


  kk[0]=aa;

//  cout << j << "\n";
  
//ex.1000=2**3+2**5+2**6+2**7+2**8+2**9 makes a array c=[3,5,6,7,8,9]
  for(i=0;i<j+1;i++){
      if(bit(bb,i) != 0){ // testbit(bb,i)
	c[count]=i;
	count=count+1;
      }
    }
//    cout << bb << endl;
//    cout << count << "\n";
//exit(1);
    for(i=1;i<c[count-1]+1;i++){
      kk[i] = kk[i-1]*kk[i-1]%oo;
    }

    jj=1;
    for(i=0;i<count;i++){
      jj=kk[c[i]]*jj%oo;
      if (jj==0){
//	print i,"\n"
      }
    }

    return jj;
}


// p>q=(p-1)/2 
void dsa(ZZ m,ZZ s56){
ZZ rr,a_r,a_s,Pub_key;

  cin >>K ;
  //k is select atrandom
  if((KEYDEF-1)%K==0){
    cout << "bad k\n";
    exit(1);
    }
  rr=exp(GROUP_GENERATOR,K,KEYDEF);
  a_r = rr % KEYDEF2;
  cout << a_r << "\n";
  a_s=(K*m+s56*a_r)%KEYDEF2;
  cout << a_s << "\n";

}



NTL_CLIENT


int A=0;
int B=0;

typedef struct{
ZZ x;
ZZ y;
} po;
typedef struct{
ZZ x;
ZZ y;
ZZ z;
}ten;
typedef struct{
char *name;
ZZ p;
ZZ seedE;
ZZ r;
ZZ a;
ZZ b;
ten G;
ZZ n;
int h;
ZZ inv;
} cv;
typedef struct{
unsigned int MD[8];
} arr;


cv CRV;
po le[256];
ten ll[256];
ten Pub_key;
po T;//eadd
po D;//edbl
ten P;//ead2
ten Q;//edl2
po N[256];//le_temp
ten M[256];//ll_temp
ten Gen_key;//randompoint
ZZ a3[100000];
int a2[100000],a4[100000];
//,pp=0;
//chargg[32];


//poPub_key;
//unsignedlonglongintg3[256][2],g4[256][2];
//intE_K=0;
ZZ I[9000];
ten L3[2][2],U3[2][2];


void init_curve(int n){

if(n==224){
//"{CBD61FC1-F50D-4","P-224","p=2^224-2^96+1",
CRV.name="eccp224";
CRV.p=to_ZZ("26959946667150639794667015087019630673557916260026308143510066298881");
CRV.seedE=to_ZZ("0xbd71344799d5c7fcdc45b59fa3b9ab8f6a948bc5");
CRV.r=to_ZZ("0x5b056c7e11dd68f40469ee7f3c7a7d74f7d121116506d031218291fb");
CRV.a=to_ZZ("-3");
CRV.b=to_ZZ("0xb4050a850c04b3abf54132565044b0b7d7bfd8ba270b39432355ffb4");
CRV.G.x=to_ZZ("0xb70e0cbd6bb4bf7f321390b94a03c1d356c21122343280d6115c1d21");
CRV.G.y=to_ZZ("0xbd376388b5f723fb4c22dfe6cd4375a05a07476444d5819985007e34");
CRV.G.z=to_ZZ("1");
CRV.n=to_ZZ("26959946667150639794667015087019625940457807714424391721682722368061");
CRV.h=1;
CRV.inv=to_ZZ("13479973333575319897333507543509815336778958130013154071755033149441");
 PP=CRV.p;
}

if(n==2244){
CRV.n=to_ZZ("13479973333575319897333507543509819484712548793029295142314934474707");
//doyouwanttoproceedwiththisone(Y/N)?y
CRV.a=to_ZZ("-3");
CRV.b=to_ZZ("7926735752311977820224618556926799352231714653617375950103029803860");
CRV.p=to_ZZ("26959946667150639794667015087019630673557916260026308143510066298881");
//R=13479973333575319897333507543509819484712548793029295142314934474707a224bitprime
CRV.G.x=to_ZZ("24155712282000049631001357595395450813097367499938434330297713128801");
CRV.G.y=to_ZZ("5882461958218329457915762297197751647381159972043925920846779622521");
CRV.G.z=to_ZZ("1");
CRV.inv=to_ZZ("13479973333575319897333507543509815336778958130013154071755033149441");
 PP=CRV.p;
}

if(n==256){
//"{B858801C-582E-4","P-256","p=2^256-2^224+2^N+2^96-1",
CRV.name="eccp256";
CRV.p=to_ZZ("115792089210356248762697446949407573530086143415290314195533631308867097853951");
CRV.seedE=to_ZZ("1122468115042657169822351801880191947498376363664");
CRV.r=to_ZZ("57436011470200155964173534038266061871440426244159038175955947309464595790349");
CRV.a=to_ZZ("-3");
CRV.b=to_ZZ("41058363725152142129326129780047268409114441015993725554835256314039467401291");
CRV.G.x=to_ZZ("48439561293906451759052585252797914202762949526041747995844080717082404635286");
CRV.G.y=to_ZZ("36134250956749795798585127919587881956611106672985015071877198253568414405109");
CRV.G.z=to_ZZ("1");
CRV.n=to_ZZ("115792089210356248762697446949407573529996955224135760342422259061068512044369");
CRV.h=1;
CRV.inv=to_ZZ("57896044605178124381348723474703786765043071707645157097766815654433548926976");
 PP=CRV.n;
 }

if(n==2563){
CRV.name="eccp256r2";
CRV.p=to_ZZ("115792089210356248762697446949407573530086143415290314195533631308867097853951");
CRV.a=to_ZZ("115792089210356248762697446949407573530086143415290314195533631308867097853948");
CRV.b=to_ZZ("41058363725152142129326129780047268409114441015993725554835256314039467401291");
CRV.G.x=to_ZZ("395815829005855038029765540278861637762572903522963440114216832740821793555094");
CRV.G.y=to_ZZ("30769603638631994634479180612906047718205418376298768584198191172839256571736");
CRV.G.z=1;
CRV.n=to_ZZ("115792089210356248762697446949407573529996955224135760342422259061068512044369");
 PP=CRV.p;
}

if(n==2562){

CRV.a=to_ZZ("20549773689227812627292831297245718700081937423295476612608601227386727850553");
CRV.b=to_ZZ("47623312769896854212861199545761181316171213330096761101722264837667685936281");
CRV.n=to_ZZ("101770390931234937383997936042792106547711735705722570460955764669295036711143");
CRV.p=to_ZZ("101770390931234937383997936042792106548349765143699330079949592058229602107737");
CRV.G.y=to_ZZ("16845429027015099874700368857878626645060314647744100515127489968869022719070");
//84924961904219837509297567184913479903289450495955229564822102089360579388667");
CRV.G.x=to_ZZ("38996611774847114330982137792567050762097251424678060141486085082902623877233");
//
//w=59
CRV.G.z=1;
 PP=CRV.p;
/*
CRV.name="eccp256r1";
CRV.p=to_ZZ("115792089210356248762697446949407573530086143415290314195533631308867097853951");
CRV.a=to_ZZ("115792089210356248762697446949407573530086143415290314195533631308867097853948");
CRV.b=to_ZZ("41058363725152142129326129780047268409114441015993725554835256314039467401291");
CRV.seedE=to_ZZ("1122468115042657169822351801880191947498376363664");
CRV.G.x=to_ZZ("395815829005855038029765540278861637762572903522963440114216832740821793555094");
CRV.G.y=to_ZZ("3600254559212783631020592788373957154744735408555473783510957625074434451321");
//59240149723730851812311272008153533141816437726696305166080887910572446982458012615605924465554721774228350039774385670824392793454808075284049927019123189");
CRV.G.z=1;
CRV.n=to_ZZ("115792089210356248762697446949407573529996955224135760342422259061068512044369");
CRV.h=1;
CRV.inv=to_ZZ("57896044605178124381348723474703786765043071707645157097766815654433548926976");
*/
}

if(n==2564){
CRV.a=to_ZZ("325379667707489826401064228424852592079356807922648328779606654148301710111");
CRV.b=to_ZZ("43638953242465233168106495530541200510616011708075374527275181032002171872628");
CRV.n=to_ZZ("65133050195990359925758679067386948173334237203809005766938102982707303781623");
CRV.p=to_ZZ("65133050195990359925758679067386948173844660754190413462133164893854956098831");
//infinity devide1
CRV.G.x=to_ZZ("18487703388218368811611273467885185415041771995400161457848598846868890320470");
CRV.G.y=to_ZZ("24687222602040641145870602721247005746364795831134621092877670314906490902760");
CRV.G.z=1;
 PP=CRV.p;
 }

if(n==2565){
CRV.a=to_ZZ("50615278656685320126791612967404283968036974455733654200179080720363497751491");
CRV.b=to_ZZ("33743519104456880084527741978269522645357982970489102800119387146908998500994");
CRV.n=to_ZZ("65133050195990359925758679067386948208553462180126136735397374851843822399097");
CRV.p=to_ZZ("65133050195990359925758679067386948209063885730507544430592436762991474716443");
//infinity devide1
CRV.G.x=to_ZZ("63582577761502127973450815015383738377077716646935254059256424901755563321273");
CRV.G.y=to_ZZ("22895574053820059180945744963571496712404540419433716833791593749823092772659");
CRV.G.z=1;
 PP=CRV.p;
 }

if(n==2566){

CRV.a=to_ZZ("58619423044276027832903787065716086236095439918520509851335164825122761913928");
CRV.b=to_ZZ("5156151719105706093936546029546688635963459581307566382625017622890757039103");
CRV.n=to_ZZ("101770390931234937383997936042792106563662471655141560935801449392638687313903");
CRV.p=to_ZZ("101770390931234937383997936042792106564300501093118320554795276781573252710547");
CRV.G.y=to_ZZ("98399506821057818865862588903161792587668472549669649472059793708337005935795");
CRV.G.x=to_ZZ("28663290192706932057771677870920156363737430016916930158558409220429370107804");
CRV.G.z=1;
 PP=CRV.p;
}

if(n==384){
//Group order=
CRV.n=to_ZZ("5628858028056354173182720014306230543582819895780778095420563755345515056616034903125147135939193286284507539411263");
CRV.a=-3;
CRV.b=to_ZZ("7480836070348502192310144960168319822230417316926886013721948420378391982808980728605112950230878688086816085055381");
CRV.p=to_ZZ("39402006196394479212279040100143613805079739270465446667948293404245721771497210611414187026722401376469034446356971");
//R=5628858028056354173182720014306230543582819895780778095420563755345515056616034903125147135939193286284507539411263a382bitprime
CRV.G.x=to_ZZ("13839325240143548436618097820237988853510646421495011597727751118065256776775190573162986203269450299582183630276103");
CRV.G.y=to_ZZ("33479584122550753431257252642915332781925124384694439200422942083526531640009189112108669026825242814943349686581134");
CRV.G.z=1;
 PP=CRV.p;
}
 if(n==0){
   CRV.n=to_ZZ("1063891");
   CRV.a=to_ZZ("394716");
   CRV.b=to_ZZ("263144");
   CRV.p=to_ZZ("1063903");
   CRV.G.x=to_ZZ("823140");
   CRV.G.y=to_ZZ("31315");
   CRV.G.z=to_ZZ("1");
   PP=CRV.p;
 }
}


ZZ inv_X[2][2];




ZZ isqrt(ZZ x){
ZZ t,s;

/*
if(x==0)
return0;
*/
s=1;
t=x;
while(s<t){
s<<=1;
t>>=1;
}
while(s<t){
t=s;
s=(x/s+s)>>1;
}

return t;

}


void jadd(ten G1,ten G2){
ZZ u1,u2,s1,s2,h,r,rev,reb,re6;
ZZ x1,x2,y1,y2,z1,z2,mod;

x1=G1.x;x2=G2.x;y1=G1.y;y2=G2.y;z1=G1.z;z2=G2.z;
mod=CRV.p;

if(x1==x2&&y1==y2&&z1==z2){
cout<<"infinitydevide1\n";
cout<<"Y1="<<y1<<"\n";
cout<<"Y2="<<y2<<"\n";
exit(1);
}

u1=x1*z2*z2;
u2=x2*z1*z1;
s1=y1*z2*z2*z2;
s2=y2*z1*z1*z1;
h=u2-u1;
r=s2-s1;
P.x=(-h*-h*-h-2*u1*h*h+r*r)%mod;
P.y=(-s1*h*h*h+r*(u1*h*h-P.x))%mod;
P.z=(z1*z2*h)%mod;

//=begin
rev=inv(P.z,mod);
reb=inv(P.z*P.z,mod);
re6=inv(P.z*P.z*P.z,mod);
P.x=reb*P.x%mod;
P.y=re6*P.y%mod;
P.z=rev*P.z%mod;

if(P.y*P.y%CRV.p!=(P.x*P.x*P.x+CRV.a*P.x*P.z*P.z*P.z*P.z+CRV.b*P.z*P.z*P.z*P.z*P.z*P.z)%CRV.p){
cout<<"err in jadd\n";
exit(1);
}

}


void jdbl(ten T){
ZZ s,m,t,x,y,z;

x=T.x;
y=T.y;
z=T.z;

s=4*x*y*y;
m=3*x*x+CRV.a*(z*z*z*z);
t=-2*s+m*m;
Q.x=t%CRV.p;
Q.y=(-8*(y*y*y*y)+m*(s-t))%CRV.p;
Q.z=2*y*z%CRV.p;


if(Q.y*Q.y%CRV.p!=(Q.x*Q.x*Q.x+CRV.a*Q.x*Q.z*Q.z*Q.z*Q.z+CRV.b*Q.z*Q.z*Q.z*Q.z*Q.z*Q.z)%CRV.p){
cout<<"errjdbl\n";
exit(1);
}

}


//make a calcrationtablefrombasepointQ
void mktbl3(ten T){
ZZ pp,xx,yy,zz,a;
int i;
ten O;

//cout<<"in_mktbl3\n";


//printCRV_name,"\n"
pp=CRV.p;
//printpp,"\n"
xx=T.x;
//printxx,"\n"
yy=T.y;
//print"y=",yy,"\n"
zz=T.z;
//print"z!=",zz,"\n"
a=CRV.a;
//printa,"\n"
//printCRV_b,"\n"


//enzantable
ll[0].x=xx;
ll[0].y=yy;
ll[0].z=zz;
O.x=xx;
O.y=yy;
O.z=zz;
for(i=1;i<256;i++){//beginPub_keyatplain
if(yy==0){
cout<<"Yga"<<i<<"\n";
//exit()
}

jdbl(O);
ll[i].x=Q.x;
ll[i].y=Q.y;
ll[i].z=Q.z;

O.x=ll[i].x;
O.y=ll[i].y;
O.z=ll[i].z;
}
//offor
//cout<<"endofmktbl3\n";

}


ten elp(ZZ k,ten Z){
ten E,F[256];
 int flg=0,l=0,i,count=0;

if(k==0)
return CRV.G;

E=Z;


while(k>0){
  //  cout << k%2 << endl;
  if(k%2==1){
    F[count++]=E;
    //    cout << Q.x << "," << Q.y << endl;
  } 

  jdbl(E);
  E=Q;
  k=(k>>1);
 }
// cout << count << endl;

 
 E=F[0];
 for(i=1;i<count;i++){
   jadd(E,F[i]);
   E=P;
 }


return E;
}

ten elp2(ZZ k,ten Z){
ten E,F;
 int flg=0,l=0,i,count=0;

if(k==0)
return CRV.G;

E=Z;


while(k%2==0){
  jdbl(E);
  E=Q;
  k=(k>>1);
 }
// cout << count << endl;

 
// E=F[0];
 F=E;
 while(k>0){
   jdbl(F);
   F=Q;
   k=(k>>1);
   if(k%2==1){
   jadd(E,F);
   E=P;
   }  
 }


return E;
}


//ComputeQ=mG
void elp3(ZZ k){
int ki[256];
ZZ L;
po s;
int j,l,i,ii,jj;


j=0;
l=0;
if(k<0){
cout<<"obsenseK\n";
cout<<k<<"\n";
exit(1);
}

if(k==0){
cout<<"infinitydevide2\n";
s.x=0;
s.y=0;
}

if(k>CRV.n){
k=k%CRV.n;
}

for(j=0;j<256;j++){
ki[j]=0;
}

L=k;
while(L>0){
L=(L>>1);
l=l+1;
}

L=k;
if(j!=0){
j=0;
}
//cout<<L<<endl;
//if(((KK^(1<<i))>>i)%2==0)//testbit(KK,i)<-shippai
for(i=0;i<l;i++){
if(L%2==1){
ki[j]=i;

j=j+1;
}
L=(L>>1);
}
//cout<<j<<endl;
//exit(1);
Pub_key.x=ll[ki[0]].x;
Pub_key.y=ll[ki[0]].y;
Pub_key.z=ll[ki[0]].z;
//cout<<Pub_key.x<<endl;
//print"j=",j,"\n"

if(k>0){
for(i=1;i<j;i++){
if(Pub_key.x!=ll[ki[i]].x||Pub_key.y!=ll[ki[i]].y||Pub_key.z!=ll[ki[i]].z){

if(Pub_key.y*Pub_key.y%CRV.p==(Pub_key.x*Pub_key.x*Pub_key.x+CRV.a*Pub_key.x*(Pub_key.z*Pub_key.z*Pub_key.z*Pub_key.z)+CRV.b*(Pub_key.z*Pub_key.z*Pub_key.z*Pub_key.z*Pub_key.z*Pub_key.z))%CRV.p){
//cout<<"doko2\n";
if(ll[ki[i]].y*ll[ki[i]].y%CRV.p==(ll[ki[i]].x*ll[ki[i]].x*ll[ki[i]].x+CRV.a*ll[ki[i]].x*(ll[ki[i]].z*ll[ki[i]].z*ll[ki[i]].z*ll[ki[i]].z)+CRV.b*(ll[ki[i]].z*ll[ki[i]].z*ll[ki[i]].z*ll[ki[i]].z*ll[ki[i]].z*ll[ki[i]].z))%CRV.p){
//cout<<"doko3\n";
jadd(Pub_key,ll[ki[i]]);
Pub_key.x=P.x;
Pub_key.y=P.y;
Pub_key.z=P.z;
if(Pub_key.x==0&&Pub_key.y==0&&Pub_key.z==0){
//	if(Pub_key_z==0)
cout<<Pub_key.x<<","<<Pub_key.y<<","<<Pub_key.z<<"\n";
cout<<"infinitydevide3\n";
exit(1);
}
//print"doko4\n"
}

//print"end1\n"
}
//print"end2\n"
}
//print"end3\n"
if(Pub_key.x==ll[ki[i]].x&&Pub_key.y==ll[ki[i]].y&&Pub_key.z==ll[ki[i]].z){

//print"ecole\n"
jdbl(Pub_key);
cout<<"edb2("<<Pub_key.x<<Pub_key.y<<Pub_key.z<<")\n";
exit(1);
}
//print"inforloop",i,"";
}


}

//noreturn--print"afterreturn\n"
}



void inv_mat(ZZ W[2][2]){
  ZZ a,tmp,E[2][2],det;
  int i,j,k;
 
  srand(clock());
  
  
  det=(W[0][0]*W[1][1]-W[0][1]*W[1][0])%CRV.p;
  if(det<0){
    while(det<0){
      det+=CRV.p;
      //      cout << "@";
    }
  }else if(det==0){cout << "baka" << endl;}


  if(det>0){
  a=inv(det,CRV.p);

  tmp=W[0][0];
  inv_X[0][0]=W[1][1]*a%CRV.p;
  inv_X[1][1]=tmp*a%CRV.p;
  inv_X[0][1]= CRV.p-(W[0][1]*a%CRV.p);
  inv_X[1][0]= CRV.p-(W[1][0]*a%CRV.p);
  }
  

  }


void seki(ZZ S[2][2],ZZ T[2][2]){
  int i,j,k;
  

  for(i=0;i<2;i++){
    for(j=0;j<2;j++){
      //cout << S[i][j];
      tt[i][j]=0;
    }
    //    printf("\n");
  }
  for(i=0;i<2;i++){
    for(k=0;k<2;k++){
      for(j=0;j<2;j++)
	tt[i][k]+=S[i][j]*T[j][k]%PP;
      // tt[i][k]%=tt[i][k];
    }
  }

}


void tabroo(ZZ V[2][2]){
  int i,j,k,l;
  ZZ VX[2][2];

  for(i=0;i<2;i++){
    for(j=0;j<2;j++)
      VX[i][j]=V[i][j];
  }
  
  for(i=0;i<2;i++){
    for(j=0;j<2;j++){
      tt[i][j]=0;
      
    }
  }
  
  for(i=0;i<2;i++){
    for(j=0;j<2;j++)
      tab[0][i][j]=VX[i][j];
    }
  
    for(i=1;i<522;i++){
      seki(VX,VX);
      
      for(j=0;j<2;j++){
	for(k=0;k<2;k++){
	  tab[i][j][k]=tt[j][k]%CRV.p;
	  VX[j][k]=tt[j][k]%CRV.p;
	  //	  cout << V[j][k];
	}
	//printf("\n");
      }
    }
    for(i=0;i<2;i++){
      for(j=0;j<2;j++)
	L2[i][j]=VX[i][j];
    }
}


void m9(ZZ m,ZZ E[2][2]){
  int i,j,k,count=0;
  ZZ M[2][2],F[2][2];


  tmp[0][0]=1;
  tmp[0][1]=0;
  tmp[1][0]=0;
  tmp[1][1]=1;

  
  tabroo(E);
while(m>0){
  if(m%2==0){
    
    // count++;
  }
  if(m%2==1){
    
      for(k=0;k<2;k++){
      for(j=0;j<2;j++)
	M[j][k]=tab[count][j][k];
      }
      seki(M,tmp);
	for(i=0;i<2;i++){
	  for(j=0;j<2;j++)
	    tmp[i][j]=tt[i][j]%CRV.p;
	}
  }
   m= m>>1;
    count++;
  }
  for(i=0;i<2;i++){
    for(j=0;j<2;j++)
      cout << tmp[i][j]%CRV.p << endl;
    printf("\n");
  }
}


int main(int argc,char *argv[]){
  ZZ a,z,r,d,I,salt,s,mm;
  int i;
  char m[1];
  FILE *fp;
  unsigned char key[32];
  po sig;
  char file[32];
  ten T[2][2],A[2][2],V[2][2],Y[2][2];
  ZZ X[2][2],X2[2][2],X3[2][2],X4[2][2],X5[2][2],X6[2][2];
  ten U[2][2],Q[2][2],C1[2][2],C2[2][2];
  int j,k;


  srand(clock());
  init_curve(0);

  X[0][0]=1;
  X[0][1]=2;
  X[1][0]=3;
  X[1][1]=4;


  A[0][0].x=CRV.G.x;
  A[0][0].y=CRV.G.y;
  A[0][0].z=CRV.G.z;
  mktbl3(A[0][0]);
  for(i=0;i<1;i++){
    for(j=1;j<2;j++){
      elp3(to_ZZ(rand()));
  A[i][j].x=Pub_key.x;
  A[i][j].y=Pub_key.y;
  A[i][j].z=Pub_key.z;
    }
  }
  for(i=1;i<2;i++){
    for(j=0;j<2;j++){
      elp3(to_ZZ(rand()));
      A[i][j].x=Pub_key.x;
      A[i][j].y=Pub_key.y;
      A[i][j].z=Pub_key.z;
    }
  }
  
  r=to_ZZ(rand());
  mm=to_ZZ(rand());
  a=to_ZZ(rand());
  m9(a,X);
  for(i=0;i<2;i++){
    for(j=0;j<2;j++)
      X2[i][j]=tmp[i][j];
  }
  ten nn[2][2];

  for(i=0;i<2;i++){
    for(k=0;k<2;k++){
      for(j=0;j<2;j++){
	mktbl3(A[j][k]);
	elp3(X2[i][j]);
       nn[i][j]=Pub_key;
      }
       jadd(nn[i][0],nn[i][1]);
      C1[i][k]=P;
    }
  }
  //  exit(1);
  inv_mat(X2);
  for(i=0;i<2;i++){
    for(k=0;k<2;k++){ 
      for(j=0;j<2;j++){
	mktbl3(C1[i][j]);
	elp3(inv_X[j][k]);
	nn[i][j]=Pub_key;
	//U[i][j].y=Pub_key.y;
	//U[i][j].z=Pub_key.z;
       

      }
      //       exit(1);  
        jadd(nn[i][0],nn[i][1]);
	U[i][k]=P;

  }
  }
  for(i=0;i<2;i++){
    for(j=0;j<2;j++){
      mktbl3(U[i][j]);
      elp3(mm);
      Y[i][j]=Pub_key;
      //      Y[i][j].y=Pub_key.y;
      //Y[i][j].z=Pub_key.z;
    }
  }
  // exit(1);
  //end of Y
      
       ten VX[2][2];


       //begin C1

       m9(a,X);
       for(i=0;i<2;i++){
	 for(j=0;j<2;j++)
	   X3[i][j]=tmp[i][j];
       }
       for(i=0;i<2;i++){
	 for(k=0;k<2;k++){
	   for(j=0;j<2;j++){
	     mktbl3(Y[j][i]); //Y
	     elp3(X3[i][j]); //Y wo mmbai
	     nn[i][j]=Pub_key;
	     //U[i][j].y=Pub_key.y;
	     //U[i][j].z=Pub_key.z;
	     
	     //nn[i][j]=U[i][j];

	   }
	   jadd(nn[i][0],nn[i][1]);
	   U[i][k]=P;
	   //   U[i][k].y=P.y;
	   //U[i][k].z=P.z;
	 }
       }
       inv_mat(X3);
       for(i=0;i<2;i++){
	 for(k=0;k<2;k++){
	   for(j=0;j<2;j++){
	     mktbl3(U[i][j]);
	     elp3(inv_X[j][k]);
	     nn[i][j]=Pub_key;
	     //  C1[i][j].y=Pub_key.y;
	     //C1[i][j].z=Pub_key.z;
	     
	       
	   }
	   jadd(nn[i][0],nn[i][1]);
	   C1[i][k]=P;
	   //   C1[i][k].y=P.y;
	   //C1[i][k].z=P.z;
	 }
       }
       //end of C1
       

       // exit(1);
       //begin of C2
       m9(a,X);
       for(i=0;i<2;i++){
	 for(j=0;j<2;j++)
	   X4[i][j]=tmp[i][j];
       }
       for(i=0;i<2;i++){
	 for(j=0;j<2;j++){
	   mktbl3(A[i][j]);
	   elp3(mm);
	   U[i][j]=Pub_key;
	   //U[i][j].y=Pub_key.y;
	   //U[i][j].z=Pub_key.z;
	 }
       }
       
       //inv_mat(X4);
       for(i=0;i<2;i++){
	 for(k=0;k<2;k++){
	   for(j=0;j<2;j++){
	     mktbl3(U[j][k]);
	     elp3(X4[i][j]);
	     nn[i][j]=Pub_key;
	     // V[i][j].y=Pub_key.y;
	     //V[i][j].z=Pub_key.z;
	     
	     
	   }
	   jadd(nn[i][0],nn[i][1]);
	   V[i][k]=P;
	   //V[i][k].y=P.y;
	   //V[i][k].z=P.z;
	 }
       }
       inv_mat(X4);
       for(i=0;i<2;i++){
	 for(k=0;k<2;k++){
	   for(j=0;j<2;j++){
	     mktbl3(V[i][j]);
	     elp3(inv_X[j][k]);
	     nn[i][j]=Pub_key;
	     //C2[i][j].y=Pub_key.y;
	     //C2[i][j].z=Pub_key.z;
	     
	       
	   }
	   jadd(nn[i][0],nn[i][1]);
	   C2[i][k]=P;

	 }
       }
// end of C2


       
       //decode
       m9(a,X);
       for(i=0;i<2;i++){
	 for(j=0;j<2;j++){
	   X5[i][j]=tmp[i][j];
	 }
       }
       for(i=0;i<2;i++){
	 for(k=0;k<2;k++){
	   for(j=0;j<2;j++){
	     mktbl3(C2[j][k]);
	     elp3(X5[i][j]);
	     nn[i][j]=Pub_key;
	     //   U[i][j].y=Pub_key.y;
	     //U[i][j].z=Pub_key.z;
	     
	       
	   }
	   jadd(nn[i][0],nn[i][1]);
	   U[i][k]=P;
	 }
       }

       inv_mat(X5);
       for(i=0;i<2;i++){
	 for(k=0;k<2;k++){
	   for(j=0;j<2;j++){
	     mktbl3(U[i][j]);
	     elp3(inv_X[j][k]);
	     nn[i][j]=Pub_key;
	     //V[i][j].y=Pub_key.y;
	     //V[i][j].z=Pub_key.z;
	     
	       
	   }
	   jadd(nn[i][0],nn[i][1]);
	   V[i][k]=P;
	 }
       }

       cout << C1[0][0].x << endl;
       cout << C2[0][0].x << endl;
       cout << V[0][0].x << endl;
       cout << Y[0][0].x << endl;
       


       return 0;
}
