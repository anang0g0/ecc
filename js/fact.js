


function fact()
{
  
  stack = new Array(10000);
  var j=0;
  var i;
  var n=0;
  var m=0;
  var l=0;
  var x;
  var count=0;
  
  
  i=1;stack[0]=1;
  x=1000;
  
  for (i=1;i<x+1;i++)
    {
      l=n+1;
      for(j=0;j < n+1;j++)
	stack[j]=stack[j]*i;
      
      j=-1;
      for (j=0;j<l;j++)
	{
	  if (stack[j] > 9999)
	    {
	      m=Math.floor(stack[j]/10000);
	      if (j==n)
		{
                  n=n+1;
		 stack[j+1]=0;
	       }
	      stack[j+1]=stack[j+1]+m;
	      stack[j]=stack[j]%10000;
	    }
	}
    }
  document.write(++n + "<br>");
  while (--n >= 0)
    {
      document.write(stack[n] + " ");
      if (++count == 10)
	{
	  document.write("<br>");
	  count=0;
	}
    }
  document.write("<br>");

}

document.write("‚¤‚Ó‚Á" + "<br>");

