// Generator Mersenne Twister
// Data   : 16.04.2008
// (C)2012 mgr Jerzy Wa³aszek
//---------------------------

program prg;

uses SysUtils,DateUtils;

var

  MT  : array[0..623] of longword;
  mti : integer;

// Inicjuje MT[]
//--------------
procedure InicjujMT(x0 : longword);

var
  i : integer;
  x : qword;
begin
  MT[0] := x0;
  for i := 1 to 623 do
  begin
    x := MT[i-1];
    x := (23023 * x) and $00000000ffffffff;
    x := (    3 * x) and $00000000ffffffff;
    MT[i] := x;
  end;
  mti := 0;
end;

// Inicjuje MT wartoœciami losowymi
//---------------------------------
procedure UprzypadkowijMT;

var
  t  : TDateTime;
  x0 : longword;
begin
  t  := Now;
  x0 := HourOf(t);
  x0 := x0 *   60 + MinuteOf(t);
  x0 := x0 *   60 + SecondOf(t);
  x0 := x0 * 1000 + MillisecondOf(t);
  InicjujMT(x0);
end;

// Generator Mersenne Twister
//--------------------------
function MersenneTwister : longword;
const
  MA : array[0..1] of longword = (0,$9908b0df);
var
  y : longword;
  i1,i397 : integer;
begin
  i1      := mti +   1; if   i1 > 623 then i1 := 0;
  i397    := mti + 397; if i397 > 623 then dec(i397,624);
  y       := (MT[mti] and $80000000) or (MT[i1] and $7fffffff);
  MT[mti] := MT[i397] xor (y shr 1) xor MA[y and 1];
  y       := MT[mti];
  y       := y xor ( y shr 11);
  y       := y xor ((y shl  7) and $9d2c5680);
  y       := y xor ((y shl 15) and $efc60000);
  y       := y xor ( y shr 18);
  mti     := i1;
  MersenneTwister := y;
end;

var
  a,b,i,n : longint;
begin
  UprzypadkowijMT;
  readln(a,b,n);
  for i := 1 to n do write(a + (MersenneTwister mod (b - a + 1)),' ');
  writeln;
end. 