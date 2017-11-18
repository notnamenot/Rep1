program pfcodes;

// Definicja węzła drzewa kodu bezprzystankowego
//----------------------------------------------
type
  PTNode = ^TNode;
  TNode  = record
    left  : PTNode;
    right : PTNode;
    key   : char;
  end;

// Tworzy z danych wejściowych
// drzewo kodu bezprzystankowego
//------------------------------
procedure makeT(var root : PTNode);
var
  n,i,j : integer;
  s,x   : char;
  b     : string;
  p     : PTNode;
begin
  new(root);                    // Tworzymy węzeł startowy
  root^.left  := nil;           // Wypełniamy pola
  root^.right := nil;

  readln(n);                    // Odczytujemy liczbę definicji

  for i := 1 to n do            // W pętli tworzymy drzewo
  begin
    readln(s,x,b);              // Czytamy znak, spację x i kod

    p := root;                  // Rozpoczynamy od korzenia

    for j := 1 to length(b) do  // Przetwarzamy kolejne bity kodu
      if b[j] = '0' then        // Czy bit = 0?
      begin
        if p^.left = nil then   // Czy istnieje lewy syn?
        begin
          new(p^.left);         // Jeśli nie, to go tworzymy
          p^.left^.left  := nil;
          p^.left^.right := nil;
        end;
        p := p^.left;           // Przechodzimy do lewego syna
      end
      else                      // To samo dla bit = 1
      begin
        if p^.right = nil then  // Czy istnieje prawy syn?
        begin
          new(p^.right);        // Jeśli nie, to go tworzymy
          p^.right^.left  := nil;
          p^.right^.right := nil;
        end;
        p := p^.right;          // Przechodzimy do prawego syna
      end;

    p^.key := s;                // Do liścia wstawiamy znak

  end;
end;

// Dekoduje wiadomość w kodzie bezprzystankowym
//---------------------------------------------
procedure decodeT(root : PTNode);
var
  p : PTNode;
  b : string;
  i : integer;
begin
  readln(b);                   // Odczytujemy kod

  writeln;

  p := root;                   // Bieżący węzeł ustawiamy na początek drzewa

  for i := 1 to length(b) do   // Przetwarzamy kolejne bity kodu
  begin
    if b[i] = '0' then p := p^.left
    else               p := p^.right;
    if p^.left = nil then
    begin
      write(p^.key);
      p := root;
    end;
  end;

  writeln;

end;

// Procedura DFS:postorder usuwająca drzewo
//-----------------------------------------
procedure DFSRelease(v : PTNode);
begin
  if v <> nil then
  begin
    DFSRelease(v^.left);   // usuwamy lewe poddrzewo
    DFSRelease(v^.right);  // usuwamy prawe poddrzewo
    dispose(v);            // usuwamy sam węzeł
  end
end;

