#ŽZpŒë‚è’ù³•„†‚ðŽg‚Á‚½”é–§Œ®ˆÃ†
#Copyright(C) 2006 by tcshacina
#20061226

#jj=aa^bb mod oo
def exp(aa, bb, oo)

  ii=oo
  j=0
  jj=0
  kk=[2**12] #prime is 4096 bit table
  c=[2**13]  #mod is 8192 bit table
  count=0

  for i in 0..1023
    kk[i]=0
  end
  while(ii>0)
	ii = (ii>>1)
	j=j+1
  end

  kk[0]=aa

#ex.1000=2**3+2**5+2**6+2**7+2**8+2**9 makes a array c=[3,5,6,7,8,9]
    for i in 0..j
      if (((bb^(1<<i)) >> i)%2 == 0) # testbit(bb,i)
	c[count]=i
	count=count+1
      end
    end
#    print count,"\n"

    for i in 1..(c[count-1])
#	if(i==1)
#	 print i,"=",kk[i-1],"\n"
#	end
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


def fr(n)
f=0
 for a in 2..100
  if(exp(a,(n-1),n)!=1)
   f=1
#   print n," ˆá‚¤I‚±‚ñ‚È‚Ì‘f”‚¶‚á‚È‚¢!!",a,"\n"
   print "."
   break
  end
 end

 if(f==0)
   p=n-1
   while(p%2==0)
    p=p/2
   end

   for i in 1..5
    if(exp(2,p*i,n)!=1 || exp(3,p*i,n)!=1 || exp(5,p*i,n)!=1 || exp(7,p*i,n)!=1 || exp(11,p*i,n)!=1 || exp(13,p*i,n)!=1 || exp(17,p*i,n)!=1 || exp(19,p*i,n)!=1 || exp(23,p*i,n)!=1 || exp(29,p*i,n)!=1 || exp(31,p*i,n)!=1 || exp(37,p*i,n)!=1 || exp(41,p*i,n)!=1 || exp(43,p*i,n)!=1 || exp(47,p*i,n)!=1 || exp(53,p*i,n)!=1)
     f=1
    end
   end
   #  print n," is prime\n"
   print "+"
    return 1;
   end
end


def an()
a=(2**(8*7)-1)/(2**8-1)
print a,"\n"

end

def an2()
a=257
b=(2**(a-1)-1)/a
print b,"\n"


end


def bit(m)

mm=m
count=0
while(mm>0)
 mm=(mm>>1)
 count=count+1
end
return count
end


def main()
a=282578800148737
b=0
s=[1000003];

key=0b10000000001000000000100000000010000000001000000000100000000010000000001000000000100000000010000000001000000000100000000010000001
k2=0b100000000010000000001000000000100000000010000000001000000000100000000010000000001000000000100000000010000000001000000000100011111
for i in 1..1000
if(fr(key)==1)
 print "\n",key,"\n"
 break
end
key=key+1;
end
f=File.open("pari-2.3.0.tar.gz",'rb')
ff=File.open("pari.cyp",'wb')
#fg=File.open("an.txt",'wb');


  srand(key)
 while(f.eof?!=TRUE)
  b= f.read(15)
  bb=0
  j=14
  b.size.times do |i|
   if(b.size==15)
    i=j-i
   end
   if(b.size<15)
    i=b.size-i-1
   end
#   print "i=",i,"\n"
   bb=(bb<<8)|b[i]
  end
  
  b= key*bb;

  while(1)
   if(a=rand(key))
    #print a,"\n"
    break
   end
  end
  while(1)
   if(bit(d=rand(k2*k2))==256)
    break
   end
  end

  c=(b+a)^d;
  array=[8]
  cc=c
#  print "c=",c,"\n"
  for i in 0..7
   array[i]=(cc&0b11111111111111111111111111111111);
   cc=(cc>>32)
  end
  if(cc!=0)
   exit()
  end
  ff.write(array.pack("L8"))

# decode-begin
#  e=((c^d)-((c^d)%key))/key
#  cc=e
#  for i in 0..14
#   array[i]=(cc&0b11111111);
#   cc=(cc>>8)
#  end
#  fg.write(array.pack("C15"))
# decode-end

#  if(e!=bb)
#   print "e=",e,"\n"
#  end
 end
f.close
ff.close
#fg.close
end

main()
