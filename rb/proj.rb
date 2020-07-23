def ead2(x1,x2,y1,y2,z1,z2,mod)
u=y2*z1-y1*z2
v=x2*z1-x1*z2
a=u*u*z1*z2-v**3-2*v*v*x1*z2
@P_x=v*a%mod
@P_y=(u*(v*v*x1*z2-a)-v**3*y1*z2)%mod
@P_z=(v**3*z1*z2)%mod
#アフィン座標に変換
rev=inv(@P_z,mod)
@P_x=@P_x*rev%mod
@P_y=@P_y*rev%mod
@P_z=@P_z*rev%mod
if(@P_y*@P_y*@P_z%mod != (@P_x*@P_x*@P_x+@CRV_a*@P_x*@P_z*@P_z+@CRV_b*@P_z*@P_z*@P_z)%mod)
  print "err in ead2\n"
  exit()
end
end

def edb2(x1,y1,z1,mod)
w=@CRV_a*z1*z1+3*x1*x1
s=y1*z1
b=s*x1*y1
h=w*w-8*b
@Q_x=2*h*s%mod
@Q_y=(w*(4*b-h)-8*y1*y1*s*s)%mod
@Q_z=8*(s**3)%mod
#アフィン座標に変換
rev=inv(@Q_z,mod)
@Q_x=@Q_x*rev%mod
@Q_y=@Q_y*rev%mod
@Q_z=@Q_z*rev%mod
  if((@Q_z*@Q_y*@Q_y)%mod!=(@Q_x*@Q_x*@Q_x+@CRV_a*@Q_x*@Q_z*@Q_z+@CRV_b*@Q_z*@Q_z*@Q_z)%mod)
    print "no point at edb2\n"
    exit()
  end
end
