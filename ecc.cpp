// ecc.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//jdbl,jaddは射影座標です。x=X/Z;y=Y/Z;でaffine座標に変換できます。
//2016.2.18 ecdsa を追加しました。


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

//def M32(x) (((1 << 32)-1)&(x)) end



ZZ KEYDEF;
ZZ KEYDEF2;
ZZ GROUP_GENERATOR;
ZZ K;


//from RFC2409
//dsa.rb Ruby version
//@GROUP_GENERATOR=2

// Default modulus value by zebedee
ZZ DFLT_MODULUS;



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


// verify DSA signature
void vera(void){
ZZ tt,v,q,m,a_r,a_s,Pub_key;
  
  cin >> Pub_key;
  cin >> m;
  cin >> a_r;
  cin >> a_s;
  //  m=sha(argc,argv);
  tt=exp(GROUP_GENERATOR,a_s,KEYDEF); // g^{(km+xr)%mod}=g^km*g^xr
  q=exp(Pub_key,a_r,KEYDEF); // g^{r*x}
  q=inv(q,KEYDEF); // g^{-xr}
  tt=tt*q%KEYDEF; // g^{(km+xr)%mod-xr}
  m=inv(m,KEYDEF2);
  tt=exp(tt,m,KEYDEF); // g^k
  v=tt%KEYDEF2;

if(a_r!=v){
   cout << "baka\n";
}
if(a_r==v){
    cout << "That's True!\n";
}
}



int dsa2(int argc,char *argv[]){

  int n,i,j,read_size;
  FILE *fp;
  char m[32],s[32];
  ZZ xx,s56,s128,s64,s168,gay,yy,md,Pub_key;
  ZZ ee;
  


fp=fopen("key.bin","rb");
  
  
// decide keysize n
  n=3072;
//  cout << "n=" << n << "\n";

    if (n!= 1024 && n!=2048 && n!=3072){
   cout << "You can select from next parametors 1024,2048\n";
   cout << "3072. First [./dsa file] Next you need to input\n";
   cout << "one of these dsa key size.\n";
   cout << "Note this version's signature is not secure because of \n";
   }


  if(n==1024){
  KEYDEF=to_ZZ("101459693097608319042758415833807677670847628544715540724500026735349301068515392099767184641851031376113522183648115338953972239406909609350543459251533166139494901562515248706419170211273185584865994044063658192209029166200554581462882695234974056443041028708526103161707004900985186431045546342831775691541");
  KEYDEF2=to_ZZ("776378143341645114049424495943980057469202238087");
  //cout << n << endl;
  }
// 2048-bitMODPGroup
  if (n==2048){
  //DSA2-2048
//  GROUP_GENERATOR=to_ZZ("17897632365819573629929421516690995329392240564338210669246123561578820182898001986314047062952709901885015040339515421277852524748737086689482837286397540833001027918735192714745525406787547844867397104909891036216567493074044699663056157063455807840400307121501500802879268087354892118549926250489315886418425836102419251044547998348285984529063830891267976483654053687247386848504479277865820007593913780659204244543282342153530132912911261891829655491924183152099688331780801720225551004877635192339824144849558987391691156930675841169504665150459882268394747288782712269513761848592346973515560328350172753584761");
  KEYDEF=to_ZZ("30981723345974435010161909523496552974699533919934322379085614661498636798097568515214479822262348814635668373190596212356380711940945934922154014218679943787759116924209774502274268759042349702152136214836347166635609098903049845488225777238895118712670994018901432361245969980840078167888393860223326555502924507123955659138424915625337173774451718035807621447511725643561397746198018458567222530032058288731896581568162423781624070371332903949092124341245711835360848611974141912660194445611902431634123654857731781595663275337139561826932358567214803181529834262455954351466450805559661991067483130544841970662773");
  KEYDEF2=to_ZZ("87887965594022234641736188661435007486940516303779074733210399408420032394343");
  }

// 3072-bitMODPGroup
  if (n==3072){
  //DSA2-3072
 // GROUP_GENERATOR=to_ZZ("2141434891434191460597654106285009794456474073127443963580690795002163321265105245635441519012876162226508712450114295048769820153232319693432987768769296824615642594321423205772115298200265241761445943720948512138315849294187201773718640619332629679913150151901308086084524597187791163240081868198195818488147354220506153752944012718951076418307414874651394412052849270568833194858516693284043743223341262442918629683831581139666162694560502910458729378169695954926627903314499763149304778624042360661276996520665523643147485282255746183568795735922844808611657078638768875848574571957417538833410931039120067791054495394347033677995566734192953459076978334017849678648355479176605169830149977904762004245805443987117373895433551186090322663122981978369728727863969397652199851244115246624405814648225543311628517631088342627783146899971864519981709070067428217313779897722021674599747260345113463261690421765416396528871227");
  KEYDEF=to_ZZ("3268470001596555685058361448517594259852327289373621024658735136696086397532371469771539343923030165357102680953673099920140531685895962914337283929936606946054169620100988870978124749211273448893822273457310556591818639255714375162549119727203843057453108725240320611822327564102565670538516259921126103868685909602654213513456013263604608261355992328266121535954955860230896921190144484094504405550995009524584190435021785232142953886543340776477964177437292693777245368918022174701350793004000567940200059239843923046609830997768443610635397652600287237380936753914127667182396037677536643969081476599565572030244212618673244188481261912792928641006121759661066004079860474019965998840960514950091456436975501582488835454404626979061889799215263467208398224888341946121760934377719355124007835365528307011851448463147156027381826788422151698720245080057213877012399103133913857496236799905578345362183817511242131464964979");
  KEYDEF2=to_ZZ("93911948940456861795388745207400704369329482570245279608597521715921884786973");
  }



// default: print "Choose your key size","\n"

//This prime is: 2^8192 - 2^8128 - 1 + 2^64 * { [2^8062 pi] + 4743158 end
//Its hexadecimal value is
//The generator is: 2.


 


  // choose random secret keys (larger than s128-bit)
  s128=to_ZZ("340282055605427970793192457633571187455");
  s168=to_ZZ("373779281620604392915322569464050882390986703503105");
  fread(m,1,32,fp);
  read_size=fread(s,1,32,fp);
//  cout << read_size << endl;
  
  gay=0;
  for(i=0;i<32;i++)
  gay=(gay<<8)^s[i];
//    to_ZZ("3618502788666131106986593281527206111185510860325500770110842981586944655359");

  
  //cout << "k is secret number which is sender choosed atrandom" << endl;
  
  //=to_ZZ("22387645283764583276458327645823764528376458327645832764528376452837645238764528376453287645");
//  freopen("con","r",stdin);

  GROUP_GENERATOR=exp(gay,(KEYDEF-1)/KEYDEF2,KEYDEF);
  if((KEYDEF-1)%KEYDEF2!=0)
    exit(1);

  yy= exp(GROUP_GENERATOR,gay,KEYDEF); //Public Key
  cout << yy << endl;
  Pub_key=yy;
  if(n==1024){
    ee=sha2(argc,argv);
  }else //if(strcmp(argv[1],"3"))
    md = sha2(argc,argv);
  cout << md << endl;
  //  printf("%08X%08X%08X%08X%08X\n",ee.MD[0],ee.MD[1],ee.MD[2],ee.MD[3],ee.MD[4]);
//  e= ("0x"+STATUS).hex
/*
  if(n==1024){
  md=to_ZZ(ee.MD[0]);
  md=(md<<32)^to_ZZ(ee.MD[1]);
  md=(md<<32)^to_ZZ(ee.MD[2]);
  md=(md<<32)^to_ZZ(ee.MD[3]);
  md=(md<<32)^to_ZZ(ee.MD[4]);
  }
*/
//  cout << argv[1] << "'s DSA Signature is \n";
  if(!strcmp(argv[1],"1"))
  dsa(md,gay);
  if(!strcmp(argv[1],"2"))
  vera();

return 0;
}




NTL_CLIENT


int A=0;
int B=0;

typedef struct {
  ZZ x;
  ZZ y;
} po;
typedef struct {
  ZZ x;
  ZZ y;
  ZZ z;
} ten;
typedef struct {
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
typedef struct {
  unsigned int MD[8];
} arr;


cv CRV;
po le[256];
ten ll[256];
ten Pub_key;
po T; //eadd
po D; //edbl
ten P; //ead2
ten Q; //edl2
po N[256]; //le_temp
ten M[256]; //ll_temp
ten Gen_key; // random point
ZZ a3[100000];
int a2[100000],a4[100000];
//,pp=0;
//char gg[32];


//po Pub_key;
//unsigned long long int g3[256][2],g4[256][2];
//int E_K=0;
ZZ I[9000];



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
}

  if(n==2244){
CRV.n= to_ZZ("13479973333575319897333507543509819484712548793029295142314934474707");
//do you want to proceed with this one (Y/N)? y
CRV.a= to_ZZ("-3");
CRV.b= to_ZZ("7926735752311977820224618556926799352231714653617375950103029803860");
CRV.p= to_ZZ("26959946667150639794667015087019630673557916260026308143510066298881");
//R= 13479973333575319897333507543509819484712548793029295142314934474707 a 224 bit prime
CRV.G.x= to_ZZ("24155712282000049631001357595395450813097367499938434330297713128801");
CRV.G.y= to_ZZ("5882461958218329457915762297197751647381159972043925920846779622521");
CRV.G.z=to_ZZ("1");
CRV.inv=to_ZZ("13479973333575319897333507543509815336778958130013154071755033149441");
}

  if(n==256){
//"{B858801C-582E-4","P-256","p=2^256-2^224+2^N+2^96-1",
CRV.name="eccp256";
CRV.p=to_ZZ("115792089210356248762697446949407573530086143415290314195533631308867097853951");
CRV.seedE=to_ZZ("1122468115042657169822351801880191947498376363664");
CRV.r=to_ZZ("57436011470200155964173534038266061871440426244159038175955947309464595790349");
CRV.a= to_ZZ("-3");
CRV.b=to_ZZ("41058363725152142129326129780047268409114441015993725554835256314039467401291");
CRV.G.x=to_ZZ("48439561293906451759052585252797914202762949526041747995844080717082404635286");
CRV.G.y=to_ZZ("36134250956749795798585127919587881956611106672985015071877198253568414405109");
CRV.G.z=to_ZZ("1");
CRV.n=to_ZZ("115792089210356248762697446949407573529996955224135760342422259061068512044369");
CRV.h=1;
CRV.inv=to_ZZ("57896044605178124381348723474703786765043071707645157097766815654433548926976");
}

if(n==2563){
CRV.name="eccp256r2";
CRV.p = to_ZZ("115792089210356248762697446949407573530086143415290314195533631308867097853951");
CRV.a = to_ZZ("115792089210356248762697446949407573530086143415290314195533631308867097853948");
CRV.b = to_ZZ("41058363725152142129326129780047268409114441015993725554835256314039467401291");
CRV.G.x = to_ZZ("395815829005855038029765540278861637762572903522963440114216832740821793555094");
CRV.G.y=to_ZZ("30769603638631994634479180612906047718205418376298768584198191172839256571736");
CRV.G.z=1;
CRV.n = to_ZZ("115792089210356248762697446949407573529996955224135760342422259061068512044369");
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

    /*
CRV.name="eccp256r1";
CRV.p = to_ZZ("115792089210356248762697446949407573530086143415290314195533631308867097853951");
CRV.a = to_ZZ("115792089210356248762697446949407573530086143415290314195533631308867097853948");
CRV.b = to_ZZ("41058363725152142129326129780047268409114441015993725554835256314039467401291");
CRV.seedE = to_ZZ("1122468115042657169822351801880191947498376363664");
CRV.G.x = to_ZZ("395815829005855038029765540278861637762572903522963440114216832740821793555094");
CRV.G.y = to_ZZ("3600254559212783631020592788373957154744735408555473783510957625074434451321");
//59240149723730851812311272008153533141816437726696305166080887910572446982458012615605924465554721774228350039774385670824392793454808075284049927019123189");
CRV.G.z=1;
CRV.n = to_ZZ("115792089210356248762697446949407573529996955224135760342422259061068512044369");
CRV.h = 1;
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
}

if(n==2566){
  
CRV.a=to_ZZ("58619423044276027832903787065716086236095439918520509851335164825122761913928");
CRV.b=to_ZZ("5156151719105706093936546029546688635963459581307566382625017622890757039103");
CRV.n=to_ZZ("101770390931234937383997936042792106563662471655141560935801449392638687313903");
CRV.p=to_ZZ("101770390931234937383997936042792106564300501093118320554795276781573252710547");
CRV.G.y=to_ZZ("98399506821057818865862588903161792587668472549669649472059793708337005935795");
CRV.G.x=to_ZZ("28663290192706932057771677870920156363737430016916930158558409220429370107804");
CRV.G.z=1;
}

if(n==384){
//  Group order=
CRV.n=to_ZZ("5628858028056354173182720014306230543582819895780778095420563755345515056616034903125147135939193286284507539411263");
CRV.a= -3;
CRV.b= to_ZZ("7480836070348502192310144960168319822230417316926886013721948420378391982808980728605112950230878688086816085055381");
CRV.p=to_ZZ("39402006196394479212279040100143613805079739270465446667948293404245721771497210611414187026722401376469034446356971");
//R= 5628858028056354173182720014306230543582819895780778095420563755345515056616034903125147135939193286284507539411263 a 382 bit prime
CRV.G.x= to_ZZ("13839325240143548436618097820237988853510646421495011597727751118065256776775190573162986203269450299582183630276103");
CRV.G.y= to_ZZ("33479584122550753431257252642915332781925124384694439200422942083526531640009189112108669026825242814943349686581134");
CRV.G.z=1;
  }
  
}




ZZ isqrt(ZZ x){
ZZ t,s;

  /*
  if(x==0)
    return 0;
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


void jadd(ZZ x1,ZZ x2,ZZ y1,ZZ y2,ZZ z1,ZZ z2,ZZ mod){
ZZ u1,u2,s1,s2,h,r,rev,reb,re6;

if(x1==x2 && y1==y2 && z1==z2){
    cout <<"infinity devide1\n";
    cout << "Y1=" <<  y1 << "\n";
    cout << "Y2=" << y2 << "\n";
    exit(1);
 }

u1=x1*z2*z2;
u2=x2*z1*z1;
s1=y1*z2*z2*z2;
s2=y2*z1*z1*z1;
h=u2-u1;
r=s2-s1;
P.x= (-h*-h*-h-2*u1*h*h+r*r)%mod;
P.y= (-s1*h*h*h+r*(u1*h*h-P.x))%mod;
P.z= (z1*z2*h)%mod;

//=begin
rev=inv(P.z,mod);
reb=inv(P.z*P.z,mod);
re6=inv(P.z*P.z*P.z,mod);
P.x=reb*P.x%mod;
P.y=re6*P.y%mod;
P.z=rev*P.z%mod;

if(P.y*P.y%CRV.p != (P.x*P.x*P.x+CRV.a*P.x*P.z*P.z*P.z*P.z+CRV.b*P.z*P.z*P.z*P.z*P.z*P.z)%CRV.p){
  cout << "err jadd\n";
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
t= -2*s+m*m;
Q.x= t%CRV.p;
Q.y= (-8*(y*y*y*y)+m*(s-t))%CRV.p;
Q.z= 2*y*z%CRV.p;


if(Q.y*Q.y%CRV.p != (Q.x*Q.x*Q.x+CRV.a*Q.x*Q.z*Q.z*Q.z*Q.z+CRV.b*Q.z*Q.z*Q.z*Q.z*Q.z*Q.z)%CRV.p){
  cout << "err jdbl\n";
  exit(1);
}

}


//make a calcration table from base point Q
void mktbl3(ten T){
ZZ pp,xx,yy,zz,a;
int i;
 ten O;
  
//cout <<"in_mktbl3\n";


// print CRV_name ,"\n"
 pp= CRV.p;
// print  pp ,"\n"
 xx= T.x;
// print  xx ,"\n"
 yy= T.y;
// print "y=", yy ,"\n"
zz= T.z;
//print "z!=",zz ,"\n"
 a= CRV.a;
// print  a ,"\n"
// print  CRV_b ,"\n"


 // enzan table
   ll[0].x=xx;
   ll[0].y=yy;
   ll[0].z=zz;
 O.x=xx;
 O.y=yy;
 O.z=zz;
for(i=1;i<256;i++){ //begin Pub_key at plain
if(yy==0){
  cout <<  "Y ga " << i << "\n";
  //     exit()
}

   jdbl(O);
   ll[i].x=Q.x;
   ll[i].y=Q.y;
   ll[i].z=Q.z;

   O.x=ll[i].x;
   O.y=ll[i].y;
   O.z=ll[i].z;
} 
//of for
//cout << "end of mktbl3\n";

}


//Compute Q=mG
void elp3(ZZ k){
int ki[256];
ZZ  L;
po s;
int j,l,i,ii,jj;

  
j=0;
l=0;
if(k<0){
    cout <<"obsense K\n";
    cout << k << "\n";
  exit(1);
}

if(k==0){
    cout << "infinity devide2\n";
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
//cout << L << endl;
//  if(((KK^(1<<i))>>i)%2 == 0) //testbit(KK,i) <- shippai
for(i=0;i<l;i++){
  if(L%2 == 1){
    ki[j]=i;

    j=j+1;
  }
  L=(L>>1);
}
//cout << j << endl;
//exit(1);
  Pub_key.x=ll[ki[0]].x;
  Pub_key.y=ll[ki[0]].y;
  Pub_key.z=ll[ki[0]].z;
//cout << Pub_key.x << endl;
//print "j=",j,"\n"

if(k>0){
  for(i=1;i<j;i++){
    if(Pub_key.x != ll[ki[i]].x || Pub_key.y != ll[ki[i]].y || Pub_key.z != ll[ki[i]].z){

      if(Pub_key.y*Pub_key.y%CRV.p == (Pub_key.x*Pub_key.x*Pub_key.x+CRV.a*Pub_key.x*(Pub_key.z*Pub_key.z*Pub_key.z*Pub_key.z)+CRV.b*(Pub_key.z*Pub_key.z*Pub_key.z*Pub_key.z*Pub_key.z*Pub_key.z))%CRV.p){
  //       cout << "doko2\n";
        if(ll[ki[i]].y*ll[ki[i]].y%CRV.p==(ll[ki[i]].x*ll[ki[i]].x*ll[ki[i]].x+CRV.a*ll[ki[i]].x*(ll[ki[i]].z*ll[ki[i]].z*ll[ki[i]].z*ll[ki[i]].z)+CRV.b*(ll[ki[i]].z*ll[ki[i]].z*ll[ki[i]].z*ll[ki[i]].z*ll[ki[i]].z*ll[ki[i]].z))%CRV.p){
    //       cout << "doko3\n";
          jadd(Pub_key.x,ll[ki[i]].x,Pub_key.y,ll[ki[i]].y,Pub_key.z,ll[ki[i]].z,CRV.p);
        Pub_key.x=P.x;
        Pub_key.y=P.y;
        Pub_key.z=P.z;
        if(Pub_key.x==0 && Pub_key.y==0 && Pub_key.z==0){
          //	if( Pub_key_z==0)
          cout << Pub_key.x << "," << Pub_key.y << "," << Pub_key.z << "\n";
          cout << "infinity devide3\n";
            exit(1);
        }
        // print "doko4\n"
        }

      //print "end1\n"
      }
    //print "end2\n"
    }
  //     print "end3\n"
  if(Pub_key.x == ll[ki[i]].x && Pub_key.y == ll[ki[i]].y && Pub_key.z == ll[ki[i]].z){
    
    //print "ecole\n"
    jdbl(Pub_key);
      cout << "edb2(" << Pub_key.x  <<  Pub_key.y  <<  Pub_key.z << ")\n";
        exit(1);
  }
  // print "in for loop " , i , " ";
  }
  

}

// no return --  print "after return\n"
}


//unsigned char gf[16]={0,1,2,4,8,9,11,15,7,14,5,10,13,3,6,12};
//unsigned char fg[16]={0,1,2,13,3,10,14,8,4,5,11,6,15,12,9,7};
//unsigned char gf[256]={0,1,2,4,8,16,32,64,128,29,58,116,232,205,135,19,38,76,152,45,90,180,117,234,201,143,3,6,12,24,48,96,192,157,39,78,156,37,74,148,53,106,212,181,119,238,193,159,35,70,140,5,10,20,40,80,160,93,186,105,210,185,111,222,161,95,190,97,194,153,47,94,188,101,202,137,15,30,60,120,240,253,231,211,187,107,214,177,127,254,225,223,163,91,182,113,226,217,175,67,134,17,34,68,136,13,26,52,104,208,189,103,206,129,31,62,124,248,237,199,147,59,118,236,197,151,51,102,204,133,23,46,92,184,109,218,169,79,158,33,66,132,21,42,84,168,77,154,41,82,164,85,170,73,146,57,114,228,213,183,115,230,209,191,99,198,145,63,126,252,229,215,179,123,246,241,255,227,219,171,75,150,49,98,196,149,55,110,220,165,87,174,65,130,25,50,100,200,141,7,14,28,56,112,224,221,167,83,166,81,162,89,178,121,242,249,239,195,155,43,86,172,69,138,9,18,36,72,144,61,122,244,245,247,243,251,235,203,139,11,22,44,88,176,125,250,233,207,131,27,54,108,216,173,71,142};
//unsigned char fg[256]={0,1,2,26,3,51,27,199,4,224,52,239,28,105,200,76,5,101,225,15,53,142,240,130,29,194,106,249,201,9,77,114,6,139,102,48,226,37,16,34,54,148,143,219,241,19,131,70,30,182,195,126,107,40,250,186,202,155,10,121,78,229,115,167,7,192,140,99,103,222,49,254,227,153,38,180,17,146,35,137,55,209,149,207,144,151,220,190,242,211,20,93,132,57,71,65,31,67,183,164,196,73,127,111,108,59,41,85,251,134,187,62,203,95,156,160,11,22,122,44,79,213,230,173,116,244,168,88,8,113,193,248,141,129,100,14,104,75,223,238,50,198,255,25,228,166,154,120,39,185,181,125,18,69,147,218,36,33,138,47,56,64,210,92,150,189,208,206,145,136,152,179,221,253,191,98,243,87,212,172,21,43,94,159,133,61,58,84,72,110,66,163,32,46,68,217,184,124,165,119,197,24,74,237,128,13,112,247,109,162,60,83,42,158,86,171,252,97,135,178,188,205,63,91,204,90,96,177,157,170,161,82,12,246,23,236,123,118,45,216,80,175,214,234,231,232,174,233,117,215,245,235,169,81,89,176};
//unsigned char F[16]; //={131, 94, 131, 129, 131, 84, 131, 140, 131, 139, 131, 95, 131, 67, 131, 96};


/*=begin
ECDSA signature eneration and verification
To sign a meddahe m, an entry A with domain parameters D=(q,FR,a,b,G,n,h)
and associated key pair (d,Q) does the following

1. Select a random or pseudorandom integer k, 1<=k<=n-1
2. Compute kG=(x1,y1) and r=x1 mod n. If r=0 then goto step1.
3. Compute k^{-1} mod n.
4. Compute e=sha1(m)
5. Compute s=k^{-1}(e+dr)mod n. If s=0 then goto step1.
6. A's signature for the message m is (r,s).
=end
*/
po rs;
po ecdsa(ZZ k,ZZ e,ZZ d){
  ZZ r,s;

  cout<< "in_ecdsa\n";

  init_curve(256);
  mktbl3(CRV.G);
    if(k<0){
      cout << "k is obsense in ecdsa\n";
      exit(1);
      }

  elp3(k);
  //#  print "Ex= " , e_x , "\n";
  r=P.x%CRV.n;
    cout << r , "\n";
    k=inv(k,CRV.n);
    //  #  e=sha(argc,argv);
      s=(k*(e+d*r))%CRV.n;
      cout << s << endl;
      //#  print "k=", k, "\n"
      //#  print "d=", d, "\n"
      //#  print "e=", e, "\n"
      rs.x=s;
      rs.y=r;
      
      return rs;

}

/*
=begin
ECDSA signature velification
1. Verify that r and s are integers in the interval[1,n-1]
2. Compute e=sha1(m)
3. Compute w=s^{-1} mod n.
4. Compute u1=ew mod n and u2=rw mod n.
5. Compute X=u1G+u2Q. If X=O, then reject the signature. Otherwise, compute
v=x1 mod n where X=(x1,y1)
6. Accept the signature if and only if v=r.
=end
*/
void vr_ecdsa(ZZ s,ZZ r,ZZ e){
  ZZ w,u1,u2,gx,gy,gz,qx,qy,qz,xx,yy,v,zz;
  FILE *fp;
  unsigned char key[32*3];
  ZZ I,px,py,pz;
  int i;
  ten T;

  cout << "in_vr_ecdsa\n";
  fp=fopen("eccpub.key","rb");
  fread(key,1,sizeof(key),fp);
  fclose(fp);

  I=0;px=py=pz=0;
  for(i=0;i<32;i++){
    I=key[i];
    px^= I<<(i*8);
  }
  for(i=0;i<32;i++){
    I=key[i+32];
    py^= I<<(i*8);    
  }
  for(i=0;i<32;i++){
    I=key[i+64];
    pz^= I<<(i*8);
  }
  T.x=px;
  T.y=py;
  T.z=pz;

  //  #  e=sha(argc,argv);
    w=inv(s,CRV.n);
    u1=e*w%CRV.n;
    //  #  cout << "u1=" << u1 << endl;
    u2=r*w%CRV.n;

    cout << "Gen_key\n";
    mktbl3(CRV.G);
    elp3(u1); // #G=
    gx=P.x;
    gy=P.y;
    gz=P.z;

    mktbl3(T);
    elp3(u2);// #Q=
    qx=P.x;
    qy=P.y;
    qz=P.z;

    if(gx==qx && gy==qy){
      cout << "equal point\n";
      exit(1);
    }


    if(gx!=qx){
      jadd(gx,qx,gy,qy,gz,qz,CRV.p); // #X=
      xx=P.x;
      yy=P.y;
      zz=P.z;
      }
    v=xx%CRV.n;
    cout << "r is " , r , "\n";
    cout << "v is " , v , "\n";

  if(v==r)
    cout << "That's true!\n";

  if(v!=r)
    cout << "baka\n";
 
}




void genkey(unsigned char str[256],unsigned char t[256] ){
FILE *fp,*fq;
  unsigned char *filename;
  unsigned char buf[256];
  int i;

  printf("genkey\n");
/*
  if(fp=fppen("key.bin","rb")!=NULL){
    cout << "既に鍵ファイルが存在します。新しい鍵ファイル名を入力してください。\n";
    cin >> filename;
  }
  */
  //cout << str << endl;
  cout << t << endl;

  

  hasha(t);
  fp=fopen("seed.key","wb");
  fwrite(c1.dd,1,16,fp);
  fwrite(c2.dd,1,16,fp);
  hasha(str);
  fwrite(c1.dd,1,16,fp);
  fwrite(c2.dd,1,16,fp);
  cout << "共有鍵seed.keyが生成されました。" << endl;
  fclose(fp);

}


void ecdh(){
  ZZ ax,ay,az,b,cx,cy,cz,bf[32],I,key;
  FILE *fp,*fq;
 unsigned char buf[32],buff[4],str[32*3],tt[256];
  int i,j,nn,II[32*3];
  ten X;
  
  fp=fopen("key.bin","rb");
  fread(buf,1,32,fp);
  fclose(fp);
  init_curve(256);
  mktbl3(CRV.G);
  if(fp==NULL){
    cout << "鍵ファイルが見つかりません。" << endl;
    exit(1);
  }
  I=key=0;
  for(i=0;i<32;i++){
    I=buf[i];
    key^=I<<(i*8);
  }
  elp3(key);
  X=P;
  

  for(i=0;i<32;i++){
    bf[i]=X.x%256;
    X.x=(X.x>>8);
    conv(II[i],bf[i]);
  }
  for(i=0;i<32;i++){
    bf[i]=X.y%256;
    X.y=(X.y>>8);
    conv(II[i+32],bf[i]);
  }
  for(i=0;i<32;i++){
    bf[i]=X.z%256;
    X.z=(X.z>>8);
    conv(II[i+64],bf[i]);
  }
  for(i=0;i<32*3;i++){
    str[i]=II[i];
  //  cout << to_ZZ(str[i]);
  }
  cout << "認証パスワードを設定します\n";
  freopen("con","r",stdin);
  scanf("%s",&tt);
  cout << "in_" << tt << endl;
  hasha(tt);
  
//  exit(1);
  
  genkey(str,tt);
  
  
//  lk(tt);
  fclose(fp);
  
}

void keygen(ZZ r){
  //  ZZ r;
  FILE *fp;
  unsigned char c[32*3];
  int i;

  fp=fopen("eccpub.key","wb");
  init_curve(256);
  mktbl3(CRV.G);
  //  cin >> r;
  elp3(r);
  cout << "y=" << Pub_key.y << endl;

  for(i=0;i<32;i++){
    c[i]=Pub_key.x%256;
  Pub_key.x= Pub_key.x>>8;
  }
  for(i=0;i<32;i++){
    c[i+32]=Pub_key.y%256;
  Pub_key.y= Pub_key.y>>8;
  }
  for(i=0;i<32;i++){
    c[i+64]=Pub_key.z%256;
  Pub_key.z= Pub_key.z>>8;
  }
  
  fwrite(c,1,sizeof(c),fp);
  fclose(fp);
  for(i=0;i<32*3;i++)
    c[i]=0;
  for(i=0;i<32;i++){
    c[i]=r%256;
    r=(r>>8);
  }
  fp=fopen("eccsec.key","wb");
  fwrite(c,1,32,fp);
  fclose(fp);

  exit(1);
}


void mv(char *argv[],int nn){
  FILE *fp,*fq,*fr;
  ZZ salt,buf[32],aa,II;
  int i,read_size,ii,c,k,a,j,count=0,cnt=0,I[32];
 unsigned char buff[SIZE],str,*e,m[32],ai[32],key[32*3];
unsigned char* to;
 ten X;
  
 init_curve(nn);
 // salt=sha2(2,argv);
   cin >> salt;
  //  salt=SecureRandom.random_number(2**(32*8));
  //cout << "P.x=" << P.x << "\n";
//cout << "P.y=" << P.y << "\n";
//cout << "P.z=" << P.z << "\n";
  

  fp = fopen(argv[1],"rb");
  fq = fopen(argv[2],"wb");

mktbl3(CRV.G);
elp3(salt);
 cout << "yr=" << Pub_key.y << endl;

 for(i=0;i<32;i++){
   key[i]=Pub_key.x%256;
 Pub_key.x= Pub_key.x>>8;
 }
 for(i=0;i<32;i++){
   key[i+32]=Pub_key.y%256;
 Pub_key.y= Pub_key.y>>8;
 }
 for(i=0;i<32;i++){
   key[i+64]=Pub_key.z%256;
 Pub_key.z= Pub_key.z>>8;
 }
 fwrite(key,1,sizeof(key),fq);
  

 fr=fopen("eccpub.key","rb");
 fread(key,1,sizeof(key),fr);
 fclose(fr);

  // cin >> Pub_key.x;
  // cin >> Pub_key.y;
  // cin >> Pub_key.z;

  Pub_key.x=0;
  Pub_key.y=0;
  Pub_key.z=0;
  for(i=0;i<32;i++){
    II=key[i];
    Pub_key.x^= II<<(i*8);
}
  for(i=0;i<32;i++){
    II=key[i+32];
    Pub_key.y^= II<<(i*8);
}
  cout << "py=" << Pub_key.y << endl;  
  for(i=0;i<32;i++){
    II=key[i+64];
    Pub_key.z^= II<<(i*8);
}
  
  mktbl3(Pub_key);
  elp3(salt);

  X.x=Pub_key.x;
  X.y=Pub_key.y;
  X.z=Pub_key.z;
  cout << "y=" << X.y << endl;

for(i=0;i<32;i++){
  I[i]=0;buf[i]=0;ai[i]=0;
  }


 while((read_size=fread(buff,1,32,fp))>0){
  for(i=0;i<read_size;i++)
      ai[i]=buff[i];

  c=0;
  salt=0;
  for(i=0;i<read_size;i++){
    II=to_ZZ(ai[i]);
    salt^= II<<(i*8);
  }
  //  salt^=to_ZZ(ai[read_size-1]);
  c=0;

//    cout << "r=" << read_size << endl;
  jadd(X.x,CRV.G.x,X.y,CRV.G.y,X.z,CRV.G.z,CRV.p);

  salt^=P.y; //%(256*read_size);

  X.x=P.x;
  X.y=P.y;
  X.z=P.z;
  i=read_size-1;
j=0;



 for(i=0;i<32;i++){
    //  cout << i << endl;
    buf[i]=salt%256;
    conv(I[i],buf[i]);
    salt=(salt>>8);
  }

    for(i=0;i<32;i++)
      m[i]=(unsigned char)I[i];

//  if(read_size==32){
    fwrite(m,1,32,fq);
}

  fclose(fp);
  fclose(fq);

}




void dec(char *argv[],int nn){
  ZZ salt,buf[32],a,II,r;
ten R;
 unsigned char buff[32],ai[32],key2[32],key[32*3];
 FILE *fp,*fq,*fr;
int read_size,i,I[32],j,count=0,cnt=0;
unsigned char m[32];
  
  
printf("in dec\n");
init_curve(nn);
 fr=fopen("eccsec.key","rb");
 fread(key2,1,32,fr);
 fclose(fr);

 r=0;
 for(i=0;i<32;i++){
   II=key2[i];
   r^=(II<<(8*i));
   }
 //  cin >> Pub_key.x;
 // cin >> Pub_key.y;
 // cin >> Pub_key.z;


  R.x=0;
  R.y=0;
  R.z=0;
fp = fopen(argv[2],"wb");
fq = fopen(argv[1],"rb");
 fread(key,1,32*3,fq);
 for(i=0;i<32;i++){
 II=key[i];
 R.x^=II<<(i*8);
 }
 for(i=0;i<32;i++){
 II=key[i+32];
 R.y^=II<<(i*8);
 }
 for(i=0;i<32;i++){
 II=key[i+64];
 R.z^=II<<(i*8);
 }
  mktbl3(R);
  elp3(r);
  //cout << "dcPubkey.x=" << Pub_key.x << "\n";
  cout << "dcPubkey_y=" << Pub_key.y << "\n";
  //cout << "dcPubkey.z=" << Pub_key.z << "\n";
  //salt=0;

while(read_size = fread(buff,1,32,fq)){
//  cout << "r=" << read_size << endl;
  salt=0;
  for(i=0;i<read_size;i++){
 //   cout << to_ZZ(buff[i]) << endl;
    II=to_ZZ(buff[i]);
    salt^= II<<(i*8);
  }
//  exit(1);
// salt^=to_ZZ(buff[read_size-1]);

 //padding
  a=salt;
  while(a>0){
    j++;
    a=(a>>8);
  }


  jadd(Pub_key.x,CRV.G.x,Pub_key.y,CRV.G.y,Pub_key.z,CRV.G.z,CRV.p);
  salt^=P.y; //%(256*read_size));
  //cout << salt << endl;
//  exit(1);
a=salt;
 Pub_key.x=P.x;  
 Pub_key.y=P.y;  
 Pub_key.z=P.z;  

   for(i=0;i<32;i++)
     I[i]=0;
    for(i=0;i<read_size;i++){
      buf[i]=salt%256;
      conv(I[i],buf[i]);
      salt=(salt>>8);
    }

  j=0;
  for(i=0;i<read_size;i++){
    m[i]=(unsigned char)I[i];
    //    j++;
  }

    fwrite(m,1,read_size,fp);

//  printf("dec=%d\n",read_size);
}

  fclose(fp);
  fclose(fq);

}



/*
def otp(x,nn)

init_curve(nn)

r=[0xf874f8444567019dae5d0686dd04f2615204d38875190df1f54af6,0xe814985c80ee06915a0ab4580dd00fe97b37dc2e84110ff5fd6f7a,0xc854f064ce120797a3b76389d309f9711c5cbc51a7140cfbfd2efb,0xe814d03c85dc089feaf00ce85d805f4415c30c467201a0cfcf2f8ef,0xf834d8648cdd0f925ac0fcf84d80bfd190364c59c6e1d06fafc9fed,0xc844a82c9d580f9eca708ef8ada0bfe19547195809f190af9f3d863,0xf04ce82c58030f97da0d1188fdd0cf421035ec231911b03f5f2da40,0xd024f8442d2c009ba497998cd301f1713b1ea021ad1808fcf226e4,0xc87c800463fa0b965aa983c8bd90efc712331a2dc4d1506fcf29a5b,0x9864801c5d0706973a8de1885dd08f671635af27299130af1f26348,0xc82ca0442d2e039ada09b9580db03fb311b35ab2c0d1f0afff8db2e,0x9024f05431370f96dab2caf81d504fe415346894a511b09f1f70d22,0xd01ca824540f08989aad31c80d607f497b2396401c1509f7f4d2af,0x901cb04c4fc5059ccafe75980d20cf961137eb957a91a0ef5f824f5,0xe02cd00c54c6059e7ab4e3885d203f3213301a55590180cfafa2c57,0xa07cb0745d040591ca4dd1c89d109f1390461fa641a100df8f0ece3,0xc034b05c4863039f5a3570b8bdb03ff614b75b24f04110bf1f11075,0x9844f00488df0b96a807ce84d005fc39232ac5dda11b01f2fb3198,0xe82c905c5a0204978a2dd1388d600f5495418fe17c2150cf8f32e3b,0x903cf8442c270497aa694988dda00f5393b20d0db1e1e04f2fe7b0c,0xe05c903c81df0e9e4a10fcb88d208f5412c24bf43cc1102fef7aae2,0x800cb0045a0605909aad11980df0efc513b219a2d291e0cfef0ff6a,0xf034e83caf5d05912af6cf189db05f9313b33958c7e1f09f0f7f425,0xd02c887cc4130d9c7acb16e85db00f1614334fec5b41101f1f74d85,0x9004a86457c20e9aca44e3a8cd90ef0293b3eac8192190bf8f2da66,0xe864d8143b310d96fa629a385d304fc692b0ed578191402f4f89fb0,0x904c800c570a0896bacd81d86db04f4194369c995fb1a04fdfbfb03,0xd85cf0048ade0898fabb51385d904fa395424dc9ac51503f0fec3a0,0xe86ca8544ecd079faace75781da05f2291427be39931b0ffff0d841,0xf87c986c21210892ead9b9482d80df6494376b091c01e02fcfac7aa,0xd83c8014313b0b901aa20a68ed90df1115c3fd919df1b0df4fc193f,0x883c805ca45c04901a969f384dd01ff690c22b845cb1f0df4f8a9ef,0x8864906c48ce02994a3e55f83d807fa793b01957a5e1900f0fefa8a,0xe0149834446706988a1590b89d30dfb710c3cd7adf91108fffc9c17,0xb02cf0744ec40c9bca7e45280de09f26742aae5fa51002fff82aff,0xa864e07c66f703946aa9b328bd904f871033184602e130ef7fefbe5,0xb824c87494f305966abb42680dd0ef0695c6ce234d1506fdfad977,0x8044f02c5c000c9b4a0d41884de07f495416ec7f901301f6f06f4c,0xd87c887ccb8904974a6981b87d009fa313b34cb4e6a160efaf97097,0x885cb8642d210197ba5939086d804fb69035cae252d160bf3f1f067,0xc074880c80d80b99dab0ec48ed107f31437cad8da1701f0f78483,0x986cb82c4d6c0c968a551078fd20df6614b33b44db01302f5f64ba3,0xe87cb0748bd70098da1b01883db0ff571230feed8321e0cf0f1767a,0xd82cd81c4fc80c92ba8e65788d604ff492b0cdcec141e0df5f4cec2,0x9824987c35350897fa523a287d008f3790356905e601502f9f3b3df,0xf064b054252907975ae999582d907f3690b70b286761007fbf0f920,0xa004c06c81dc029dda10fcf8ed905f31532c9eacd71b0ef3f75cc8,0xa06cd84c310c0d9c9a5dc248bd40af3292b569b47bf1802f1fc49a0,0xe834a0245bc6079f9a44d3d83dd09f1316c1fd645691f04f2fe14ba,0xd86cf83c2f260d9cbac949681d705f1712c42f861501701f8f269dd];
c=[0x8014b87450cd0a96fac4b3389d504f6297b1dd23d51101fcf38a80,0x9044a0145c0b099d8a0d7128ad708f02963039499f31a06f6f7fd08,0xa054e86480e00f9e4a4ad478cd909f7396b04ef8e7e160dfcf9fe2d,0xe01c882487da0b948aebe1c87d30bf7390c63d9ea13150dfbf5cfcb,0xc034882c58c90692fa9493085d308fc311316d34fc11600ffffaae1,0x8024d07c3a360c99ac2ca08ed60bf41e1c49f292f01807fdf3f80a,0xa804d02c406a07982a85d0281d401fa514b6cd7a8d61f00f2f555cc,0xb864b07ca9560495a56af08dd20af3510b36f3887d1e08f5fc4af0,0xd064c06c86e70b959abad4481db0af4795c6fb5ed041709f5f69ab2,0x907c90148ce60e95eaea24b80d80ef731631ac925011b0af8f3d627,0xb854c86c390c01904a8d12989d809fa795b4ec18a98140df8ffda6e,0x8054d0244cc50b919abe7558bde05f4394c36ed5da41d07fff8acc7,0xe05c984c446307954a4500c82dd0cf4314b218bd34a1109f8f14bc6,0xa824b03480e20497ca0af418cd704f079436793e3b2140cfef8fc45,0xa004f0448bd90896a60dc785d90cf293b6cd881771b02f6fc47fc,0xa034e8145a050e9a3a3d81a8ed108f649241fc4268c1c0cf4f26771,0xf82c90043935029f2ab21a282da01f2513b15c599641405f3f39ee2,0xa874e81c2528009f9a69e928ad909f5110b31c24c1d1c0ff4f5dba8,0x807c884c80d401935a506ca8fd10ff1792b06a9ab0d1707f1fad1d4,0x883cb83c6ef400968ac9e308bd80ff2914169394e21504fef3a413,0x987cb86c89de069dea5bc158bda00fd590b498f55a91e0df1f721f9,0xd85cc04c340d08999a3d22b81d309f7197b69ec65521a05f0f968d0,0x885cc8744b6900994ae5a0382d80ff2695b45c36717150cf0fce3ea,0xa01cf874c51b0496ba0b26486d800ff690c7db586671a0cf2feb795,0xe84cb00c50010195dabdd1f84d60bfe293468b72de1a05f3fc8086,0xc814a07c81ea049eafa34e8ed50cf4314c4b8fe5101309f7f6cfca,0xe804d02c52020c9f1a9d61882d50af5416316c32d811d0ef8f7637c,0xa07cf07489d708902a50ec685d005fc394b6dfca8001b01f0f0d9d9,0xf034a80caa5f059e1a16ff988d900f069331eb2d1a71807fdf93599,0xc024c044590204942afdf1188d400f592358b6a9d5190df4fa5aca,0xb83ce87c59cf0a9d1ad4e328ad40df341545edb5d9f180bfcf92c52,0xf044c014370f019d9add52580d505f9112361fb44c11203f0fcaeea,0xa014900482e4079afafab4288d408fd295450b52605120df9fdd92d,0xc01cb06c3b340498baf28ac8cd400fa614c66816961e0ef3ff8ee9,0x8844a87ca45d06993a66dff84d40dff515c2a954c77150efbfd872f,0xa834d04c4e6807924a15c0a8adc08fb51240b9986711f05f1f64df6,0xe064f07438390896ea82aa28fd108f41032eb4c3be1909fbf24080,0x8024f82c5703089fa7df118ed702fa792b6f84dca21500fefa3b9c,0x981cf80c88d00e92fa805c884d004fd417c68fe1bc21e00f9fc2338,0x9844e8643c3906988ad24a18fd600f1116c69f0808b1a09f6f4b6cf,0xf814c82447cd0497ca1ed598ed701f7195b28b34de160cfdf4898a,0xe864e86c85d80e917a40fc68ada05fe69230be7e8961805f1fadcb3,0x884cd83cc61907945abb1688fd001fa39345ef190e81c04fdf7a61d,0xf854a01c98f703986acbf2386d305f710361c67b59140ef5f3fe83,0x8034f074af5c06958a66ffb80d109ff596b13cc19c71009f6fd2536,0xe07c8874320f0f967aeda298bd908fe293471f027a71409fcf822ea,0xc824802c5c090c9aaaad91680d90efc596b39a5cda130af2fa858f,0xa07ca82c98550291cac09e58edd07f5591c2b9f307f1a01f9f70b5b,0xc024904cc413079ea4b3658adf0ff7712b03d2bba31609f5fcd069,0x8014c02450080b9ecacd11d84d509fb19042ead38931a09f6f6dd49]
a.x=[50]
a.y=[50]
a.z=[50]
b=[50]

mktbl3(CRV.G.x,CRV.G.y,CRV.G.z)
//ellip(CRV_n)
//exit()

flag=0
elp3(x)
y.x=Pub_key.x
y.y=Pub_key.y
y.z=Pub_key.z
d.x=[50]
d.y=[50]
d.z=[50]
e.x=[50]
e.y=[50]
e.z=[50]

for i in 0..49
  elp3(r[i])
  a.x[i]=Pub_key.x
  a.y[i]=Pub_key.y
  a.z[i]=Pub_key.z
  print r[i],"\n"
end
for i in 0..49
  b[i]=(r[i]-c[i]*x)%CRV.n
  print "b=",b[i],"\n"
end
for i in 0..49
  elp3(b[i])
  d.x[i]=Pub_key.x
  d.y[i]=Pub_key.y
  d.z[i]=Pub_key.z
  print "dx=",d.x[i],"\n"
end
for i in 0..49
  elp3(c[i]*x)
  e.x[i]=Pub_key.x
  e.y[i]=Pub_key.y
  e.z[i]=Pub_key.z
  print "c=",c[i],"\n"
end
//exit()
for i in 0..49
  jadd(d.x[i],e.x[i],d.y[i],e.y[i],d.z[i],e.z[i],CRV.p)
  if(P.x!=a.x[i] || P.y!=a.y[i] || P.z!=a.z[i])
	//print "i=",i,"\n"
    flag=1
  end
end
  if(flag==0)
    print "That's True !\n"
  end
  if(flag==1)
    print "baka\n"
  end

end
*/



void logcom(int nn,int argc,char *argv[]){
int  j=0;
ZZ  plain[21],ai,nha,r;
ten v,c,gr,vm;
combo e;


init_curve(nn);
mktbl3(CRV.G);
//elp3(CRV_n)
//print eccp192 ,"\n"


// print secp128r1_p ,"\n"


 //schlor bai
   plain[0]=to_ZZ("30166869646807636562727106419");
   plain[1]=to_ZZ("10045117565996920939000919144");
   plain[2]=to_ZZ("30153181069665353679546770802");
   plain[3]=to_ZZ("10033396893489366934389337632");
   plain[4]=to_ZZ("22631414519632726019188813428");
   plain[5]=to_ZZ("10044280489496830406925033588");
   plain[6]=to_ZZ("32308695848121561557187447072");
   plain[7]=to_ZZ("21179691622725275949743743092");
   plain[8]=to_ZZ("32308695848121561556958080800");
   plain[9]=to_ZZ("30765204363694166514334572576");
   plain[10]=to_ZZ("26119354342939208172857421088");
   plain[11]=to_ZZ("30059276595547511335976247399");
   plain[12]=to_ZZ("34493224637425338651624109358");
   plain[13]=to_ZZ("22631636489395346365953810503");
   plain[14]=to_ZZ("34473881935204201160487432814");
   plain[15]=to_ZZ("32629405756452437358033266789");
   plain[16]=to_ZZ("10024939110908884670107837728");
   plain[17]=to_ZZ("36265758736633729355313211168");
   plain[18]=to_ZZ("30151120555452877393537363824");
   plain[19]=to_ZZ("33546635831558563763501754217");
   plain[20]=to_ZZ("34161127499042836141910073459");
   

//plain text


 //encryption
ai=plain[1];
//cout << "r1=" << ai << "\n";
elp3(ai);
v.x=Pub_key.x;
v.y=Pub_key.y;
v.z=Pub_key.z;
//print v_x, " ",v_y,"\n"

e=hash2(argc,argv);
nha^=e.e1.dd[0];
nha=(nha<<64);
nha^=e.e1.dd[1];
nha=(nha<<64);
nha^=e.e2.dd[0];
nha=(nha<<64);
nha^=e.e2.dd[1];

cout <<"mha=" << nha << "\n";
mktbl3(v);
elp3(nha);
c.x=Pub_key.x;
c.y=Pub_key.y;
c.z=Pub_key.z;
//print c_x, " ",c_y,"\n"
cin >> r;
cout << r << endl;
mktbl3(CRV.G);
elp3(r);
gr.x=Pub_key.x;
gr.y=Pub_key.y;
gr.z=Pub_key.z;
  jadd(gr.x,c.x,gr.y,c.y,gr.z,c.z,CRV.p);
Gen_key.x=P.x;
Gen_key.y=P.y;
Gen_key.z=P.z;
if((Gen_key.y*Gen_key.y)%CRV.p!=((Gen_key.x*Gen_key.x*Gen_key.x)+CRV.a*Gen_key.x*Gen_key.z*Gen_key.z*Gen_key.z*Gen_key.z+CRV.b*Gen_key.z*Gen_key.z*Gen_key.z*Gen_key.z*Gen_key.z*Gen_key.z)%CRV.p){
cout << "error!!\n";
exit(1);
}

if((Gen_key.y*Gen_key.y)%CRV.p==((Gen_key.x*Gen_key.x*Gen_key.x)+CRV.a*Gen_key.x*Gen_key.z*Gen_key.z*Gen_key.z*Gen_key.z+CRV.b*Gen_key.z*Gen_key.z*Gen_key.z*Gen_key.z*Gen_key.z*Gen_key.z)%CRV.p){
  cout << argv[1] << "'s Log Commitment is " << "\n";
  cout << "x=" << Gen_key.x << "\n";
  cout << "y=" << Gen_key.y << "\n";
  cout << "z=" << Gen_key.z << endl;
}

}


//
//otp(133,2244)

int ecc(int argc,char *argv[]){
  unsigned char *str,m[32],s[32],ss[64];
  ZZ x,y,z,salt;
  int i,n,mm[32];
  FILE *fp;
//  cout << "input ecc 256,2562,2563,2564,2565" << endl;
//  cin >> i;
  n=256;
  init_curve(n);
  //logcom(256,argc,argv);
  //exit(1);

  fp=fopen("key.bin","rb");
  if(fp==NULL){
    printf("鍵ファイルがありません。\n");
    exit(1);
  }
  fread(m,1,32,fp);
  salt=0;
  for(i=0;i<32;i++)
    salt=(salt<<8)^m[i];

  fclose(fp);
  if(!strcmp(argv[1],"x") && argv[2]==NULL){
    cout << "ecdh Version 0.01α　\n 実行ナンバーを指定してください。" << endl;
    cout << "０：自分の公開鍵を生成する。" << endl;
    cout << "１：鍵ファイルにDSA2署名を生成する" << endl;
    cout << "２：受信した鍵の署名を検証する" << endl;
    cout << "３：相手の公開鍵を入力して共有鍵を生成する" << endl;
    exit(1);
  }
  if(salt<1){
    cout << "鍵が不正です。" << endl;
    exit(1);
  }
  
  if(!strcmp(argv[2],"0")){
    keygen(salt);
	exit(0);
  }
  if(!strcmp(argv[2],"3")){
    ecdh();
	exit(0);
  }
  if(!strcmp(argv[2],"1")){
    dsa2(argc,argv);
	exit(0);
  }
  if(!strcmp(argv[2],"2")){
    dsa2(argc,argv);
	exit(0);
  }
  else if(strcmp(argv[2],"0") && strcmp(argv[2],"1") && strcmp(argv[2],"2") && strcmp(argv[2],"3")){
    cout << "存在しないモードです。" << endl;
    exit(1);
  }

//  ecdh(to_ZZ("12"),to_ZZ("97"),n);

  return 0;
}



int main(int argc,char *argv[]){
  ZZ z,r,d,I,salt;
  int i;
  char m[1];
  FILE *fp;
  unsigned char key[32];
  po sig;
  char file[32];

  if(strcmp(argv[1],"k")==0){
    seed();
    argv[1]="-s";
    argv[2]=password;
    salt=sha2(3,argv);
    keygen(salt);
  }
  
  cout << "input mode\n";
  cin >> m;
  if(strcmp(m,"e")==0)
     mv(argv,256);


  if(strcmp(m,"h")==0){
    cout << "usage:e file encryption;d file decryption;s generate signature;\n";
    return 0;
  }
  if(strcmp(m,"d")==0)
    dec(argv,256);
  
  if(strcmp(m,"s")==0){
    I=0;d=0;
    fp=fopen("eccsec.key","rb");
    fread(key,1,32,fp);
    fclose(fp);
    for(i=0;i<32;i++){
      I=key[i];
      d^= I<<(i*8);
    }
    cin >> r;
    z=sha2(argc,argv);
    sig=ecdsa(r,z,d);
    vr_ecdsa(sig.x,sig.y,z);
  }

return 0;
}
