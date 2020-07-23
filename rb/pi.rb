require 'bigdecimal' 

N=6000

def sqrt(x)
x=BigDecimal(x.to_s,4)
s=BigDecimal("1.0",4)
last=BigDecimal("6.0",4)
a=BigDecimal("2.0",4)
k=0
if(x>1.0)
  s=x
end
while(k<7)
  last=s.truncate(N)
  s=((x/s+s)/a).truncate(N)
#  print last,"\n"
k=k+1
end
print "x*x=",(last*last).truncate(N)," x=",x.truncate(N),"\n"

return last.truncate(N)
end


def f(x,a)
return x**5-a
end

def df(x)
return 5*(x**4)
end

def newton(x,a)
k=0
while(((x**5-a)>0.000000000000001 && x>0) && k<30)
 s=x
 x=s-f(s,a)/df(s)
# print "root5=",x,"\n"
# print x**5," a=",a,"\n"
 k=k+1
# print "k=",k,"\n"
end

return x
end


def pi2()
y=[20]
a=[20]

for n in 0..20
  y[n]=BigDecimal("0.0",4)
  a[n]=BigDecimal("0.0",4)
end
c=BigDecimal("1.0",4)
d=BigDecimal("6.0",4)
e=BigDecimal("4.0",4)
f=BigDecimal("2.0",4)

y[0]=sqrt(2.0)-c
a[0]=d-e*sqrt(2.0)
print y[0].truncate(N),"\n"
print a[0].truncate(N),"\n"

for n in 0..6
  y[n+1]=(c-sqrt(sqrt(c-y[n]**4)))/(c+sqrt(sqrt(c-y[n]**4)))
  y[n+1]=y[n+1].truncate(N)
  print "y1=",y[n+1],"\n"
  a[n+1]=((c+y[n+1])**4)*a[n]-(f**(2*n+3))*y[n+1]*(c+y[n+1]+y[n+1]**2)
  a[n+1]=a[n+1].truncate(N)
  print "a=",a[n+1],"\n"
end
  print "pi2=",(c/a[6]).truncate(N),"\n"

end


def pi()
s=[100]
a=[100]
z=[100]
s[0]=5.0*(sqrt(5.0)-2.0)
a[0]=0.5
z[0]=0.0
k=0
#while(k<4)
  print "s=",s[0],"\n"
  x=5.0/s[0]-1.0
  print "x=",x,"\n"
  y=((x-1.0)**2)+7.0
  print "y=",y,"\n"
#  exit()
  z=x*(y+sqrt(y*y-4.0*(x**3)))
  print "z=",z,"\n"
  z=newton(z+1.0,z)/2.0
  print "z2=",z,"\n"
  s[1]=25.0/(s[0]*((z+x/z+1.0)**2))
  print "s=",s[1],"\n"
  a[1]=s[0]*s[0]*a[0]-(1)*((s[0]*s[0]-5.0)/2.0+sqrt(s[0]*(s[0]*s[0]-2.0*s[0]+5.0)))
  print "aa=",a[1],"\n"
  if(a[1]>1)
    print "pi<3\n"
#    break;
  end
  print "pi=",1.0/a[1],"\n"
  print "k=",k,"\n"
  k=k+1

 print "s=",s[1],"\n"
  x=5.0/s[1]-1.0
  print "x=",x,"\n"
  y=((x-1.0)**2)+7.0
  print "y=",y,"\n"
#  exit()
  z=x*(y+sqrt(y*y-4.0*(x**3)))
  print "z=",z,"\n"
  z=newton(z+1.0,z)/2.0
  print "z2=",z,"\n"
  s[2]=25.0/(s[1]*((z+x/z+1.0)**2))
  print "s=",s[2],"\n"
  a[2]=s[1]*s[1]*a[1]-(5)*((s[1]*s[1]-5.0)/2.0+sqrt(s[1]*(s[1]*s[1]-2.0*s[1]+5.0)))
  print "aa=",a[2],"\n"
  if(a[2]>1)
    print "pi<3\n"
 #   break;
  end
  print "pi=",1.0/a[2],"\n"
  print "k=",k,"\n"
  k=k+1
#end

end



#print sqrt(5.0),"\n"
#newton(2.0,5.0)
#pi()
pi2()

