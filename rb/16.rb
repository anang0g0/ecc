gf=[0,1,2,4,8,9,11,15,7,14,5,10,13,3,6,12]
fg=[0,1,2,13,3,10,14,8,4,5,11,6,15,12,9,7]
inv=[0,1,15,4,14,7,3,9,13,12,6,11,2,5,8,10]
K=6
N=16
@G=Array.new(K){Array.new(N) {0}}

#gf=[0,1,2,4,8,16,32,64,128,29,58,116,232,205,135,19,38,76,152,45,90,180,117,234,201,143,3,6,12,24,48,96,192,157,39,78,156,37,74,148,53,106,212,181,119,238,193,159,35,70,140,5,10,20,40,80,160,93,186,105,210,185,111,222,161,95,190,97,194,153,47,94,188,101,202,137,15,30,60,120,240,253,231,211,187,107,214,177,127,254,225,223,163,91,182,113,226,217,175,67,134,17,34,68,136,13,26,52,104,208,189,103,206,129,31,62,124,248,237,199,147,59,118,236,197,151,51,102,204,133,23,46,92,184,109,218,169,79,158,33,66,132,21,42,84,168,77,154,41,82,164,85,170,73,146,57,114,228,213,183,115,230,209,191,99,198,145,63,126,252,229,215,179,123,246,241,255,227,219,171,75,150,49,98,196,149,55,110,220,165,87,174,65,130,25,50,100,200,141,7,14,28,56,112,224,221,167,83,166,81,162,89,178,121,242,249,239,195,155,43,86,172,69,138,9,18,36,72,144,61,122,244,245,247,243,251,235,203,139,11,22,44,88,176,125,250,233,207,131,27,54,108,216,173,71,142]
#fg=[0,1,2,26,3,51,27,199,4,224,52,239,28,105,200,76,5,101,225,15,53,142,240,130,29,194,106,249,201,9,77,114,6,139,102,48,226,37,16,34,54,148,143,219,241,19,131,70,30,182,195,126,107,40,250,186,202,155,10,121,78,229,115,167,7,192,140,99,103,222,49,254,227,153,38,180,17,146,35,137,55,209,149,207,144,151,220,190,242,211,20,93,132,57,71,65,31,67,183,164,196,73,127,111,108,59,41,85,251,134,187,62,203,95,156,160,11,22,122,44,79,213,230,173,116,244,168,88,8,113,193,248,141,129,100,14,104,75,223,238,50,198,255,25,228,166,154,120,39,185,181,125,18,69,147,218,36,33,138,47,56,64,210,92,150,189,208,206,145,136,152,179,221,253,191,98,243,87,212,172,21,43,94,159,133,61,58,84,72,110,66,163,32,46,68,217,184,124,165,119,197,24,74,237,128,13,112,247,109,162,60,83,42,158,86,171,252,97,135,178,188,205,63,91,204,90,96,177,157,170,161,82,12,246,23,236,123,118,45,216,80,175,214,234,231,232,174,233,117,215,245,235,169,81,89,176]
g=[130, 160, 130, 193, 130, 211, 130, 241, 130, 160, 130, 169, 130, 241, 130, 196];
f=[131, 94, 131, 129, 131, 84, 131, 140, 131, 139, 131, 95, 131, 67, 131, 96];

def fg()
for i in 0..N-1
  for j in 0..N-1
    if(@gf[j]==i)
      print j,","
    end
  end
end

end

def mlt(x, y)

    if(x==0||y==0)
        return 0
    end
    return ((x+y-2)%(N-1))+1;
end


def mltn(n, x)

#if(x==0)
#  return 1;
#end
  i=x
  for j in 1..n
    i=mlt(i,x)
  end
  return i
end


def inv(x)

  return mltn(N-2,x)

end

def div(x, y)
    if(y==0)
	#/* printf("y‚ª0\n"); */
	#/* exit(1); */
    end
    if(x==0)
        return 0
    end
    return ((x-y+(N-1))%(N-1))+1
end



#fg();
#mlt(2,3)

o=0;
for x in 0..N-1
#print fg[3]-1
#  a=gf[mlt(fg[x],fg[3])];
#  a=gf[mlt(mlt(fg[x],fg[x]),fg[x])]^gf[fg[x]]^1; 
#  

a=gf[mlt(mlt(mlt(fg[x],fg[x]),mlt(fg[x],fg[x])),mlt(fg[x],fg[x]))]^gf[mlt(fg[x],fg[x])]^1; 

=begin
a32=gf[mlt(mlt(mlt(mlt(mlt(fg[x],fg[x]),mlt(fg[x],fg[x])),mlt(mlt(fg[x],fg[x]),mlt(fg[x],fg[x]))),mlt(mlt(mlt(fg[x],fg[x]),mlt(fg[x],fg[x])),mlt(mlt(fg[x],fg[x]),mlt(fg[x],fg[x])))),mlt(mlt(mlt(mlt(fg[x],fg[x]),mlt(fg[x],fg[x])),mlt(mlt(fg[x],fg[x]),mlt(fg[x],fg[x]))),mlt(mlt(mlt(fg[x],fg[x]),mlt(fg[x],fg[x])),mlt(mlt(fg[x],fg[x]),mlt(fg[x],fg[x])))))];
a16=gf[mlt(mlt(mlt(mlt(fg[x],fg[x]),mlt(fg[x],fg[x])),mlt(mlt(fg[x],fg[x]),mlt(fg[x],fg[x]))),mlt(mlt(mlt(fg[x],fg[x]),mlt(fg[x],fg[x])),mlt(mlt(fg[x],fg[x]),mlt(fg[x],fg[x]))))];
a15=gf[mlt(mlt(mlt(mlt(fg[x],fg[x]),mlt(fg[x],fg[x])),mlt(mlt(fg[x],fg[x]),mlt(fg[x],fg[x]))),mlt(mlt(mlt(fg[x],fg[x]),mlt(fg[x],fg[x])),mlt(mlt(fg[x],fg[x]),mlt(fg[x],g[15]))))];
a14=gf[mlt(mlt(mlt(mlt(fg[x],fg[x]),mlt(fg[x],fg[x])),mlt(mlt(fg[x],fg[x]),mlt(fg[x],fg[x]))),mlt(mlt(mlt(fg[x],fg[x]),mlt(fg[x],fg[x])),mlt(mlt(fg[x],fg[x]),g[14])))];
a13=gf[mlt(mlt(mlt(mlt(fg[x],fg[x]),mlt(fg[x],fg[x])),mlt(mlt(fg[x],fg[x]),mlt(fg[x],fg[x]))),mlt(mlt(mlt(fg[x],fg[x]),mlt(fg[x],fg[x])),mlt(fg[x],g[13])))];
a12=gf[mlt(mlt(mlt(mlt(fg[x],fg[x]),mlt(fg[x],fg[x])),mlt(mlt(fg[x],fg[x]),mlt(fg[x],fg[x]))),mlt(mlt(mlt(fg[x],fg[x]),mlt(fg[x],fg[x])),g[12]))];
a11=gf[mlt(mlt(mlt(mlt(fg[x],fg[x]),mlt(fg[x],fg[x])),mlt(mlt(fg[x],fg[x]),mlt(fg[x],fg[x]))),mlt(mlt(fg[x],fg[x]),mlt(fg[x],g[11])))];
a10=gf[mlt(mlt(mlt(mlt(fg[x],fg[x]),mlt(fg[x],fg[x])),mlt(mlt(fg[x],fg[x]),mlt(fg[x],fg[x]))),mlt(mlt(fg[x],fg[x]),g[10]))];
a9=gf[mlt(mlt(mlt(mlt(fg[x],fg[x]),mlt(fg[x],fg[x])),mlt(mlt(fg[x],fg[x]),mlt(fg[x],fg[x]))),mlt(fg[x],g[9]))];
a8=gf[mlt(mlt(mlt(fg[x],fg[x]),mlt(fg[x],fg[x])),mlt(mlt(fg[x],fg[x]),mlt(mlt(fg[x],fg[x]),g[8])))];
a7=gf[mlt(mlt(mlt(fg[x],fg[x]),mlt(fg[x],fg[x])),mlt(mlt(fg[x],fg[x]),mlt(fg[x],g[7])))];
a6=gf[mlt(mlt(mlt(fg[x],fg[x]),mlt(fg[x],fg[x])),mlt(mlt(fg[x],fg[x]),g[6]))];
a5=gf[mlt(mlt(mlt(fg[x],fg[x]),mlt(fg[x],fg[x])),mlt(fg[x],g[5]))]
a4=gf[mlt(mlt(mlt(fg[x],fg[x]),mlt(fg[x],fg[x])),g[4])];
a3=gf[mlt(mlt(fg[x],fg[x]),mlt(fg[x],g[3]))];
a2=gf[mlt(mlt(fg[x],fg[x]),g[2])];
a=gf[mlt(fg[x],g[1])]^g[0];
a=a^a2^a3^a4^a5^a6^a7^a8^a9^a10^a11^a12^a13^a14^a15^a16^a32;
=end

if(a==0)
  print "trace 0\n"
  exit()
end

#  print a," "
#  for j in 0..15
#    b=gf[mlt(mlt(fg[j],fg[j]),fg[j])]^gf[fg[j]]^1^a;
#    if(b==0)
#     print "j=",j,"\n"
#    end
#  end


#c=[1^a,0,1,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1]
#c=[g[0]^a,g[1],g[2],g[3],g[4],g[5],g[6],g[7],g[8],g[9],g[10],g[11],g[12],g[13],g[14],g[15],1];
#c=[g[0]^a,g[1],g[2],g[3],g[4],g[5],g[6],g[7],g[8],g[9],g[10],g[11],g[12],g[13],g[14],g[15],0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1];
c=[1^a,0,1,0,0,0,1]
d=[x,1]
#e=[0,0,0,0,0,0]
#r=[0,0,0,0,0,0,0]
e=[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
r=[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
e[K-1]=1;i=K;
while(i>0)
  r[i]=gf[mlt(fg[d[1]],fg[e[i-1]])];
  r[i-1]=gf[mlt(fg[d[0]],fg[e[i-1]])];
#print r[i]," r",i," ",r[i-1],"\n"
	j=K;
  while(j>-1)
    c[j]=r[j]^gf[fg[c[j]]];
#    print c[j]," "
    j=j-1;
  end
#  print "\n"
  r[i]=c[i];
  if(i-2>-1)
    e[i-2]=c[i-1];
#    print "e ",e[i-2],"\n"
  end
i=i-1;
end

print gf[mlt(fg[e[5]],div(1,fg[a]))],",",gf[mlt(fg[e[4]],div(1,fg[a]))],",",gf[mlt(fg[e[3]],div(1,fg[a]))],",",gf[mlt(fg[e[2]],div(1,fg[a]))],",",gf[mlt(fg[e[1]],div(1,fg[a]))],",",gf[mlt(fg[e[0]],div(1,fg[a]))],"\n"

#print gf[mlt(fg[e[15]],div(1,fg[a]))],",",gf[mlt(fg[e[14]],div(1,fg[a]))],",",gf[mlt(fg[e[13]],div(1,fg[a]))],",",gf[mlt(fg[e[12]],div(1,fg[a]))],",",gf[mlt(fg[e[11]],div(1,fg[a]))],",",gf[mlt(fg[e[10]],div(1,fg[a]))],",",gf[mlt(fg[e[9]],div(1,fg[a]))],",",gf[mlt(fg[e[8]],div(1,fg[a]))],",",gf[mlt(fg[e[7]],div(1,fg[a]))],",",gf[mlt(fg[e[6]],div(1,fg[a]))],",",gf[mlt(fg[e[5]],div(1,fg[a]))],",",gf[mlt(fg[e[4]],div(1,fg[a]))],",",gf[mlt(fg[e[3]],div(1,fg[a]))],",",gf[mlt(fg[e[2]],div(1,fg[a]))],",",gf[mlt(fg[e[1]],div(1,fg[a]))],",",gf[mlt(fg[e[0]],div(1,fg[a]))],"\n";

=begin
@G[0][x]=gf[mlt(fg[e[31]],div(1,fg[a]))]
@G[1][x]=gf[mlt(fg[e[30]],div(1,fg[a]))]
@G[2][x]=gf[mlt(fg[e[29]],div(1,fg[a]))]
@G[3][x]=gf[mlt(fg[e[28]],div(1,fg[a]))]
@G[4][x]=gf[mlt(fg[e[27]],div(1,fg[a]))]
@G[5][x]=gf[mlt(fg[e[26]],div(1,fg[a]))]
@G[6][x]=gf[mlt(fg[e[25]],div(1,fg[a]))]
@G[7][x]=gf[mlt(fg[e[24]],div(1,fg[a]))]
@G[8][x]=gf[mlt(fg[e[23]],div(1,fg[a]))]
@G[9][x]=gf[mlt(fg[e[22]],div(1,fg[a]))]
@G[10][x]=gf[mlt(fg[e[21]],div(1,fg[a]))]
@G[11][x]=gf[mlt(fg[e[20]],div(1,fg[a]))]
@G[12][x]=gf[mlt(fg[e[19]],div(1,fg[a]))]
@G[13][x]=gf[mlt(fg[e[18]],div(1,fg[a]))]
@G[14][x]=gf[mlt(fg[e[17]],div(1,fg[a]))]
@G[15][x]=gf[mlt(fg[e[16]],div(1,fg[a]))]
@G[16][x]=gf[mlt(fg[e[15]],div(1,fg[a]))]
@G[17][x]=gf[mlt(fg[e[14]],div(1,fg[a]))]
@G[18][x]=gf[mlt(fg[e[13]],div(1,fg[a]))]
@G[19][x]=gf[mlt(fg[e[12]],div(1,fg[a]))]
@G[20][x]=gf[mlt(fg[e[11]],div(1,fg[a]))]
@G[21][x]=gf[mlt(fg[e[10]],div(1,fg[a]))]
@G[22][x]=gf[mlt(fg[e[9]],div(1,fg[a]))]
@G[23][x]=gf[mlt(fg[e[8]],div(1,fg[a]))]
@G[24][x]=gf[mlt(fg[e[7]],div(1,fg[a]))]
@G[25][x]=gf[mlt(fg[e[6]],div(1,fg[a]))]
@G[26][x]=gf[mlt(fg[e[5]],div(1,fg[a]))]
@G[27][x]=gf[mlt(fg[e[4]],div(1,fg[a]))]
@G[28][x]=gf[mlt(fg[e[3]],div(1,fg[a]))]
@G[29][x]=gf[mlt(fg[e[2]],div(1,fg[a]))]
@G[30][x]=gf[mlt(fg[e[1]],div(1,fg[a]))]
@G[31][x]=gf[mlt(fg[e[0]],div(1,fg[a]))]
=end

#print x," "

end

for i in 0..K-1
  for j in 0..N-1
    print @G[i][j],","
  end
  print "\n"
end

print "\n"
print g[0],"\n"

for i in 1..15
  print gf[div(1,fg[i])],",";
end
print "\n"


#print mlt(fg[15],inv(fg[7]))," "
#print mlt(fg[11],inv(fg[7]))," "
#print mlt(fg[7],inv(fg[7]))," "


