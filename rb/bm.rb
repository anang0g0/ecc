#Polynomial factoring over GF(2)
#Copyright(C) 2006/12/02 by tcshacina
#Cに比べると恐ろしく遅いです。こんなもん実用になるかー！みたいな。これを作るのに5ヶ月もかかったのだ！ふぅ〜終わったっ！

#/* [63,16,23]-BCH */
 gt63=[1,3,6,12,25,51,102,205,411,822,1644,3289,6578,13156,26313,52627,39718,13900,27800,55600,45665,25794,51589,37643,9751,19503,39006,12477,24955,49911,34286,3037,6074,12148,24297,48595,31655,63310,61085,56635,47734,29932,59865,54194,42853,20170,40341,15147,30294,60588,55640,45744,25952,51904,38272,11008,22016,44032,22528,45056,24576,49152,32768]

@K=1024
@N=1024
@L=1
@CC=0 

@H=[256]
@S=[256]
@E=Array.new(@K){Array.new(@N) {0}}
p @E[512][512]
$cc=Array.new(256){Array.new(128) {0}}
#p $C[256][128]


def seki(a , b)

  c=0;
  while(a!=0)
    if ((a & 1)==1)
	 c^=b;
    end
    b<<=1; a>>=1;
  end

  return c;
end


#/* 合同式 */
def inv(a, n, gcd)

  d = n;
  x = 0;
  s = 1;
  while (a != 0) 
    q = d / a;
    r = d % a;  d = a;  a = r;
    t = x - q * s;  x = s;  s = t;
  end
  gcd = d;  #/* $\gcd(a, n)$ */

  return ((x + n) % (n / d));
end


def i2b(n)
  x=n
  i=0;
  while(x>0)
    x=(x>>1); i=i+1;
  end
c=i


  while(c>0) 
    i=c-1
    if(n[i]==1)
      print "1";
    end
  
    if(n[i]==0)
      print "0";
    end
  c=c-1;
  end
#  print "\n";

end


def itob(n)

k=0;
  while(n>0)
    if(n%2==1)
      k=k+1;
    end
    n=(n>>1);
  end

  #  printf("k=%d\n",k);

  return k;
end


#/* 何ビット整数か返す */
def cb( x)

  i=0;
  while(x>0)
    x=(x>>1); i=i+1;
  end
  return i;
  
end


#/* F_2 quot */
def pd(p, d)

t=[64];

 
  if(cb(p)<cb(d))
    return p;
  end

#  print "a"

  q=p; y=d;
  r=0;
  i=cb(q)-cb(y);

  y=(y<<i);

  if(y>p)
    y=(y>>1);
  end
  while(cb(q) >= cb(d))
    y=d;
    i=cb(q)-cb(y);
    #print "i=",i,"\n"
    if(i>0)
      y=(y<<i);
    end

    if(i<0)
      break;
    end
    if(cb(q)==cb(y))
      r=r + (1<<i);
      itob(q);
      itob(y);
      q=(q^y);
      itob(q);
      itob(y);
    end
  end

  return q;

end


#/* F_2 mod */
def pq( p, d)

t=[64];

 
  if(cb(p)<cb(d))
    return p;
  end


  q=p;
  y=d;
  r=0;
  i=cb(q)-cb(y);
  y=(y<<i);

  if(y>p)
    y=(y>>1);
  end

  while(cb(q) >= cb(d))
    y=d;
    i=cb(q)-cb(y);

    if(i>0)
      y=(y<<i);
    end

    if(i<0)
      break;
    end
    if(cb(q)==cb(y))
      r=r + (1<<i);
      itob(q);
      itob(y);
      q=(q^y);
      itob(q);
      itob(y);
    end
  end


  return r;

end


def bibun(ff)
kk=1;
i=1

  ii=ff;
  gg=1;
  while(ii>0)
    if(testbit(ff,i)==1 && i%2==1)
      if(i>1)
        for j in 0..i-2
	  kk=kk*2;
	end
      gg=gg^kk;
      end
    end
  ii=(ii>>1);
  i=i+1;
  kk=1;

  end

  if(ff[0]==1 && ff[1]==0)
    gg=gg^1;
  end
  if(ff[0]==0 && ff[1]==0)
    gg=gg^1;
  end
  
  return gg;

end

#  deg(f0)>deg(f1)
def fgcd( f0, f1)

#print "d"
#print "f0=",f0,"\n"
#print "f1=",f1,"\n"
  if(f0<f1)
    t=f0;
    f0=f1;
    f1=t;
  end
  if(f0>=f1)
    r=f1;
    q=f0;
    while(r>0)
      f0=r;
      #print "^"
      r=pd(q,r);
      #print "r=",r,"\n"
      q=f0;
    end
  end

  #print "q=",q,"\n"

  return q;
end


def deg(f)
n=0;
  
  while(f>0)
    n=n+1;
    f=(f>>1);
  end
  
  return n;
end


class Array
 def bubble_sort
   loop{
	sorted=true
	for i in 1..self.length
	    if self[i] &gt; self[i]
	       self[i-1],self[i] = self[i], self[i-1]
	       sorted = false
	    end
	end
	break if sorted
   }
   self
  end
end
#p [5,8,9,1,4,3,2].bubble_sort



def gauss()
count=[@N]
k=Array.new(256){Array.new(128) {0}}
flag=0
t=[@K];


  for i in 0..255
    @H[i]=0;
  end



  for l in 0..@N-1
    flag=0
    for i in 0..@N-1
      count[i]=0;
      for j in 0..@N-1
	if($cc[i][j]==1)
	  k[i][count[i]]=j;
	  count[i]=count[i]+1;
	end
      end
	#print "count=",count[i],"\n "
    end

n=0;
    if(count[l]>1)
      j=0;
      while(j<count[l])
	n=0;
	while(n<count[l])
	#print "m=",k[l][n],"\n"
	  for i in 1..l-1
	    flag=0;
	    for o in 0..l-1
	      if($cc[o][k[l][n]]!=0)
		flag=1;
	      end
	    end
	  end
	i=l;
	#print "m=",k[i][n],"i=",i,"l=",l,"\n"
	#print "flag=",flag,"\n"
	  if(flag==0)
	    if(n<count[l])
	      m=k[i][n];
	      break;
	    end
	  end
	  if(flag==1)
	    n=n+1;
	    #print "n=",n,"\n"
	  end
	  if(n>count[l])
	    break;
	  end
	end

	#print "j=",j,"m2=",m,",k=",k[l][j],"\n"
	if(m!=k[l][j] && flag==0)
	  for i in 0..@N-1
	    $cc[i][k[l][j]]=$cc[i][m]^$cc[i][k[l][j]];
	  end
	end
      #end
	j=j+1;

=begin
for i in 0..62
for jj in 0..62
print $cc[i][jj]," "
end
print "\n"
end
print "\n"
=end
	end
      end
    end

#print "n=",n,"\n"

#exit();

  i=1;
  for i in 0..@N-1
    m=0;
    if($cc[i][i]!=1)
      for j in 0..@N-1
	if($cc[i][j]==1)
	  for l in 0..@N-1
	    if($cc[i][l]==1) 
	      m=m+1;
	    end
	  end
	  if(m==1)
	    for o in 0..@N-1
	      t[o]=$cc[o][i];
	    end
	    for o in 0..@N-1
	      $cc[o][i]=$cc[o][j];
	    end
	    for o in 0..@N-1
	      $cc[o][j]=t[o];
	    end
	  end
	end
      end
    end
  end
=begin
print "\nsorted\n"
for i in 0..62
for j in 0..62
print $cc[i][j]
end
print "\n"
=end


  o=0;
  for i in 0..@N-1
    if($cc[i][i]!=1)
	$cc[i][i]=1;
	j=@N-1
	while (j>-1)
	  @H[o]=(@H[o]<<1)^$cc[i][j];
	  j=j-1;
	end
	o=o+1; 
    end
  end
  if(o==1)
	#print "irreducible\n"
      	return -1;
	
  end

=begin
for i in 0..o-1
print "H="
for j in 0..@N-1
 print testbit(@H[i],j)
end
print "\n"
=end


  return o;

end


def testbit(a,i)

return a[i];

end


def bm1(f)

count=0
po=[256]
flag=0
e=[512]
ii=[256]
oo=[256]
cc=Array.new(256){Array.new(128) {0}}
ee=Array.new(512){Array.new(512) {0}}

  for i in 0..255
    ii[i]=0;
    oo[i]=0;
  end

  #print "b";
  
  q=2;
  ff=bibun(f);

  if(ff==0)
    print "bm1_f'=0\n";
    return -2;
  end

  if(f>1)
    for i in 0..255
      po[i]=0;
    end
    if(fgcd(f,ff)>1)
	print "!!\n"
      return 0;
    end
    
    if(fgcd(f,ff)==1)
      i=deg(f)-1;
      @N=i;
      @K=i;
      ii[0]=1;
      for k in 1..i-1
	ii[k]=seki(ii[k-1],0b100);
	#i2b(ii[k]);
	ii[k]=pd(ii[k],f);
      end
    end

    oo[0]=0;
    iii=1;
    for k in 1..i-1
      iii=seki(iii,2);
      oo[k]=iii;
      oo[k]=oo[k]^ii[k];
    end

    for i in 0..deg(f)-2
      for j in 0..deg(f)-2
	$cc[i][j]=testbit(oo[i],j);
      end
    end

  end


  return gauss();
  
end



def euc(f)
g=[256]
e=[1024]
w=[1024]
mke=[1024]
cc=0

print "c"
    o=bm1(f);
    print "!o=",o,"\n";

# irreducible
  if(o== -1)
    print i2b(f) ,"irr\n";
    return 0;
  end
  if(o==0)
	return 1;
  end
  if(o== -2)
    return 1;
  end

  ff=@H[1]+1;
  g[0]=fgcd(f,@H[1]);
  g[1]=fgcd(f,ff);

  if(o==2)
    g[1]=pq(f,g[0]);
    print "g1euc=" , g[1] ,"\n"
    e[0]=g[0];
    e[1]=g[1];
    if(seki(g[0],g[1])==f)
      if(g[0]>1)
	while(pd(f,g[0])==0)

	  f=pq(f,g[0]);
	  print "g00="
	  i2b(g[0]) 
	  print "*\n";
	  if(g[0]>1)
	    @E[1][cc]=g[0];
	    cc=cc+1;
	  end
	end
      end
      if(g[1]>1)
	while(pd(f,g[1])==0)
	  f=pq(f,g[1]);
	  print "g11="
 	  i2b(g[1])
	  print "*\n";
	  if(g[1]>1)
	    @E[1][cc]=g[1];
	    cc=cc+1;
	  end
	end
      end
      print "That's True!\n"
      print f , "\n"
    end
  end

l=0;
  j=2;
  count=0;
  if(o>2)
    for i in 2..o-1
      ff=@H[i]+1;
      g[j]=fgcd(f,@H[i]);
      if(g[j]>1)
	mke[j]=bm1(g[j]);
	if(mke[j]== -1)
	  e[j]=g[j];
	  #print "e=",e[j],"\n"
	end
	j=j+1;
      end


      g[j]=fgcd(f,ff);
      if(g[j]>1)
	mke[j]=bm1(g[j]);
	if(mke[j]== -1)
	  e[j]=g[j];
#	  print "e=",e[j],"\n"
	end
	  j=j+1;
      end
    end
    
    l=0;
    for i in 0..o-1
	print "i=",i,"\n"
      for k in 0..j-1
	ff=@H[i]+1;
	w[l]=fgcd(@H[i],g[k]);
	if(w[l]>1)
	  mke[l+j]=bm1(w[l]);
	  if(mke[l+j]== -1)
	    e[j+l]=w[l]
	#  print "e=",e[j+l],"\n"
	  end
	    l=l+1;	  
	end


	w[l]=fgcd(ff,g[i]);
	if(w[l]>1)
	  mke[l+j]=bm1(w[l]);
	  if(mke[l+j]== -1)
	    e[j+l]=w[l];
	 # print "e=",e[j+l],"\n"
	  end

	    l=l+1;
	end
      end
    end
      k=0;
   end


   for i in 2..j+l-1
#print "e=",e[i],",i=",i,"\n"
     for k in i+1..l+j-1
      if(e[i]==e[k])
	e[k]=1;
      end
    end
  end

  
  for i in 2..j+l-1
#print "e=",e[i]
#print "i=", i,"\n"
if(e[i]!=nil)
    if(e[i]>1)
      print "e="
      i2b(e[i]);
      print "\n"
      f=pq(f,e[i]);
end
    end
  end

  
  a=bm1(f);
  if(a== -1 && f>1)
    print "e="
    i2b(f) 
    print "\n"
    f=pq(f,f);
  end


    return f;

end


=begin
def sqf( f){
  Integer s[512],t,r,v,bib,G,I,t2,t3,r2,M=0,V[512];
  int i,j,k,e[512],cc;


  bib=bibun(f);
  
  cout << "f=" << Itoa(f,2) << endl;
  cout << "f'=" << Itoa(bib,2) << endl;

  r=fgcd(f,bibun(f));
  cout << "fgcd=" << Itoa(r,2) << endl;
  t=pq(f,r);
  cout << "fqrt=" << Itoa(t,2) << endl;
  
  if(bib==0){
    j=1+L;
    k=cb(f);
    for(i=0;i<k+1;i++){
      if(testbit(f,i)==1){
	cout << "k=" << k << endl;
	M=M^(1<<(i/2));
      }
    }
    f=M;
    bib=bibun(f);
    cout << "f=" << Itoa(f,2) << endl;
    cout << "f'=" << Itoa(bib,2) << endl;
    r=fgcd(f,bibun(f));
    cout << "fgcd=" << Itoa(r,2) << endl;
    t=pq(f,r);
    cout << "fqrt=" << Itoa(t,2) << endl;
  }
  #  exit(1);
  /*
  if(bib!=0)
    j=1;
  if(r==1)
    S[1]=t;
  cout << "r=" << Itoa(r,2) << endl;
  t2=fgcd(r,t);
  S[1]=pq(r,t2);
  r2=pq(r,t2);
  t3=fgcd(r2,t2);
  if(t3==1){
    S[2]=t2;
    S[3]=r2;
  for(i=0;i<4;i++)
    cout << Itoa(S[i],2) << endl;
  }
  */
  j=1;
  while(r!=1){
    cout << "rinroop=" << r << endl;
    v=fgcd(r,t);
    cout << "v=" << Itoa(v,2) << endl;
    if(v==1){
      S[j]=t;
      S[j-1]=r;
      if(j==1){
	S[2]=r;
	cout << "r=" << Itoa(r,2) << endl;
	S[0]=0;
      }
      cout << "j=" << j << endl;
      for(i=1;i<j+1;i++){
	cout << "S" << i << "=" << Itoa(S[i],2) << endl;
	e[i]=bm1(S[i]);
	cout << "e[" << i << "]=" << e[i] << endl;
	if(e[i]== -2 && S[i]>1)
	  cout << Itoa(S[i],2) << endl;
      }
      #exit(1);


      for(i=1;i<j+1;i++){
	if(e[i]==-1 && S[i]>1){
	  while(pd(f,S[i])==0){
	    f=pq(f,S[i]);
	    if(S[i]>1)
	    E[i][cc++]=S[i];
	    cout << Itoa(S[i],2) << "*";
	  }
	}
      }
      /*
	if(e[i]== -2)
	  sqf(S[i]);
      }
      */
      if(e[1]>1){
	if(bibun(S[1])==0)
	  sqr(S[1]);
	euc(S[1]);
      }
      
      printf("\n");
      if(f>1){
	cout << "f=" << Itoa(f,2) << endl;
	return f;
      }
      return 0;
    }
    if(j==10)
      exit(1);
    S[j]=pq(t,v);
    cout << "s=" << Itoa(S[j],2) << endl;
    r=pq(r,v);
    cout << "r=" << Itoa(r,2) << endl;
    t=v;
    cout << "t=" << Itoa(t,2) << endl;
    j++;
    cout << "j=" << j << endl;
    # S[j]=t;
  }
  #10000000011100=10*10*11*11*11*1101*100101

  cout << "L2=" << L << endl;
  
  if(L>1 && j==0){
    S[L]=S[1];
    S[1]=0;
    for(i=0;i<L+1;i++){
      cout << "Sa" << i << "=" << Itoa(S[i],2) << endl;
      if(e[i]== -1){
	while(pd(f,S[i])==0){
	  f=pq(f,S[i]);
	  if(S[i]>1)
	  E[i][cc++]=S[i];
	  cout << Itoa(S[i],2) << "*";
	}
      }
    }
      return 0;
  }
  if(L==1){
    S[j]=t;
    bm1(S[1]);
    euc(S[1]);
    for(i=0;i<j+1;i++){
    cout << "Sb" << i << "=" << Itoa(S[i],2) << endl;
      if(e[i]== -1){
	while(pd(f,S[i])==0){
	  f=pq(f,S[i]);
	  if(S[i]>1)
	  E[i][cc++]=S[i];
	  cout << Itoa(S[i],2) << "*";
	}
      }
    }
    return 0;
  }
  if(L>1 && j>0 && r==1 && t!=1){
    cout << "t=" << Itoa(t,2) << endl;
    L=L*j;
    S[L]=t;
    S[1]=0;
    for(i=0;i<j*L+1;i++){
    cout << "Sc" << i << "=" << Itoa(S[i],2) << endl;
      if(e[i]== -1){
	while(pd(f,S[i])==0){
	  f=pq(f,S[i]);
	  if(S[i]>1)
	  E[i][cc++]=S[i];
	  cout << Itoa(S[i],2) << "*";
	}
      }
    }
    return 0;
  }
  if(L>1 && j>0 && r==1 && t==1){
    L=L*j;
    S[L*j]=S[1];
    S[1]=0;
    for(i=0;i<j*L+1;i++){
    cout << "Sd" << i << "=" << Itoa(S[i],2) << endl;
      if(e[i]== -1){
	while(pd(f,S[i])==0){
	  f=pq(f,S[i]);
	  if(S[i]>1)
	  E[i][cc++]=S[i];
	  cout << Itoa(S[i],2) << "*";
	}
      }
    }
    return 0;
  }

}
=end


def main()
t=[64];
count=0;
f=[10];

  jj=seki(seki(seki(0b101111,0b1101101),seki(0b111,0b11001)),seki(seki(0b11111,0b1),seki(0b110110001,0b1011)));
  p=seki(seki(seki(seki(0103,0127),seki(0147,0111)),seki(seki(015,0155),seki(0133,0165))),07);
  ff=seki(seki(seki(0b11,0b10),seki(0b10011,0b100101)),seki(seki(0b101001,0b110111),seki(0b111011,0b111101)));
  ff=seki(0b1000000000001,1);
  print p ,"\n"
  #print i2b(hh) ,"\n"
  # hh=seki(seki(seki(atoI("111101",2),atoI("111",2)),seki(atoI("111",2),atoI("111",2))),seki(atoI("1011",2),atoI("1011",2))); #1
  #ff=0b101011001;
  #ff=atoI("10000001",2);
  #hh=seki(seki(seki(atoI("110011",2),atoI("1010101",2)),seki(atoI("10",2),atoI("10",2))),atoI("1101",2)); #2
  #hh=seki(seki(seki(atoI("1101",2),atoI("1101",2)),seki(atoI("111",2),atoI("111",2))),seki(seki(atoI("111",2),seki(atoI("11111",2),atoI("1011",2))),seki(atoI("10001",2),atoI("1000000",2)))); #3
  #hh=atoI("10110",2); #4
  #  cout << "bib=" << Itoa(bibun(ff),2) << endl;
  #  cout << Itoa(fgcd(ff,hh),2) << endl;
  #cout << Itoa(hh,2) << endl;

  #hh=sqf(hh);
  #cout << "hhf=" << Itoa(hh,2) << endl;
  #ff=atoI("1000000000000000000000100000000001100000000010000000000010000011",2);
  #ff=atoI("1000000000000000000000100000000001100000000010000000000010001100",2);
print ff,"\n"
   i2b(ff);   print "\n";
   print "bib=";   i2b(bibun(ff));
   print "\n"

  jj=ff;
  while(1)
    ff=jj;
    print "ff=" 
    i2b(jj);
    print "\n"
    while(ff!=1)
      ff=euc(ff);
    end
    jj=jj+1;
  end
  
  
end


main();