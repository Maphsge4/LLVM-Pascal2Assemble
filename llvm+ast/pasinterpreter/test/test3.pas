program MAX(input,output);
var a,b:integer;
function max (x,y:integer):integer;

begin
	if x>y then max:=x else max:=y;
end;

begin
	a:=12;b:=60;
	outputivar:=max(a,b);
	outputInt;
end.
