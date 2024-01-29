program hello(input,output);
const b=2;

var a:array [0..5] of integer;c:integer;d:boolean;e:integer;
f:record h:integer;g:boolean end;

function func(num1,num2:integer):integer;
var i,j:integer;
begin
	i:=num1;
	j:=num2;

	func:=i+j
end

procedure pro;
var x,y:integer;
begin
	x:=10;
	y:=x;
	y:=x+y;
end;


begin
	c:=5;
	e:=(-c)/5;
	a[3]:=-(b*3)/5;
	d:=(not 1 )or 1;
	e:=a[3];
	e:=e+c;
	f.h:=10;
	c:=f.h+13;
end.