program quicksort(input,output);
var a:array[1..5] of integer;k,x,y:integer;
function qsort(l,r:integer):integer;
var i,j,m,t:integer;
begin
  i:=l;
  j:=r;
  m:=((l+r)/2);
  m:=a[m];

  while i<=j do
  begin
  
    while a[i]<m do i:=i+1;
    while a[j]>m do j:=j-1;
    
  
    if i<=j then
    begin
      t:=a[i];
      a[i]:=a[j];
      a[j]:=t;
      i:=i+1;
      j:=j-1;
    end;
  end;

  if l<j then qsort(l,j);
  if i<r then qsort(i,r);
  qsort:=1;
end;

begin
  (*
  k:=0;
  while k<=9 do
  begin
  inputInt;
  a[k]:=inputivar;
  k:=k+1;
  end;
  *)
  a[1]:=8;
  a[2]:=4;
  a[3]:=5;
  a[4]:=6;
  a[5]:=1;
  x:=1;y:=5;

  qsort(x,y);

  k:=1;
  while k<=5 do
  begin
  outputivar:=a[k];
  outputInt;
  k:=k+1;
  end;
end.
