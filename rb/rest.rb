
=begin
if(@temp[2][1]!=1)
  for a in 1..15
    b=mlt(a,@temp[2][1])
    if(b==1)
      @temp[2][1]=b;
      print @temp[2][1],","
      break;
    end
  end
  print a,"=",@temp[2][1],"\n"
end


for i in 0..4
  j=4;
  while(j>-1)
    print @temp[j][i],","
    j=j-1;
  end
  print "\n"
end

for i in 0..4
  if(i!=2)
    @temp[i][1]=mlt(@temp[i][1],a)
  end
end

j=4;
while(j>-1)
  print @temp[j][1],",";
  j=j-1;
end
print "\n\n"

for i in 2..3
  
    @tmp[2][i]=mlt(@temp[2][i],@temp[2][1]);
  
end
for j in 2..3
  for i in 0..4
    
      @tmp2[i][j]=mlt(@temp[i][1],@tmp[2][j]);
    
  end
end
for j in 2..3
  for i in 0..4
    
      @temp[i][j]=@fg[@gf[@tmp2[i][j]]^@gf[@temp[i][j]]];
    
  end
end
for i in 0..3
  j=4
  while(j>-1)
    print @temp[j][i],",";
    j=j-1;
  end
  print "\n"
end


if(@temp[1][2]!=1)
  for a in 1..15
    b=mlt(a,@temp[1][2])
    if(b==1)
      @temp[1][2]=b;
      print @temp[1][2],","
      break;
    end
  end
  print a,"=",@temp[1][2],"\n"
end


for i in 0..4
  j=4;
  while(j>-1)
    print @temp[j][i],","
    j=j-1;
  end
  print "\n"
end

for i in 0..4
  if(i!=1)
    @temp[i][2]=mlt(@temp[i][2],a)
  end
end

j=4;
while(j>-1)
  print @temp[j][2],",";
  j=j-1;
end
print "\n\n"

for i in 3..3
  @tmp[1][i]=mlt(@temp[1][i],@temp[1][2]);
end
for j in 3..3
  for i in 0..4
    @tmp2[i][j]=mlt(@temp[i][2],@tmp[1][j]);
  end
end
for j in 3..3
  for i in 0..4
    @temp[i][j]=@fg[@gf[@tmp2[i][j]]^@gf[@temp[i][j]]];
  end
end

for i in 0..3
  j=4
  while(j>-1)
    print @temp[j][i],",";
    j=j-1;
  end
  print "\n"
end



if(@temp[0][3]!=1)
  for a in 1..15
    b=mlt(a,@temp[0][3])
    if(b==1)
      @temp[0][3]=b;
      print @temp[0][3],","
      break;
    end
  end
  print a,"=",@temp[0][3],"\n"
end


for i in 0..4
  j=4;
  while(j>-1)
    print @temp[j][i],","
    j=j-1;
  end
  print "\n"
end

for i in 0..4
  if(i!=0)
    @temp[i][3]=mlt(@temp[i][3],a)
  end
end

print "@\n"
j=4;
while(j>-1)
  print @temp[j][3],",";
  j=j-1;
end
print "\n\n"


for i in 0..3
  j=4
  while(j>-1)
    print @temp[j][i],",";
    j=j-1;
  end
  print "\n"
end
print "\n"
=end
