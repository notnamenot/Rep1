

//x


procedure DFSHamilton(v : integer);
var


  i    : integer;
  test : boolean;
  p    : PslistEl;
begin
  S[sptr] := v;                 // Wierzcho�ek v na stos
  inc(sptr);
  if sptr < n then              // Jest �cie�ka Hamiltona?
  begin
    visited[v] := true;         // Nie ma, odwiedzamy v
    p := graf[v];
    while p <> nil do           // Przegl�damy s�siad�w v
    begin
      if not visited[p^.v] then DFSHamilton(p^.v); // Wywo�anie rekurencyjne
      p := p^.next;             // Nast�pny s�siad
    end;
    visited[v] := false;        // Wycofujemy si� z v
  end
  else                          // Jest �cie�ka Hamiltona
  begin
    test := false;              // Zak�adamy brak cyklu
    p := graf[v];               // Przegl�damy s�siad�w
    while p <> nil do
    begin
      if p^.v = 0 then          // Je�li s�siadem jest wierzcho�ek 0,
      begin
        test := true;           // to mamy cykl
        break;
      end;
      p := p^.next;             // Nast�pny s�siad
    end;
    if test then write('Hamiltonian Cycle :')
    else         write('Hamiltonian Path  :');
    for i := 0 to sptr - 1 do   // Wypisujemy �cie�k� Hamiltona
      write(S[i]:3);
    if test then write(0:3);    // Dla cyklu dopisujemy wierzcho�ek startowy
    writeln;
  end;
  dec(sptr);                    // Wierzcho�ek v usuwamy ze stosu
end;

// **********************
// *** PROGRAM G��WNY ***
// **********************

var
  i,v1,v2 : integer;
  p,r     : PslistEl;
begin
  read(n,m);                    // Czytamy liczb� wierzcho�k�w i kraw�dzi

  // Tworzymy tablice dynamiczne

  SetLength(graf,n);
  SetLength(visited,n);
  for i := 0 to n - 1 do
  begin
    graf[i]    := nil;
    visited[i] := false;
  end;
  SetLength(S,n);
  sptr := 0;

  // Odczytujemy definicje kraw�dzi grafu

  for i := 0 to m - 1 do
  begin
    read(v1,v2);
    new(p);
    p^.v := v2;
    p^.next := graf[v1];
    graf[v1] := p;
    new(p);
    p^.v := v1;
    p^.next := graf[v2];
    graf[v2] := p;
  end;

  writeln;

  // Wy�wietlamy �cie�ki i cykle Hamiltona

  DFSHamilton(0);

  // Usuwamy zmienne dynamiczne

  SetLength(visited,0);
  SetLength(S,0);

  for i := 0 to n - 1 do
  begin
    p := graf[i];
    while p <> nil do
    begin
      r := p;
      p := p^.next;
      dispose(r);
    end;
  end;

  SetLength(graf,0);
end. 