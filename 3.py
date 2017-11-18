

//x


procedure DFSHamilton(v : integer);
var


  i    : integer;
  test : boolean;
  p    : PslistEl;
begin
  S[sptr] := v;                 // Wierzcho³ek v na stos
  inc(sptr);
  if sptr < n then              // Jest œcie¿ka Hamiltona?
  begin
    visited[v] := true;         // Nie ma, odwiedzamy v
    p := graf[v];
    while p <> nil do           // Przegl¹damy s¹siadów v
    begin
      if not visited[p^.v] then DFSHamilton(p^.v); // Wywo³anie rekurencyjne
      p := p^.next;             // Nastêpny s¹siad
    end;
    visited[v] := false;        // Wycofujemy siê z v
  end
  else                          // Jest œcie¿ka Hamiltona
  begin
    test := false;              // Zak³adamy brak cyklu
    p := graf[v];               // Przegl¹damy s¹siadów
    while p <> nil do
    begin
      if p^.v = 0 then          // Jeœli s¹siadem jest wierzcho³ek 0,
      begin
        test := true;           // to mamy cykl
        break;
      end;
      p := p^.next;             // Nastêpny s¹siad
    end;
    if test then write('Hamiltonian Cycle :')
    else         write('Hamiltonian Path  :');
    for i := 0 to sptr - 1 do   // Wypisujemy œcie¿kê Hamiltona
      write(S[i]:3);
    if test then write(0:3);    // Dla cyklu dopisujemy wierzcho³ek startowy
    writeln;
  end;
  dec(sptr);                    // Wierzcho³ek v usuwamy ze stosu
end;

// **********************
// *** PROGRAM G£ÓWNY ***
// **********************

var
  i,v1,v2 : integer;
  p,r     : PslistEl;
begin
  read(n,m);                    // Czytamy liczbê wierzcho³ków i krawêdzi

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

  // Odczytujemy definicje krawêdzi grafu

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

  // Wyœwietlamy œcie¿ki i cykle Hamiltona

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