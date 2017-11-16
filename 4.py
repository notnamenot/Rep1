// Sito Eratostenesa
// Data   : 17.03.2008
// (C)2012 mgr Jerzy Wa³aszek
//----------------------------

program prg;

type
  Tbarray = array of boolean;

var
  c,k,t,q,m,n,i,j,ij : longword;
  S : Tbarray;

begin
  readln(n);
  m := n div 3;
  if (m and 1) = 0 then inc(m); 
  setlength(S,m+1);
  c := 0; k := 1; t := 2;
  q := round(sqrt(n)) div 3;
  for i := 1 to m do S[i] := true;
  for i := 1 to q do
  begin
    k  := 3 - k;
    inc(c,(k shl 2) * i);
    j  := c;
    ij := (i shl 1) * (3 - k) + 1;
    inc(t,k shl 2);
    while j <= m do
    begin
      S[j] := false;
      inc(j,ij);
      ij   := t - ij;
    end;
  end;
  write(2,' ',3,' ');
  for i := 1 to m do
    if S[i] then
    begin
      if (i and 1) = 1 then write(3 * i + 2)
      else                  write(3 * i + 1);
      write(' ');
    end;
  writeln;
end. 