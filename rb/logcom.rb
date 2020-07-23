N=256
@le_x=[N]
@le_y=[N]
@Pub_key_x=0 #return of ellip
@Pub_key_y=0
@T_x=0 #eadd
@T_y=0
@D_x=0 #edbl
@D_y=0
@N_x=[N] #le_temp
@N_y=[N]
@P_x=0
@P_y=0
@Gen_key_x=0 # random point
@Gen_key_y=0

require 'digest/sha1'

def M32(x) (((1 << 32)-1)&(x)) end


=begin
#include <stdio.h>
void say_hello(void) { printf("Hello!\n"); return; }

$ cc -shared greetings..c -o greetings.so

#!/usr/bin/env ruby
require 'dl'
require 'dl/import'
module Greetings
extend DL::Importable
dlload './greetings.so'
extern 'void say_hello()' # 'void say_hello(void)' ‚¾‚Æ‚È‚º‚©“{‚ç‚ê‚é
end
Greetings.say_hello() 
=end


@Pub_key=0
@KEYDEF=0
@KEYDEF2=0
@GROUP_GENERATOR=0
@K=0

class String
  def sha1hex
    SHA1.new(self).hexdigest
  end
end

# close ‚µ‚½‚¢‚¾‚¯ close ‚µ‚È‚­‚Ä‚à‚¢‚¢‚©‚È
# File.open(filename).read ‚Å‘ã—p‰»
def fileread(file)
  f = File.open(file)
  str = f.read
  f.close
  str
end

def usage
  STDERR.puts "usage: #{$0} [OPTION] [FILE]...
  -t, -v      check SHA1 sums against given list
      --status     do not output anything, status code shows success"
  exit 1
end

opt_check = false
opt_status = false

while ARGV[0] =~ /^-/
  $_ = ARGV.shift
  if ~/^-c/ or ~/^--check/
    opt_check = true
  elsif ~/^--status/
    opt_status = true
  else
    usage
  end
end

if opt_status == true and opt_check == false
  STDERR.puts "#{$0}: the --status option is meaningful only when verifying checksums(--check)"
  exit 1
end

require 'sha1'

if opt_check
  ck_count_total = 0
  ck_count_failed = 0
end

while file_str = gets(nil)
  if opt_check
    file_str.split("\n").each do |l|
      ck_count_total += 1
      sum1, fname = l.split
      sum2 = fileread(fname).shahex
      status = if sum1 == sum2
                 'OK'
               else
                 ck_count_failed += 1
                 'FAILED'
               end
      if opt_status
      else
        puts fname + ': ' + status
      end
    end
  else
    puts file_str.sha1hex + '  ' + ARGF.filename
    STATUS= file_str.sha1hex
  end
end

if opt_check and ck_count_failed > 0
  if opt_status
  else
    STDERR.puts "#{$0}: WARNING: #{ck_count_failed} of #{ck_count_total} computed checksum did NOT match"
  end
  exit 1
end


def init_curve(n)
if(n==224)
#"{CBD61FC1-F50D-4","P-224","p=2^224-2^96+1",
@CRV_name="eccp224"
@CRV_p=26959946667150639794667015087019630673557916260026308143510066298881
@CRV_seedE=0xbd71344799d5c7fcdc45b59fa3b9ab8f6a948bc5
@CRV_r=0x5b056c7e11dd68f40469ee7f3c7a7d74f7d121116506d031218291fb
@CRV_a=-3
@CRV_b=0xb4050a850c04b3abf54132565044b0b7d7bfd8ba270b39432355ffb4
@CRV_G_x=0xb70e0cbd6bb4bf7f321390b94a03c1d356c21122343280d6115c1d21
@CRV_G_y=0xbd376388b5f723fb4c22dfe6cd4375a05a07476444d5819985007e34
@CRV_n=26959946667150639794667015087019625940457807714424391721682722368061
@CRV_h=1
end

if(n==2244)
@CRV_n= 13479973333575319897333507543509819484712548793029295142314934474707
#do you want to proceed with this one (Y/N)? y
@CRV_a= -3
@CRV_b= 7926735752311977820224618556926799352231714653617375950103029803860
@CRV_p= 26959946667150639794667015087019630673557916260026308143510066298881
#R= 13479973333575319897333507543509819484712548793029295142314934474707 a 224 bit prime
@CRV_G_x= 24155712282000049631001357595395450813097367499938434330297713128801
@CRV_G_y= 5882461958218329457915762297197751647381159972043925920846779622521
end

if(n==256)
#"{B858801C-582E-4","P-256","p=2^256-2^224+2^N+2^96-1",
@CRV_name="eccp256"
@CRV_p=115792089210356248762697446949407573530086143415290314195533631308867097853951
@CRV_seedE=0xc49d360886e704936a6678e1139d26b7819f7e90
@CRV_r=0x7efba1662985be9403cb055c75d4f7e0ce8d84a9c5114abcaf3177680104fa0d
@CRV_a= -3
@CRV_b=0x5ac635d8aa3a93e7b3ebbd55769886bc651d06b0cc53b0f63bce3c3e27d2604b
@CRV_G_x=0x6b17d1f2e12c4247f8bce6e563a440f277037d812deb33a0f4a13945d898c296
@CRV_G_y=0x4fe342e2fe1a7f9b8ee7eb4a7c0f9e162bce33576b315ececbb6406837bf51f5
@CRV_n=115792089210356248762697446949407573529996955224135760342422259061068512044369
@CRV_h=1
end
if(n==2562)
@CRV_name="eccp256r1"
@CRV_p = 0xFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEFFFFFC2F
@CRV_a = 0
@CRV_b = 7
@CRV_G_x = 0x0279BE667EF9DCBBAC55A06295CE870B07029BFCDB2DCE28D959F2815B16F81798
@CRV_G_y = 0x0479BE667EF9DCBBAC55A06295CE870B07029BFCDB2DCE28D959F2815B16F81798483ADA7726A3C4655DA4FBFC0E1108A8FD17B448A68554199C47D08FFB10D4B8
@CRV_n = 0xFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEBAAEDCE6AF48A03BBFD25E8CD0364141
@CRV_h = 1
end
if(n==2563)
@CRV_name="eccp256r2"
@CRV_p = 0xFFFFFFFF00000001000000000000000000000000FFFFFFFFFFFFFFFFFFFFFFFF
@CRV_a = 0xFFFFFFFF00000001000000000000000000000000FFFFFFFFFFFFFFFFFFFFFFFC
@CRV_b = 0x5AC635D8AA3A93E7B3EBBD55769886BC651D06B0CC53B0F63BCE3C3E27D2604B
@CRV_seedE = 0xC49D360886E704936A6678E1139D26B7819F7E90
@CRV_G_x = 0x036B17D1F2E12C4247F8BCE6E563A440F277037D812DEB33A0F4A13945D898C296
@CRV_G_y = 0x046B17D1F2E12C4247F8BCE6E563A440F277037D812DEB33A0F4A13945D898C2964FE342E2FE1A7F9B8EE7EB4A7C0F9E162BCE33576B315ECECBB6406837BF51F5
@CRV_n = 0xFFFFFFFF00000000FFFFFFFFFFFFFFFFBCE6FAADA7179E84F3B9CAC2FC632551
@CRV_h = 1
end

end


# GCD
def gcd(xx, yy)
  
  while (yy != 0) 
    tt = xx % yy
    xx = yy
    yy = tt
  end

  return xx

end


# invert of integer
def inv(a, n)
  
  d = n
  x = 0
  s = 1
  while (a != 0)
    q = d / a
    r = d % a
    d = a
    a = r
    t = x - q * s
    x = s
    s = t
  end
  gcd = d  # $\gcd(a, n)$ 

  return ((x + n) % (n / d))
end



def isqrt(x)

  if(x==0)
    return 0
  end
  s=1
  t=x
  while(s<t)
    s<<=1
    t>>=1
  end
  while(s<t)
    t=s
    s=(x/s+s)>>1
  end
  
  return t
  
end


# 0335196068
def eadd(x1, x2, y1, y2, mod)

  if(y1*y1%mod!=(x1*x1*x1+@CRV_a*x1+@CRV_b)%mod)
    printf("no point X1\n");
    print x1 , "\n"
    print y1 , "\n"
    exit()
  end
    
  if(y2*y2%mod!=(x2*x2*x2+@CRV_a*x2+@CRV_b)%mod)
    print "no point X2\n"
    exit()
  end

  if(x1==x2)
    print "infinity devide1\n"
    print "Y1=" , y1 , "\n"
    print "Y2=" , y2 , "\n"
    if(y1*y1%mod==(x1*x1*x1+@CRV_a*x1+@CRV_b)%mod)
      print "X1 on Curve\n"
    end
    if(y2*y2%mod==(x2*x2*x2+@CRV_a*x2+@CRV_b)%mod)
      print "X2 on Curve\n"
    end
    print x1 , "\n"
    exit()
  end

  #lamda
  if(y2>y1)
    y3=y2-y1
  end
  if(y2<y1)
    y3=mod+(y2-y1)
  end

  if(x2>x1)
    x3=x2-x1
  end
  if(x2<x1)
    x3=mod+(x2-x1)
  end
 
  if(y3==0)
    print "Y2=0 is ord=2 !\n"
    print "X1=" , x1 , "," , y1 , "\n"
    print "X2=" , x2 , "," , y2 , "\n"
    #   exit(1);
  end
  if(x3==0)
    print "X2=0\n"
    print x1 , "\n"
    print x2 , "\n"
    #    exit(1);
  end
  #  X3=(Y3*Y3*Inv(X3*X3,mod,&Q)-X1-X2)%mod;

  q=inv(x3, mod)

  #lambda
  ll=y3*q%mod
  if(ll<0)
    print "L is - " , ll ,"\n"
    exit()
  end

  x3=(ll*ll-x1-x2)%mod
  if(x3>0)
    x3=x3%mod
  end
  if(x3<0)
    while(x3<0)
      x3=x3+mod
    end
  end

  if(x1>x3)
    y3=(ll*(x1-x3)-y1)%mod
    #    cout << "X1>X3" << endl;
  end
  if(x1<x3)
    y3=(ll*(mod+x1-x3)-y1)%mod
    #    cout << "X1<X3" << endl;
  end
  if(x1==x3)
    y3=mod-y1
    #    cout << "X1==X3" << endl;
  end
  if(y3<0)
    print "Y<0\n"
    y3=mod+y3%mod
    #    exit(1);
  end
  #  cout << "X3=" << X3 << endl;
  #  cout << "Y3=" << Y3 << endl;
  e_x=x3
  e_y=y3
  if(y3*y3%mod!=(x3*x3*x3+@CRV_a*x3+@CRV_b)%mod)
    print "in eadd no point at\n"
    print x1 , "\n"
    print x2 , "\n"
    print y1 , "\n"
    print y2 , "\n"
    exit()
  end

  @T_x=x3%mod
  @T_y=y3%mod

end


def edbl(x1, y1, a, mod)

  if(y1*y1%@CRV_p!=(x1*x1*x1+@CRV_a*x1+@CRV_b)%@CRV_p)
    print "no point at edbl\n"
    exit()
  end

  ii=1
  x=3*x1*x1+a
  y=2*y1
  x3=inv(y, mod)
  ll=x3*x%mod
  x=ll*ll%mod

  if(x > 2*x1)
    x3=x-(2*x1%mod)
  end
  if(x < 2*x1)
    x3=mod+x-(2*x1%mod)
  end
  de_x=x3%mod
  #  cout << "in_dbl_L=" << L << endl;
  x3=x3%mod

  if(x1>x3)
    y3=ll*(x1-x3)
  end
  if(x1<x3)
    y3=ll*(mod+x1-x3)
  end
  if(y3<0)
    print y3 , "\n"
    exit()
  end
  if(y3>y1)
    y=y3-y1
  end
  if(y3<y1)
    y=y3-y1+mod
  end

  de_y=y%mod
  #  cout << de.x << "," << de.y << endl;
  if(de_y*de_y%@CRV_p!=(de_x*de_x*de_x+@CRV_a*x3+@CRV_b)%@CRV_p)
    print "in edbl no point at\n"
    print de_x , "\n"
    exit()
  end
  if(x3==0 && y3*y3%mod==(x3*x3*x3+@CRV_a*x3+@CRV_b)%mod)
    print "hakken!\n"
    print x3 , "\n"
    print y3 , "\n"
    exit()
  end

  @D_x=de_x%@CRV_p
  @D_y=de_y%@CRV_p

end


=begin
#Compute Q=mG
def ellip(k)

j=0
l=0
  if(k<0)
    printf "obsense K\n"
    print k "\n"
    exit()
  end

  if(k==0)
    print "infinity devide2\n"
    s_x=0
    s_y=0
    return s
   end

  if(k>@CRV_n)
    k=k%@CRV_n
  end


  ll=k
  while(ll>0)
#    print ll%2
    ll=(ll>>1)
    l=l+1
  end

  ll=k
  if(j!=0)
    j=0
  end

@le_x=@CRV_G_x
@le_y=@CRV_G_y

#  if(((kk^(1<<i))>>i)%2 == 0) #testbit(kk,i) <- shippai
  for i in 0..l-1
    if(ll%2 == 1 && i==0)
        @Pub_key_x=@CRV_G_x
	@Pub_key_y=@CRV_G_y
    end
    if(ll%2==1 && i>0 && j==0)
	@Pub_key_x=@le_x
	@Pub_key_y=@le_y
	j=1
    end
#	print "ll=",ll," %2=",ll%2," i=",i,"\n"
#	print "x=",@Pub_key_x," y=",@Pub_key_y,"\n"
	if(@Pub_key_x!=@le_x && @Pub_key_y!=@le_y && ll%2==1)
	  eadd(@Pub_key_x,@le_x,@Pub_key_y,@le_y,@CRV_p)
	  @Pub_key_x=@T_x
	  @Pub_key_y=@T_y
	end
    edbl(@le_x,@le_y,@CRV_a,@CRV_p)
    @le_x=@D_x
    @le_y=@D_y
#print "lex=",@le_x," ley=",@le_y,"\n"
    ll=(ll>>1)
  end


# no return --  print "after return\n"

=end

#=begin
#make a calcration table from base point Q
def mktable(x,y)
 print "in_mktable\n"


# print @CRV_name ,"\n"
 pp= @CRV_p
# print  pp ,"\n"
 xx= x
# print  xx ,"\n"
 yy= y
# print  yy ,"\n"
 a= @CRV_a
# print  a ,"\n"
# print  @CRV_b ,"\n"


if((xx**3+a*xx+@CRV_b)%pp!=(yy**2)%pp)
  print "x is nor point\n"
  print xx , "\n"
  print yy , "\n"
  exit()
end


 # enzan table
   @le_x[0]=xx
   @le_y[0]=yy


for i in 1..N #begin Pub_key at plain
   if(yy==0)
     print  "Y ga " , i ,"\n"
#     exit()
   end

if((xx**3+@CRV_a*xx+@CRV_b)%@CRV_p!=(yy**2)%@CRV_p)
  print "x is n0r point\n"
  print i,"\n"
  exit()
end

   edbl(xx,yy,a,pp)
   @le_x[i]=@D_x
   @le_y[i]=@D_y
   #   print  Itoa(le[i]_x,16) << "," << Itoa(le[i]_y,16) ,"\n"
   if(@le_x[i] > pp)
     print  "X > mod" ,"\n"
     exit()
   end
   if(@le_y[i] > pp)
     print  "Y > mod" ,"\n"
     exit()
   end
   xx=@le_x[i]
   yy=@le_y[i]
 end #of for
end




#Compute Q=mG
def ellip(k)
ki=[N]
j=0
l=0
  if(k<0)
    printf "obsense K\n"
    print k "\n"
    exit()
  end

  if(k==0)
    print "infinity devide2\n"
    s_x=0
    s_y=0
    return s
   end

  if(k>@CRV_n)
    k=k%@CRV_n
  end

  for j in 0..N
    ki[j]=0
  end

  ll=k
  while(ll>0)
    ll=(ll>>1)
    l=l+1
  end

  ll=k
  if(j!=0)
    j=0
  end

#  if(((kk^(1<<i))>>i)%2 == 0) #testbit(kk,i) <- shippai
  for i in 0..l-1
    if(ll%2 == 1)
      ki[j]=i
	j=j+1
    end
    ll=(ll>>1)
  end

  @Pub_key_x=@le_x[ki[0]]
  @Pub_key_y=@le_y[ki[0]]


  if(k>0)
    for i in 1..j-1
      if(@Pub_key_x != @le_x[ki[i]] || @Pub_key_y != @le_y[ki[i]])
	#      printf("doko1\n");
	if(@Pub_key_y*@Pub_key_y%@CRV_p != (@Pub_key_x*@Pub_key_x*@Pub_key_x+@CRV_a*@Pub_key_x+@CRV_b)%@CRV_p)
	  print "in ellip no point at\n"
	  print i ,"\n"
	  print @Pub_key_x ,"\n"
	  exit()
	end
	if(@le_y[ki[i]]*@le_y[ki[i]]%@CRV_p!=(@le_x[ki[i]]*@le_x[ki[i]]*@le_x[ki[i]]+@CRV_a*@le_x[ki[i]]+@CRV_b)%@CRV_p)
	  print ki[i], "\n"
	  print "no point in ellip\n"
	  exit()
	end
	if(@Pub_key_y*@Pub_key_y%@CRV_p == (@Pub_key_x*@Pub_key_x*@Pub_key_x+@CRV_a*@Pub_key_x+@CRV_b)%@CRV_p)
	  #	 printf("doko2\n");
	  if(@le_y[ki[i]]*@le_y[ki[i]]%@CRV_p==(@le_x[ki[i]]*@le_x[ki[i]]*@le_x[ki[i]]+@CRV_a*@le_x[ki[i]]+@CRV_b)%@CRV_p)
	    #	    printf("doko3\n");
	    eadd(@Pub_key_x,@le_x[ki[i]],@Pub_key_y,@le_y[ki[i]],@CRV_p)
	    @Pub_key_x=@T_x
	    @Pub_key_y=@T_y
	    # printf("doko4\n");
	  end
	  if(@le_y[ki[i]]*@le_y[ki[i]]%@CRV_p!=(@le_x[ki[i]]*@le_x[ki[i]]*@le_x[ki[i]]+@CRV_a*@le_x[ki[i]]+@CRV_b)%@CRV_p)
	    print "no point ellip at\n"
	    print @le_x[ki[i]], "\n"
	    exit()
	  end
	end
      end
      
      if(@Pub_key_x == @le_x[ki[i]] && @Pub_key_y == @le_y[ki[i]])
	edbl(@Pub_key_x,@Pub_key_y,@CRV_a,@CRV_p)
	print "dbl(" , @Pub_key_x , "," , @Pub_key_y , ")" , "\n"
	exit()
      end
      #     cout << "in for loop " << i << " ";
    end
    
    if(@Pub_key_y*@Pub_key_y%@CRV_p != (@Pub_key_x*@Pub_key_x*@Pub_key_x+@CRV_a*@Pub_key_x+@CRV_b)%@CRV_p)
      print "bad " , ii , "\n"
      print "j= " , j , "\n"
      for jj in 0..j
	print ki[jj] , " "
      end
      print "\n"
      exit()
    end
    
    if(@Pub_key_y*@Pub_key_y%@CRV_p == (@Pub_key_x*@Pub_key_x*@Pub_key_x+@CRV_a*@Pub_key_x+@CRV_b)%@CRV_p)
      #     cout << "Public key = (" << Itoa(Pub_key.x,16) << "," << Itoa(Pub_key.y,16) << ")" << endl;
#       print "in ellip of x=", @T_x,"\n"
#       print "in ellip of y=", @T_y,"\n"
    end
  end
# no return --  print "after return\n"
end


def otp(x,nn)

init_curve(nn)

r=[0xf874f8444567019dae5d0686dd04f2615204d38875190df1f54af6,0xe814985c80ee06915a0ab4580dd00fe97b37dc2e84110ff5fd6f7a,0xc854f064ce120797a3b76389d309f9711c5cbc51a7140cfbfd2efb,0xe814d03c85dc089feaf00ce85d805f4415c30c467201a0cfcf2f8ef,0xf834d8648cdd0f925ac0fcf84d80bfd190364c59c6e1d06fafc9fed,0xc844a82c9d580f9eca708ef8ada0bfe19547195809f190af9f3d863,0xf04ce82c58030f97da0d1188fdd0cf421035ec231911b03f5f2da40,0xd024f8442d2c009ba497998cd301f1713b1ea021ad1808fcf226e4,0xc87c800463fa0b965aa983c8bd90efc712331a2dc4d1506fcf29a5b,0x9864801c5d0706973a8de1885dd08f671635af27299130af1f26348,0xc82ca0442d2e039ada09b9580db03fb311b35ab2c0d1f0afff8db2e,0x9024f05431370f96dab2caf81d504fe415346894a511b09f1f70d22,0xd01ca824540f08989aad31c80d607f497b2396401c1509f7f4d2af,0x901cb04c4fc5059ccafe75980d20cf961137eb957a91a0ef5f824f5,0xe02cd00c54c6059e7ab4e3885d203f3213301a55590180cfafa2c57,0xa07cb0745d040591ca4dd1c89d109f1390461fa641a100df8f0ece3,0xc034b05c4863039f5a3570b8bdb03ff614b75b24f04110bf1f11075,0x9844f00488df0b96a807ce84d005fc39232ac5dda11b01f2fb3198,0xe82c905c5a0204978a2dd1388d600f5495418fe17c2150cf8f32e3b,0x903cf8442c270497aa694988dda00f5393b20d0db1e1e04f2fe7b0c,0xe05c903c81df0e9e4a10fcb88d208f5412c24bf43cc1102fef7aae2,0x800cb0045a0605909aad11980df0efc513b219a2d291e0cfef0ff6a,0xf034e83caf5d05912af6cf189db05f9313b33958c7e1f09f0f7f425,0xd02c887cc4130d9c7acb16e85db00f1614334fec5b41101f1f74d85,0x9004a86457c20e9aca44e3a8cd90ef0293b3eac8192190bf8f2da66,0xe864d8143b310d96fa629a385d304fc692b0ed578191402f4f89fb0,0x904c800c570a0896bacd81d86db04f4194369c995fb1a04fdfbfb03,0xd85cf0048ade0898fabb51385d904fa395424dc9ac51503f0fec3a0,0xe86ca8544ecd079faace75781da05f2291427be39931b0ffff0d841,0xf87c986c21210892ead9b9482d80df6494376b091c01e02fcfac7aa,0xd83c8014313b0b901aa20a68ed90df1115c3fd919df1b0df4fc193f,0x883c805ca45c04901a969f384dd01ff690c22b845cb1f0df4f8a9ef,0x8864906c48ce02994a3e55f83d807fa793b01957a5e1900f0fefa8a,0xe0149834446706988a1590b89d30dfb710c3cd7adf91108fffc9c17,0xb02cf0744ec40c9bca7e45280de09f26742aae5fa51002fff82aff,0xa864e07c66f703946aa9b328bd904f871033184602e130ef7fefbe5,0xb824c87494f305966abb42680dd0ef0695c6ce234d1506fdfad977,0x8044f02c5c000c9b4a0d41884de07f495416ec7f901301f6f06f4c,0xd87c887ccb8904974a6981b87d009fa313b34cb4e6a160efaf97097,0x885cb8642d210197ba5939086d804fb69035cae252d160bf3f1f067,0xc074880c80d80b99dab0ec48ed107f31437cad8da1701f0f78483,0x986cb82c4d6c0c968a551078fd20df6614b33b44db01302f5f64ba3,0xe87cb0748bd70098da1b01883db0ff571230feed8321e0cf0f1767a,0xd82cd81c4fc80c92ba8e65788d604ff492b0cdcec141e0df5f4cec2,0x9824987c35350897fa523a287d008f3790356905e601502f9f3b3df,0xf064b054252907975ae999582d907f3690b70b286761007fbf0f920,0xa004c06c81dc029dda10fcf8ed905f31532c9eacd71b0ef3f75cc8,0xa06cd84c310c0d9c9a5dc248bd40af3292b569b47bf1802f1fc49a0,0xe834a0245bc6079f9a44d3d83dd09f1316c1fd645691f04f2fe14ba,0xd86cf83c2f260d9cbac949681d705f1712c42f861501701f8f269dd];
c=[0x8014b87450cd0a96fac4b3389d504f6297b1dd23d51101fcf38a80,0x9044a0145c0b099d8a0d7128ad708f02963039499f31a06f6f7fd08,0xa054e86480e00f9e4a4ad478cd909f7396b04ef8e7e160dfcf9fe2d,0xe01c882487da0b948aebe1c87d30bf7390c63d9ea13150dfbf5cfcb,0xc034882c58c90692fa9493085d308fc311316d34fc11600ffffaae1,0x8024d07c3a360c99ac2ca08ed60bf41e1c49f292f01807fdf3f80a,0xa804d02c406a07982a85d0281d401fa514b6cd7a8d61f00f2f555cc,0xb864b07ca9560495a56af08dd20af3510b36f3887d1e08f5fc4af0,0xd064c06c86e70b959abad4481db0af4795c6fb5ed041709f5f69ab2,0x907c90148ce60e95eaea24b80d80ef731631ac925011b0af8f3d627,0xb854c86c390c01904a8d12989d809fa795b4ec18a98140df8ffda6e,0x8054d0244cc50b919abe7558bde05f4394c36ed5da41d07fff8acc7,0xe05c984c446307954a4500c82dd0cf4314b218bd34a1109f8f14bc6,0xa824b03480e20497ca0af418cd704f079436793e3b2140cfef8fc45,0xa004f0448bd90896a60dc785d90cf293b6cd881771b02f6fc47fc,0xa034e8145a050e9a3a3d81a8ed108f649241fc4268c1c0cf4f26771,0xf82c90043935029f2ab21a282da01f2513b15c599641405f3f39ee2,0xa874e81c2528009f9a69e928ad909f5110b31c24c1d1c0ff4f5dba8,0x807c884c80d401935a506ca8fd10ff1792b06a9ab0d1707f1fad1d4,0x883cb83c6ef400968ac9e308bd80ff2914169394e21504fef3a413,0x987cb86c89de069dea5bc158bda00fd590b498f55a91e0df1f721f9,0xd85cc04c340d08999a3d22b81d309f7197b69ec65521a05f0f968d0,0x885cc8744b6900994ae5a0382d80ff2695b45c36717150cf0fce3ea,0xa01cf874c51b0496ba0b26486d800ff690c7db586671a0cf2feb795,0xe84cb00c50010195dabdd1f84d60bfe293468b72de1a05f3fc8086,0xc814a07c81ea049eafa34e8ed50cf4314c4b8fe5101309f7f6cfca,0xe804d02c52020c9f1a9d61882d50af5416316c32d811d0ef8f7637c,0xa07cf07489d708902a50ec685d005fc394b6dfca8001b01f0f0d9d9,0xf034a80caa5f059e1a16ff988d900f069331eb2d1a71807fdf93599,0xc024c044590204942afdf1188d400f592358b6a9d5190df4fa5aca,0xb83ce87c59cf0a9d1ad4e328ad40df341545edb5d9f180bfcf92c52,0xf044c014370f019d9add52580d505f9112361fb44c11203f0fcaeea,0xa014900482e4079afafab4288d408fd295450b52605120df9fdd92d,0xc01cb06c3b340498baf28ac8cd400fa614c66816961e0ef3ff8ee9,0x8844a87ca45d06993a66dff84d40dff515c2a954c77150efbfd872f,0xa834d04c4e6807924a15c0a8adc08fb51240b9986711f05f1f64df6,0xe064f07438390896ea82aa28fd108f41032eb4c3be1909fbf24080,0x8024f82c5703089fa7df118ed702fa792b6f84dca21500fefa3b9c,0x981cf80c88d00e92fa805c884d004fd417c68fe1bc21e00f9fc2338,0x9844e8643c3906988ad24a18fd600f1116c69f0808b1a09f6f4b6cf,0xf814c82447cd0497ca1ed598ed701f7195b28b34de160cfdf4898a,0xe864e86c85d80e917a40fc68ada05fe69230be7e8961805f1fadcb3,0x884cd83cc61907945abb1688fd001fa39345ef190e81c04fdf7a61d,0xf854a01c98f703986acbf2386d305f710361c67b59140ef5f3fe83,0x8034f074af5c06958a66ffb80d109ff596b13cc19c71009f6fd2536,0xe07c8874320f0f967aeda298bd908fe293471f027a71409fcf822ea,0xc824802c5c090c9aaaad91680d90efc596b39a5cda130af2fa858f,0xa07ca82c98550291cac09e58edd07f5591c2b9f307f1a01f9f70b5b,0xc024904cc413079ea4b3658adf0ff7712b03d2bba31609f5fcd069,0x8014c02450080b9ecacd11d84d509fb19042ead38931a09f6f6dd49]
a_x=[50]
a_y=[50]
b=[50]

mktable(@CRV_G_x,@CRV_G_y)
#ellip(@CRV_n)
#exit()

flag=0
ellip(x)
y_x=@Pub_key_x
y_y=@Pub_key_y
d_x=[50]
d_y=[50]
e_x=[50]
e_y=[50]

for i in 0..49
  ellip(r[i])
  a_x[i]=@Pub_key_x
  a_y[i]=@Pub_key_y
  print r[i],"\n"
end
for i in 0..49
  b[i]=(r[i]-c[i]*x)%@CRV_n
  print "b=",b[i],"\n"
end
for i in 0..49
  ellip(b[i])
  d_x[i]=@Pub_key_x
  d_y[i]=@Pub_key_y
  print "dx=",d_x[i],"\n"
end
for i in 0..49
  ellip(c[i]*x)
  e_x[i]=@Pub_key_x
  e_y[i]=@Pub_key_y
  print "c=",c[i],"\n"
end
#exit()
for i in 0..49
  eadd(d_x[i],e_x[i],d_y[i],e_y[i],@CRV_p)
  if(@T_x!=a_x[i] || @T_y!=a_y[i])
	print "i=",i,"\n"
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


def ecdh(a,b,nn)

init_curve(nn)
mktable(@CRV_G_x,@CRV_G_y)
#ellip(@CRV_n)
ellip(a)
print "a's Pubkey ",ax=@Pub_key_x,",",ay=@Pub_key_y,"\n"
ellip(b)
print "b's Pubkey ",bx=@Pub_key_x,",",by=@Pub_key_y,"\n"
mktable(ax,ay)
ellip(b)
cx=@Pub_key_x
cy=@Pub_key_y
mktable(bx,by)
ellip(a)
dx=@Pub_key_x
dy=@Pub_key_y
if(cx==dx && cy==dy)
  print "key exchanged\n"
  print cx,",",cy,"\n"
end

end


def logcom(u,nn)
 n=N
 j=0
 ki=[N]
 plain=[21]
 k=[21][51]


init_curve(nn)
mktable(@CRV_G_x,@CRV_G_y)
#ellip(@CRV_n)
#print eccp192 ,"\n"


# print secp128r1_p ,"\n"
 for i in 0..20
   plain[i]=0
 end

 ii=0

 #schlor bai
   plain[0]=0x617973206865206b6e6f7773
   plain[1]=0x207520626574746572207468
   plain[2]=0x616e2075276c6c2065766572
   plain[3]=0x206b6e6f776e2068696d2e20
   plain[4]=0x4920446f6e27742077616e74
   plain[5]=0x20746f206368616e67652074   
   plain[6]=0x686520776f726c642e204920  
   plain[7]=0x446f6e277f2077616e742074
   plain[8]=0x686520776f726c6420746f20
   plain[9]=0x6368616e6765206d652e2020 
   plain[10]=0x54656c6c206d652049276d20
   plain[11]=0x612073696969657220492067
   plain[12]=0x6f74206e657773203420752e
   plain[13]=0x492073706f6b6520746f2047
   plain[14]=0x6f642074686973206d6f726e
   plain[15]=0x696e696e6720616e64206865
   plain[16]=0x20646f6e2774206c696b6520
   plain[17]=0x752e552074656c6c696e6720
   plain[18]=0x616c6c207468652070656f70
   plain[19]=0x6c6520746865206f72696769
   plain[20]=0x6e616c2073696e2048652073   
   
  # for(i=1i<11i++)     print  i << "=" << Legendle(i,11) << endl

 #plain text
=begin
 for ii in 0..20
   print  ii, "= ",plain[ii],"\n"
=end


 #encryption
ai=plain[1]
print "r=",ai,"\n"
ellip(ai)
v_x=@Pub_key_x
v_y=@Pub_key_y
#print v_x, " ",v_y,"\n"

  e= ("0x"+STATUS).hex
print "sha=" ,e , "\n"
ellip(e)
c_x=@Pub_key_x
c_y=@Pub_key_y
#print c_x, " ",c_y,"\n"

eadd(v_x,c_x,v_y,c_y,@CRV_p)
@Gen_key_x=@T_x
@Gen_key_y=@T_y

if((@Gen_key_y*@Gen_key_y)%@CRV_p!=((@Gen_key_x*@Gen_key_x*@Gen_key_x)+@CRV_a*@Gen_key_x+@CRV_b)%@CRV_p)
print "error!!\n"
exit()
end

if((@Gen_key_y*@Gen_key_y)%@CRV_p==((@Gen_key_x*@Gen_key_x*@Gen_key_x)+@CRV_a*@Gen_key_x+@CRV_b)%@CRV_p)
  print  ARGF.filename , "'s Log Commitment is " ,"\n"
  print  "x=", @Gen_key_x ,"\n"
  print  "y=", @Gen_key_y ,"\n"
end

end


#logcom(ARGV[0].to_i,2244)
#otp(133,2244)
ecdh(1234567890,9876543210,2244)

