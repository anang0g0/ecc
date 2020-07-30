/* Elliptic Curve Domain of Parametor */

#include <Integer.h>

//random CM-curves
//cup supp


typedef struct point {
  Integer x;
  Integer y;
} Po;

typedef struct curve {
  char *name;
  Integer a;
  Integer b;
  Integer r;
  Integer n;
  Integer p;
  Integer seedE;
  Po G;
  Po N;
  int h;
  Integer T;
  Integer s;
  Integer bb;
} ECC;


const Po test[28]={
  {0,2},{0,21},{1,11},{1,12},{4,7},{4,16},
  {7,3},{7,20},{8,8},{8,15},{9,11},{9,12},{10,5},{10,18},{11,9},{11,14},
  {13,11},{13,12},{14,5},{14,18},{15,6},{15,17},{17,9},{17,14},{18,9},
  {18,14},{22,5},{22,19}
};


/* p ,seedE, r, a, b, h, n, seedP, Px, Py, seedQ, Qx, Qy */

 ECC eccp521;
 ECC eccp384;
 ECC eccp192;
 ECC eccp256;
 ECC eccp224;
 ECC eccp160;
 ECC eccp161;
 ECC eccp130;
 ECC eccp131;
 ECC eccp190;
 ECC eccp191;
 ECC eccp230;



 ECC tujii;


// Kobliz Curve &
ECC eccp163;
ECC exxp163;
ECC eccp571;
ECC exxp571;
ECC eccp409;
ECC exxp409;
ECC eccp283;
ECC exxp283;
ECC eccp233;



/* generate Galois Field over GF(2^?) */
static char *normal[5]={
"10000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000011001001", /* 2^163 */
"100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000100000000000000000000000000000000000000000000000000000000000000000000000001", /* 2^233 */
"10000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001000010100001", /* 2^283 */
"10000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001000000000000000000000000000000000000000000000000000000000000000000000000000000000000001", /* 2^409 */
"10000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000010000100101", /* 2^571 */
};


static void init_curve(void)
{
//"{0E8920FD-B914-4","P-521","p=2^521-1",

eccp521.name="eccp521";
eccp521.p=atoI("6864797660130609714981900799081393217269435300143305409394463459185543183397656052122559640661454554977296311391480858037121987999716643812574028291115057151",10);
eccp521.seedE=atoI("d09e8800291cb85396cc6717393284aaa0da64ba",16);
eccp521.r=atoI("0b48bfa5f420a34949539d2bdfc264eeeeb077688e44fbf0ad8f6d0edb37bd6b533281000518e19f1b9ffbe0fe9ed8a3c2200b8f875e523868c70c1e5bf55bad637",16);
eccp521.a=atoI("-3",10);
eccp521.b=atoI("051953eb9618e1c9a1a0b68540eea2da725b99b315f3b8b489918ef109e156193951ec7e937b1652c0bd3bb1bf073573df883d2c34f1ef451fd46b503f00",16);
eccp521.G.x=atoI("0c6858e06b70404e9cd9e3ecb662395b4429c648139053fb521f828af606b4d3dbaa14b5e77efe75928fe1dc127a2ffa8de3348b3c1856a429bf97e7e31c2e5bd66",16);
eccp521.G.y=atoI("11839296a789a3bc0045c8a5fb42c7d1bd998f54449579b446817afbd17273e662c97ee72995ef42640c550b9013fad0761353c7086a272c24088be94769fd16650",16);
eccp521.n=atoI("6864797660130609714981900799081393217269435300143305409394463459185543183397655394245057746333217197532963996371363321113864768612440380340372808892707005449",10);


//"{564D7012-E054-4","P-384","p=2^384-2N!N0128-2N!N096+2N!N032-1",

eccp384.name="eccp384";
eccp384.p=atoI("39402006196394479212279040100143613805079739270465446667948293404245721771496870329047266088258938001861606973112319",10);
eccp384.seedE=atoI("a335926aa319a27a1d00896a6773a4827acdac73",16);
eccp384.r=atoI("79d1e655f868f02fff48dcdee14151ddb80643c1406d0ca10dfe6fc52009540a495e8042ea5f744f6e184667cc722483",16);
eccp384.a=atoI("-3",10);
eccp384.b=atoI("b3312fa7e23ee7e4988e056be3f82d19181d9c6efe8141120314088f5013875ac656398d8a2ed19d2a85c8edd3ec2aef",16);
eccp384.G.x=atoI("aa87ca22be8b05378eb1c71ef320ad746e1d3b628ba79b9859f741e082542a385502f25dbf55296c3a545e3872760ab7",16);
eccp384.G.y=atoI("3617de4a96262c6f5d9e98bf9292dc29f8f41dbd289a147ce9da3113b5f0b8c00a60b1ce1d7e819d7a431d7c90ea0e5f",16);
eccp384.n=atoI("39102006196394479212279040100143613805079739270465446667946905279627659399113263569398956308152294913554433653942643",10);
eccp384.h=1;


//"{7DE16579-4B05-4","P-192","p=2^192-2^64-1",

eccp192.name="eccp192";
eccp192.p=atoI("6277101735386680763835789423207666416083908700390324961279",10);
eccp192.seedE=atoI("3045ae6fc8422f64ed579528d38120eae12196d5",16);
eccp192.r=atoI("3099d2bbbfcb2538542dcd5fb078b6ef5f3d6fe2c745de65",16);
eccp192.a=atoI("-3",10);
eccp192.b=atoI("64210519e59c80e70fa7e9ab72243049feb8deecc146b9b1",16);
eccp192.G.x=atoI("188da80eb03090f67cbf20eb43a18800f4ff0afd82ff1012",16);
eccp192.G.y=atoI("07192b95ffc8da78631011ed6b24cdd573f977a11e794811",16);
eccp192.n=atoI("6277101735386680763835789423176059013767194773182842284081",10);
eccp192.h=1;



//"{B858801C-582E-4","P-256","p=2^256-2^224+2^192+2^96-1",

eccp256.name="eccp256";
eccp256.p=atoI("115792089210356248762697446949407573530086143415290314195533631308867097853951",10);
eccp256.seedE=atoI("c49d360886e704936a6678e1139d26b7819f7e90",16);
eccp256.r=atoI("7efba1662985be9403cb055c75d4f7e0ce8d84a9c5114abcaf3177680104fa0d",16);
eccp256.a=atoI("-3",10);
eccp256.b=atoI("5ac635d8aa3a93e7b3bbd55769886bc651d06b0cc53b0f63bce3c3e27d2604b",16);
eccp256.G.x=atoI("6b17d1f2e12c4247f8bce6e563a440f277037d812deb33a0f4a13945d898c296",16);
eccp256.G.y=atoI("4fe342e2fe1a7f9b8ee7eb4a7c0f9e162bce33576b315ececbb6406837bf51f5",16);
eccp256.n=atoI("11579208921035624876269744694940757352999695524135760342422259061068512044369",10);
eccp256.h=1;

//"{CBD61FC1-F50D-4","P-224","p=2^224-2^96+1",
eccp224.name="eccp224";
eccp224.p=atoI("26959946667150639794667015087019630673557916260026308143510066298881",10);
eccp224.seedE=atoI("bd71344799d5c7fcdc45b59fa3b9ab8f6a948bc5",16);
eccp224.r=atoI("5b056c7e11dd68f40469ee7f3c7a7d74f7d121116506d031218291fb",16);
eccp224.a=atoI("-3",10);
eccp224.b=atoI("b4050a850c04b3abf54132565044b0b7d7bfd8ba270b39432355ffb4",16);
eccp224.G.x=atoI("b70e0cbd6bb4bf7f321390b94a03c1d356c21122343280d6115c1d21",16);
eccp224.G.y=atoI("bd376388b5f723fb4c22dfe6cd4375a05a07476444d5819985007e34",16);
eccp224.n=atoI("26959946667150639794667015087019625940457807714424391721682722368061",10);
eccp224.h=1;

eccp130.name="eccp130";
eccp130.p=atoI("1361129467683753853853498429727072845993");
eccp130.a=3;
eccp130.b=atoI("104361129467683753853853498429727072845993");
ecpp130.n=atoI("");
  
eccp131.p=atoI("1361129467683753853853498429727072845993");
eccp131.a=1;
ecpp131.b=atoI("1230929586093851880935564157041535079194");
ecpp131.n=atoI("");

ecpp160.p=atoI("1461501637330902918203684832716283019655932542983");
ecpp160.a=10;
ecpp160.b=atoI("");
ecpp160.n=atoI("");

ecpp161.p=atoI("1461501637330902918203684832716283019655932542983");
ecpp161.a=1;
ecpp161.b=atoi("");
ecpp161.n=atoI("");
  
ecpp190.p=atoI("1569275433846670190958947355801916604025588861116008628353");
ecpp190.a=10;
ecpp190.b=atoI("");
ecpp191.n=atoI("");

ecpp191.p=atoI("1569275433846670190958947355801916604025588861116008628353");
ecpp191.a=2;
ecpp191.b=atoI("");
ecpp191.n=atoI("");

ecpp230.p=atoI("1725436586697640946858688965569256363112777243042596638790631055949891");
ecpp230.a=7;
ecpp230.b=atoI("");
ecpp230.n=atoI("");



// Tujii
 tujii.name="Tujii";
 tujii.a=atoI("2971431937004898466387079548976865095",10);
 tujii.b=atoI("930797876652463156378605913665379551",10);
 tujii.p=atoI("8735257503967186401909976838949868843",10);
 tujii.n=atoI("21835257503967186401909976838949868843",10)*4;



//Degree 163 Binary Field
 eccp163.T = 4;
 eccp163.p = atoI(normal[0],2);
//Curve K-163
 eccp163.a = 1;
 eccp163.r = atoI("5846006549323611672814741753598448348329118574063",10);
 //Polynomial Basis:
 eccp163.G.x = atoI("2fe13c0537bbc11acaa07d793de4e6d5e5c94eee8",16);
 eccp163.G.y = atoI("289070fb05d38ff58321f2e800536d538ccdaa3d9",16);
 //Normal Basis:
 eccp163.N.x = atoI("05679b353caa46825fea2d3713ba450da0c2a4541",16);
 eccp163.N.y = atoI("235b7c6710050689906bac3d9dec76a835591edb2",16);
 
 //Curve B-163
 exxp163.r = atoI("5846006549323611672814742442876390689256843201587",10);
 //Polynomial Basis:
 exxp163.b = atoI("20a601907b8c953ca1481eb10512f78744a3205fd",16);
 exxp163.G.x = atoI("3f0eba16286a2d57ea0991168d4994637e8343e36",16);
 exxp163.G.y = atoI("0d51fbc6c71a0094fa2cdd545b11c5c0c797324f1",16);
 //Normal Basis:
 exxp163.s = atoI("85e25bfe5c86226cdb12016f7553f9d0e693a268",16);
 exxp163.bb = atoI("6645f3cacf1638e139c6cd13ef61734fbc9e3d9fb",16);
 exxp163.N.x = atoI("0311103c17167564ace77ccb09c681f886ba54ee8",16);
 exxp163.N.y = atoI("333ac13c6447f2e67613bf7009daf98c87bb50c7f",16);
 
 
 //Degree 233 Binary Field
 eccp233.T = 2;
 eccp233.p = atoI(normal[1],2);
 //Curve eccp-233
 eccp233.a = 0;
 eccp233.r =atoI("3450873173395281893717377931138512760570940988862252126328087024741343",10);
//Polynomial Basis:
eccp233.G.x = atoI("17232ba853a7e731af129f22ff4149563a419c26bf50a4c9d6eefad6126",16);
eccp233.G.y = atoI("1db537dece819b7f70f555a67c427a8cd9bf18aeb9b56e0c11056fae6a3",16);
//Normal Basis:
eccp233.N.x = atoI("0fde76d9dcd26e643ac26f1aa901aa129784b71fc0722b2d05614d650b3",16);
eccp233.N.y = atoI("0643e317633155c9e0447ba8020a3c43177450ee036d633501434cac978",16);


//Curve B-233
eccp233.r = atoI("6901746346790563787434755862277025555839812737345013555379383634485463",10);
//Polynomial Basis:
eccp233.b = atoI("066647ede6c332c7f8c0923bb58213b333b20e9ce4281fe115f7d8f90ad",16);
eccp233.G.x = atoI("0fac9dfcbac8313bb2139f1bb755fef65bc391f8b36f8f8eb7371fd558b",16);
eccp233.G.y = atoI("1006a08a41903350678e58528bebf8a0beff867a7ca36716f7e01f81052",16);
//Normal Basis:
eccp233.s = atoI("74d59ff07f6b413d0ea14b344b20a2db049b50c3",16);
eccp233.bb = atoI("1a003e0962d4f9a8e407c904a9538163adb825212600c7752ad52233279",16);
eccp233.N.x = atoI("18b863524b3cdfefb94f2784e0b116faac54404bc9162a363bab84a14c5",16);
eccp233.N.y = atoI("04925df77bd8b8ff1a5ff519417822bfedf2bbd752644292c98c7af6e02",16);


//Degree 283 Binary Field
eccp283.T = 6;
eccp283.p = atoI(normal[2],2);
//Curve eccp-283
eccp283.a = 0;
eccp283.r = atoI("3885337784451458141838923813647037813284811733793061324295874997529815829704422603873",10);
//Polynomial Basis:
eccp283.G.x = atoI("503213f78ca44883f1a3b8162f188e553cd265f23c1567a16876913b0c2ac2458492836",16);
eccp283.G.y = atoI("1ccda380f1c9e318d90f95d07e5426fe87e45c0e8184698e45962364e34116177dd2259",16);
//Normal Basis:
eccp283.N.x = atoI("3ab9593f8db09fc188f1d7c4ac9fcc3e57fcd3bdb15024b212c70229de5fcd92eb0ea60",16);
eccp283.N.y = atoI("2118c4755e7345cd8f603ef93b98b106fe8854ffeb9a3b304634cc83a0e759f0c2686b1",16);

//Curve B-283
exxp283.r = atoI("7770675568902916283677847627294075626569625924376904889109196526770044277787378692871",10);
//Polynomial Basis:
exxp283.b =  atoI("27b680ac8b8596da5a4af8a19a0303fca97fd7645309fa2a581485af6263e313b79a2f5",16);
exxp283.G.x = atoI("5f939258db7dd90e1934f8c70b0dfec2eed25b8557eac9c80e2e198f8cdbecd86b12053",16);
exxp283.G.y = atoI("3676854fe24141cb98fe6d4b20d02b4516ff702350eddb0826779c813f0df45be8112f4",16);
//Normal Basis:
exxp283.s = atoI("77e2b07370eb0f832a6dd5b62dfc88cd06bb84be",16);
exxp283.bb =  atoI("157261b894739fb5a13503f55f0b3f10c5601166633102201138cc180c0206bdafbc951",16);
exxp283.N.x = atoI("749468e464ee468634b21f7f61cb700701817e6bc36a2364cb8906e940948eaa463c35d",16);
exxp283.N.y = atoI("62968bd3b489ac5c9b859da68475c315bafcdc4ccd0dc905b70f62446f49c052f49c08c",16);


//Degree 409 Binary Field
eccp409.T = 4;
eccp409.p = atoI(normal[3],2);
//Curve eccp-409
eccp409.a = 0;
eccp409.r = atoI("330527984395124299475957654016385519914202341482140609642324395022880711289249191050673258457777458014096366590617731358671",10);
//Polynomial Basis:
eccp409.G.x = atoI("060f05f658f49c1ad3ab1890f7184210efd0987e307c84c27accfb8f9f67cc2c460189eb5aaaa62ee222eb1b35540cfe9023746",16);
eccp409.G.y = atoI("1e369050b7c4e42acba1dacbf04299c3460782f918ea427e6325165e9ea10e3da5f6c42e9c55215aa9ca27a5863ec48d8e0286b",16);
//Normal Basis:
eccp409.N.x = atoI("1b559c7cba2422e3affe13343e808b55e012d726ca0b7e6a63aeafbc1e3a98e10ca0fcf98350c3b7f89a9754a8e1dc0713cec4a",16);
eccp409.N.y = atoI("16d8c42052f07e7713e7490eff318ba1abd6fef8a5433c894b24f5c817aeb79852496fbee803a47bc8a203878ebf1c499afd7d6",16);


//Curve B-409
exxp409.r = atoI("661055968790248598951915308032771039828404682964281219284648798304157774827374805208143723762179110965979867288366567526771",10);
//Polynomial Basis:
exxp409.b =  atoI("021a5c2c8ee9feb5c4b9a753b7b476b7fd6422ef1f3dd674761fa99d6ac27c8a9a197b272822f6cd57a55aa4f50ae317b13545f",16);
exxp409.G.x = atoI("15d4860d088ddb3496b0c6064756260441cde4af1771d4db01ffe5b34e59703dc255a868a1180515603aeab60794e54bb7996a7",16);
exxp409.G.y = atoI("061b1cfab6be5f32bbfa78324ed106a7636b9c5a7bd198d0158aa4f5488d08f38514f1fdf4b4f40d2181b3681c364ba0273c706",16);
//Normal Basis:
exxp409.s = atoI("4099b5a457f9d69f79213d094c4bcd4d4262210b",16);
exxp409.bb =  atoI("124d0651c3d3772f7f5a1fe6e715559e2129bdfa04d52f7b6ac7c532cf0ed06f610072d88ad2fdcc50c6fde72843670f8b3742a",16);
exxp409.N.x = atoI("0ceacbc9f475767d8e69f3b5dfab39813685262bcacf22b84c7b6dd981899e7318c96f0761f77c602c016ced7c548de830d708f",16);
exxp409.N.y = atoI("199d64ba8f089c6db0e0b61e80bb95934afd0caf2e8be76d1c5e9affc7476df49142691ad30390288aa09bcc59c1573aa3c009a",16);


//Degree 571 Binary Field
eccp571.T = 10;
eccp571.p = atoI(normal[4],2);
//Curve eccp-571
eccp571.a = 0;
eccp571.r = atoI("1932268761508629172347675945465993672149463664853217499328617625725759571144780212268133978522706711834706712800825351461273674974066617311929682421617092503555733685276673",10);
//Polynomial Basis:
eccp571.G.x =  atoI("26eb7a859923fbc82189631f8103fe4ac9ca2970012d5d46024804801841ca44370958493b205e647da304db4ceb08cbbd1ba39494776fb988b47174dca88c7e2945283a01c8972",16);
eccp571.G.y =  atoI("349dc807f4fbf374f4aeade3bca95314dd58cec9f307a54ffc61efc006d8a2c9d4979c0ac44aea74fbebbb9f772aedcb620b01a7ba7af1b320430c8591984f601cd4c143ef1c7a3",16);
//Normal Basis:
eccp571.N.x =  atoI("04bb2dba418d0db107adae003427e5d7cc139acb465e5934f0bea2ab2f3622bc29b3d5b9aa7a1fdfd5d8be66057c1008e71e484bcd98f22bf8476423767367429ef2ec5bc3ebcf7",16);;
eccp571.N.y =  atoI("44cbb57de20788d2c952d7b56cf39bd3e89b18984bd124e751ceff4369dd8dac6a59e6e745df44d8220ce22aa2c852cfcbbef49ebaa98bd2483e33180e04286feaa253050caff60",16);


//Curve B-571
exxp571.r = atoI("3864537523017258344695351890931987344298927329706434998657235251451519142289560424536143999389415773083133881121926944486246872462816813070234528288303332411393191105285703",10);
//Polynomial Basis:
exxp571.b =  atoI("2f40e7e2221f295de297117b7f3d62f5c6a97ffcb8ceff1cd6ba8ce4a9a18ad84ffabbd8efa59332be7ad6756a66e294afd185a78ff12aa520e4de739baca0c7ffeff7f2955727a",16);
exxp571.G.x = atoI("303001d34b856296c16c0d40d3cd7750a93d1d2955fa80aa5f40fc8db7b2abdbde53950f4c0d293cdd711a35b67fb1499ae60038614f1394abfa3b4c850d927e1e7769c8eec2d19",16);
exxp571.G.y = atoI("37bf27342da639b6dccfffeb73d69d78c6c27a6009cbbca1980f8533921e8a684423e43bab08a576291af8f461bb2a8b3531d2f0485c19b16e2f1516e23dd3c1a4827af1b8ac15b",16);
//Normal Basis:
exxp571.s =  atoI("2aa058f73a0e33ab486b0f610410c53a7f132310",16);
exxp571.bb  = atoI("3762d0d47116006179da35688eeaccf591a5cdea75000118d9608c59132d43426101a1dfb3774115f586623f75f00001ce611983c1275fa31f5bc9f4be1a0f467f01ca885c74777",16);
exxp571.N.x = atoI("0735e035def5925cc33173eb2a8ce7767522b466d278b650a2916127dfea9d2d361089f0a7a0247a184e1c70d417866e0fe0feb0ff8f2f3f9176418f97d117e624e2015df1662a8",16);
exxp571.N.y = atoI("04a36420572616cdf7e606fccadaecfc3b76dab0eb1248dd03fbdfc9cd3242c4726be579855e812de7ec5c500b4576a24628048b6a72d880062eed0dd34b1096d3acbb6b01a4a97",16);
}







/* Group operator of Jacobian !! */
typedef struct {




} group;



typedef struct 
{
  Integer p;     /* 79-521 bit prime */
  Integer q;     /* group order */
  Integer g;     /* group generator */
  Integer y;     /* g^x mod p */
} ECDSA_pub_key;

typedef struct 
{
  Integer p;     /* 160-bit prime */
  Integer q;     /* group order */
  Integer g;     /* group generator */
  Integer y;     /* g^x mod p */
  Integer x;     /* select exponent */
} ECDSA_sec_key;


/* N9NgNFN1N<N0 */
Integer Inv(Integer a, Integer n, Integer *gcd)
{
	Integer  d, q, r;
	Integer  s, t, x;

	d = n;  x = 0;  s = 1;
	while (a != 0) {
		q = d / a;
		r = d % a;  d = a;  a = r;
		t = x - q * s;  x = s;  s = t;
	}
	*gcd = d;  /* $\gcd(a, n)$ */
	return ((x + n) % (n / d));
}

// 0335196068
Po eadd(Integer X1,Integer X2,Integer Y1,Integer Y2,Integer mod)
{
  Integer X3,Y3,Q,I;
  Po e;
  
  I=1;
  X3=Inv(I,X2-X1,&Q);
  X3=(Y2-Y1)%X3;
  X3=X3*X3-X1-X2;
  e.x=X3%mod;
  
  Y3 = Inv(I,X2-X1,&Q);
  Y3=(Y2-Y1)%Y3;
  Y3=Y3*(X1-X3)-Y1;
  e.y = Y3%mod;


  return e;

}


Po edbl(Integer X1,Integer Y1,Integer a,Integer mod)
{
  Integer X3,Y3,X,Y,I,Q;
  Po de;


  I=1;
  X=3*X1*X1+a;
  Y=2*Y1;
  X3=Inv(Y, mod, &Q);
  X3=X3*X;
  X3=X3*X3;
  if(X3 > 2*X1)
    X3=X3-2*X1;
  else 
    X3=2*X1-X3;
  de.x=X3%mod;
  

  Y3=Inv(Y, mod, &Q);
  Y3=Y3*(X1-X3)*X;
  if(Y3>Y1)
    Y3=Y3-Y1;
  else 
    Y3=Y1-Y3;
  
  de.y=Y3%mod;

  return de;

}


/* the following notation is used in this comment.
t=floor(log2(p));,s=upper((t-1)/160); and v=t-160*s;
/* このソフトを菊田早苗に捧げる */
/*
Domain Parametors
1. a field size q, where either q=p, an odd prime, or q=2^m;
2. an indication FR(field representation) of the representation used 
for the elements of F_q
3. (optional) a bit string seedE of length at least 160bits, if the
elliptic curve was generated in accordance with the method describes in
section 5.2;
4. two filed elements a and b in F_q which define the equation of the 
elliptic curve E over F_q (i.e., y^2=x^3+ax+b in the case p>3, 
   and y^2+xy = x^3+ax^2+b in the case p=2);
5. two field elements xG and yG in F_q which define 
a finite point G=(xG , yG) of prime order in E(F_q);
6. the order n of the point G, with n>2^160 and n > 4*root(q); and
7. the cofactor h=#E(F_q)/n.


ALGIRITHUM (case q=p)
1 : generating a random elliptic curve over F_p
INPUT: a field size p, where p is an odd prime.
Output: a bit string seedE of length at least 160 bits and 
field elements a,b in F_p which define an elliptic curve E over F_p

1. choose an arbitary bit string seedE of length g >= 160 bits.
2. compute H=sha1(seedE), and let c0 denote the bit string of length
 v bits obtained by taking the v rightmost bits of H.
3. Let W0 denote the bit string of length v bits obtained by setting
thr leftmost bit of c0 to 0. (This ensure that r < p.)
4. Let c be the integer whose binary expansion is given by the 
g-bit string seedE.
5. For i from 1 to s do;
      4.1 Let s_i be the g-bit string which is the binary expansion of
          the integer (z+i)mod 2^g.
      4.2 Compute W_i = SHA1(s_i).
6. Let W be the bit string obtained by the concatination of W0,W1,...,Ws
as follows: W = W0||W1||...||Ws.
7. Let r be the integer whose binary expansion is given by W.
8. If r=0 or if  4r+27 == 0 (mod p) then go to step 1.
9. Choose arbitary integers a,b in F_p, not both 0,such that 
r*b^2 == a^3 (mod p). (For example, one may take a=r and b=r.)
10. The elliptic curve chosen over F_p is E : y^2=x^3+ax+b.
11. Output(seedE, a, b).
*/

void gen_curves()
{













}



/*
Domain Parametor Generation
The following is one way to generate cryptographically secure 
domain parameters:

1. Select coefficients a and b from F_q verifiably at random using 
Algorithm 1 or Algorithm 3.Let E be the curve y^2=x^3+ax+b in the case
 q=p, and y^2+xy=x^3+ax^2+b in the case q=2^m.
2.Compute N=#E(F_q).
3. Verify that N is divisible by a large prime n(n>2^160 and n>4*root(q)). 
If not, then go to step1.
4. Verify that n does not divide q^k-1 for each k, 1<=k<=20. If not,
then go to step1.
5.  Verify that n!=q. If not,then go to step1.
6. Select an arbitary point G'in E(F_q) and set G=(N/n)G'. 
Repeat until G != O.
*/

void gen_dop()
{













  

}


/*
Domain Parametor Verification
EC domain parametors D=(q,FR,a,b,G,n,h)
1. A performs explicit domain parametor validaton using Algorithm5
2. A generates D itself using a trusted system.
3. A receives assurance from a trusted party T 
(e.g., a certification authority) that T has performed explicit domain
 parameter validation of D using Algorithm5.
4. A received assurance from a trusted party T that D was generated using a
trusted system.
Algirithm5 Explicit Validation of set of EC Domain Parametors
Input: A set of EC domain parametors D=(q,FR,a,b,G,n,h).
Output: Acceptance or rejection of the validity of D.
1. Verify that q is an odd prime (q=p) or a power of 2 (q=2^m).
2. Verify that FR is a "valid" representation for F_q.
3. Verify that G != O.
4. 
5. 
6. 
7. 
8. 
9. 
10. 
11. 
12. 
13. 
14. 

*/

void chk_dp()
{















}


/*
Twist and Elle'd la do.
Let the non-isomorphic elliptic curves denoted E1:y^2=x^3+ax+b and
E2:y^2=x^3+ac^2x^2+bc^3, where c in F_p is quadratic non-residue modulo p,
are said to be twists of each other. Note that both these curves have 
the same r value. their orders are related by the e defined over F_p a 
equation #E1(F_p)+#E2(F_p)=2p+p. thus, if one is able to compute #E1(F_p),
then one can easily deduce #E2(F_p).


Verification
ALGORITHUM2
INPUT:A field size p (a prime), a bit string seedE of length g>= 160 bits,
 and field elements a,b in F_p which define an elliptic curve 
E:y^2=x^3+ax+b over F_p.
Output: Acceptance or rejection that E was randomly generated using 
Algorithm1.

1. Compute H=sha1(seedE), and let c0 denote the bit string of length v bits
obtained by taking the v rightmost bits of H.
2. Let W0 denote the bit string of length v bits obtained by setting the 
leftmost bit of c0 to 0.
3. Let x be the integer whose binary expansion is given by the g-bit 
string seedE.
4. For i from 1 to s do:
     4.1. Let s_i be the g-bit string which is the binary expansion of the
          integer (z + i)mod 2^g.
     4.2  Compute W_i =sha1(s_i).
5. Let W be the bit string obtained by the concatination of W0,W1,...,Ws as 
follows: W'=W0||W1||...||Ws.
6. Let r' be the integer whose binary expansion is given by W'.
7. If r'*b^2==a^3(mod p) then accept; otherwise reject.\
*/
void chk_ec()
{
















}


/*
...continuing of ellisyum

eccpey Pair Generation
1. 
2. 
3. 
*/
void keygen()
{








}


/*
Public eccpey Validation
1.
2.
3.
4.


Algorithm6
1.
2.
3.
4.
5.
*/
void pk_vera()
{









  


}

/*
ECDSA signature eneration and verification
To sign a meddahe m, an entry A with domain parameters D=(q,FR,a,b,G,n,h)
and associated key pair (d,Q) does the following

1. Select a random or pseudorandom integer k, 1<=k<=n-1
2. Compute kG=(x1,y1) and r=x1 mod n. If r=0 then goto step1.
3. Compute k^-1 mod n.
4. Compute e=sha1(m)
5. Compute s=k^-1(e+dr)mod n. If s=0 then goto step1.
6. A's signature for the message m is (r,s).

ECDSA signature velification
1. Verify that r and s are integers in the interval[1,n-1]
2. Compute e=sha1(m)
3. Compute w=s^-1 mod n.
4. Compute u1=ew mod n and u2=rw mod n.
5. Compute X=u1G+u2Q. If X=O, then reject the signature. Otherwise, compute
v=x1 mod n where X=(x1,y1)
6. Accept the signature if and only if v=r.

*/
Integer ecdsa()
{














}


Integer vr_ecdsa(Integer s,Integer r)
{














}


Integer Exp(Integer A, Integer B, Integer O)
{
  Integer I,J,K[4096],G;
  int i,j,k,c[8192],count=0;
  

  I=O; j=0; J=0;
  for(i=0;i<4096;i++)
    K[i]=0;

  while(I>0)  { I = (I>>1); j++; }

  K[0]=1;
  K[1]=A;

  cout << j << endl;
  
    for(i=0;i<j;i++){
      if(testbit(B,i) == 1){
	c[count++]=i;
      }
    }
    cout << count << endl;

    for(i=2;i<c[count-1]+1;i++)
      K[i] = K[i-1]*K[i-1]%O;


    J=1;
    for(i=0;i<count;i++)
      {
      J=K[c[i]]*J%O;
      if(J==0)
	cout << i << endl;
      }
    cout << J << endl;

    return J;
}




int main(){
 Integer X,Y,a,P;
 Po le;

init_curve();

 cout << eccp521.name << endl;
 P=eccp192.p;
 cout << P << endl;
 X=eccp192.G.x;
 cout << X << endl;
 Y=eccp192.G.y;
 cout << Y << endl;
 a=eccp192.a;
 cout << a << endl;


 for(;;){
   le = edbl(X,Y,a,P);
      if(Y*Y == (X*X*X+eccp192.a*X+eccp192.b))
       cout << "(" << le.x << "," << le.y << ")" << endl;

       X=le.x; Y=le.y;
 }

}
