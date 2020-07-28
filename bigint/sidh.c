#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "bigint.h"


typedef struct {
  bigint p[1];
  bigint e2[1];
  bigint e3[1];
  bigint xQ20[1];
  bigint xQ21[1];
  bigint yQ20[1];
  bigint yQ21[1];
  bigint xP20[1];
  bigint xP21[1];
  bigint yP20[1];
  bigint yP21[1];
  bigint xR20[1];
  bigint xR21[1];
  bigint xQ30[1];
  bigint xQ31[1];
  bigint yQ30[1];
  bigint yQ31[1];
  bigint xP30[1];
  bigint xP31[1];
  bigint yP30[1];
  bigint yP31[1];
  bigint xR30[1];
  bigint xR31[1];
} SIDH;

typedef struct{

  int n;
  int p;
  int q;
  char s[200];

} tor;


//  SIDH sp434;


SIDH init(SIDH a, int i){
  char buf[65536];

  bigint_init(a.p);
  bigint_init(a.e2);
  bigint_init(a.e3);
  bigint_init(a.xQ20);
  bigint_init(a.xQ21);
  bigint_init(a.yQ20);
  bigint_init(a.yQ21);
  bigint_init(a.xP20);
  bigint_init(a.xP21);
  bigint_init(a.yP20);
  bigint_init(a.yP21);
  bigint_init(a.xR20);
  bigint_init(a.xR21);
  bigint_init(a.xQ30);
  bigint_init(a.xQ31);
  bigint_init(a.yQ30);
  bigint_init(a.yQ31);
  bigint_init(a.xP30);
  bigint_init(a.xP31);
  bigint_init(a.yP30);
  bigint_init(a.yP31);
  bigint_init(a.xR30);
  bigint_init(a.xR31);

    if(i==1){
      //   SIDH sp434;

      //sp434=a;
      printf("initializasation sp434\n");
      
  bigint_from_str(a.p, "24439423661345221551909145011457493619085780243761596511325807336205221239331976725970216671828618445898719026692884939342314733567");

  bigint_from_str(a.e2,"216");
  bigint_from_str(a.e3,"137");
  bigint_from_str(a.xQ20,"8633131302536015373065425580178973814526244742660764898957635611033517358603093513483897324469034427019598357249425684820405193836");
  bigint_from_str(a.xQ21,"1640555213321637736080614728970921962714590288563692816952785470842808462670732196555713644986698688787353020078064569199240185333");
  bigint_from_str(a.yQ20,"20276452752220665548202189403598170750834982427130760850813254160550305310659929663123304778814287531500756146204805251963783256037");
  bigint_from_str(a.yQ21,"10045306525245350298803819046509877432229480969314772374869175643233206473596453796721101344057683381390923103776706006170651177942");
  bigint_from_str(a.xP20,"2634539327592482918121599540115765431217195093350648632832477775508933673747596362667240890051240463853167541162279343167040310088");
  bigint_from_str(a.xP21,"18590308952679468489364793668589003541299106140709579196186461020066893645141198854487503147226318730158493210982567772716162869840");
  bigint_from_str(a.yP20,"18499992072774772182750461054948965122862326576938683155863157755664308576685791546530637605543615310883354355922717114976263189216");
bigint_from_str(a.yP21,"10983718925653566249610333622918370357192097441961014913751641775508865561311331364566791542776619041356373750734992554370506677551");
bigint_from_str(a.xR20,"10548244869191429978994573331033429460802791853191679921432716242390096998215982561051229194803656270150791181542353263212179039510");
bigint_from_str(a.xR21,"17623338845092751517427595119320347017334966146230013113905734683582704966390296970846105400364294574370981828797535336936167097772");
bigint_from_str(a.xQ30,"13106015910647201458426811493288965923311702902321179794984306791335898269651901670809619116119997952683697617529379507339288983622");
 bigint_from_str(a.xQ31,"0");
 bigint_from_str(a.yQ30,"0");
 bigint_from_str(a.yQ31,"10209775938515962501771741506081580425243588708606392462054462399651871393790372518908435424495021346995173633235373991504988757970");
 bigint_from_str(a.xP30,"5822289030790821842647204127346110197186614331916510409554480418611145246532692679762948023941031185216358707524703325193156147113");
 bigint_from_str(a.xP31,"0");
 bigint_from_str(a.yP30,"4631002038627486062145710538859886699092897850004224163519174820337269208909673679867855016325656365561668068341925816094377133115");
 bigint_from_str(a.yP31,"0");
 bigint_from_str(a.xR30,"19978714732817982296321998790126652405475699311529669091328949981490769847281914491438519436155586335833863255694913096932863948652");
 bigint_from_str(a.xR31,"14167827257511306746606440016400170231086622175754382579855491498256779752299521404090563911050166061448571907478184141518856743652");

  puts(bigint_write(buf, sizeof(buf), a.p));
    }

      if(i==2){
    printf("initializasation sp503\n");
    //    SIDH sp503;
    //sp503=a;
    
    bigint_from_str(a.p,"13175843156907117380839252916199345042492186767578363998445663477035843932020761233518914911546024351608607150390087656982982306331019593961154237431807");
    bigint_from_str(a.e2,"250");
    bigint_from_str(a.e3,"159");
    bigint_from_str(a.xQ20,"10303639081125516279001395287746760176758405254609941364872116054854162905961918713361681608991552251201029580427357273234152024018341363107600917423201");
    bigint_from_str(a.xQ21,"12782700525274606080563088995687953414271121242085716929817360778487970449266550563914806669696607531319998303840529920531168654117474642657984154795441");
    bigint_from_str(a.yQ20,"11907913747401263372631993650383474010460887355731972007259579839843387604583306264088777388731137707596732200482457305106853755102838384483226607408980");
    bigint_from_str(a.yQ21,"5292840094190856756897919330752760358645449293970119310207955661961420744230791925978770188802827628077305751047954330175704766117841777492781885522580");
    bigint_from_str(a.xP20,"598731473478175178061187348602069297333549163428939979629523574390608068248963076780259720359959333459849068307643602107176506677543421128505637017208");
    bigint_from_str(a.xP21,"6320532212404399382016063711621672519097819289093008132287422899586558654154409534465288623620152707063792403841177958686744730460358867369790214313426");
    bigint_from_str(a.yP20,"7426962917961886750223017992649030370937754287299592176293296013750046278528127270441749990770397646543053639338703118870066071949533225567468389035535");
    bigint_from_str(a.yP21,"4933101381662632860793723128899783676713316867789870876301082420674288633349127213108982942657184880054878201780353332330135295382721630567005079288999");
    bigint_from_str(a.xR20,"12509218309718532854332942208346153574542996164252915421699889272598958199135267399861163567618642166784471853904581905190717363517810244763641679761055");
    bigint_from_str(a.xR21,"1335105158761904375086321733636949601061387148884944277886595669505349266124420727230365047604242373250586612001990261861820516208603215663680538711192");
    bigint_from_str(a.xQ30,"11662485637823763116959534565001872592010882475641226843176985866588019368676991560369559249358763311711849556241666760730606211268182513109721338236243");
    bigint_from_str(a.xQ31,"0");
    bigint_from_str(a.yQ30,"0");
    bigint_from_str(a.yQ31,"7634548483727126773543333352398604451954368718228168550650277018082903630942062065511172438901759852748000940036717851411221926820916595391278637026820");
    bigint_from_str(a.xP30,"10395771746384663457709878182675363876289472956896319955035800944963560043487131351381624225079611557910169511157250351409611867388651460757963950045919");
    bigint_from_str(a.xP31,"0");
    bigint_from_str(a.yP30,"9309552127100257329408002157658859489453309131568607095068230354479868403549207476529964476434226430001454218770443683472755151470484422193528293469683");
    bigint_from_str(a.yP31,"0");
    bigint_from_str(a.xR30,"154459043155387065396424009957419869712039499996384186684154952283149434421831909414629931121223671648463292265394714392291130151414443679316615935266");
    bigint_from_str(a.xR31,"8286885299052081621711535235896514343196092250707482373802887092860779668469128499005462149290615896285463027295046426298617122298134606667068233750360");
  }
 
  


  if(i==3){
    printf("initializasation sp610\n");
    //SIDH sp610;
    //sp610=a;

    bigint_from_str(a.p,"2638940411073262671963620699288286770183560231187222316750407556465639836010558150163225530335162533481049256757217964651333810422125728537407397155806079217346919294449255613110157311");
    bigint_from_str(a.e2,"305");
    bigint_from_str(a.e3,"192");
    bigint_from_str(a.xQ20,"157069315455315725572406262836101190536820419345266922310200723719159706129514384706934713497529220788845330796136656469811063377500153295284407501527218118951386898985387213358467978");
    bigint_from_str(a.xQ21,"2278312578911463860663452047317840188913500964088463497564614625278006320197173705099325691383536120882530302172224873945210653977858551912928766782033403861412424442219027598444372205");
    bigint_from_str(a.yQ20,"684626837739439515527178368449616516042502767036426400873151573458794526207996577208813714111255823391912747544929297502418344725328410684102507049000900022835828681443590694359470796");
    bigint_from_str(a.yQ21,"2131943785947274690175172687017894976900651676838954493459391896401215835004922340925879480814182310742063072231869657104890652187484750858130293569134468169460850644363191828281970838");
    bigint_from_str(a.xP20,"1806736940449204756670130402045974891976541035129146635282788880605274195484852513511499140814745888005770886742088608789738701225260796101949251672750216548726048403327295530268488300");
    bigint_from_str(a.xP21,"1351032392344570862820165806841417419483707333389008032303844817986587931915067411261641353376786861740821136696258561077148293590024228334589369728107287048428009459387461704345197218");
    bigint_from_str(a.yP20,"1914836262154229412574833552285540119942953261355870652513258346940220805607860257037379503860349019441684789905537418459133057322907158810963334977929603783189005569389818236718757287");
    bigint_from_str(a.yP21,"2124817562111324870916785225238457163073501863745565628478675166072657660756968132145149012564540863190658044019839657530708614993593391844597004323203766106519379786043735933044429912");
    bigint_from_str(a.xR20,"1806757458218259225156534580511548505833883774142338473287942070985938962041251026714693281304444695051081172458270390380464507723783778567071195320180990351856314147239093354974560181");
    bigint_from_str(a.xR21,"1609131430270017471990006924510606609431891799867136925322674553530669498358084247117993461750586570202830035499520725525396028899931410374987906357459699445433374400400750016649013650");
    bigint_from_str(a.xQ30,"1387566999709320073344076391171172507738190670755781932803785722061027377438810471125423396121694767682815386582033193953279150259291357025344318501976216211001662765956497194286817351");
    bigint_from_str(a.xQ31,"0");
    bigint_from_str(a.yQ30,"0");
    bigint_from_str(a.yQ31,"956269241486681620129413265985396885225285468299622733925657142107888353766338280468038649293217037815600441332404132752013327889696962453572069418479767380512285984353519960428869979");
    bigint_from_str(a.xP30,"1429380650836801398435074225540873431964527974757736685640904411443279737690636600949107717631340803268699150860993995901981057449903476488360396389680606139935614560386298802463567851");
    bigint_from_str(a.xP31,"0");
    bigint_from_str(a.yP30,"86922338762137764722249229503399840011748426938614565165720420711418613695847056338321754727088992463807067011159743359520826426882081401616192743451060098430406302548560564784275248");
    bigint_from_str(a.yP31,"0");
    bigint_from_str(a.xR30,"1972895850285459029794960334469425167487807650191402546363441621434982885771442857918903807540216972404065512911628943430544935487752338262279560904794385436987010367702239754753360418");
    bigint_from_str(a.xR31,"1804050615893003794750561676329461570838418813828126329026032658780644412457060169809428216963063524684911526771046147309867689093694679672105409554258338717969948675911849061206166344");
  }
  

  if(i==4){
    printf("initializasation sp751\n");
    // SIDH sp751;

    //a=sp751;

    bigint_from_str(a.p,"10354717741769305252977768237866805321427389645549071170116189679054678940682478846502882896561066713624553211618840202385203911976522554393044160468771151816976706840078913334358399730952774926980235086850991501872665651576831");
    bigint_from_str(a.e2,"372");
    bigint_from_str(a.e3,"239");
    bigint_from_str(a.xQ20,"2141306817115640038993862181765492931500972641785085350947220052387904285572880641340973064166142567836013875254694387171253686309941716659316458912387577733949836538957913038827049600784199475852241950366745525218545897974030");
    bigint_from_str(a.xQ21,"3462139332946457351613256472394206428708902796442953775366163334092154110965882738568198703970873585433373209361346635159539572450380354861849053160099274714477389537230240941950694098078938506114926490884815238642940114646471");
    bigint_from_str(a.yQ20,"4971051208676818538130306644600904750607598138754082242929568850388838017558578628906892821517384408377387956108839597010516351547749023772854937884508640768345992159506835114833220113674841882696215314922388871071388491092308");
    bigint_from_str(a.yQ21,"1400417812997368920915551682180377281636897329246851400968757977812707768224457059133981091372384547426963624786120814884621423687862104250447066981364505731819707788795768880909806522716391019159881409233478267422518729910305");
    bigint_from_str(a.xP20,"6392653750389499144594798145926583444354409039583606858359849849952175922439864668710005278778374444865434395866810086432449384862893379044515952989369610078853427396744868696171536543536691791447062025853410930611265727936250");
    bigint_from_str(a.xP21,"1993436594774325849134512059294984900092784525889309731865924302516333954639088053874784298502590615500299169775920492705338536494948131816798689951115100682529755597000522266521373993031102110056636212011317531431383151419457");
    bigint_from_str(a.yP20,"1107155950129604944058105130119415511264677550994695757860863353531605838302084169705309368726951698311435745863980668883833942102749156669587603793264404414816300918111443416878395850730885359490151046561089035507783599969704");
    bigint_from_str(a.yP21,"1944360814274992967790694755086384528911568810504894043226517588614661307924121353430029161010012544745085495519191328692275625095407629659251973225185479118063426457881083398198905214991988954261689720043570183102687622930302");
    bigint_from_str(a.xR20,"8920767099889265354270903767976190589347780532338110811601966065539889197224092469005030134458217535515117192741315988190233956060833229415177951494574325212388096836354324553840374916089004540013556866495215628182837045568955");
    bigint_from_str(a.xR21,"7485054888408186199988187951947272686736588976237807119427933559723580777349951819085282578750816796140208081851358534302244661919771165437390420226722284298495663460285754671947773474537816261384790115136982920513335294841189");
    bigint_from_str(a.xQ30,"8511019311184218364369646557252415173765495706553816075924705665118452233626065646710473783622713033004291163624815196837285573011460225202480327659675906178097793861901498715713456623486950717478378070640744966049319812387057");
    bigint_from_str(a.xQ31,"0");
    bigint_from_str(a.yQ30,"0");
bigint_from_str(a.yQ31,"4749025853221149447389147807862158495105283944255389717972469416583735997074470053838648384206219228347785356007779344031309965298006031166126067665328960313132108190232784245275591536191227746136931577835184145448867010458179");
  bigint_from_str(a.xP30,"8917296521312037934018779383955573993264347381711746006893090701936594237023232166684104618705889709151882479004705477580016078091729035680421189641116128972780575456542140523559278016360828837041023736833315936592076152779518");
bigint_from_str(a.xP31,"0");
bigint_from_str(a.yP30,"7977151852055161869642019263638055005058107660484391511988982056175137577840003410730173583183108331994556547443371187542870574283672599677654119934277234663107913274966085467251791279439311595825268323079739889435353405326871");
bigint_from_str(a.yP31,"0");
  bigint_from_str(a.xR30,"7948472920477987382026230091597296324770743133322382953559027144948810258767547973629670019619498810386907603969957459770220385943384654803338204542090155222002874700542244358439397441360179573140328384790672595434635205779427");
bigint_from_str(a.xR31,"8399745264634857705578681279266694258039523836471824133317786739845301013095107323108209992417182837952421722872170331095872127782294209276940273704388772866734580589843768351599575913837321305038643830671122310284823719495713");

  }

  return a;
}


void tor_set(int i){

  if(i==1){

    tor atp434;
    char a[108]={48, 28, 16, 8, 4, 2, 1, 1, 2, 1, 1, 4, 2, 1, 1, 2, 1, 1, 8, 4, 2, 1, 1, 2, 1, 1, 4, 2, 1, 1, 2, 1, 1, 13, 
7, 4, 2, 1, 1, 2, 1, 1, 3, 2, 1, 1, 1, 1, 5, 4, 2, 1, 1, 2, 1, 1, 2, 1, 1, 1, 21, 12, 7, 4, 2, 1, 1, 2, 1, 
      1, 3, 2, 1, 1, 1, 1, 5, 3, 2, 1, 1, 1, 1, 2, 1, 1, 1, 9, 5, 3, 2, 1, 1, 1, 1, 2, 1, 1, 1, 4, 2, 1, 1, 1, 2, 1 };
    char b[137]={66, 33, 17, 9, 5, 3, 2, 1, 1, 1, 1, 2, 1, 1, 1, 4, 2, 1, 1, 1, 2, 1, 1, 8, 4, 2, 1, 1, 1, 2, 1, 1, 4, 2, 1, 1, 
2, 1, 1, 16, 8, 4, 2, 1, 1, 1, 2, 1, 1, 4, 2, 1, 1, 2, 1, 1, 8, 4, 2, 1, 1, 2, 1, 1, 4, 2, 1, 1, 2, 1, 1, 32, 
16, 8, 4, 3, 1, 1, 1, 1, 2, 1, 1, 4, 2, 1, 1, 2, 1, 1, 8, 4, 2, 1, 1, 2, 1, 1, 4, 2, 1, 1, 2, 1, 1, 16, 8, 4, 
2, 1, 1, 2, 1, 1, 4, 2, 1, 1, 2, 1, 1, 8, 4, 2, 1, 1, 2, 1, 1, 4, 2, 1, 1, 2, 1, 1};

    atp434.n=107;
    atp434.p=5633;
    atp434.q=5461;
    memcpy(atp434.s,a,sizeof(a));
  

  tor btp434;
  
  btp434.n=136;
  btp434.p=5322;
  btp434.q=5282;
  memcpy(btp434.s,b,sizeof(b)); }


  if(i==2){

    tor atp503;
    char a[125]={61, 32, 16, 8, 4, 2, 1, 1, 2, 1, 1, 4, 2, 1, 1, 2, 1, 1, 8, 4, 2, 1, 1, 2, 1, 1, 4, 2, 1, 1, 2, 1, 1, 16, 8, 4, 2, 1, 1, 2, 1, 1, 4, 2, 1, 1, 2, 1, 1, 8, 4, 2, 1, 1, 2, 1, 1, 4, 2, 1, 1, 2, 1, 1, 29, 16, 8, 4, 2, 1, 1, 2, 1, 1, 4, 2, 1, 1, 2, 1, 1, 8, 4, 2, 1, 1, 2, 1, 1, 4, 2, 1, 1, 2, 1, 1, 13, 8, 4, 2, 1, 1, 2, 1, 1, 4, 2, 1, 1, 2, 1, 1, 5, 4, 2, 1, 1, 2, 1, 1, 2, 1, 1, 1};
    char b[158]={
      71, 38, 21, 13, 8, 4, 2, 1, 1, 2,
      1, 1, 4, 2, 1, 1, 2, 1, 1, 5,
      4, 2, 1, 1, 2, 1, 1, 2, 1, 1,
      1, 9, 5, 3, 2, 1, 1, 1, 1, 2,
      1, 1, 1, 4, 2, 1, 1, 1, 2, 1,
      1, 17, 9, 5, 3, 2, 1, 1, 1, 1,
      2, 1, 1, 1, 4, 2, 1, 1, 1, 2,
      1, 1, 8, 4, 2, 1, 1, 1, 2, 1,
      1, 4, 2, 1, 1, 2, 1, 1, 33, 17,
      9, 5, 3, 2, 1, 1, 1, 1, 2, 1,
      1, 1, 4, 2, 1, 1, 1, 2, 1, 1,
      8, 4, 2, 1, 1, 1, 2, 1, 1, 4,
      2, 1, 1, 2, 1, 1, 16, 8, 4, 2,
      1, 1, 1, 2, 1, 1, 4, 2, 1, 1,
      2, 1, 1, 8, 4, 2, 1, 1, 2, 1,
      1, 4, 2, 1, 1, 2, 1, 1};
    atp503.n=124;
    atp503.p=7490;
    atp503.q=7278;
    memcpy(atp503.s,a,sizeof(a));
  
    tor btp503;
  
    btp503.n=158;
    btp503.p=7189;
    btp503.q=7051;
    memcpy(btp503.s,b,sizeof(b));
  }

  if(i==3){
    
  tor atp610;
  char a[152]={67, 37, 21, 12, 7, 4, 2, 1, 1, 2, 1, 1, 3, 2, 1, 1, 1, 1, 5, 3, 2, 1, 1, 1, 1, 2, 1, 1, 1, 9, 5, 3, 2, 1, 
1, 1, 1, 2, 1, 1, 1, 4, 2, 1, 1, 1, 2, 1, 1, 16, 9, 5, 3, 2, 1, 1, 1, 1, 2, 1, 1, 1, 4, 2, 1, 1, 1, 2, 1, 
1, 8, 4, 2, 1, 1, 2, 1, 1, 4, 2, 1, 1, 2, 1, 1, 33, 16, 8, 5, 2, 1, 1, 1, 2, 1, 1, 1, 4, 2, 1, 1, 2, 1, 
1, 8, 4, 2, 1, 1, 2, 1, 1, 4, 2, 1, 1, 2, 1, 1, 16, 8, 4, 2, 1, 1, 1, 2, 1, 1, 4, 2, 1, 1, 2, 1, 1, 8, 
4, 2, 1, 1, 2, 1, 1, 4, 2, 1, 1, 2, 1, 1};
  char b[192]={86, 48, 27, 15, 8, 4, 2, 1, 1, 2, 1, 1, 4, 2, 1, 1, 2, 1, 1, 7, 4, 2, 1, 1, 2, 1, 1, 3, 2, 1, 1, 1, 1, 12, 
7, 4, 2, 1, 1, 2, 1, 1, 3, 2, 1, 1, 1, 1, 5, 3, 2, 1, 1, 1, 1, 2, 1, 1, 1, 21, 12, 7, 4, 2, 1, 1, 2, 1, 1, 
3, 2, 1, 1, 1, 1, 5, 3, 2, 1, 1, 1, 1, 2, 1, 1, 1, 9, 5, 3, 2, 1, 1, 1, 1, 2, 1, 1, 1, 4, 2, 1, 1, 1, 2, 1, 
1, 38, 21, 12, 7, 4, 2, 1, 1, 2, 1, 1, 3, 2, 1, 1, 1, 1, 5, 3, 2, 1, 1, 1, 1, 2, 1, 1, 1, 9, 5, 3, 2, 1, 
1, 1, 1, 2, 1, 1, 1, 4, 2, 1, 1, 1, 2, 1, 1, 17, 9, 5, 3, 2, 1, 1, 1, 1, 2, 1, 1, 1, 4, 2, 1, 1, 1, 2, 1, 1, 
8, 4, 2, 1, 1, 1, 2, 1, 1, 4, 2, 1, 1, 2, 1, 1};

  atp610.n=151;
  atp610.p=10370;
  atp610.q=10096;
  memcpy(atp610.s,a,sizeof(a));
   

tor btp610;
  
 btp610.n=191;
 btp610.p=10084;
 btp610.q=9794;

 memcpy(btp610.s,b,sizeof(b));

  }

  if(i==4){

    tor atp751;
  char a[186]={80, 48, 27, 15, 8, 4, 2, 1, 1, 2, 1, 1, 4, 2, 1, 1, 2, 1, 1, 7, 4, 2, 1, 1, 2, 1, 1, 3, 2, 1, 1, 1, 1, 
12, 7, 4, 2, 1, 1, 2, 1, 1, 3, 2, 1, 1, 1, 1, 5, 3, 2, 1, 1, 1, 1, 2, 1, 1, 1, 21, 12, 7, 4, 2, 1, 1, 
2, 1, 1, 3, 2, 1, 1, 1, 1, 5, 3, 2, 1, 1, 1, 1, 2, 1, 1, 1, 9, 5, 3, 2, 1, 1, 1, 1, 2, 1, 1, 1, 4, 2, 1, 
1, 1, 2, 1, 1, 33, 20, 12, 7, 4, 2, 1, 1, 2, 1, 1, 3, 2, 1, 1, 1, 1, 5, 3, 2, 1, 1, 1, 1, 2, 1, 1, 1, 
8, 5, 3, 2, 1, 1, 1, 1, 2, 1, 1, 1, 4, 2, 1, 1, 2, 1, 1, 16, 8, 4, 2, 1, 1, 1, 2, 1, 1, 4, 2, 1, 1, 2, 1, 
1, 8, 4, 2, 1, 1, 2, 1, 1, 4, 2, 1, 1, 2, 1, 1};
  char b[239]={112, 63, 32, 16, 8, 4, 2, 1, 1, 2, 1, 1, 4, 2, 1, 1, 2, 1, 1, 8, 4, 2, 1, 1, 2, 1, 1, 4, 2, 1, 1, 2, 1, 
1, 16, 8, 4, 2, 1, 1, 2, 1, 1, 4, 2, 1, 1, 2, 1, 1, 8, 4, 2, 1, 1, 2, 1, 1, 4, 2, 1, 1, 2, 1, 1, 31, 16, 
8, 4, 2, 1, 1, 2, 1, 1, 4, 2, 1, 1, 2, 1, 1, 8, 4, 2, 1, 1, 2, 1, 1, 4, 2, 1, 1, 2, 1, 1, 15, 8, 4, 2, 1, 
1, 2, 1, 1, 4, 2, 1, 1, 2, 1, 1, 7, 4, 2, 1, 1, 2, 1, 1, 3, 2, 1, 1, 1, 1, 49, 31, 16, 8, 4, 2, 1, 1, 2, 
1, 1, 4, 2, 1, 1, 2, 1, 1, 8, 4, 2, 1, 1, 2, 1, 1, 4, 2, 1, 1, 2, 1, 1, 15, 8, 4, 2, 1, 1, 2, 1, 1, 4, 2, 
1, 1, 2, 1, 1, 7, 4, 2, 1, 1, 2, 1, 1, 3, 2, 1, 1, 1, 1, 21, 12, 8, 4, 2, 1, 1, 2, 1, 1, 4, 2, 1, 1, 2, 1, 
1, 5, 3, 2, 1, 1, 1, 1, 2, 1, 1, 1, 9, 5, 3, 2, 1, 1, 1, 1, 2, 1, 1, 1, 4, 2, 1, 1, 1, 2, 1, 1};
  
  atp751.n=185;
  atp751.p=14166;
  atp751.q=13810;
  memcpy(atp751.s,a,sizeof(a));
  
  
  tor btp751;
  
  btp751.n=238;
  btp751.p=13898;
  btp751.q=13409;
  memcpy(btp751.s,b,sizeof(b));

  }

}


int main(){

  char buf[65536];
  SIDH sp434;
  

  sp434=init(sp434,1);
  puts(bigint_write(buf, sizeof(buf), sp434.p));
  //  setup(1);
  
  return 0;
}
