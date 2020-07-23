N=256
@A=0
@B=0
@C=0
@le_x=[N]
@le_y=[N]
@ll_x=[N]
@ll_y=[N]
@ll_z=[N]
@Pub_key_x=0 #return of ellip
@Pub_key_y=0
@Pub_key_z=0
@T_x=0 #eadd
@T_y=0
@D_x=0 #edbl
@D_y=0
@P_x=0 #ead2
@P_y=0
@P_z=0
@Q_x=0 #edl2
@Q_y=0
@Q_z=0
@N_x=[N] #le_temp
@N_y=[N]
@M_x=[N] #ll_temp
@M_y=[N]
@M_z=[N]
@P_x=0
@P_y=0
@Gen_key_x=0 # random point
@Gen_key_y=0
@Gen_key_z=0


require 'digest/sha1'
require 'openssl'

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
extern 'void say_hello()' # 'void say_hello(void)' だとなぜか怒られる
end
Greetings.say_hello() 
=end


@Pub_key=0
@KEYDEF=0
@KEYDEF2=0
@GROUP_GENERATOR=0
@K=0
@I=[9000000]

SHA1=Digest::SHA1

class String
  def sha1hex
    SHA1.hexdigest self
  end
end


# close したいだけ close しなくてもいいかな
# File.open(filename).read で代用化
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
=begin
A= -3
B= 7604282099657777500484621014808122868819881297501795229350968662542
P= 26959946667150639794667015087019630673557916260026308143510066298881
R= 13479973333575319897333507543509816934201006739333580278933849609027 a 224 bit prime
x=0
y=18612406876496176846476728192317424643475275919230634843914083116408
=end
if(n==1)
@CRV_n=331
@CRV_a=19
@CRV_b=77
@CRV_p=307
@CRV_G_x=0
@CRV_G_y=153
@CRV_G_z=1
end

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
@CRV_G_z=1
@CRV_n=26959946667150639794667015087019625940457807714424391721682722368061
@CRV_h=1
@CRV_inv=13479973333575319897333507543509815336778958130013154071755033149441
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
@CRV_G_z=1
@CRV_inv=13479973333575319897333507543509815336778958130013154071755033149441
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
@CRV_G_z=1
@CRV_n=115792089210356248762697446949407573529996955224135760342422259061068512044369
@CRV_h=1
@CRV_inv=57896044605178124381348723474703786765043071707645157097766815654433548926976
end

if(n==2562)
@CRV_name="eccp256r1"
@CRV_p = 0xFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEFFFFFC2F
@CRV_a = 0
@CRV_b = 7
@CRV_G_x = 0x0279BE667EF9DCBBAC55A06295CE870B07029BFCDB2DCE28D959F2815B16F81798
@CRV_G_y = 0x0479BE667EF9DCBBAC55A06295CE870B07029BFCDB2DCE28D959F2815B16F81798483ADA7726A3C4655DA4FBFC0E1108A8FD17B448A68554199C47D08FFB10D4B8
@CRV_G_z=1
@CRV_n = 0xFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEBAAEDCE6AF48A03BBFD25E8CD0364141
@CRV_h = 1
@CRV_inv=57896044618658097711785492504343953926634992332820282019728792003954417335832
end

if(n==2563)
@CRV_name="eccp256r2"
@CRV_p = 0xFFFFFFFF00000001000000000000000000000000FFFFFFFFFFFFFFFFFFFFFFFF
@CRV_a = 0xFFFFFFFF00000001000000000000000000000000FFFFFFFFFFFFFFFFFFFFFFFC
@CRV_b = 0x5AC635D8AA3A93E7B3EBBD55769886BC651D06B0CC53B0F63BCE3C3E27D2604B
@CRV_seedE = 0xC49D360886E704936A6678E1139D26B7819F7E90
@CRV_G_x = 0x036B17D1F2E12C4247F8BCE6E563A440F277037D812DEB33A0F4A13945D898C296
@CRV_G_y = 0x046B17D1F2E12C4247F8BCE6E563A440F277037D812DEB33A0F4A13945D898C2964FE342E2FE1A7F9B8EE7EB4A7C0F9E162BCE33576B315ECECBB6406837BF51F5
@CRV_G_z=1
@CRV_n = 0xFFFFFFFF00000000FFFFFFFFFFFFFFFFBCE6FAADA7179E84F3B9CAC2FC632551
@CRV_h = 1
@CRV_inv=57896044605178124381348723474703786765043071707645157097766815654433548926976
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


def jadd(x1,x2,y1,y2,z1,z2,mod)

  if(y1*y1%mod!=(x1**3+@CRV_a*x1*(z1**4)+@CRV_b*(z1**6))%mod)
    printf("no point X1\n");
    print x1 , "\n"
    print y1 , "\n"
    exit()
  end
    
  if(y2*y2%mod!=(x2**3+@CRV_a*x2*(z2**4)+@CRV_b*(z2**6))%mod)
    print "no point X2\n"
    exit()
  end

  if(x1==y1 || x2==y2)
    print "infinity devide3\n"
    print "Y1=" , y1 , "\n"
    print "Y2=" , y2 , "\n"
    if(y1*y1%mod==(x1**3+@CRV_a*x1*(z1**4)+@CRV_b*(z1**6))%mod)
      print "X1 on Curve\n"
    end
    if(y2*y2%mod==(x2**3+@CRV_a*x2*(z2**4)+@CRV_b*(z2**6))%mod)
      print "X2 on Curve\n"
    end
    print x1 , "\n"
    exit()
  end
#print "in ead2\n"
if(z1!=1 || z2!=1)
u1=x1*z2*z2
u2=x2*z1*z1
s1=y1*z2**3
s2=y2*z1**3
h=u2-u1
r=s2-s1
@P_x= (-h**3-2*u1*h*h+r*r)%mod
@P_y= (-s1*h**3+r*(u1*h*h-@P_x))%mod
@P_z= (z1*z2*h)%mod
end

if(z1==1 && z2==1)
u1=x1
u2=x2
s1=y1
s2=y2
h=u2-u1
r=s2-s1
@P_x= (-h**3-2*u1*h*h+r*r)%mod
@P_y= (-s1*h**3+r*(u1*h*h-@P_x))%mod
@P_z= (h)%mod
end

if(@P_z!=1)
rev=inv(@P_z,mod)
reb=inv(@P_z**2,mod)
re6=inv(@P_z**3,mod)
@P_x=reb*@P_x%mod
@P_y=re6*@P_y%mod
@P_z=rev*@P_z%mod
end
#exit()

if(@P_y**2%@CRV_p != (@P_x**3+@CRV_a*@P_x*@P_z**4+@CRV_b*@P_z**6)%@CRV_p)
  print "err jadd\n"
  exit()
end

end


def jdbl(x,y,z,mod)
s=4*x*y*y
m=3*x*x+@CRV_a*(z**4)
t= -2*s+m*m
@Q_x= t%mod
@Q_y= (-8*(y**4)+m*(s-t))%mod
@Q_z= 2*y*z%mod



if(@Q_y**2%@CRV_p != (@Q_x**3+@CRV_a*@Q_x*@Q_z**4+@CRV_b*@Q_z**6)%@CRV_p)
  print "err jdbl\n"
  exit()
end

end


#make a calcration table from base point Q
def mktbl3(x,y,z)
 print "in_mktbl3\n"


# print @CRV_name ,"\n"
 pp= @CRV_p
# print  pp ,"\n"
 xx= x
# print  xx ,"\n"
 yy= y
# print "y=", yy ,"\n"
zz= z
#print "z!=",zz ,"\n"
 a= @CRV_a
# print  a ,"\n"
# print  @CRV_b ,"\n"


if((xx**3+a*xx*(zz**4)+@CRV_b*(zz**6))%pp!=(yy**2)%pp)
  print "x is nor point\n"
  print xx , "\n"
  print yy , "\n"
  print zz , "\n"
  exit()
end


 # enzan table
   @ll_x[0]=xx
   @ll_y[0]=yy
   @ll_z[0]=zz

for i in 1..N #begin Pub_key at plain
   if(yy==0)
     print  "Y ga " , i ,"\n"
#     exit()
   end

if((xx**3+@CRV_a*xx*(zz**4)+@CRV_b*(zz**6))%@CRV_p!=(yy**2)%@CRV_p)
  print "x is n0r point\n"
  print i,"\n"
  exit()
end

   jdbl(xx,yy,zz,pp)
   @ll_x[i]=@Q_x
   @ll_y[i]=@Q_y
   @ll_z[i]=@Q_z
   #   print  Itoa(le[i]_x,16) << "," << Itoa(le[i]_y,16) ,"\n"
   if(@ll_x[i] > pp)
     print  "X > mod" ,"\n"
     exit()
   end
   if(@ll_y[i] > pp)
     print  "Y > mod" ,"\n"
     exit()
   end
   if(@ll_z[i] > pp)
     print  "Z > mod" ,"\n"
     exit()
   end
   xx=@ll_x[i]
   yy=@ll_y[i]
   zz=@ll_z[i]
 end #of for

end

#Compute Q=mG
def elp3(k)
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
    return -1
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

  @Pub_key_x=@ll_x[ki[0]]
  @Pub_key_y=@ll_y[ki[0]]
  @Pub_key_z=@ll_z[ki[0]]

#print "j=",j,"\n"

  if(k>0)
    for i in 1..j-1
#print "i=",i,"\n"
      if(@Pub_key_x != @ll_x[ki[i]] || @Pub_key_y != @ll_y[ki[i]] || @Pub_key_z != @ll_z[ki[i]])
	
	if(@Pub_key_y*@Pub_key_y%@CRV_p != (@Pub_key_x**3+@CRV_a*@Pub_key_x*(@Pub_key_z**4)+@CRV_b*(@Pub_key_z**6))%@CRV_p)
	  print "in ellip no point3 at\n"
	  print i ,"\n"
	  print @Pub_key_x ,"\n"
	  exit()
	end
	if(@ll_y[ki[i]]*@ll_y[ki[i]]%@CRV_p!=(@ll_x[ki[i]]**3+@CRV_a*@ll_x[ki[i]]*@ll_z[ki[i]]**4+@CRV_b*@ll_z[ki[i]]**6)%@CRV_p)
	  print ki[i], "\n"
	  print "no point in ellip3\n"
	  exit()
	end
	if(@Pub_key_y*@Pub_key_y%@CRV_p == (@Pub_key_x**3+@CRV_a*@Pub_key_x*(@Pub_key_z**4)+@CRV_b*(@Pub_key_z**6))%@CRV_p)
	  	# print "doko2\n"
	  if(@ll_y[ki[i]]*@ll_y[ki[i]]%@CRV_p==(@ll_x[ki[i]]**3+@CRV_a*@ll_x[ki[i]]*(@ll_z[ki[i]]**4)+@CRV_b*(@ll_z[ki[i]]**6))%@CRV_p)
	    	   # print "doko3\n"
	    jadd(@Pub_key_x,@ll_x[ki[i]],@Pub_key_y,@ll_y[ki[i]],@Pub_key_z,@ll_z[ki[i]],@CRV_p)
	    @Pub_key_x=@P_x
	    @Pub_key_y=@P_y
	    @Pub_key_z=@P_z
	if(@Pub_key_x==0 && @Pub_key_y==0 && @Pub_key_z==0)
#	if( @Pub_key_z==0)
	print @Pub_key_x , "," , @Pub_key_y , "," , @Pub_key_z ,"\n"
		print "infinity devide3\n"
		exit()
	end
	    # print "doko4\n"
	  end
	  if(@ll_y[ki[i]]*@ll_y[ki[i]]%@CRV_p!=(@ll_x[ki[i]]**3+@CRV_a*@ll_x[ki[i]]*@ll_z[ki[i]]**4+@CRV_b*@ll_z[ki[i]]**6)%@CRV_p)
	    print "no point ellip at\n"
	    print @ll_x[ki[i]], "\n"
	    exit()
	  end
#print "end1\n"
	end
#print "end2\n"
      end
 #     print "end3\n"
      if(@Pub_key_x == @ll_x[ki[i]] && @Pub_key_y == @ll_y[ki[i]] && @Pub_key_z == @ll_z[ki[i]])
	#print "ecole\n"
	jdbl(@Pub_key_x,@Pub_key_y,@Pub_key_z,@CRV_p)
	print "edb2(" , @Pub_key_x , "," , @Pub_key_y , "," , @Pub_key_z , ")\n"
	exit()
      end
         # print "in for loop " , i , " ";
    end
    
    if(@Pub_key_y*@Pub_key_y%@CRV_p != (@Pub_key_x**3+@CRV_a*@Pub_key_x*@Pub_key_z**4+@CRV_b*@Pub_key_z**6)%@CRV_p)
      print "bad1 " , ii , "\n"
      print "j= " , j , "\n"
      for jj in 0..j
	print ki[jj] , " "
      end
      print "\n"
      exit()
    end
  end

# no return --  print "after return\n"
end


def ecdh(a,b,nn)
init_curve(nn)
mktbl3(@CRV_G_x,@CRV_G_y,@CRV_G_z)
elp3(a)
print "a's Pubkey ",ax=@Pub_key_x,",",ay=@Pub_key_y,az=@Pub_key_z ,"\n"
elp3(b)
print "b's Pubkey ",bx=@Pub_key_x,",",by=@Pub_key_y,bz=@Pub_key_z, "\n"
mktbl3(ax,ay,az)
elp3(b)
cx=@Pub_key_x
cy=@Pub_key_y
cz=@Pub_key_z
mktbl3(bx,by,bz)
elp3(a)
dx=@Pub_key_x
dy=@Pub_key_y
dz=@Pub_key_z
if(cx==dx && cy==dy && cz=dz)
  print "key exchanged\n"
  print cx,",",cy,"\n"
end
if(cx!=dx || cy!=dy || cz!=dz)
  print "baka\n"
#  print cx,",",cy,"\n"
end

end

def mv(key,nn)
print "in mv\n"
init_curve(nn)
mktbl3(@CRV_G_x,@CRV_G_y,@CRV_G_z)
elp3(key)
print "Pubkey_x=",@Pub_key_x,"\n"
print "Pubkey_y=",@Pub_key_y,"\n"
print "Pubkey_z=",@Pub_key_z,"\n"

#command = { 'e' => 0, 'd' => 1}[(ARGV[0]||'').strip.downcase]
#data    = ARGV[1] && IO.read(ARGV[1])
#print "argv1=",ARGF.filename,"\n"

require 'securerandom'

  f = File.open(ARGF.filename,"rb")
  g = File.open(ARGF.filename + ".ecc","wb")
#=begin
int=0

  salt=SecureRandom.random_number(2**(32*8)) 
#  salt=[OpenSSL::Random.random_bytes(32)].pack("m")
#  salt.each_byte{|c| int=(int<<8)^c}
#  salt=int
print "salt=",salt,"\n"

  mktbl3(@Pub_key_x,@Pub_key_y,@Pub_key_z)
  elp3(salt)
  print "salt*Pubkey_x=",@Pub_key_x,"\n"
  print "salt*Pubkey_y=",@Pub_key_y,"\n"
  print "salt*Pubkey_z=",@Pub_key_z,"\n"
  @Gen_key_x=@Pub_key_x
  @Gen_key_y=@Pub_key_y
  @Gen_key_z=@Pub_key_z
for i in 0..10000
  @I[i]=0
end
ii=0
  mktbl3(@CRV_G_x,@CRV_G_y,@CRV_G_z)
  elp3(salt)
#=end
  while((str=f.read(32))!=nil)
    @I[ii]=str.size
    ii=ii+1
    c=0
    i=0
    salt=0
    str.each_byte{|c| salt=(salt<<8)^c}
    #print "length=",str.split(//s).length,"\n"
    jadd(@Gen_key_x,@CRV_G_x,@Gen_key_y,@CRV_G_y,@Gen_key_z,@CRV_G_z,@CRV_p)
    salt^=(@P_y%(2**8*str.size))
    @Gen_key_x=@P_x
    @Gen_key_y=@P_y
    @Gen_key_z=@P_z
=begin
    # 巨大な数 salt をバイトごとの配列に変換(packが使えないので原始的に)
    bytes = []
    while salt > 0
    salt, byte = salt >> 8, salt & 0xff
    bytes.unshift(byte) # 望むエンディアネスによっては push かも。
    end
    # バイトの配列をバイト文字列として書き出す
    open(ARGF.filename + ".ecc", 'wb') {|out| out.print(bytes.pack('C*')) } 
=end
    g.write(salt)
    g.write("\n")
  end


  f.close
  g.close

end



def dec(key,nn)
print "in mv\n"
init_curve(nn)
mktbl3(@Pub_key_x,@Pub_key_y,@Pub_key_z)
elp3(key)
print "dcPubkey_x=",@Pub_key_x,"\n"
print "dcPubkey_y=",@Pub_key_y,"\n"
print "dcPubkey_z=",@Pub_key_z,"\n"
salt=[32]


#OpenSSL::Random.random_bytes(32)

#print "salt=",salt,"\n"
command = { 'e' => 0, 'd' => 1}[(ARGV[0]||'').strip.downcase]
data    = ARGV[1] && IO.read(ARGV[1])

  g = File.open(ARGF.filename + ".txt","wb")
  f = File.open(ARGF.filename + ".ecc","rb")
  lines = fields = 0
ii=0

open(ARGF.filename + ".ecc") {|file|
  while l = file.gets
	l=l.to_i
	ls=@I[ii]
	ii=ii+1

=begin
value = 0
# バイナリデータを読み込んでバイト列に分解
raw = open(ARGF.filename + ".ecc"){|f| f.read.unpack('C*')}
  # 数を復元
  until raw.empty?
    value = (value << 8) + raw.shift
  end 
l=value
=end

#print "l=",ls,"\n"
    jadd(@Pub_key_x,@CRV_G_x,@Pub_key_y,@CRV_G_y,@Pub_key_z,@CRV_G_z,@CRV_p)
    @Pub_key_x=@P_x
    @Pub_key_y=@P_y
    @Pub_key_z=@P_z
    lines += 1
    fields += l.to_s.split(',').size
    l^=(@P_y%(2**8*ls))
    for i in 0..31
	salt[i]=0
    end
    while(l>0)
      i=0
      while(i<ls)
        salt[i]=l&0xff
        salt[i]=sprintf("%c",salt[i])
        l=(l>>8)
        i=i+1
      end
    end
	i=ls-1
	while(i>-1)
          g.write(salt[i])
	  i=i-1
	end
  end
}
puts "Total #{lines} lines, #{fields} fields"

    #print "length=",str.split(//s).length,"\n"

  f.close
  g.close

end


def otp(x,nn)

init_curve(nn)

r=[0xf874f8444567019dae5d0686dd04f2615204d38875190df1f54af6,0xe814985c80ee06915a0ab4580dd00fe97b37dc2e84110ff5fd6f7a,0xc854f064ce120797a3b76389d309f9711c5cbc51a7140cfbfd2efb,0xe814d03c85dc089feaf00ce85d805f4415c30c467201a0cfcf2f8ef,0xf834d8648cdd0f925ac0fcf84d80bfd190364c59c6e1d06fafc9fed,0xc844a82c9d580f9eca708ef8ada0bfe19547195809f190af9f3d863,0xf04ce82c58030f97da0d1188fdd0cf421035ec231911b03f5f2da40,0xd024f8442d2c009ba497998cd301f1713b1ea021ad1808fcf226e4,0xc87c800463fa0b965aa983c8bd90efc712331a2dc4d1506fcf29a5b,0x9864801c5d0706973a8de1885dd08f671635af27299130af1f26348,0xc82ca0442d2e039ada09b9580db03fb311b35ab2c0d1f0afff8db2e,0x9024f05431370f96dab2caf81d504fe415346894a511b09f1f70d22,0xd01ca824540f08989aad31c80d607f497b2396401c1509f7f4d2af,0x901cb04c4fc5059ccafe75980d20cf961137eb957a91a0ef5f824f5,0xe02cd00c54c6059e7ab4e3885d203f3213301a55590180cfafa2c57,0xa07cb0745d040591ca4dd1c89d109f1390461fa641a100df8f0ece3,0xc034b05c4863039f5a3570b8bdb03ff614b75b24f04110bf1f11075,0x9844f00488df0b96a807ce84d005fc39232ac5dda11b01f2fb3198,0xe82c905c5a0204978a2dd1388d600f5495418fe17c2150cf8f32e3b,0x903cf8442c270497aa694988dda00f5393b20d0db1e1e04f2fe7b0c,0xe05c903c81df0e9e4a10fcb88d208f5412c24bf43cc1102fef7aae2,0x800cb0045a0605909aad11980df0efc513b219a2d291e0cfef0ff6a,0xf034e83caf5d05912af6cf189db05f9313b33958c7e1f09f0f7f425,0xd02c887cc4130d9c7acb16e85db00f1614334fec5b41101f1f74d85,0x9004a86457c20e9aca44e3a8cd90ef0293b3eac8192190bf8f2da66,0xe864d8143b310d96fa629a385d304fc692b0ed578191402f4f89fb0,0x904c800c570a0896bacd81d86db04f4194369c995fb1a04fdfbfb03,0xd85cf0048ade0898fabb51385d904fa395424dc9ac51503f0fec3a0,0xe86ca8544ecd079faace75781da05f2291427be39931b0ffff0d841,0xf87c986c21210892ead9b9482d80df6494376b091c01e02fcfac7aa,0xd83c8014313b0b901aa20a68ed90df1115c3fd919df1b0df4fc193f,0x883c805ca45c04901a969f384dd01ff690c22b845cb1f0df4f8a9ef,0x8864906c48ce02994a3e55f83d807fa793b01957a5e1900f0fefa8a,0xe0149834446706988a1590b89d30dfb710c3cd7adf91108fffc9c17,0xb02cf0744ec40c9bca7e45280de09f26742aae5fa51002fff82aff,0xa864e07c66f703946aa9b328bd904f871033184602e130ef7fefbe5,0xb824c87494f305966abb42680dd0ef0695c6ce234d1506fdfad977,0x8044f02c5c000c9b4a0d41884de07f495416ec7f901301f6f06f4c,0xd87c887ccb8904974a6981b87d009fa313b34cb4e6a160efaf97097,0x885cb8642d210197ba5939086d804fb69035cae252d160bf3f1f067,0xc074880c80d80b99dab0ec48ed107f31437cad8da1701f0f78483,0x986cb82c4d6c0c968a551078fd20df6614b33b44db01302f5f64ba3,0xe87cb0748bd70098da1b01883db0ff571230feed8321e0cf0f1767a,0xd82cd81c4fc80c92ba8e65788d604ff492b0cdcec141e0df5f4cec2,0x9824987c35350897fa523a287d008f3790356905e601502f9f3b3df,0xf064b054252907975ae999582d907f3690b70b286761007fbf0f920,0xa004c06c81dc029dda10fcf8ed905f31532c9eacd71b0ef3f75cc8,0xa06cd84c310c0d9c9a5dc248bd40af3292b569b47bf1802f1fc49a0,0xe834a0245bc6079f9a44d3d83dd09f1316c1fd645691f04f2fe14ba,0xd86cf83c2f260d9cbac949681d705f1712c42f861501701f8f269dd];
c=[0x8014b87450cd0a96fac4b3389d504f6297b1dd23d51101fcf38a80,0x9044a0145c0b099d8a0d7128ad708f02963039499f31a06f6f7fd08,0xa054e86480e00f9e4a4ad478cd909f7396b04ef8e7e160dfcf9fe2d,0xe01c882487da0b948aebe1c87d30bf7390c63d9ea13150dfbf5cfcb,0xc034882c58c90692fa9493085d308fc311316d34fc11600ffffaae1,0x8024d07c3a360c99ac2ca08ed60bf41e1c49f292f01807fdf3f80a,0xa804d02c406a07982a85d0281d401fa514b6cd7a8d61f00f2f555cc,0xb864b07ca9560495a56af08dd20af3510b36f3887d1e08f5fc4af0,0xd064c06c86e70b959abad4481db0af4795c6fb5ed041709f5f69ab2,0x907c90148ce60e95eaea24b80d80ef731631ac925011b0af8f3d627,0xb854c86c390c01904a8d12989d809fa795b4ec18a98140df8ffda6e,0x8054d0244cc50b919abe7558bde05f4394c36ed5da41d07fff8acc7,0xe05c984c446307954a4500c82dd0cf4314b218bd34a1109f8f14bc6,0xa824b03480e20497ca0af418cd704f079436793e3b2140cfef8fc45,0xa004f0448bd90896a60dc785d90cf293b6cd881771b02f6fc47fc,0xa034e8145a050e9a3a3d81a8ed108f649241fc4268c1c0cf4f26771,0xf82c90043935029f2ab21a282da01f2513b15c599641405f3f39ee2,0xa874e81c2528009f9a69e928ad909f5110b31c24c1d1c0ff4f5dba8,0x807c884c80d401935a506ca8fd10ff1792b06a9ab0d1707f1fad1d4,0x883cb83c6ef400968ac9e308bd80ff2914169394e21504fef3a413,0x987cb86c89de069dea5bc158bda00fd590b498f55a91e0df1f721f9,0xd85cc04c340d08999a3d22b81d309f7197b69ec65521a05f0f968d0,0x885cc8744b6900994ae5a0382d80ff2695b45c36717150cf0fce3ea,0xa01cf874c51b0496ba0b26486d800ff690c7db586671a0cf2feb795,0xe84cb00c50010195dabdd1f84d60bfe293468b72de1a05f3fc8086,0xc814a07c81ea049eafa34e8ed50cf4314c4b8fe5101309f7f6cfca,0xe804d02c52020c9f1a9d61882d50af5416316c32d811d0ef8f7637c,0xa07cf07489d708902a50ec685d005fc394b6dfca8001b01f0f0d9d9,0xf034a80caa5f059e1a16ff988d900f069331eb2d1a71807fdf93599,0xc024c044590204942afdf1188d400f592358b6a9d5190df4fa5aca,0xb83ce87c59cf0a9d1ad4e328ad40df341545edb5d9f180bfcf92c52,0xf044c014370f019d9add52580d505f9112361fb44c11203f0fcaeea,0xa014900482e4079afafab4288d408fd295450b52605120df9fdd92d,0xc01cb06c3b340498baf28ac8cd400fa614c66816961e0ef3ff8ee9,0x8844a87ca45d06993a66dff84d40dff515c2a954c77150efbfd872f,0xa834d04c4e6807924a15c0a8adc08fb51240b9986711f05f1f64df6,0xe064f07438390896ea82aa28fd108f41032eb4c3be1909fbf24080,0x8024f82c5703089fa7df118ed702fa792b6f84dca21500fefa3b9c,0x981cf80c88d00e92fa805c884d004fd417c68fe1bc21e00f9fc2338,0x9844e8643c3906988ad24a18fd600f1116c69f0808b1a09f6f4b6cf,0xf814c82447cd0497ca1ed598ed701f7195b28b34de160cfdf4898a,0xe864e86c85d80e917a40fc68ada05fe69230be7e8961805f1fadcb3,0x884cd83cc61907945abb1688fd001fa39345ef190e81c04fdf7a61d,0xf854a01c98f703986acbf2386d305f710361c67b59140ef5f3fe83,0x8034f074af5c06958a66ffb80d109ff596b13cc19c71009f6fd2536,0xe07c8874320f0f967aeda298bd908fe293471f027a71409fcf822ea,0xc824802c5c090c9aaaad91680d90efc596b39a5cda130af2fa858f,0xa07ca82c98550291cac09e58edd07f5591c2b9f307f1a01f9f70b5b,0xc024904cc413079ea4b3658adf0ff7712b03d2bba31609f5fcd069,0x8014c02450080b9ecacd11d84d509fb19042ead38931a09f6f6dd49]
a_x=[50]
a_y=[50]
a_z=[50]
b=[50]

mktbl3(@CRV_G_x,@CRV_G_y,@CRV_G_z)
#ellip(@CRV_n)
#exit()

flag=0
elp3(x)
y_x=@Pub_key_x
y_y=@Pub_key_y
y_z=@Pub_key_z
d_x=[50]
d_y=[50]
d_z=[50]
e_x=[50]
e_y=[50]
e_z=[50]

for i in 0..49
  elp3(r[i])
  a_x[i]=@Pub_key_x
  a_y[i]=@Pub_key_y
  a_z[i]=@Pub_key_z
  print r[i],"\n"
end
for i in 0..49
  b[i]=(r[i]-c[i]*x)%@CRV_n
  print "b=",b[i],"\n"
end
for i in 0..49
  elp3(b[i])
  d_x[i]=@Pub_key_x
  d_y[i]=@Pub_key_y
  d_z[i]=@Pub_key_z
  print "dx=",d_x[i],"\n"
end
for i in 0..49
  elp3(c[i]*x)
  e_x[i]=@Pub_key_x
  e_y[i]=@Pub_key_y
  e_z[i]=@Pub_key_z
  print "c=",c[i],"\n"
end
#exit()
for i in 0..49
  jadd(d_x[i],e_x[i],d_y[i],e_y[i],d_z[i],e_z[i],@CRV_p)
  if(@P_x!=a_x[i] || @P_y!=a_y[i] || @P_z!=a_z[i])
	#print "i=",i,"\n"
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

def logcom(nn)
 n=N
 j=0
 ki=[N]
 plain=[21]
 k=[21][51]


init_curve(nn)
mktbl3(@CRV_G_x,@CRV_G_y,@CRV_G_z)
#elp3(@CRV_n)
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
elp3(ai)
v_x=@Pub_key_x
v_y=@Pub_key_y
v_z=@Pub_key_z
#print v_x, " ",v_y,"\n"

  e= ("0x"+STATUS).hex
print "sha=" ,e , "\n"
elp3(e)
c_x=@Pub_key_x
c_y=@Pub_key_y
c_z=@Pub_key_z
#print c_x, " ",c_y,"\n"

jadd(v_x,c_x,v_y,c_y,v_z,c_z,@CRV_p)
@Gen_key_x=@P_x
@Gen_key_y=@P_y
@Gen_key_z=@P_z
if((@Gen_key_y*@Gen_key_y)%@CRV_p!=((@Gen_key_x*@Gen_key_x*@Gen_key_x)+@CRV_a*@Gen_key_x*@Gen_key_z**4+@CRV_b*@Gen_key_z**6)%@CRV_p)
print "error!!\n"
exit()
end

if((@Gen_key_y*@Gen_key_y)%@CRV_p==((@Gen_key_x*@Gen_key_x*@Gen_key_x)+@CRV_a*@Gen_key_x*@Gen_key_z**4+@CRV_b*@Gen_key_z**6)%@CRV_p)
  print  ARGF.filename , "'s Log Commitment is " ,"\n"
  print  "x=", @Gen_key_x ,"\n"
  print  "y=", @Gen_key_y ,"\n"
end

end

#logcom(2244)
#otp(133,2244)
ecdh(0x12312312300000000000000001,0x1230000000000000000000012313,256)
# mv(1234156748901,256)
#dec(1234156748901,256)
#init_curve(256)
#mktbl3(@CRV_G_x,@CRV_G_y,@CRV_G_z)
#elp3(@CRV_n)
#test()
#rd()
