# Copyright(C) 2003 by tcshacina (20031230)
# Elliptic Curve Domain of Parametor from www.secg.org
# This is a kind of a ECDSA's imprementation
# This program will includes ECNR imprementation
# FreeECDSA ver0.1 CRV.n is prime but not so good prime.
# ñ≥ë Ç»ä÷êîÇ∆Ç©ââéZÇÃç≈ìKâªÇ∆Ç©ÇÕå„âÒÇµÇ°Å`ÅBê≥ÇµÇ¢Ç©Ç«Ç§Ç©Ç‡ïsñæÅBîzïzÇÕGPLÇ…èÄãíÇ∑ÇÈÅB


N=521
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
@sign_r=0 #signature
@sign_v=0
@Gen_key_x=0 # random point
@Gen_key_y=0


def M32(x) (((1 << 32)-1)&(x)) end

@s_r=0
@s_s=0
@a_r=0
@a_s=0
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

# close ÇµÇΩÇ¢ÇæÇØ close ÇµÇ»Ç≠ÇƒÇ‡Ç¢Ç¢Ç©Ç»
# File.open(filename).read Ç≈ë„ópâª
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


# in EU 
def init_curve(n)

print "in_init_curve\n"

if(n==521)
#"{0E8920FD-B914-4","P-521","p=2^521-1",
@CRV_name="eccp521"
@CRV_p=6864797660130609714981900799081393217269435300143305409394463459185543183397656052122559640661454554977296311391480858037121987999716643812574028291115057151
@CRV_seedE=0xd09e8800291cb85396cc6717393284aaa0da64ba
@CRV_r=0x0b48bfa5f420a34949539d2bdfc264eeeeb077688e44fbf0ad8f6d0edb37bd6b533281000518e19f1b9ffbe0fe9ed8a3c2200b8f875e523868c70c1e5bf55bad637
@CRV_a= -3
@CRV_b=0x051953eb9618e1c9a1f929a21a0b68540eea2da725b99b315f3b8b489918ef109e156193951ec7e937b1652c0bd3bb1bf073573df883d2c34f1ef451fd46b503f00
@CRV_G_x=0x0c6858e06b70404e9cd9e3ecb662395b4429c648139053fb521f828af606b4d3dbaa14b5e77efe75928fe1dc127a2ffa8de3348b3c1856a429bf97e7e31c2e5bd66
@CRV_G_y=0x11839296a789a3bc0045c8a5fb42c7d1bd998f54449579b446817afbd17273e662c97ee72995ef42640c550b9013fad0761353c7086a272c24088be94769fd16650
print @CRV_name,"=","(",@CRV_G_x,",",@CRV_G_y,")","\n"
@CRV_n=6864797660130609714981900799081393217269435300143305409394463459185543183397655394245057746333217197532963996371363321113864768612440380340372808892707005449
end

if(n==5212)
@CRV_name="secp521r1"
@CRV_p = 0x01FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
@CRV_a = 0x01FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFC
@CRV_b = 0x0051953EB9618E1C9A1F929A21A0B68540EEA2DA725B99B315F3B8B489918EF109E156193951EC7E937B1652C0BD3BB1BF073573DF883D2C34F1EF451FD46B503F00
@CRV_seedE = 0xD09E8800291CB85396CC6717393284AAA0DA64BA
@CRV_G_x = 0x0200C6858E06B70404E9CD9E3ECB662395B4429C648139053FB521F828AF606B4D3DBAA14B5E77EFE75928FE1DC127A2FFA8DE3348B3C1856A429BF97E7E31C2E5BD66
@CRV_G_y = 0x0400C6858E06B70404E9CD9E3ECB662395B4429C648139053FB521F828AF606B4D3DBAA14B5E77EFE75928FE1DC127A2FFA8DE3348B3C1856A429BF97E7E31C2E5BD66011839296A789A3BC0045C8A5FB42C7D1BD998F54449579B446817AFBD17273E662C97EE72995EF42640C550B9013FAD0761353C7086A272C24088BE94769FD16650
@CRV_n = 0x01FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFA51868783BF2F966B7FCC0148F709A5D03BB5C9B8899C47AEBB6FB71E91386409
@CRV_h = 1
end

if(n==384)
#"{564D7012-E054-4","P-384","p=2^384-2N!N0128-2N!N096+2N!N032-1",
@CRV_name="eccp384"
@CRV_p=39402006196394479212279040100143613805079739270465446667948293404245721771496870329047266088258938001861606973112319
@CRV_seedE=0xa335926aa319a27a1d00896a6773a4827acdac73
@CRV_r=0x79d1e655f868f02fff48dcdee14151ddb80643c1406d0ca10dfe6fc52009540a495e8042ea5f744f6e184667cc722483
@CRV_a= -3
@CRV_b=0xb3312fa7e23ee7e4988e056be3f82d19181d9c6efe8141120314088f5013875ac656398d8a2ed19d2a85c8edd3ec2aef
@CRV_G_x=0xaa87ca22be8b05378eb1c71ef320ad746e1d3b628ba79b9859f741e082542a385502f25dbf55296c3a545e3872760ab7
@CRV_G_y=0x3617de4a96262c6f5d9e98bf9292dc29f8f41dbd289a147ce9da3113b5f0b8c00a60b1ce1d7e819d7a431d7c90ea0e5f
@CRV_n=39402006196394479212279040100143613805079739270465446667946905279627659399113263569398956308152294913554433653942643
@CRV_h=1
end

if(n==192)
#"{7DE16579-4B05-4","P-N","p=2^N-2^64-1",
@CRV_name="eccp192"
@CRV_p=6277101735386680763835789423207666416083908700390324961279
@CRV_seedE=0x3045ae6fc8422f64ed579528d38120eae12196d5
@CRV_r=0x3099d2bbbfcb2538542dcd5fb078b6ef5f3d6fe2c745de65
@CRV_a= -3
@CRV_b=0x64210519e59c80e70fa7e9ab72243049feb8deecc146b9b1
@CRV_G_x=0x188da80eb03090f67cbf20eb43a18800f4ff0afd82ff1012
@CRV_G_y=0x07192b95ffc8da78631011ed6b24cdd573f977a11e794811
@CRV_n=6277101735386680763835789423176059013767194773182842284081
@CRV_h=1
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

if(n==130)
@CRV_name="eccp130"
@CRV_p=1361129467683753853853498429727072845993
@CRV_a= 3
@CRV_b=104361129467683753853853498429727072845993
@CRV_n=136112946783753853808807784495688874237
end
if(n==131)
@CRV_p=1361129467683753853853498429727072845993
@CRV_a= 1
@CRV_b=1230929586093851880935564157041535079194
@CRV_n=1361129467683753853846060531160085896483
end
if(n==160)
@CRV_p=1461501637330902918203684832716283019655932542983
@CRV_a=10
@CRV_b=1343632762150092499701637438970764818528075565078
@CRV_n=146150163733090291820368351828126812711137002561
end

if(n==161)
@CRV_p=1461501637330902918203684832716283019655932542983
@CRV_a=1
@CRV_b=1010685925500572430206879608558642904226772615919
@CRV_n=1461501637330902918203683038630093524408650319587
end
if(n==190)  
@CRV_p=1569275433846670190958947355801916604025588861116008628353
@CRV_a=10
@CRV_b=1348462411414361312611054113116931087580694918677422294274
end
if(n==191)
@CRV_n=1569275433846670190958947355780287040305255540896946997883
@CRV_p=1569275433846670190958947355801916604025588861116008628353
@CRV_a=2
@CRV_b=1235224671237188587186683314843039551549145551652348919785
@CRV_n=1569275433846670190958947355744860428187339379278234198947
end

if(n==230)
@CRV_p=1725436586697640946858688965569256363112777243042596638790631055949891
@CRV_a=7
@CRV_b=30760627165932116708009308342886016941744188615122817540619633362515
@CRV_n=172543658669764094685868896556925619567876384646209701190542123355279
 #57514552889921364895289632185641873189292128215403233730180707785093*3
end

#sec2
if(n==112)
@CRV_name="secp112r1"
@CRV_p = 0xDB7C2ABF62E35E668076BEAD208B
@CRV_a = 0xDB7C2ABF62E35E668076BEAD2088
@CRV_b = 0x659EF8BA043916EEDE8911702B22
@CRV_seedE = 0x00F50B028E4D696E676875615175290472783FB1
@CRV_G_x = 0x0209487239995A5EE76B55F9C2F098
@CRV_G_y = 0x0409487239995A5EE76B55F9C2F098A89CE5AF8724C0A23E0E0FF77500
@CRV_n = 0xDB7C2ABF62E35E7628DFAC6561C5
@CRV_h = 1
end
if(n==1122)
@CRV_name="secp112r2"
@CRV_p = 0xDB7C2ABF62E35E668076BEAD208B
@CRV_a = 0x6127C24C05F38A0AAAF65C0EF02C
@CRV_b = 0x51DEF1815DB5ED74FCC34C85D709
@CRV_seedE = 0x002757A1114D696E6768756151755316C05E0BD4
@CRV_G_x = 0x034BA30AB5E892B4E1649DD0928643
@CRV_G_y = 0x044BA30AB5E892B4E1649DD0928643ADCD46F5882E3747DEF36E956E97
@CRV_n = 0x36DF0AAFD8B8D7597CA10520D04B
@CRV_h = 4
end

if(n==128)
@CRV_name="secp128r1"
@CRV_p = 0xFFFFFFFDFFFFFFFFFFFFFFFFFFFFFFFF
@CRV_a = 0xFFFFFFFDFFFFFFFFFFFFFFFFFFFFFFFC
@CRV_b = 0xE87579C11079F43DD824993C2CEE5ED3
@CRV_seedE = 0x000E0D4D696E6768756151750CC03A4473D03679
@CRV_G_x = 0x03161FF7528B899B2D0C28607CA52C5B86
@CRV_G_y = 0x04161FF7528B899B2D0C28607CA52C5B86CF5AC8395BAFEB13C02DA292DDED7A83
@CRV_n = 0xFFFFFFFE0000000075A30D1B9038A115
@CRV_h = 1
end
if(n==1282)
@CRV_name="secp128r2"
@CRV_p = 0xFFFFFFFDFFFFFFFFFFFFFFFFFFFFFFFF
@CRV_a = 0xD6031998D1B3BBFEBF59CC9BBFF9AEE1
@CRV_b = 0x5EEEFCA380D02919DC2C6558BB6D8A5D
@CRV_seedE = 0x004D696E67687561517512D8F03431FCE63B88F4
@CRV_G_x = 0x027B6AA5D85E572983E6FB32A7CDEBC140
@CRV_G_y = 0x047B6AA5D85E572983E6FB32A7CDEBC14027B6916A894D3AEE7106FE805FC34B44
@CRV_n = 0x3FFFFFFF7FFFFFFFBE0024720613B5A3
@CRV_h = 4
end

#secp160k1_name="secp160k1"
#secp160k1_p = 0xFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEFFFFAC73
#secp160k1_a = 0
#secp160k1_b = 0x0000000000000000000000000000000000000007
#secp160k1_G_x = 0x023B4C382CE37AANA4019E763036F4F5DD4D7EBB
#secp160k1_G_y = 0x043B4C382CE37AANA4019E763036F4F5DD4D7EBB938CF935318FDCED6BC28286531733C3F03C4FEE
#secp160k1_n = 0x0100000000000000000001B8FA16DFAB9ACA16B6B3
#secp160k1_h = 1

if(n==160)
@CRV_name="secp160r1"
@CRV_p = 0xFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF7FFFFFFF
@CRV_a = 0xFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF7FFFFFFC
@CRV_b = 0x1C97BEFC54BD7A8B65ACF89F81D4D4ADC565FA45
@CRV_seedE = 0x1053CDE42C14D696E67687561517533BF3F83345
@CRV_G_x = 0x024A96B5688EF573284664698968C38BB913CBFC82
@CRV_G_y = 0x044A96B5688EF573284664698968C38BB913CBFC8223A628553168947D59DCC912042351377AC5FB32
@CRV_n = 0x0100000000000000000001F4C8F927AED3CA752257
@CRV_h = 1
end
if(n==1602)
@CRV_name="secp160r2"
@CRV_p = 0xFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEFFFFAC73
@CRV_a = 0xFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEFFFFAC70
@CRV_b = 0xB4E134D3FB59EB8BAB57274904664D5AF50388BA
@CRV_seedE = 0xB99B99B099B323E02709A4D696E6768756151751
@CRV_G_x = 0x0252DCB034293A117E1F4FF11B30F7199D3144CE6D
@CRV_G_y = 0x0452DCB034293A117E1F4FF11B30F7199D3144CE6DFEAFFEF2E331F296E071FA0DF9982CFEA7D43F2E
@CRV_n = 0x0100000000000000000000351EE786A818F3A1A16B
@CRV_h = 1
end

if(n==1922)
@CRV_name="secpNk1"
@CRV_p = 0xFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEFFFFEE37
@CRV_a = 0
@CRV_b = 0x000000000000000000000000000000000000000000000003
@CRV_G_x = 0x03DB4FF10EC057E9AE26B07D0280B7F4341DA5D1B1EAE06C7D
@CRV_G_y = 0x04DB4FF10EC057E9AE26B07D0280B7F4341DA5D1B1EAE06C7D9B2F2F6D9C5628A7844163D015BE86344082AA88D95E2F9D
@CRV_n = 0xFFFFFFFFFFFFFFFFFFFFFFFE26F2FC10F69466A74DEFD8D
@CRV_h = 1
end
if(n==1923)
@CRV_name="secpNr1"
@CRV_p = 0xFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEFFFFFFFFFFFFFFFF
@CRV_a = 0xFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEFFFFFFFFFFFFFFFC
@CRV_b = 0x64210519E59C80E70FA7E9AB72243049FEB8DEECC146B9B1
@CRV_seedE = 0x3045AE6FC8422F64ED579528D38120EAE12196D5
@CRV_G_x = 0x03188DA80EB03090F67CBF20EB43A18800F4FF0AFD82FF1012
@CRV_G_y = 0x04188DA80EB03090F67CBF20EB43A18800F4FF0AFD82FF101207192B95FFC8DA78631011ED6B24CDD573F977A11E794811
@CRV_n = 0xFFFFFFFFFFFFFFFFFFFFFFFF99DEF836146BC9B1B4D22831
@CRV_h = 1
end

if(n==2242)
@CRV_name="secp224k1"
@CRV_p = 0xFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEFFFFE56D
@CRV_a = 0
@CRV_b = 0x00000000000000000000000000000000000000000000000000000005
@CRV_G_x = 0x03A1455B334DF099DF30FC28A169A467E9E47075A90F7E650EB6B7A45C
@CRV_G_y = 0x04A1455B334DF099DF30FC28A169A467E9E47075A90F7E650EB6B7A45C7E089FED7FBA344282CAFBD6F7E319F7C0B0BD59E2CA4BDB556D61A5
@CRV_n = 0x010000000000000000000000000001DCE8D2EC6184CAF0A971769FB1F7
@CRV_h = 1
end
if(n==2243)
@CRV_name="eccp224r1"
@CRV_p = 0xFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF000000000000000000000001
@CRV_a = 0xFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEFFFFFFFFFFFFFFFFFFFFFFFE
@CRV_b = 0xB4050A850C04B3ABF54132565044B0B7D7BFD8BA270B39432355FFB4
@CRV_seedE = 0xBD71344799D5C7FCDC45B59FA3B9AB8F6A948BC5
@CRV_G_x = 0x02B70E0CBD6BB4BF7F321390B94A03C1D356C21122343280D6115C1D21
@CRV_G_y = 0x04B70E0CBD6BB4BF7F321390B94A03C1D356C21122343280D6115C1D21BD376388B5F723FB4C22DFE6CD4375A05A07476444D5819985007E34
@CRV_n = 0xFFFFFFFFFFFFFFFFFFFFFFFFFFFF16A2E0B8F03E13DD29455C5C2A3D
@CRV_h = 1
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
if(n==3842)
@CRV_name="eccp384"
@CRV_p = 0xFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEFFFFFFFF0000000000000000FFFFFFFF
@CRV_a = 0xFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEFFFFFFFF0000000000000000FFFFFFFC
@CRV_b = 0xB3312FA7E23EE7E4988E056BE3F82D19181D9C6EFE8141120314088F5013875AC656398D8A2ED19D2A85C8EDD3EC2AEF
@CRV_seedE = 0xA335926AA319A27A1D00896A6773A4827ACDAC73
@CRV_G_x = 0x03AA87CA22BE8B05378EB1C71EF320AD746E1D3B628BA79B9859F741E082542A385502F25DBF55296C3A545E3872760AB7
@CRV_G_y = 0x04AA87CA22BE8B05378EB1C71EF320AD746E1D3B628BA79B9859F741E082542A385502F25DBF55296C3A545E3872760AB73617DE4A96262C6F5D9E98BF9292DC29F8F41DBD289A147CE9DA3113B5F0B8C00A60B1CE1D7E819D7A431D7C90EA0E5F
@CRV_n = 0xFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFC7634D81F4372DDF581A0DB248B0A77AECEC196ACCC52973
@CRV_h = 1
end
 
end


=begin
typedef struct 
{
  Integer p     # 79-521 bit prime */
  Integer q     # group order */
  Integer g     # group generator */
  Integer y     # g^x mod p */
end ECDSA_pub_key

typedef struct 
{
  Integer p     # 160-bit prime */
  Integer q     # group order */
  Integer g     # group generator */
  Integer y     # g^x mod p */
  Integer x     # select exponent */
end ECDSA_sec_key
=end



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


#jj=aa^bb mod oo
def exp(aa, bb, oo)

  ii=oo
  j=0
  jj=0
  kk=[2**12] #prime is 4096 bit table
  c=[2**13]  #mod is 8N bit table
  count=0

  for i in 0..4096
    kk[i]=0
  end
  while(ii>0) 
	ii = (ii>>1)
	j=j+1
  end


  kk[0]=aa
#  print j,"\n"
  
#ex.1000=2**3+2**5+2**6+2**7+2**8+2**9 makes a array c=[3,5,6,7,8,9]
    for i in 0..j
      if (((bb^(1<<i))>>i)%2 == 0) # testbit(bb,i)
	c[count]=i
	count=count+1
      end
    end
#    print count,"\n"

    for i in 1..(c[count-1]+1)
      kk[i] = kk[i-1]*kk[i-1]%oo
    end

    jj=1
    for i in 0..count-1
      jj=kk[c[i]]*jj%oo
      if (jj==0)
#	print i,"\n"
      end
    end

    return jj
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


def pwr(x, y)

  z=x
  y=y-1
  while(y>0)
    z=z*x
    y=y-1
  end

  return z
end


=begin
# Point Complession
Integer PC(Integer A, Integer P)
  Integer X,N,Q,Y,R,B,T,M,I
  int e=0,flag=0


  #  print  "PC= " << A << endl
  I=1
  N=867587657675
  while(Legendle(N,P) != -1) N=N+1

  if(Legendle(N,P)== -1)
    Q=P-1

    while(Q%2==0)  Q=Q/2 e++ end
    if(Q%2!=0) e=1

    print  "e=" << e << endl
    print  "Q=" << Q << endl
    
    if(Q%2!=0 || e%2!=0)
      Y=Exp(N,Q,P) R=e X=Exp(A,(Q-1)/2,P)
      if(A*X*X>P) B=A*X*X%P
      if(A*X*X<P) B=A*X*X
      if(A*X>P)   X=A*X%P
      if(A*X<P)   X=A*X

      M=1
      while(B%P!=1)
	print  "B=" << B << endl
	while(Exp(B,Exp(2,M,P),P)!=1) 
	  
	    M=M+1
	    if(M>1024)
	      exit()
	    end
	if(Exp(B,Exp(2,M,P),P)==1)
	  T=Exp(Y,Exp(2,R-M-1,P),P) Y=T*T%P R=M
	  X=X*T%P B=B*Y%P
	end
	M=M+1
      end
    end
  end

  return X
=end


=begin
# the following notation is used in this comment_
t=floor(log2(p)),s=upper((t-1)/160) and v=t-160*s
# $(B$3$N%=%U%H$r5FEDAaID$KJ{$2$k(B */
#
Domain Parametors
1_ a field size q, where either q=p, an odd prime, or q=2^m
2_ an indication FR(field representation) of the representation used 
for the elements of F_q
3_ (optional) a bit string seedE of length at least 160bits, if the
elliptic curve was generated in accordance with the method describes in
section 5_2
4_ two filed elements a and b in F_q which define the equation of the 
elliptic curve E over F_q (i_e_, y^2=x^3+ax+b in the case p>3, 
   and y^2+xy = x^3+ax^2+b in the case p=2)
5_ two field elements xG and yG in F_q which define 
a finite point G=(xG , yG) of prime order in E(F_q)
6_ the order n of the point G, with n>2^160 and n > 4*root(q) and
7_ the cofactor h=#E(F_q)/n_


ALGIRITHUM (case q=p) CM method will appear

#madayo, assettya dhame.

function : generating a random elliptic curve over F_p
INPUT: a field size p, where p is an odd prime_
Output: a bit string seedE of length at least 160 bits and 
field elements a,b in F_p which define an elliptic curve E over F_p

1_ choose an arbitary bit string seedE of length g >= 160 bits_
2_ compute H=sha1(seedE), and let c0 denote the bit string of length
 v bits obtained by taking the v rightmost bits of H_
3_ Let W0 denote the bit string of length v bits obtained by setting
thr leftmost bit of c0 to 0_ (This ensure that r < p_)
4_ Let c be the integer whose binary expansion is given by the 
g-bit string seedE_
5_ For i from 1 to s do
      4_1 Let s_i be the g-bit string which is the binary expansion of
          the integer (z+i)mod 2^g_
      4_2 Compute W_i = SHA1(s_i)_
6_ Let W be the bit string obtained by the concatination of W0,W1,___,Ws
as follows: W = W0||W1||___||Ws_
7_ Let r be the integer whose binary expansion is given by W_
8_ If r=0 or if  4r+27 == 0 (mod p) then go to step 1_
9_ Choose arbitary integers a,b in F_p, not both 0,such that 
r*b^2 == a^3 (mod p)_ (For example, one may take a=r and b=r_)
10_ The elliptic curve chosen over F_p is E : y^2=x^3+ax+b_
11_ Output(seedE, a, b)_
=end

def gen_curves()


end



=begin
Domain Parametor Generation
The following is one way to generate cryptographically secure 
domain parameters:

1_ Select coefficients a and b from F_q verifiably at random using 
Algorithm 1 or Algorithm 3_Let E be the curve y^2=x^3+ax+b in the case
 q=p, and y^2+xy=x^3+ax^2+b in the case q=2^m_
2_Compute N=#E(F_q)_
3_ Verify that N is divisible by a large prime n(n>2^160 and n>4*root(q))_ 
If not, then go to step1_
4_ Verify that n does not divide q^k-1 for each k, 1<=k<=20_ If not,
then go to step1_
5_  Verify that n!=q_ If not,then go to step1_
6_ Select an arbitary point G'in E(F_q) and set G=(N/n)G'_ 
Repeat until G != O_
=end

def gen_dop()


end


=begin
Domain Parametor Verification
EC domain parametors D=(q,FR,a,b,G,n,h)
1_ A performs explicit domain parametor validaton using Algorithm5
2_ A generates D itself using a trusted system_
3_ A receives assurance from a trusted party T 
(e_g_, a certification authority) that T has performed explicit domain
 parameter validation of D using Algorithm5_
4_ A received assurance from a trusted party T that D was generated using a
trusted system_
Algirithm5 Explicit Validation of set of EC Domain Parametors
Input: A set of EC domain parametors D=(q,FR,a,b,G,n,h)_
Output: Acceptance or rejection of the validity of D_
1_ Verify that q is an odd prime (q=p) or a power of 2 (q=2^m)_
2_ Verify that FR is a "valid" representation for F_q_
3_ Verify that G != O_
4_ 
5_ 
6_ 
7_ 
8_ 
9_ 
10_ 
11_ 
12_ 
13_ 
14_ 

=end

def chk_dp()


end


=begin

Let the non-isomorphic elliptic curves denoted E1:y^2=x^3+ax+b and
E2:y^2=x^3+ac^2x^2+bc^3, where c in F_p is quadratic non-residue modulo p,
are said to be twists of each other_ Note that both these curves have 
the same r value_ their orders are related by the e defined over F_p a 
equation #E1(F_p)+#E2(F_p)=2p+p_ thus, if one is able to compute #E1(F_p),
then one can easily deduce #E2(F_p)_


Verification
ALGORITHUM2
INPUT:A field size p (a prime), a bit string seedE of length g>= 160 bits,
 and field elements a,b in F_p which define an elliptic curve 
E:y^2=x^3+ax+b over F_p_
Output: Acceptance or rejection that E was randomly generated using 
Algorithm1_

1_ Compute H=sha1(seedE), and let c0 denote the bit string of length v bits
obtained by taking the v rightmost bits of H_
2_ Let W0 denote the bit string of length v bits obtained by setting the 
leftmost bit of c0 to 0_
3_ Let x be the integer whose binary expansion is given by the g-bit 
string seedE_
4_ For i from 1 to s do:
     4_1_ Let s_i be the g-bit string which is the binary expansion of the
          integer (z + i)mod 2^g_
     4_2  Compute W_i =sha1(s_i)_
5_ Let W be the bit string obtained by the concatination of W0,W1,___,Ws as 
follows: W'=W0||W1||___||Ws_
6_ Let r' be the integer whose binary expansion is given by W'_
7_ If r'*b^2==a^3(mod p) then accept otherwise reject_\
=end

def chk_ec()


end


=begin
___continuing of ellisyum

eccpey Pair Generation
1_ 
2_ 
3_ 
=end
def keygen()


end


=begin
Public eccpey Validation
1_
2_
3_
4_


Algorithm6
1_
2_
3_
4_
5_
=end

def pk_vera() end


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




#key exchange
def ecdh()
end


#decryption
#Integer dcr()end


#Elliptic Curve Nyberg-Ruppel Signature
def ecnr()

end



#=========================================

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


=begin
ECDSA signature eneration and verification
To sign a meddahe m, an entry A with domain parameters D=(q,FR,a,b,G,n,h)
and associated key pair (d,Q) does the following

1. Select a random or pseudorandom integer k, 1<=k<=n-1
2. Compute kG=(x1,y1) and r=x1 mod n. If r=0 then goto step1.
3. Compute k^{-1end mod n.
4. Compute e=sha1(m)
5. Compute s=k^{-1}(e+dr)mod n. If s=0 then goto step1.
6. A's signature for the message m is (r,s).
=end
def ecdsa(k, e, d)

print "in_ecdsa\n"

  mktable(@CRV_G_x,@CRV_G_y)
  if(k<0)
    print "k is obsense in ecdsa\n"
    exit()
  end

  ellip(k)
#  print "Ex= " , e_x , "\n";
  r=@T_x%@CRV_n
  print r , "\n"
  k=inv(k,@CRV_n)
  #  e=sha(argc,argv);
  s=(k*(e+d*r))%@CRV_n
#  print "k=", k, "\n"
#  print "d=", d, "\n"
#  print "e=", e, "\n"
  @sign_s=s
  @sign_r=r

#  return sign;

end

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
def vr_ecdsa(s, r, e)

print "in_vr_ecdsa\n"

  #  e=sha(argc,argv);
  w=inv(s,@CRV_n)
  u1=e*w%@CRV_n
  #  cout << "u1=" << u1 << endl;
  u2=r*w%@CRV_n

  print "Gen_key\n"
  mktable(@CRV_G_x,@CRV_G_y)
  ellip(u1) #G=
  gx=@T_x
  gy=@T_y

  mktable(@Gen_key_x,@Gen_key_y)
  ellip(u2) #Q=
  qx=@T_x
  qy=@T_y

  if(gx==qx && gy==qy)
    print "equal point\n"
    exit()
  end


  if(gx!=qx)
    eadd(gx,qx,gy,qy,@CRV_p) #X=
    xx=@T_x
    yy=@T_y
  end
  v=xx%@CRV_n
    print "r is " , r , "\n"
    print "v is " , v , "\n"

  if(v==r)
    print "That's true!\n"
  end
  if(v!=r)
    print "baka\n"
  end

end


def main(u)
 n=N
 j=0
 ki=[N]
 plain=[21]
 k=[21][51]


 init_curve(n)
#print eccp192 ,"\n"


# print secp128r1_p ,"\n"
 for i in 0..20
   plain[i]=0
 end

 ii=0
 @Pub_key_x=0 
 @Pub_key_y=0

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

mktable(@CRV_G_x,@CRV_G_y)

# xx=(xx**3+@CRV_a*xx+@CRV_b)
# print  xx%pp ,"\n"
# print  yy**2%pp ,"\n"
# print  PC(xx,pp)%pp ,"\n"


 #encryption
  for ii in 0..20
    ai = plain[ii]  #72110381051
        ellip(ai)
#	print  @Pub_key_x, ",", @Pub_key_y ,"\n"
  end
  @Gen_key_x=@Pub_key_x
  @Gen_key_y=@Pub_key_y

  e= ("0x"+STATUS).hex
print "sha=" ,e , "\n"
#=begin
  ecdsa(plain[1],e,ai)
  print  ARGF.filename , "'s ECDSA Signature is " ,"\n"
  print  "s=", @sign_s ,"\n"
  print  "r=", @sign_r ,"\n"
  vr_ecdsa(@sign_s,@sign_r,e)
#=end

end

main(ARGV[0].to_i)


################### end of program #######################
