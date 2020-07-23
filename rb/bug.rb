# Math.sqrt(n)!=Å„n
#! /usr/local/bin/ruby

MAX_SIZE=100000000
@Array=[100000000]


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

  return ((x + n) % (n / d))
end


def isqrt(x)

  if(x==0)
    print "sqrt0\n"
    exit()
  end
  s=1
  t=x
  while(s<t)
    s<<=1
    t>>=1
  end

    t=s
    s=(x/s+s)>>1
  while(s<t)
    t=s
    s=(x/s+s)>>1
  end

  return t  
end


def qs()

  n =1834729514979351371768185745442641443774091
  print "n=        ",n,"\n"
  b=isqrt(n)
  print "isqrt^2=  ",b*b,"\n"
  print "(b+1)^2=  ",(b+1)**2,"\n"
  a=Math.sqrt(n).floor
  print "sqrt(n)^2=",a*a,"\n"
  m=1354521876892119956788
  print "m^2=      ",m*m,"\n"
  print "sqrt ",Math.sqrt(n).floor,"\n"
  if(m==Math.sqrt(n).floor)
    print "bingo!\n"
  end

end

qs()
