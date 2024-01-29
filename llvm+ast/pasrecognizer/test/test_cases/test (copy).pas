program quicksort(input,output);
var a:array[0..9] of integer;
function qsort(l,r:integer):integer;
var
  i,j,m,t:integer;
begin
  i:=l;
  j:=r;
  m:=a[(l+r)div 2];
  while i<=j do
  begin
    while a[i]<m do i:=i+1;
    while a[j]>m do j:=j-1;
    if not(i>j) then
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

end.