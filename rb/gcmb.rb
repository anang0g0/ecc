#! /usr/local/bin/ruby
# /root/ruby-1.6.7/sample/dsa.rb
# Created: Jul 15,2004
# Author: tcshacina
# $Id: dsa.rb,v 0.9 2004/07/15
# usage: ruby gcmb.rb
# hint: 組合せの生成

#@N=1024
@N=24
@K=3

def first(n) 
return ((1 << n) - 1)
end


def nmlt(i)
l=1;

  for j in 0..i-1
    l=l*2
  end

    return l
end


def nextset(x)
  
  smallest=(x & -x)
  ripple=x+smallest
  n_small=(ripple & -ripple)
  ones=((n_small/smallest)>>1)-1
  return ripple|ones

end


def printest(s)

b=0
j=0


  for i in 1..@N
    if(s&1==1)
      print i," "
      j=j^nmlt(i-1)
    end
    s >>= 1
  end

  print "\n"
  print j,"\n"

end


def main()

 
 print "N=",@N,"\n"

  print "K=",@K,"\n"

  count=0
  count2=0
  i=1
  m=0
  x=first(@K)
print x,"\n"
#exit()
  while((x & ~first(@N))==0)
    print i,":"
    printest(x)
    x=nextset(x)
    i=i+1
  end

end

main()